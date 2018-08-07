#ifndef BEHAVIORTHREAD_H
#define BEHAVIORTHREAD_H

#include <QThread>
#include <QTimer>
#include <QObject>
#include <Windows.h>


class BehaviorThread:public QThread
{
    Q_OBJECT
public:
    BehaviorThread(){}

    virtual void run();

signals:
    void wave(int);
    void attack(int);
    void attackDown(int i);
    void attackUp(int i);
    void damage(int i);
    void dead(int i);
    void jump(int i);
    void _run(int i);

private:
    enum Behavior{
        _attack,
        _attackDown,
        _attackUp,
        _damage,
        _dead,
        _jump,
        Run
    };

    void waveBehave(){
        for(int i=0;i!=8;i++){
            emit wave(i);
            Sleep(130);
        }
    }

    void attackBehave(){
        for(int i=0;i!=9;i++){
            emit attack(i);
            Sleep(130);
        }
    }

    void attackDownBehave(){
        for(int i=0;i!=8;i++){
            emit attackDown(i);
            Sleep(130);
        }
    }

    void attackUpBehave(){
        for(int i=0;i!=8;i++){
            emit attackUp(i);
            Sleep(130);
        }
    }

    void damageBehave(){
        for(int i=0;i!=3;i++){
            emit damage(i);
            Sleep(130);
        }
    }

    void deadBehave(){
        for(int i=0;i!=10;i++){
            emit dead(i);
            Sleep(130);
        }
    }

    void jumpBehave(){
        for(int i=0;i!=9;i++){
            emit jump(i);
            Sleep(130);
        }
    }

    void runBehave(){
        for(int i=0;i!=8;i++){
            emit _run(i);
            Sleep(130);
        }
    }
};

#endif // BEHAVIORTHREAD_H
