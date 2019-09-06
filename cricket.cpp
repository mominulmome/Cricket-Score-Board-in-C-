#include<iostream>
#include<string>

using namespace std;

class cricket
{
private:
    string A_team,B_team;
    int over,wicket,totalRun,extra;
public:
    cricket()
    {
        A_team = " ";
        B_team = " ";
        over = 0;
        wicket = 0;
        totalRun = 0;
        extra = 0;
    }
    ~cricket(){ }
    void getTeamName(void);
    string putA_teamName(void);
    string putB_teamName(void);
    int putOver(void);
    void getOver(void);
    void getScore(int);
    void getWicket(void);
    int putWicket(void);
    void getExtra(int);
    void putScore(void);
};
void cricket::getTeamName(void){
    cout << "Enter first team name : " << endl;
    getline(cin,this->A_team);
    cout << "Enter second team name : " << endl;
    getline(cin,this->B_team);
}
string cricket::putA_teamName(void){
    return this->A_team;
}

string cricket::putB_teamName(void){
    return this->B_team;
}
int cricket::putOver(void){
    return this->over;
}
void cricket::getOver(void){
    this->over += 1;
}
void cricket::getScore(int run){
    this->totalRun += run;
    this->over += 1;
}

void cricket::getWicket(){
    this->wicket += 1;
}

int cricket::putWicket(){
    return this->wicket;
}

void cricket::getExtra(int extra){
    this->extra += extra;
    this->totalRun += extra;
}

void cricket::putScore(void){
    cout << "Total Run : " << this->totalRun << "      Wicket : " << this->wicket << "       Over : " << this->over/6 << "."
    << this->over % 6 << endl;
    cout << "Extra : " << this->extra << endl << endl;
}
