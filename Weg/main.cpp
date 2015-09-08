#include "includes.h"
#include "setvars.h"
#include "functions.h"
int main()
{
    //maakt buiten kant weg
    for( j = 0 ; j < 75 ; ++j ){
        for( i = 0; i < 75 ; ++i ){
            map[j][linksbuiten] = '|';
            map[j][rechtsbuiten] = '|';
        }
    }
    //maakt de binnen weg
    for(int i=0; i < 20; ++i) {
        for(int j=0; j < 20; ++j) {
            map[i][linksbinnen] = '#';
            map[i][rechtsbinnen] = '#';
        }
    }

    for( ; ; )
    {
        weggetje();
        clearscreen();
        //getch();
        acceleration();
        keyhit();
    }
}
