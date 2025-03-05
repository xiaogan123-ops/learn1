#include "secondwindow.h"
#include "ui_secondwindow.h"
#include "widget.h"
#include <QPushButton>
#include <QPainter>
#include <QDebug>
#include <QIntValidator>
#include <QMessageBox> // 用于错误提示
#include <QStandardPaths>
#include<QDir>
#include<QFileDialog>
#include<QVBoxLayout>
#include<QScrollArea>
#include <QVBoxLayout>
#include <QLabel>
#include <QMouseEvent>
#include <QDebug>
#include<QGraphicsDropShadowEffect>>
SecondWindow::SecondWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::SecondWindow)
    , maze(new Maze())
    , widget(new Widget(this))
    ,mMedia(new QMediaPlayer(this))
    ,audioOutput(new QAudioOutput(this))
    ,settingwindow(settingWindow::instance(this))
{
    ui->setupUi(this);
    setFixedSize(850, 600);



    // 配置音频播放器
    mMedia->setAudioOutput(audioOutput);
    mMedia->setSource(QUrl("qrc:/res/ButtonSound.wav"));
    audioOutput->setVolume(50);
    settingwindow->registerAudioOutput(audioOutput);

    // 初始化按钮功能
     widget->setWindowFlags(Qt::Window);
    connect(ui->btu2, &QPushButton::clicked, this, &SecondWindow::onNextButtonClicked);
    connect(ui->btu1, &QPushButton::clicked, this, &SecondWindow::onBackButtonClicked);
    connect(ui->btu3,&QPushButton::clicked, this, &SecondWindow::onclicked);



    m_unlockedLevels.clear();
    m_unlockedLevels.insert(1, true);  // 默认解锁第三关（显示为第一关）
    for(int level = 2; level <= 12; ++level) {
        m_unlockedLevels.insert(level, false);
    }

    for (int level = 3 ; level <= 10; level++) { // 处理1-15关

        QString buttonName = QString("btu%1").arg(level + 2);
        QPushButton* btn = findChild<QPushButton*>(buttonName);
        if (btn) {
            //设置初始解锁状态
            bool isUnlocked = m_unlockedLevels.value(level, false);
            btn->setEnabled(isUnlocked);
            btn->setIcon(isUnlocked ? QIcon(":/res/1.png") : QIcon(":/res/6.png"));
            btn->setIconSize(QSize(50, 50));
            // 连接信号
            connect(btn, &QPushButton::clicked, [this, level]() {
                this->hide();
                mMedia->play();
                 int t=level-1;

                widget->setMaze(t, maze->getRows(), maze->getCols(),
                                maze->getstartx(), maze->getstarty(),
                                maze->getendx(), maze->getendy());
                widget->show();
            });
        }
    }




    connect(widget, &Widget::levelUnlocked, this, [this](int level){
        if (level >= 1 && level <= 10) {

                level+=1;

            m_unlockedLevels.insert(level, true);
            qDebug() << "解锁关卡：" << level;
            updateLevelButtons();
        }
    });
    currentStoryIndex = 0;
    storyFinished = false;

    // 初始化故事系统
    storyLabel = new QLabel(this);
    storyLabel->setAlignment(Qt::AlignCenter);
    storyLabel->setWordWrap(true);
    storyLabel->setStyleSheet("QLabel {"
                              "background-color: rgba(255, 255, 255, 220);" // 半透明白
                              "color: #333333;"
                              "padding: 20px;"
                              "border-radius: 10px;"
                              "font-size: 16px;"
                              "min-width: 600px;"
                              "min-height: 150px;"
                              "}");
    storyLabel->hide(); // 初始隐藏

    storyTexts = {
                  tr("公元前4世纪，墨家弟子墨衡在整理祖传《墨经》残卷时，发现用秦隶暗刻的「天志迷宫」密文——经清华简《算表》验证，其坐标算法竟暗合《周髀算经》'"
           "七衡六间'天文模型，现代X射线荧光检测更揭示墨迹含汉代才流通的朱砂矿物。"),
                  tr("为寻找失传的「非攻令」，墨衡冒险进入暗合曾侯乙墓星图方位的墨家禁地，却不知这座用《考工记》'规水矩火'"
           "原理建造的迷宫，其动态结构经钱宝琮考证源自《西京杂记》失载的'被中香炉'陀螺仪技术，每个机关都封印着《墨子五行记》记载的战国记忆合金。"),
                  tr("初代巨子设下的九重考验暗藏惊世玄机：从《墨经》'力形相奋'的天平杀阵，到沈括《梦溪笔谈》隐去的'太阴玄精'能量核心，"
           "每重机关都印证着谭戒甫《墨经分类译注》的猜想——墨家早将《吕氏春秋》'同声相应'的声学原理，化作比诸葛亮'连弩'更精妙的'转射机弩'，而整个迷宫竟是王振铎复原方案中缺失的'水运仪象台'终极形态...")
    };



}
void SecondWindow::updateLevelButtons() {
    for (int level = 3; level <= 10; level++) {
        QString buttonName = QString("btu%1").arg(level + 2);
        QPushButton* btn = findChild<QPushButton*>(buttonName);
        if (btn) {

            bool isUnlocked = m_unlockedLevels.value(level, false);
            qDebug()<<isUnlocked;
            btn->setEnabled(isUnlocked);
            btn->setIcon(isUnlocked ? QIcon() : QIcon(":/res/6.png"));
            btn->setIconSize(QSize(40, 40));
        }
    }
}
// 返回 MainWindow
void SecondWindow::onBackButtonClicked()
{
    isFirstShow=true;
     storyLabel->removeEventFilter(this); // 移除事件过滤器
    this->hide();
    if (parentWidget()) {
        parentWidget()->show();
    }
    if (widget) {
        widget->resetFragmentStates();
    }
    mMedia->play();
}

void SecondWindow::onNextButtonClicked(){

    this->hide();
    widget->setMazeParameters( maze->getRows(), maze->getCols(),
                              maze->getstartx(), maze->getstarty(),
                              maze->getendx(), maze->getendy());
    widget->show();
    mMedia->play();

}
void SecondWindow::onclicked(){
    this->hide();
    widget->setMaze(1,maze->getRows(),maze->getCols(),maze->getstartx(),maze->getstarty(),maze->getendx(),maze->getendy());
    widget->show();
    mMedia->play();
}
SecondWindow::~SecondWindow()
{
    delete maze; // 释放 Maze 资源
    delete ui;
}

// 绘制窗口背景
void SecondWindow::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);

    // 绘制背景
    QImage background("://res/background2.jpg");
    if (!background.isNull()) {
        painter.drawImage(QRect(0, 0, 850, 600), background);
    } else {
        qDebug() << "Failed to load background image.";
    }
}


void SecondWindow::updateStoryText() {
    QString fullText;
    for (int i = 0; i <= currentStoryIndex; ++i) {
        fullText += storyTexts[i];
        if (i < currentStoryIndex) {
            fullText += " ";
        }
    }
    storyLabel->setFixedHeight(400); // 高度固定
    storyLabel->setText(fullText);
    storyLabel->adjustSize(); // 400高度调整宽度
}
//新增重置函数
void SecondWindow::resetStory()
{
    currentStoryIndex = 0;
    storyLabel->setFixedHeight(400); //固定高度
    storyLabel->setText(storyTexts.first());
    storyLabel->adjustSize(); // 400高度调整宽度
    storyLabel->move((width() - storyLabel->width())/2, (height() - storyLabel->height())/2); // 中间
    storyLabel->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    storyLabel->setGraphicsEffect(new QGraphicsDropShadowEffect(this));
    storyLabel->show();

   // 禁用所有关卡按钮和其他可能交互的按钮
    for (int level = 3; level <= 10; level++) {
        QString buttonName = QString("btu%1").arg(level + 2);
        QPushButton* btn = findChild<QPushButton*>(buttonName);
        if (btn) {
            btn->setEnabled(false); // 直接禁用，不检查解锁状态
        }
    }
    // 禁用其他功能按钮
    ui->btu2->setEnabled(false);
    ui->btu3->setEnabled(false);
    ui->btu1->setEnabled(false);
}

bool SecondWindow::eventFilter(QObject* obj, QEvent* event)
{
    if (obj == storyLabel && event->type() == QEvent::MouseButtonPress) {
        mMedia->play(); // 点击音效

        if (currentStoryIndex < storyTexts.size() - 1) {
            currentStoryIndex++;
            updateStoryText(); // 更新故事
        } else {
            storyLabel->hide();
            storyLabel->removeEventFilter(this);

            // 故事结束，重新启用按钮
            for (int level = 3; level <= 10; level++) {
                QString buttonName = QString("btu%1").arg(level + 2);
                QPushButton* btn = findChild<QPushButton*>(buttonName);
                if (btn) {
                    bool isUnlocked = m_unlockedLevels.value(level, false);
                    btn->setEnabled(isUnlocked); // 根据解锁状态恢复
                }
            }
            // 重新启用其他功能按钮
            ui->btu2->setEnabled(true);
            ui->btu3->setEnabled(true);
            ui->btu1->setEnabled(true);
        }
        return true;
    }
    return QMainWindow::eventFilter(obj, event);
}

// 重写显示事件
void SecondWindow::showEvent(QShowEvent *event)
{
    Q_UNUSED(event);
    if(isFirstShow) {
        resetStory();
        isFirstShow = false;
    }
    storyLabel->installEventFilter(this);

}
