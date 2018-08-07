#include "behaviorthread.h"




void BehaviorThread::run(){

    while(true){
        auto i = qrand() % 250;
        switch (Behavior(i)) {
        case Behavior::_attack:
            this->attackBehave();
                        this->waveBehave();
            break;
        case Behavior::_attackDown:
            this->attackDownBehave();
                        this->waveBehave();
            break;
        case Behavior::_attackUp:
            this->attackUpBehave();
                        this->waveBehave();
            break;
        case Behavior::_damage:
            this->damageBehave();
                        this->waveBehave();
            break;
        case Behavior::_dead:
            this->deadBehave();
                        this->waveBehave();
            break;
        case Behavior::_jump:
            this->jumpBehave();
                        this->waveBehave();
            break;
        case Behavior::Run:
            this->runBehave();
                        this->waveBehave();
            break;
        default:
            this->waveBehave();
            break;
        }

    }

}
