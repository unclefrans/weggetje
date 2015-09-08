#include <iostream>
#include <Windows.h>
#include <conio.h>
using namespace std;

char map[20][70];
int li_bu = 00;
int re_bu = 61;
int li_bi = 20;
int re_bi = 41;
int autoX = 30;
int autoY = 20;

void clearscreen(){
    HANDLE hOut;
    COORD Position;
    hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    Position.X = 0;
    Position.Y = 0;
    SetConsoleCursorPosition(hOut, Position);
}

signed getOffset(){
    int offset = rand() % 3;
    switch (offset) {
      case 0: return 0;
      case 1: return +1;
      case 2: return -1;
        default:break;
    }
}

void appendRoad(){
    for(int y = 1; y < 21; ++y)
        for(int x = 0; x < 71 ; ++x)
                map[y][x] = map[y-1][x];

    signed offset = getOffset();
    li_bi += offset;
    re_bi += offset;

    for(int x = 0; x < 71 ; ++x){
            if(x == re_bu|| x == li_bu)
                map[0][x] = '|';
            else if(x == li_bi+offset || x == re_bi+offset)
                map[0][x] = '#';
            else
                map[0][x] = ' ';
    }
}

void maakweg(){
    //vult de weg
    for(int y = 0; y < 21; ++y){
        for(int x = 0; x < 71 ; ++x){
            //if(y == autoY && x == autoX)
                //map[y][x] = 'X';
            if(x == re_bu|| x == li_bu)
                map[y][x] = '|';
            else if(x == li_bi|| x == re_bi)
                map[y][x] = '#';
            else
                map[y][x] = ' ';
        }
    }
}

void printweg(){
    //print de weg
    for(int i = 0; i < 21; ++i){
        for(int j = 0; j < 70; ++j){
            cout << map[i][j];
            if(j >= 69)
                cout << endl;
        }
    }
}

int main(){
    maakweg();
    for(;;){
        printweg();
        maakweg();
        //cout << string( 50, '\n' );
        appendRoad();
        Sleep(500);
        clearscreen();
    }
}
