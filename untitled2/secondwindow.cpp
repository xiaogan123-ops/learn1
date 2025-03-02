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
SecondWindow::SecondWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::SecondWindow)
    , widget(new Widget(this))
    , maze(new Maze())
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
    for(int level = 2; level <= 18; ++level) {
        m_unlockedLevels.insert(level, false);
    }
    // 动态绑定迷宫关卡按钮
    for (int level = 3 ; level <= 17; level++) { // 处理1-15关

        QString buttonName = QString("btu%1").arg(level + 2);
        QPushButton* btn = findChild<QPushButton*>(buttonName);
        if (level == 2) { // 调试第0关（实际level2）
            qDebug() << "找到按钮指针：" << btn;
        }
        if (btn) {
            // 设置初始解锁状态
            // bool isUnlocked = m_unlockedLevels.value(level, false);
            // btn->setEnabled(isUnlocked);
            // btn->setIcon(isUnlocked ? QIcon(":/res/1.png") : QIcon(":/res/6.png"));
            // btn->setIconSize(QSize(50, 50));
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


    // ui->btu4->setEnabled(false);
    //  ui->btu4->setIcon(false ? QIcon() : QIcon(":/res/6.png"));
    //  ui->btu4->setIconSize(QSize(40, 40));

    connect(widget, &Widget::levelUnlocked, this, [this](int level){
        if (level >= 1 && level <= 17) {
            if(level==2){
                level+=1;
            }
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
        tr("公元前4世纪，墨家弟子墨衡（主人公）在整理祖传《墨经》残卷时，发现记载着「天志迷宫」的密文。"),
        tr("为寻找失传的「非攻令」——传说能平息战争的终极机关术，他冒险进入墨家禁地，"),
        tr("却触发初代巨子设下的考验机制，陷入动态变化的16重机关迷宫...")
    };



}
void SecondWindow::updateLevelButtons() {
    for (int level = 3; level <= 17; level++) {
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
    // storyLabel->removeEventFilter(this); // 移除事件过滤器
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
    storyLabel->setText(fullText);
    storyLabel->adjustSize();
    storyLabel->setFixedHeight(250); // 保持固定高度
}
//新增重置函数
void SecondWindow::resetStory()
{
    currentStoryIndex = 0;
    storyLabel->setText(storyTexts.first());
    storyLabel->adjustSize();
    storyLabel->move((width() - storyLabel->width())/2, 400); // 定位到下方1/4区域
    storyLabel->show();

    // // 禁用所有关卡按钮和其他可能交互的按钮
    // for (int level = 3; level <= 17; level++) {
    //     QString buttonName = QString("btu%1").arg(level + 2);
    //     QPushButton* btn = findChild<QPushButton*>(buttonName);
    //     if (btn) {
    //         btn->setEnabled(false); // 直接禁用，不检查解锁状态
    //     }
    // }
    // // 禁用其他功能按钮（根据需求调整）
    // ui->btu2->setEnabled(false); // 例如禁用"下一步"按钮
    // ui->btu3->setEnabled(false); // 禁用"第一关"按钮
    // ui->btu1->setEnabled(false);
}

// bool SecondWindow::eventFilter(QObject* obj, QEvent* event)
// {
//     if (obj == storyLabel && event->type() == QEvent::MouseButtonPress) {
//         mMedia->play(); // 点击音效

//         if (currentStoryIndex < storyTexts.size() - 1) {
//             currentStoryIndex++;
//             updateStoryText(); // 更新到当前索引的故事
//         } else {
//             storyLabel->hide();
//             storyLabel->removeEventFilter(this);

//             // 故事结束，重新启用按钮
//             for (int level = 3; level <= 17; level++) {
//                 QString buttonName = QString("btu%1").arg(level + 2);
//                 QPushButton* btn = findChild<QPushButton*>(buttonName);
//                 if (btn) {
//                     bool isUnlocked = m_unlockedLevels.value(level, false);
//                     btn->setEnabled(isUnlocked); // 根据解锁状态恢复
//                 }
//             }
//             // 重新启用其他功能按钮
//             ui->btu2->setEnabled(true);
//             ui->btu3->setEnabled(true);
//             ui->btu1->setEnabled(true);
//         }
//         return true; // 事件已处理
//     }
//     return QMainWindow::eventFilter(obj, event);
// }

// // 重写显示事件
// void SecondWindow::showEvent(QShowEvent *event)
// {
//     Q_UNUSED(event);
//     if(isFirstShow) {
//         resetStory();
//         isFirstShow = false;
//     }
//     storyLabel->installEventFilter(this);

// }
