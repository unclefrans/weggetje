#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace std;
int carpos = 35;

void car(){
    char map[80][100];
    for( int y = 0 ; y < 72 ; ++y ) {
        for( int x = 0; x < 72 ; ++x ) {
        map[y][carpos] = 'X';
        map[y][x] = ' ';
        }
    }
    for( int y = 0 ; y < 1 ; ++y ) {
        for( int x = 0 ; x < 72 ; ++x ) {
            cout << map[y][x];
            if( x >= 71 ) {
                cout << endl;
            }
        }
    }
}

void keyhit(){
    if (GetAsyncKeyState(VK_LEFT))
    {
        carpos = carpos -1;
    }
    else if (GetAsyncKeyState(VK_RIGHT))
    {
        carpos = carpos +1;
    }
}

int main()
{
    for(;;){
        Sleep(1000);
        car();
        keyhit();
    }
}
