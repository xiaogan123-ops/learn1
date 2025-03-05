#include"widget.h"
#include "ui_widget.h"
#include "maze.h"
#include <QPainter>
#include <QKeyEvent>
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <QInputDialog>
#include<QFileDialog>
#include<QSettings>
#include<QRandomGenerator>>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
    , mpmap(nullptr)
    , mrole(nullptr)
    , mtime(nullptr)
    , gameWon(false)
    , mazeRows(0)
    , mazeCols(0)
    , startX(0)
    , startY(0)
    , endX(0)
    , endY(0)
    ,propsx(0)
    ,propsy(0)
    ,mMedia(new QMediaPlayer(this))
    ,mMedia_2(new QMediaPlayer(this))
    ,mMedia_3(new QMediaPlayer(this))
    ,audioOutput(new QAudioOutput(this))
    ,audioOutput_2(new QAudioOutput(this))
    ,audioOutput_3(new QAudioOutput(this))
    ,showVictory(false)
    ,victoryScale(0.0)  // 胜利动画缩放比例
    , victorySoundPlayed(false) // 初始化标志
    ,mMedia_4(new QMediaPlayer(this)) // 媒体播放器
    ,audioOutput_4(new QAudioOutput(this))// 音频输出
    ,isPropCollected(false)
    ,failureScale(0.0)
    ,settingwindow(settingWindow::instance(this))
    , m_hasBanana(false)
    , m_isSpeedBoosted(false)
    , m_stepSize(1)
    ,gameFailed(false)
    ,currentLevel(0)
    ,is_bookCollected(false)
{
    ui->setupUi(this);

    setFixedSize(850, 600);

    // 添加胜利动画定时器
    victoryTimer = new QTimer(this);
    connect(victoryTimer, &QTimer::timeout, this, [this]() {
        if (victoryScale < 1.0) {
            victoryScale += 0.05;// 逐步增加缩放比例
            update();
        } else {
            victoryTimer->stop();
        }
    });

    // 添加失败动画定时器
    failureTimer_2 = new QTimer(this);
    connect(failureTimer_2, &QTimer::timeout, this, [this]() {
        if (failureScale < 1.0) {
            failureScale += 0.05;
            update();
        } else {
            failureTimer_2->stop();
        }
    });

    // 配置背景音乐
    mMedia->setAudioOutput(audioOutput); // 绑定音频输出
    mMedia->setSource(QUrl("qrc:/res/4.mp4")); // 使用资源路径
    audioOutput->setVolume(50); // 设置音量（0~100）
    settingwindow->registerAudioOutput(audioOutput);

    mMedia_2->setAudioOutput(audioOutput_2);
    mMedia_2->setSource(QUrl("qrc:/res/ButtonSound.wav"));
    audioOutput_2->setVolume(50);
    settingwindow->registerAudioOutput(audioOutput_2);

    mMedia_3->setAudioOutput(audioOutput_3);
    mMedia_3->setSource(QUrl("qrc:/res/victory_sound.mp3"));
    audioOutput_3->setVolume(50);
    settingwindow->registerAudioOutput(audioOutput_3);

    mMedia_4->setAudioOutput(audioOutput_4);
    mMedia_4->setSource(QUrl("qrc:/res/failure_sound.mp3"));
    audioOutput_4->setVolume(50);
    settingwindow->registerAudioOutput(audioOutput_4);

    connect(ui->But1, &QPushButton::clicked, this, &Widget::onBackButtonClicked);
    connect(ui->btu2, &QPushButton::clicked, this, &Widget::onAutoPathButtonClicked);
    connect(ui->btu3, &QPushButton::clicked, this, &Widget::onNoSolutionButtonClicked);

    //怪物
    monsterImageMap.insert({5, 0}, ":/res/bird.jpg");

    monsterImageMap.insert({6, 0}, ":/res/7.jpg");
    monsterImageMap.insert({7, 0}, ":/res/8.jpg");

    monsterImageMap.insert({8, 0}, ":/res/8.jpg");
    monsterImageMap.insert({9, 0}, ":/res/9.jpg");
    monsterImageMap.insert({9, 1}, ":/res/9.jpg");

    monsterTimer = new QTimer(this);
    connect(monsterTimer, &QTimer::timeout, this, &Widget::moveMonsters);

    initLevelDialogs();

    setFocusPolicy(Qt::StrongFocus);
    QTimer::singleShot(100, this, &Widget::setFocusToGame);

    // 初始化加速计时器
    m_speedBoostTimer = new QTimer(this);
    connect(m_speedBoostTimer, &QTimer::timeout, this, [this](){
        m_isSpeedBoosted = false;
        m_stepSize = 1;
        m_speedBoostTimer->stop();
    });

    fragmentsCollected = 0;
    fragmentCollectedInLevel.clear();
    m_fragmentPos = QPoint(-1, -1);
}
void Widget::setFocusToGame()
{
    this->setFocus();
    if(currentDialog){
        currentDialog->setFocusProxy(this);
    }
}
void Widget::setupMonstersForLevel(int level) {
    // 清空原有怪物
    qDeleteAll(m_monsters);
    m_monsters.clear();

    // 根据关卡配置怪物
    switch(level) {
    case 5: // 鼻涕怪直线巡逻
        m_monsters.append(new Monster());
        m_monsters[0]->setPatrolRoute({{8,14}, {12,14}});
        break;
    case 6:
        m_monsters.append(new Monster());
        m_monsters[0]->setPatrolRoute({{17,6}, {17,9}});
        break;
    case 7:
        m_monsters.append(new Monster());
        m_monsters[0]->setPatrolRoute({{8,8}, {10,8}});
        break;
    case 8:
        m_monsters.append(new Monster());
        m_monsters[0]->setPatrolRoute({{19,5}, {19,9}});
        break;
    case 9: { // 两个跳跳怪交叉巡逻
        // 红怪路线
        m_monsters.append(new Monster());
        m_monsters.last()->setPatrolRoute({{9,1}, {12,1}});

        // 第二个跳跳怪（蓝色）
        m_monsters.append(new Monster());
        m_monsters.last()->setPatrolRoute({{15,11}, {17,11}});
        break;
    }
    }
}
Widget::~Widget()
{

    // 清理旧资源
    if (mtime) {
        mtime->stop();
        delete mtime;
    }
    delete mpmap;
    delete mrole;
    delete ui;
    if(currentDialog) {
        currentDialog->deleteLater();
    }

    if (monsterTimer) {
        monsterTimer->stop();
        delete monsterTimer;
    }
}

//设置迷宫参数
void Widget::setMazeParameters(int rows, int cols, int startX, int startY, int endX, int endY) {
    this->mazeRows = rows;
    this->mazeCols = cols;
    this->startX = startX;
    this->startY = startY;
    this->endX = endX;
    this->endY = endY;
    mMedia->play();   // 播放背景音乐
    resetGame();  // 先重置游戏
    ui->btu2->setVisible(true);

    if (!mpmap) return; // 确保 mpmap 初始化成功


}


// 重置游戏状态
void Widget::resetGame()
{


    qDebug() << "正在重置游戏...";

    // 先停止定时器
    if (mtime) {
        mtime->stop();
        delete mtime;
        mtime = nullptr;
    }

    // 清理旧数据
    if (mpmap) {
        delete mpmap;
        mpmap = nullptr;
    }

    if (mrole) {
        qDebug() << "清理角色数据，最后位置:" << mrole->row() << "," << mrole->col();
        delete mrole;
        mrole = nullptr;
    }

    // 初始化游戏状态变量
    victorySoundPlayed = false; // 重置音效播放标志
    gameWon = false;
    showVictory = false;
    victoryScale = 0.0;
    victoryTimer->stop();

    solutionPath.clear();
    showingPath = false;

    // 创建新迷宫对象并加载文件
    Maze* maze=new(Maze);
    QString filePath = QFileDialog::getOpenFileName(this, "选择迷宫文件", "", "Text Files (*.txt);;All Files (*)");
    if (filePath.isEmpty()) {
        QMessageBox::warning(this, "错误", "未选择迷宫文件！");
        return;
    }

    if(maze->loadFromFile(filePath)){
        qDebug() << "迷宫成功加载";
    } else {
        QMessageBox::warning(this, "错误", "迷宫加载失败！");
        return;
    }

    mazeRows = maze->getmaze().size();
    mazeCols = (mazeRows > 0) ? maze->getmaze()[0].size() : 0;

    // 设置起始点和角色位置
    QPair<int, int> startPos = maze->findStartPosition();
    startX = startPos.first;
    startY = startPos.second;
    mrole = new Role(this);
    mrole->setPosition(startX, startY);  // 让角色在起点



    QPair<int, int> endPos = maze->findEndPosition();
    endX = endPos.first;
    endY = endPos.second;
    // 初始化地图和角色
    mpmap = new Gameman(this);
    mpmap->InitByData(maze->getmaze());

    // 检查终点是否有效
    if (endX == -1 || endY == -1) {
        QMessageBox::warning(this, "错误", "未找到迷宫终点！");
        return;
    }


    // 创建新计时器
    if (!mtime) {
        mtime = new QTimer(this);
    }
    gameWon = false;
    update();
    delete maze;


}

void Widget::onBackButtonClicked()
{

    isPropCollected = false;
    m_hasBanana = false;
    m_stepSize=1;
    gameFailed=false;
    mMedia_2->play(); // 播放按钮音效

    if (mMedia) {
        mMedia->stop();  // 停止播放
    }


    // 重置失败相关状态
    failureScale = 0.0;           // 重置动画缩放比例
    failure_soundPlayed_2 = false; // 重置声音播放标志
    failureTimer_2->stop();        // 停止失败动画定时器




    this->hide();
    if (parentWidget()) {
        parentWidget()->show(); // 返回上一个窗口
    }

}

void Widget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);

    // 绘制背景图片
    QImage background("://res/background.jpg");
    if (!background.isNull()) {
        painter.drawImage(QRect(0, 0, 850, 600), background);
    } else {
        qDebug() << "Failed to load background image.";
    }
    // 绘制地图
    if (mpmap) {
        mpmap->paint(&painter, QPoint(0, 0));
    }

    if(currentLevel==1&&!is_bookCollected){
        int cellWidth = 600 / mazeCols;
        int cellHeight = 600 / mazeRows;
        painter.drawImage(QRect(
                             m_book.y() * cellWidth,
                             m_book.x()* cellHeight,
                              cellWidth,
                              cellHeight),
                          QImage(":/res/book.jpg"));
    }


    if((currentLevel == 3||currentLevel==4) && !isPropCollected){
        int cellWidth = 600 / mazeCols;
        int cellHeight = 600 / mazeRows;
        painter.drawImage(QRect(
                              m_props.y() * cellWidth,
                              m_props.x()* cellHeight,
                              cellWidth,
                              cellHeight),
                          QImage(":/res/11.jpg"));
    }


    if((currentLevel == 6||currentLevel==2||currentLevel==8||currentLevel==9||currentLevel==4||currentLevel==7)&& m_hasBanana){
        int cellWidth = 600 / mazeCols;
        int cellHeight = 600 / mazeRows;
        painter.drawImage(QRect(
                              m_bananaPos.y() * cellWidth,
                              m_bananaPos.x() * cellHeight,
                              cellWidth,
                              cellHeight),
                          QImage(":/res/shoe.jpg"));
    }

    if ((currentLevel == 2 || currentLevel == 8 ||currentLevel==7) &&
        !fragmentCollectedInLevel.value(currentLevel, false) &&
        m_fragmentPos != QPoint(-1, -1))
    {
        int cellWidth = 600 / mazeCols;
        int cellHeight = 600 / mazeRows;
        painter.drawImage(QRect(
                              m_fragmentPos.y() * cellWidth,
                              m_fragmentPos.x() * cellHeight,
                              cellWidth,
                              cellHeight),
                          QImage(":/res/debris.jpg"));
    }

    if((currentLevel == 3||currentLevel==5||currentLevel==9) && !m_hasTriggeredKite){
        int cellWidth = 600 / mazeCols;
        int cellHeight = 600 / mazeRows;
        painter.drawImage(QRect(
                              m_woodenKitePos.y() * cellWidth,
                              m_woodenKitePos.x() * cellHeight,
                              cellWidth,
                              cellHeight),
                          QImage(":/res/wooden_kite.jpg"));
    }


    // 角色绘制
    if (mrole) {
        int cellWidth = 600 / mazeCols;
        int cellHeight = 600 / mazeRows;
        mrole->Paint(&painter, QPoint(0, 0), cellWidth, cellHeight);
    }





    // 检查胜利状态
    if (mrole && mrole->row() == endX && mrole->col() == endY) {
        qDebug() << "到达终点! 角色位置("
                 << mrole->row() << "," << mrole->col()
                 << ") 终点位置(" << endX << "," << endY << ")";


        // 先处理特殊结局
        if (currentLevel == 9 && fragmentsCollected >= 3 && !specialEndingShown) {
            specialEndingShown = true;
            gameWon = true;  // 锁定游戏状态

            // 停止所有游戏逻辑
            if(mtime) mtime->stop();
            if(monsterTimer) monsterTimer->stop();
            victoryTimer->stop();

            // 显示特殊结局对话框
            showLevelDialog(QStringList()
                            << "天志传承"
                            << "周身机关突然停止运转，墙上浮现古篆："
                            << "「兼爱众生，可承墨守」");
            return;
        } else if (currentLevel==9&& fragmentsCollected < 3 && !specialEndingShown) {
            // 碎片不足的失败情况
            specialEndingShown = true;
            gameWon = true;
            if(mtime) mtime->stop();
            if(monsterTimer) monsterTimer->stop();
            victoryTimer->stop();
            showLevelDialog(QStringList()
                            << "墨守未成"
                            << "机关发出低沉轰鸣，墙上篆文渐显："
                            << "「非攻碎片未齐，难承天志传承」");
            return;
        }
        if (!gameWon) { //未胜利状态检查
            levelComplete();
            gameWon = true;
            showVictory = true;
            victoryScale = 0.0;
            if (mtime) mtime->stop();
            victoryTimer->start(50);

            if (!victorySoundPlayed) {
                mMedia_3->play();
                victorySoundPlayed = true;
            }

            if (mMedia) {
                mMedia->stop();
            }
        }
    }

    // 绘制胜利标志
    if (showVictory) {



        QPixmap victoryPixmap("://res/2.jpg");
        if (!victoryPixmap.isNull()) {
            int baseWidth = 200;
            int baseHeight = 200;

            qDebug() << "Drawing victory image at scale:" << victoryScale;

            int scaledWidth = baseWidth * victoryScale;
            int scaledHeight = baseHeight * victoryScale;

            QRect targetRect(
                (width() - scaledWidth) / 2,
                (height() - scaledHeight) / 2 - 50,
                scaledWidth,
                scaledHeight
                );


            painter.save();  // 保存当前绘制状态
            painter.setOpacity(victoryScale);
            painter.drawPixmap(targetRect, victoryPixmap);
            painter.restore();  // 恢复绘制状态
        } else {
            qDebug() << "Failed to load victory image!";
        }
    }


    for(int i=0; i<m_monsters.size(); ++i){
        Monster* monster = m_monsters[i];
        QString imgPath = monsterImageMap.value({currentLevel, i}, "");

        if(!imgPath.isEmpty()){
            QImage monsterImg(imgPath);
            int cellW = 600/mazeCols, cellH = 600/mazeRows;
            painter.drawImage(QRect(
                                  monster->col()*cellW,
                                  monster->row()*cellH,
                                  cellW, cellH), monsterImg);
        }
    }

    if (failureTimer_2->isActive() || failureScale > 0) {
        QPixmap failurePixmap("://res/3.jpg");
        if (!failurePixmap.isNull()) {
            int baseWidth = 200;
            int baseHeight = 200;
            int scaledWidth = baseWidth * failureScale;
            int scaledHeight = baseHeight * failureScale;
            QRect targetRect(
                (width() - scaledWidth) / 2,
                (height() - scaledHeight) / 2 - 50,
                scaledWidth,
                scaledHeight
                );
            painter.save();
            painter.setOpacity(failureScale);
            painter.drawPixmap(targetRect, failurePixmap);
            painter.restore();
        }
    }




    // 绘制路径（排除角色当前位置）
    if (showingPath && !solutionPath.isEmpty()) {

        int cellWidth = 600 / mazeCols;
        int cellHeight = 600 / mazeRows;

        QPoint rolePos(mrole->row(), mrole->col()); // 获取当前角色位置

        foreach (QPoint p, solutionPath) {
            // 跳过角色当前位置和终点
            if (p == rolePos || p == QPoint(endX, endY)) continue;

            painter.drawImage(QRect(
                                  p.y() * cellWidth,
                                  p.x() * cellHeight,
                                  cellWidth,
                                  cellHeight
                                  ), QImage("://res/destination.jpg")); // 专用路径标记图片
        }
    }




}

void Widget::keyPressEvent(QKeyEvent *event)
{
    if (!mrole || gameWon || isDialogActive||gameFailed) return;


    int dRow = 0, dCol = 0;
    switch(event->key()) {
    // 方向键控制
    case Qt::Key_Up:    dRow = -1; break;
    case Qt::Key_Down:  dRow = 1;  break;
    case Qt::Key_Left:  dCol = -1; break;
    case Qt::Key_Right: dCol = 1;  break;
    // WASD 控制
    case Qt::Key_W:     dRow = -1; break; // W 上
    case Qt::Key_S:     dRow = 1;  break; // S 下
    case Qt::Key_A:     dCol = -1; break; // A 左
    case Qt::Key_D:     dCol = 1;  break; // D 右
    default: QWidget::keyPressEvent(event); return;
    }

    //碎片
    if ((currentLevel == 2 || currentLevel == 8||currentLevel==7 ) &&
        !fragmentCollectedInLevel[currentLevel] &&
        mrole->row() == m_fragmentPos.x() &&
        mrole->col() == m_fragmentPos.y())
    {

        fragmentCollectedInLevel[currentLevel] = true;
        fragmentsCollected++;

        // 立即暂停游戏逻辑
        gameWon = true;  // 临时锁定游戏
        if(monsterTimer) monsterTimer->stop();
        if(mtime) mtime->stop();

        // 显示对话框
        showLevelDialog(QStringList()
                        << "墨家秘宝"
                        << "获得机关术残篇"
                        << "此物似乎记载着某种上古机关的奥秘..."
                        <<"收集完善者便可得到终极机关术");

        // 强制界面刷新
        update();
        QApplication::processEvents();

        // 恢复游戏状态（在对话框关闭后处理）
        return;  // 立即返回避免后续移动
    }

    //书竹
    if(currentLevel==1&&!is_bookCollected&&mrole->row() == m_book.x() &&
        mrole->col() == m_book.y()){

        is_bookCollected=true;

        // 立即暂停游戏逻辑
        gameWon = true;  // 临时锁定游戏
        if(monsterTimer) monsterTimer->stop();
        if(mtime) mtime->stop();

        // 显示对话框
        showLevelDialog(QStringList()
                    << "「书竹·机关传承」"  // 物品名称
                    << "传说集齐墨家机关残篇者，可得窥\n"  // 描述文本
                    "上古机关术之精髓。此竹简隐现玄光，\n"
                    "似与《墨经》残卷存有微妙感应......");

        // 强制界面刷新
        update();
        QApplication::processEvents();


    }


    if(currentLevel==5&&is_monster_n &&((mrole->row() == m_monster_1.x() &&
                                               mrole->col() == m_monster_1.y())||(mrole->row()==m_montser_tow.x()&&mrole->col()==m_montser_tow.y()))){

        if(mtime) mtime->stop();
        if(monsterTimer) monsterTimer->stop();
        showLevelDialog(QStringList()
              << "此兽通体嵌璇玑玉衡，三百六十齿咬合无隙"
              << "其怒时械瞳迸朱砂火，铜爪裂地三丈！");
        is_monster_n=false;
        return;
    }else if(currentLevel==6&&is_monster_n&&mrole->row() == m_monster_1.x() &&
               mrole->col() == m_monster_1.y()){
        if(mtime) mtime->stop();
        if(monsterTimer) monsterTimer->stop();
        showLevelDialog(QStringList()
          << "此兽开阖似饕餮吞日，足踏之处"
          << "地涌黄泉阴火，墨绳丈量生死界");
        is_monster_n=false;
        return;
    }else if(currentLevel==7&&is_monster_n&&mrole->row() == m_monster_1.x() &&
               mrole->col() == m_monster_1.y()){
        if(mtime) mtime->stop();
        if(monsterTimer) monsterTimer->stop();
        showLevelDialog(QStringList()
                        <<"《墨子·备城门》有载：『轒辒悬陴，机发连弩，百步绝杀』"
                        <<"此玄铁所铸机关人，瞳嵌夔纹水玉，三百六十关节暗藏璇玑轮轴"
                        <<"其掌中飞鸢匣可弹射九连星弩，恰合《考工记》『轮辐三十，以象日月』之数！");
        is_monster_n=false;
        return;
    }else if(currentLevel==9&&is_monster_n&&mrole->row() == m_monster_1.x() &&
               mrole->col() == m_monster_1.y()){
        if(mtime) mtime->stop();
        if(monsterTimer) monsterTimer->stop();
        showLevelDialog(QStringList()
                        << "《天工开物·锤锻篇》言：『凡铁牛镇水，必取阳燧方位』"
                        <<"眼前巨兽乃熔铸二十八宿星图，牛角嵌河图洛书，四蹄暗合地维之道"
                        <<"观其脊椎七十二环相扣，正应《唐会要》所载『黄河铁牛，每环承千钧』的液压传动之理！");
        is_monster_n=false;
        return;
    }
    // 检查是否吃到香蕉皮
    if((currentLevel == 6||currentLevel==2||currentLevel==8||currentLevel==9||currentLevel==4||currentLevel==7) && m_hasBanana &&
        mrole->row() == m_bananaPos.x() &&
        mrole->col() == m_bananaPos.y())
    {

        m_hasBanana = false;
        m_isSpeedBoosted = true;
        m_stepSize = 2; // 加速时每次移动2格
        m_speedBoostTimer->start(5000); // 加速持续5秒
        if(mtime) mtime->stop();
        if(monsterTimer) monsterTimer->stop();
        showLevelDialog(QStringList()
                        << "转重速履"
                        << "铜足踏火碾寒霜"
                        << "啮铁衔风自稳航"
                        <<"缩地何须借仙术"
                        <<"履下玄黄藏阴阳");
        return;

    }

    //木鸢
    if((currentLevel == 3||currentLevel==5||currentLevel==9) &&
        mrole->row() == m_woodenKitePos.x() &&
        mrole->col() == m_woodenKitePos.y() &&
        !m_hasTriggeredKite)
    {
        triggerWoodenKiteEvent();
        return; // 中断后续移动处理
    }


    if(currentLevel==6||currentLevel==2||currentLevel==8||currentLevel==9||currentLevel==4||currentLevel==7){

        for(int i=0; i<m_stepSize; i++){
            int newRow = mrole->row() + dRow;
            int newCol = mrole->col() + dCol;

            if(mpmap->isValid(newRow, newCol) && mpmap->isRoad(newRow, newCol)){
                mrole->setPosition(newRow, newCol);
                checkMonsterCollisions();
                if (showingPath) {
                    solutionPath.clear();
                    showingPath = false;
                }
            } else {
                break; // 如果遇到墙或者边界，停止后续移动
            }

        }
        qDebug()<<"abc";
        update();
    }else {
        int newRow = mrole->row() + dRow;
        int newCol = mrole->col() + dCol;
        if (mpmap->isValid(newRow, newCol) && mpmap->isRoad(newRow, newCol)) {
            mrole->setPosition(newRow, newCol); // 设置新位置
            if (showingPath) {
                solutionPath.clear();
                showingPath = false;
            }
            update();
        }
    }

    if( (currentLevel == 3||currentLevel==4) && !isPropCollected &&
        ((mrole->row() == m_props.rx() && mrole->col() == m_props.y())||(mrole->row() == 13 && mrole->col()==1)))
    {

        if(mtime) mtime->stop();
        if(monsterTimer) monsterTimer->stop();
        showLevelDialog(QStringList()
                        << "《殷墟甲骨·舆图》"
                        << "灼龟甲契兽骨，朱砂纹路间藏星斗排列："
                        << "『癸巳卜，贞：东方析木起连隼，西雉于雷泽』"
                        << "此乃先王占风卜地势之图，暗合二十八宿分野！"
                        << "若以墨家璇玑尺测算，可破译三千年前的地脉机关！"
                        );

        isPropCollected = true;
         onAutoPathButtonClicked();

        return;
    }

}

void Widget::checkMonsterCollisions()
{
    foreach (Monster* monster, m_monsters) {
        if(monster->row() == mrole->row() &&
            monster->col() == mrole->col())
        {

            gameFailed=true;
            handleGameFailure();
            return;
        }
    }
}
// 角色移动逻辑
void Widget::moveRole(int dRow, int dCol)
{
    if (!mrole || gameWon) return;

    // 计算新位置
    QMutexLocker locker(&moveMutex);
    int newRow = mrole->row() + dRow;
    int newCol = mrole->col() + dCol;


    // 边界检查和碰撞检测
    if (newRow < 0 || newRow >= mazeRows || newCol < 0 || newCol >= mazeCols) return;
    if (mpmap->isWall(newRow, newCol)) return;

    mrole->Move(dRow, dCol);
    if (showingPath) {
        solutionPath.clear();
        showingPath = false;
    }
    update(); // 触发重绘以检测胜利条件

    if (newRow == endX && newCol == endY) {
        mrole->setPosition(newRow, newCol);  // 强制到达终点
        levelComplete(); // 触发胜利逻辑
        return;
    }


}

void Widget::closeEvent(QCloseEvent* event) {
    // 停止所有音乐播放
    if (mMedia) mMedia->stop();
    if (mMedia_2) mMedia_2->stop();
    if (mMedia_3) mMedia_3->stop();
    if (mMedia_4) mMedia_4->stop();



    // 释放定时器
    if (victoryTimer) {
        victoryTimer->stop();
        delete victoryTimer;
    }
    if (failureTimer_2) {
        failureTimer_2->stop();
        delete failureTimer_2;
    }
    if (mtime) {
        mtime->stop();
        delete mtime;
    }
    if (monsterTimer) {
        monsterTimer->stop();
        delete monsterTimer;
    }


    QWidget::closeEvent(event);
}

void Widget::onAutoPathButtonClicked() {
    solutionPath.clear();
    showingPath = false;
    mMedia_2->play();
    if (findPathDFS(solutionPath)) { // 使用DFS算法找路径
        showingPath = true;
        update(); // 触发重绘
        qDebug()<<"aaa";
    } else {
        QMessageBox::warning(this, "提示", "当前迷宫无解！");
    }
}

void Widget::onNoSolutionButtonClicked() {
    mMedia_2->play();
    QList<QPoint> dummyPath;
    if (!findPathDFS(dummyPath)) {
        failureScale = 0.0;
        failure_soundPlayed_2 = false; // 重置标志以允许再次播放
        if (mtime) mtime->stop();
        failureTimer_2->start(50);

        if (!failure_soundPlayed_2) {
            mMedia_4->play();
            failure_soundPlayed_2 = true;
        }
        if (mMedia) mMedia->stop();
        update();
    } else {
        QMessageBox::information(this, "提示", "存在可行路径");
    }
}

//关卡
void Widget::setMaze(int level, int rows, int cols, int startX, int startY, int endX, int endY) {
    currentLevel = level; // 关键！设置当前关卡
    this->mazeRows = rows;
    this->mazeCols = cols;
    this->startX = startX;
    this->startY = startY;
    this->endX = endX;
    this->endY = endY;
    ui->btu2->setVisible(level == 0);

    resetGame1(level);  // 传递关卡号

    if (!mpmap) return;

    if(level == 6){
        m_bananaPos = QPoint(1, 12); // 设置香蕉皮位置
        m_hasBanana = true;
    }else if(level==2){
        m_bananaPos = QPoint(0, 4);
        m_hasBanana = true;
    }else if(level==8){
        m_bananaPos = QPoint(5, 19);
        m_hasBanana = true;
    }else if(level==9){
        m_bananaPos = QPoint(0, 19);
        m_hasBanana = true;
    }else if(level==4){
        m_bananaPos = QPoint(14, 16);
        m_hasBanana = true;
    }else if(level==7){
        m_bananaPos = QPoint(7, 12);
        m_hasBanana = true;
    }

    m_fragmentPos = QPoint(-1, -1);
    if (level == 2) {
        m_fragmentPos = QPoint(6, 3);
    } else if (level == 8) {
        m_fragmentPos = QPoint(1, 9);
    }else if(level==7){
         m_fragmentPos = QPoint(15, 2);
    }

    if(currentLevel == 3){
        m_woodenKitePos = QPoint(13, 7);  // 木鸢地板位置
        m_transferTarget = QPoint(7, 1);  // 传送目标位置
        m_hasTriggeredKite = false;       // 重置触发状态
    }else if(currentLevel==5){
        m_woodenKitePos = QPoint(14, 0);
        m_transferTarget = QPoint(12, 16);
        m_hasTriggeredKite = false;
    }else if(currentLevel==9){
        m_woodenKitePos = QPoint(6, 1);
        m_transferTarget = QPoint(14, 17);
        m_hasTriggeredKite = false;
    }

    if(level==3){
        m_props=QPoint(13,1);
        isPropCollected =false;
    }else if(level==4){
         m_props=QPoint(3,8);
        isPropCollected =false;
    }

    if(level==1){
        m_book=QPoint(1,11);
        is_bookCollected=false;
    }

    //触发怪物对话
    if(level==5){
        m_monster_1=QPoint(10,12);
        m_montser_tow=QPoint(10,16);
        is_monster_n=true;
    }else if(level==6){
         m_monster_1=QPoint(15,7);
        is_monster_n=true;
    }else if(level==7){
        m_monster_1=QPoint(11,9);
        is_monster_n=true;
    }else if(level==9){
        m_monster_1=QPoint(12,3);
        is_monster_n=true;
    }


}
void Widget::resetGame1(int level) {
    // 清理旧资源
    delete mpmap;
    mpmap = nullptr;
    delete mrole;
    mrole = nullptr;
    mMedia->play();

    victorySoundPlayed = false; // 重置音效播放标志
    gameWon = false;
    showVictory = false;
    victoryScale = 0.0;
    victoryTimer->stop();

    isDialogActive = false;
    gameWon = false;

    isPropCollected = false;  // 重置道具状态
    m_hasBanana = false;      // 重置香蕉状态
     specialEndingShown = false;

    setupMonstersForLevel(level); // 初始化怪物
    monsterTimer->start(800); // 启动怪物定时器

     m_hasTriggeredKite = false; // 重置木鸢触发状态

    if(level == 6){
        m_hasBanana = true;
        m_bananaPos = QPoint(1, 12); // 根据实际迷宫调整坐标
        m_isSpeedBoosted = false;
        m_stepSize = 1;
    }else {
        m_hasBanana = false;
    }

    if (level == 2 || level == 8||level==7) {
        // 仅当从未收集过时才重置
        if (!fragmentCollectedInLevel.contains(level)) {
            fragmentCollectedInLevel[level] = false;
        }
    }




    // 动态生成文件名
    QString fileName = QString("新建文件夹/taxt%1.txt").arg(level);
    QString appDir = QCoreApplication::applicationDirPath();
    QString filePath = QDir(appDir).filePath(fileName);

    solutionPath.clear();
    showingPath = false;


    Maze* maze = new Maze;
    if (!maze->loadFromFile(filePath)) {
        QMessageBox::warning(this, "错误", QString("迷宫%1加载失败！").arg(level));
        delete maze;
        return;
    }

    // 初始化角色和地图
    mazeRows = maze->getmaze().size();
    mazeCols = (mazeRows > 0) ? maze->getmaze()[0].size() : 0;

    QPair<int, int> startPos = maze->findStartPosition();
    startX = startPos.first;
    startY = startPos.second;
    mrole = new Role(this);
    mrole->setPosition(startX, startY);

    QPair<int, int> endPos = maze->findEndPosition();
    endX = endPos.first;
    endY = endPos.second;

    mpmap = new Gameman(this);
    mpmap->InitByData(maze->getmaze());





    if(levelDialogs.contains(currentLevel)){
        showLevelDialog(levelDialogs[currentLevel]);
    }



    if (endX == -1 || endY == -1) {
        QMessageBox::warning(this, "错误", "未找到迷宫终点！");
        return;
    }

    if (!mtime) {
        mtime = new QTimer(this);
    }
    gameWon = false;
    update();
    delete maze;
}

//寻路
bool Widget::findPathDFS(QList<QPoint>& path) {
    if (!mpmap || !mrole) return false;


    // 使用栈实现的DFS算法
    QStack<QPoint> stack;
    QVector<QVector<bool>> visited(mazeRows, QVector<bool>(mazeCols, false));

    QPoint start(mrole->row(), mrole->col());
    QPoint end(endX, endY);

    stack.push(start);
    visited[start.x()][start.y()] = true;

    // 用于记录路径的父节点
    QHash<QPoint, QPoint> parent;

    while (!stack.isEmpty()) {
        QPoint current = stack.pop();

        // 找到终点
        if (current == end) {
            // 回溯路径
            QPoint p = end;
            while (p != start) {
                path.prepend(p);
                p = parent[p];
            }
            path.prepend(start);
            return true;
        }

        // 四个方向：右，上，左，下
        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, -1, 0, 1};

        for (int i = 0; i < 4; ++i) {
            int newRow = current.x() + dx[i];
            int newCol = current.y() + dy[i];

            if (newRow >= 0 && newRow < mazeRows &&
                newCol >= 0 && newCol < mazeCols &&
                !mpmap->isWall(newRow, newCol) &&
                !visited[newRow][newCol]) {

                visited[newRow][newCol] = true;
                parent[QPoint(newRow, newCol)] = current;
                stack.push(QPoint(newRow, newCol));
            }
        }
    }
    return false;
}

void Widget::levelComplete() {
    int nextLevel = currentLevel + 1;
    if (nextLevel <= 9) {
        emit levelUnlocked(nextLevel); // 直接发射信号，由SecondWindow处理
    }
}




void Widget::handleGameFailure()
{
    // 停止游戏计时器和怪物移动
    if (mtime) mtime->stop();
    monsterTimer->stop();

    // 触发失败动画
    failureScale = 0.0;
    failure_soundPlayed_2 = false;
    failureTimer_2->start(50);

    gameFailed=true;//role不能移动

    // 播放失败音效
    if (!failure_soundPlayed_2) {
        mMedia_4->play();
        failure_soundPlayed_2 = true;
    }

    // 停止背景音乐
    if (mMedia) {
        mMedia->stop();
    }

    update();
}
void Widget::showLevelDialog(const QStringList &messages)
{
    // 确保旧对话框已清理
    if(currentDialog) {
        currentDialog->deleteLater();
        currentDialog = nullptr;
    }


    if (monsterTimer && monsterTimer->isActive()) {
        monsterTimer->stop();
    }

    // 设置对话框激活状态
    isDialogActive = true;

    QStringList styledMessages = messages;
    if (!styledMessages.isEmpty()) {
        // 为标题添加红色和粗体样式
        styledMessages[0] = QString("<span style='color: #FF3333; font-weight: bold;'>%1</span>")
                                .arg(styledMessages[0]);
    }

     currentDialog = new CustomDialog(styledMessages, this);
    if (monsterTimer && monsterTimer->isActive()) {
        monsterTimer->stop();
    }
    if (mtime && mtime->isActive()) {
        mtime->stop();
    }

    if (monsterTimer && monsterTimer->isActive()) {
        monsterTimer->stop();
    }

    // 设置对话框位置（底部1/3区域）
    currentDialog->setGeometry(
        width()*0.1,
        height()*2/3,
        width()*0.8,
        height()/3 - 20
        );

    connect(currentDialog, &CustomDialog::dialogFinished, this, [=](){


        if(currentLevel == 9 && fragmentsCollected >= 3) {
            levelComplete();  // 延迟执行胜利逻辑
        } else {
            gameWon = false;  // 解除锁定
            if(mtime) mtime->start(1000);
            if(monsterTimer) monsterTimer->start(800);
        }

        isDialogActive = false;
        // 强制焦点设置
        this->setFocus();
        QApplication::processEvents(); // 处理挂起的事件

        // 延迟状态检查
        QTimer::singleShot(50, this, [this](){
            qDebug() << "对话框关闭后焦点状态:" << this->hasFocus();
            if(mrole && mrole->row() == endX && mrole->col() == endY) {
                qDebug() << "触发延迟胜利检测";
                levelComplete();
            }
        });
        // 强制更新游戏状态
        QTimer::singleShot(0, this, [this](){
            if(mrole && mrole->row() == endX && mrole->col() == endY) {
                levelComplete();
            }
        });

        if(mtime) mtime->start(1000);
        if (monsterTimer) monsterTimer->start(800);
        currentDialog->deleteLater();
        currentDialog = nullptr;
        this->setFocus();
    });

    if(messages.contains("天志传承")) {
        connect(currentDialog, &CustomDialog::dialogFinished, this, [=](){
            qDebug() << "触发最终传承动画";
            showVictory = true;
            victoryScale = 0.0;
            victoryTimer->start(50);
            mMedia_3->play();
        });
    }
    if (messages.contains("墨守未成")) {
        connect(currentDialog, &CustomDialog::dialogFinished, this, [=](){
            showVictory = true;
            victoryScale = 0.0;
            victoryTimer->start(50);
            mMedia_3->play();
        });
    }

    // 暂停游戏计时
    if(mtime) mtime->stop();
    currentDialog->show();
    currentDialog->setFocus();
}
void Widget::showLevelDialog(const QString &title, const QString &text1, const QString &text2)
{
     showLevelDialog(QStringList{title, text1, text2});
}
void Widget::initLevelDialogs()
{
    levelDialogs[1] = {
        "墨鸢枢机阵",
        "铜牙轮啮合定枢杼", // 源自《墨子·备城门》齿轮传动系统
        "循枢杼铜羽旋向行进！" // 铜羽是古代齿轮定位装置
    };

    levelDialogs[2] = {
        "悬衡石门阵",
        "地栿承重启天衡机关", // "天衡"为古代衡器装置
        "踏稳三块悬权石板！" // "悬权"出自《墨子》的平衡称重概念
    };

    levelDialogs[3] = {
        "璇玑弩机廊",
        "阳燧聚光显生门方位", // 阳燧是古代凹面铜镜取火器
        "唯踏璇光映照之枨！" // 枨指古代门槛/界石
    };

    levelDialogs[4] = {
        "欹器暗道关",
        "虚则欹满则覆守其中", // 引用《荀子》记载的欹器特性
        "沿欹器中正线潜行！"
    };

    levelDialogs[5] = {
        "云梯桔槔桥", // 桔槔是《墨经》记载的杠杆提水工具
        "天衡地衡须交相为用", // 引自《墨经》杠杆原理
        "先降地衡再固天衡！"
    };

    levelDialogs[6] = {
        "候气听瓮室", // 源自古代用陶瓮监听地道的技术
        "五音相生辨虚实", // 宫商角徵羽五声音阶
        "择羽音微弱处遁形！"
    };

    levelDialogs[7] = {
        "参连弩机枢", // 三矢连发谓之参连
        "勾三股四弦五定弩向", // 引用《周髀算经》勾股定理
        "弦音三停间隙疾行！" // 三停指弩机转动周期
    };

    levelDialogs[8] = {
        "燧镜阳燎关", // 取自《淮南子》"阳燧见日则燃为火"
        "金燧木燧须得法相生", // 分金属凹面镜和木钻取火两种
        "急旋柘木燧取离火！" // 离卦象征火
    };

    levelDialogs[9] = {
        "天机锁钥阵", // 出自《鲁班书》机关锁记载
        "四维相制八极相生", // 源自《墨经》空间力学概念
        "先启地维再解天纲！" // 天地四维的机关联动
    };

}
void Widget::moveMonsters() {
    foreach (Monster* monster, m_monsters) {
        monster->move();

        // 碰撞检测
        if(monster->row() == mrole->row() &&
            monster->col() == mrole->col())
        {
            handleGameFailure();
            return;
        }
    }
    update();
}
void Widget::resetFragmentStates()
{
    fragmentsCollected = 0;
    fragmentCollectedInLevel.clear();
    fragmentCollectedInLevel[2] = false;
    fragmentCollectedInLevel[8] = false;
    fragmentCollectedInLevel[7]=false;

}
void Widget::triggerWoodenKiteEvent()
{
    m_hasTriggeredKite = true;


    // 执行传送
    mrole->setPosition(m_transferTarget.x(), m_transferTarget.y());

    // 显示知识对话框
    showLevelDialog(QStringList()
                    << "《墨子·木鸢》"
                    << "足下所踏乃墨家木鸢机关阵，据《韩非子》载："
                    << "『墨子为木鸢，三年而成，蜚一日而败』"
                    << "此乃早期空气动力学实践，以机关术借风御气！");

    update();
}
