#include "widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent)
{
    this->move(QApplication::desktop()->width()-150,550);

    this->setWindowFlags(Qt::FramelessWindowHint \
                         | Qt::WindowStaysOnTopHint\
                         |Qt::Tool);

    paint(".\\data\\Madoka\\idle\\0000.png");

    // Connect the tread and the controler
    b = new BehaviorThread();
    connect(b,SIGNAL(wave(int)),this,SLOT(wave(int)));
    connect(b,SIGNAL(attack(int)),this,SLOT(attack(int)));
    connect(b,SIGNAL(attackDown(int)),this,SLOT(attackDown(int)));
    connect(b,SIGNAL(attackUp(int)),this,SLOT(attackUp(int)));
    connect(b,SIGNAL(damage(int)),this,SLOT(damage(int)));
    connect(b,SIGNAL(dead(int)),this,SLOT(dead(int)));
    connect(b,SIGNAL(jump(int)),this,SLOT(jump(int)));
    connect(b,SIGNAL(_run(int)),this,SLOT(run(int)));
    b->start();

    // Set right click and show the menu;
    auto visible = new QAction(QString::fromLocal8Bit("可见"),this);
    visible->setCheckable(true);
    visible->setChecked(true);
    menu = new QMenu(this);
    menu->addAction(visible);
    auto spiritQuit = new QAction(QString::fromLocal8Bit("退出"),this);
    menu->addAction(spiritQuit);

    connect(visible,SIGNAL(triggered(bool)),this,SLOT(setVisible(bool)));
    connect(spiritQuit,SIGNAL(triggered(bool)),this,SLOT(quit()));

    // SystemTrayIcon
    QSystemTrayIcon *TrayIcon= new QSystemTrayIcon(this);
     TrayIcon->setIcon(QIcon(".\\data\\Madoka\\madoka.ico"));

     TrayIcon->setContextMenu(menu);
     TrayIcon->show();
}

Widget::~Widget()
{
    delete b;
}


void Widget::mousePressEvent(QMouseEvent *event){

    if(event->button() == Qt::LeftButton){

    dragPosition =event->globalPos()-frameGeometry().topLeft();
    paint(".\\data\\Madoka\\drag\\0000.png");

    disconnect(b,SIGNAL(wave(int)),this,SLOT(wave(int)));
    disconnect(b,SIGNAL(attack(int)),this,SLOT(attack(int)));
    disconnect(b,SIGNAL(attackDown(int)),this,SLOT(attackDown(int)));
    disconnect(b,SIGNAL(attackUp(int)),this,SLOT(attackUp(int)));
    disconnect(b,SIGNAL(damage(int)),this,SLOT(damage(int)));
    disconnect(b,SIGNAL(dead(int)),this,SLOT(dead(int)));
    disconnect(b,SIGNAL(jump(int)),this,SLOT(jump(int)));
    disconnect(b,SIGNAL(_run(int)),this,SLOT(run(int)));
    }


}

void Widget::mouseMoveEvent(QMouseEvent *event){

    if(event->buttons()==Qt::LeftButton)
        {
            move(event->globalPos()-dragPosition);
            event->accept();
        }
}

void Widget::mouseReleaseEvent(QMouseEvent *event){
    if(event->button() == Qt::LeftButton){
    connect(b,SIGNAL(wave(int)),this,SLOT(wave(int)));
    connect(b,SIGNAL(attack(int)),this,SLOT(attack(int)));
    connect(b,SIGNAL(attackDown(int)),this,SLOT(attackDown(int)));
    connect(b,SIGNAL(attackUp(int)),this,SLOT(attackUp(int)));
    connect(b,SIGNAL(damage(int)),this,SLOT(damage(int)));
    connect(b,SIGNAL(dead(int)),this,SLOT(dead(int)));
    connect(b,SIGNAL(jump(int)),this,SLOT(jump(int)));
    connect(b,SIGNAL(_run(int)),this,SLOT(run(int)));
    }
}

void Widget::paint(QString name){
    pix.load(name);
    setMask(pix.mask());
    QPalette palette;
    palette.setBrush(QPalette::Window,QBrush(pix));
    setPalette(palette);
}

void Widget::wave(int i){

    switch (i) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
        paint(QString("./data/Madoka/idle/000")+QString::number(i)+".png");
        break;
    default:
        break;
    }

}

void Widget::attack(int i){
    switch (i) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
        paint(QString("./data/Madoka/attack/000")+QString::number(i)+".png");
        break;
    default:
        break;
    }
}

void Widget::attackDown(int i){
    switch (i) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
        paint(QString("./data/Madoka/attackDown/000")+QString::number(i)+".png");
        break;
    default:
        break;
    }
}

void Widget::attackUp(int i){
    switch (i) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
        paint(QString("./data/Madoka/attackUp/000")+QString::number(i)+".png");
        break;
    default:
        break;
    }
}

void Widget::damage(int i){
    switch (i) {
    case 0:
    case 1:
    case 2:
    case 3:
        paint(QString("./data/Madoka/damage/000")+QString::number(i)+".png");
        break;
    default:
        break;
    }
}

void Widget::dead(int i){
    switch (i) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
        paint(QString("./data/Madoka/dead/000")+QString::number(i)+".png");
        break;
    default:
        break;
    }
}

void Widget::jump(int i){
    switch (i) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
        paint(QString("./data/Madoka/jump/000")+QString::number(i)+".png");
        break;
    default:
        break;
    }
}

void Widget::run(int i){
    //TO BE CONTINUED...
}

void Widget::quit(){
    QApplication::exit(0);
}

void Widget::contextMenuEvent(QContextMenuEvent *event){
    menu->exec(QCursor::pos());
    event->accept();
}
