#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QMouseEvent>
#include <QPixmap>
#include <QBitmap>
#include <QPalette>
#include <QPoint>
#include <QAction>
#include <QString>
#include <QMenu>
#include <QContextMenuEvent>
#include <QCursor>
#include <QApplication>
#include <QSystemTrayIcon>
#include <QDesktopWidget>

#include "behaviorthread.h"

#include <QDebug>


class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

    virtual void mousePressEvent(QMouseEvent *event);

    virtual void mouseMoveEvent(QMouseEvent *event);

    virtual void mouseReleaseEvent(QMouseEvent *event);

    virtual void contextMenuEvent(QContextMenuEvent *event);

private:
    QPoint lastPos;
    QPixmap pix;
    QPoint dragPosition;
    QMenu* menu;

    BehaviorThread* b;

    void paint(QString name);
public slots:

    void wave(int i);
    void attack(int i);
    void attackDown(int i);
    void attackUp(int i);
    void damage(int i);
    void dead(int i);
    void jump(int i);
    void run(int i);


    void quit();
};

#endif // WIDGET_H
