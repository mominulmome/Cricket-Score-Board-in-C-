#ifndef PLAYER_H
#define PLAYER_H 1

#include<iostream>
#include<string>

using namespace std;

class player
{
private:
    string name;
    int run,ball,strickrate;
    bool out,batting,balling,isBaller;

    int ballDelivery,giveRun,wicket;

public:
    player()
    {
        name = " ";
        run = 0;
        ball = 0;
        strickrate = 0;
        batting = false;
        out = false;

        balling = false;
        isBaller = false;
        ballDelivery = 0;
        giveRun = 0;
        wicket = 0;
    }
    ~player(){

    }
    void getPlayerName(string);

    string putPlayerName(void);

    void getRun(int);
    void getOutOrNot(void);

    bool putOutOrNot(void);

    void getBollerData(int);
    void getWicket(void);
    void getBattingOrNot(void);
    void getBallingOrNot(bool);
    void getExtraRun(int);
    void getIsBaller(void);

    bool putIsBaller(void);
    bool putBallingOrNot(void);
    bool putBattingOrNot(void);

    void putBattingData(void);
    void putBallingData(void);
};
void player::getPlayerName(string name){
    this->name = name;
}
string player::putPlayerName(void){
    return this->name;
}
void player::getRun(int run){
    this->ball += 1;
    this->run += run;
    this->strickrate = this->run * 100 / this->ball;
}

void player::getOutOrNot(){
    this->out = true;
    this->batting = false;
}

bool player::putOutOrNot(){
    return this->out;
}

void player::getBollerData(int giveRun){
    this->giveRun += giveRun;
    this->ballDelivery += 1;
}

void player::getWicket(void){
    this->wicket += 1;
}

void player::getBattingOrNot(void){
    this->batting = true;
}

void player::getBallingOrNot(bool balling){
    this->balling = balling;
}

void player::getExtraRun(int giveRun){
    this->giveRun += giveRun;
}
void player::getIsBaller(void){
    this->isBaller = true;
}
bool player::putIsBaller(void){
    return this->isBaller;
}

bool player::putBallingOrNot(void){
    return this->balling;
}

bool player::putBattingOrNot(void){
    return this->batting;
}
void player::putBattingData(void){
    cout << this->name << " : " << this->run << "  (" << this->ball << ")  S.rate: " << this->strickrate <<endl << endl;
}
void player::putBallingData(void){
    cout << this->name << " : " << this->ballDelivery / 6 << "." << this->ballDelivery % 6 << " (" << this->giveRun
    << ")   wicket : " << this->wicket << endl;
}
#endif // PLAYER_H
