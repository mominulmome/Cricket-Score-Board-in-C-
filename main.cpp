#include<iostream>
#include "player.h"
#include "cricket.h"
#include<cstdlib>

/// here define each team total player and over have to play
#define PLAYER_NUMBER 5
#define TOTAL_OVER 12

using namespace std;

void getAllPlayersName(void);
void select_batsman(void);
void select_baller(void);
void clrscr(void);
void playCricket(void);

cricket game;
player a_team[PLAYER_NUMBER];
player b_team[PLAYER_NUMBER];

int ballerIndex = -1;
bool flag = true;

int main()
{
    game.getTeamName();

    clrscr();

    getAllPlayersName();

    clrscr();

    select_batsman();
    select_baller();

    for(int i=1;i<=2;i++){
        playCricket();
        clrscr();
        cout << game.putA_teamName() << " team batting data : " << endl;
        for(int i=0;i<PLAYER_NUMBER;i++){
            a_team[i].putBattingData();
        }
        cout << endl << endl << endl;
        cout << game.putB_teamName() << " team balling data : " << endl;
        for(int i=0;i<PLAYER_NUMBER;i++){
            if(b_team[i].putIsBaller() == true){
                b_team[i].putBallingData();
            }
        }
        char xxx;
        cin >> xxx;
    }

    return 0;
}

/*********************************************************************************************/

void getAllPlayersName(void){
    cout << "Enter the " << game.putA_teamName() << " player's name :" << endl;
    for(int i=0;i<PLAYER_NUMBER;i++){
        string name;
        getline(cin,name);
        a_team[i].getPlayerName(name);
    }

    clrscr();

    cout << "Enter the " << game.putB_teamName() << " player's name :" << endl;
    for(int i=0;i<PLAYER_NUMBER;i++){
        string name;
        getline(cin,name);
        b_team[i].getPlayerName(name);
    }
}

/*********************************************************************************************/

void select_batsman(void){
    clrscr();
    if(flag){
        while(true){
            cout << "Select two batsman : " << endl;
            for(int i=0;i<PLAYER_NUMBER;i++){
                cout << i << "   " << a_team[i].putPlayerName() << endl;
            }
            int i,j;
            cin >> i >> j;

            if(i < PLAYER_NUMBER && j <= PLAYER_NUMBER && (!a_team[i].putOutOrNot())){
                a_team[i].getBattingOrNot();
                a_team[j].getBattingOrNot();
                break;
            }
            else{
                clrscr();
                cout << "You entered an invalid number." << endl << "Try again." <<endl;
            }
        }
        flag = false;
    }
    else{
        while(true){
            cout << "Select one batsman : " << endl;
            for(int i=0;i<PLAYER_NUMBER;i++){
                cout << i << "   " << a_team[i].putPlayerName() << endl;
            }
            int i;
            cin >> i;

            if(i < PLAYER_NUMBER && (!a_team[i].putOutOrNot())){
                a_team[i].getBattingOrNot();
                break;
            }
            else{
                clrscr();
                cout << "You entered an invalid number." << endl << "Try again." <<endl;
            }
        }
    }
    clrscr();
}

/*********************************************************************************************/

void select_baller(void){
    while(true){
        cout << "Select baller : " << endl;
        for(int i=0;i<PLAYER_NUMBER;i++){
            cout << i << "   " << b_team[i].putPlayerName() << endl;
        }
        int i;
        cin >> i ;
        if(i<=PLAYER_NUMBER){
            ballerIndex = i;
            b_team[i].getBallingOrNot(true);
            b_team[i].getIsBaller();
            break;
        }else{
            clrscr();
            cout << "You entered an invalid number." << endl << "Try again." <<endl;
        }
    }
    clrscr();
}


void playCricket(void){
        while(game.putOver() < TOTAL_OVER && game.putWicket() < PLAYER_NUMBER){
        cout << game.putA_teamName() << " : " << endl;
        for(int i=0;i<PLAYER_NUMBER;i++){
            if(a_team[i].putBattingOrNot() == true){
                cout << i << "  ";
                a_team[i].putBattingData();
            }
        }

        game.putScore();

        cout << "Balling : " << endl;
        for(int i=0;i<PLAYER_NUMBER;i++){
            if(b_team[i].putBallingOrNot() == true){
                b_team[i].putBallingData();
            }
        }

        cout << endl << endl << endl << "[............................................... ]" << endl
                << "Enter player number and after a space put run" << endl
                << "11 for 'Extra'." << endl
                << "12 for 'Wicket'." << endl;
        int i,j;
        cin >> i >> j ;
        if(i == 11){
            game.getExtra(j);
            b_team[ballerIndex].getExtraRun(j);
        }
        else if(i == 12){
            a_team[j].getOutOrNot();
            b_team[ballerIndex].getWicket();
            game.getWicket();
            game.getOver();
            b_team[ballerIndex].getBollerData(0);

            if(game.putWicket() == PLAYER_NUMBER-1)
                break;

            select_batsman();
        }
        else{
            a_team[i].getRun(j);
            b_team[ballerIndex].getBollerData(j);
            game.getScore(j);
        }
        clrscr();
        if(game.putOver() % 6 == 0 && game.putOver() != TOTAL_OVER){
            b_team[ballerIndex].getBallingOrNot(false);
            select_baller();
        }
    }
}
void clrscr(void){
    ///in windows os use cls instead of clear command
    system("cls || clear");
}

