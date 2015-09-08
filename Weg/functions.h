void clearscreen()
{
    HANDLE hOut;
    COORD Position;
    hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    Position.X = 0;
    Position.Y = 0;
    SetConsoleCursorPosition(hOut, Position);
}

void bepalingbocht()
{
    int bepalingbocht = rand()%3;
    if( bepalingbocht == 0 )
    {
        linksbinnen = linksbinnen +1;
        rechtsbinnen = rechtsbinnen +1;
    }
    else if ( bepalingbocht == 1 )
    {
        linksbinnen = linksbinnen -1;
        rechtsbinnen = rechtsbinnen -1;
    }
    else
    {
        linksbinnen = linksbinnen;
        rechtsbinnen = rechtsbinnen;
    }
    if( rechtsbinnen == rechtsbuiten )
    {
        linksbinnen = linksbinnen -1;
        rechtsbinnen = rechtsbinnen -1;
    }
    if( linksbinnen == linksbuiten )
    {
        linksbinnen = linksbinnen +1;
        rechtsbinnen = rechtsbinnen +1;
    }
}

void acceleration()
{
    if( timer == 3 )
    {
        timer = 0;
        if( accel != 0 )
            accel = accel -100;
        else
            accel = 0;
    }
    else
        timer = timer +1;
    Sleep( accel );
}

void keyhit()
{
    if (GetAsyncKeyState( VK_LEFT ))
        x = x -1;
    if (GetAsyncKeyState( VK_RIGHT ))
        x = x +1;
}

void weggetje()
{
    //maakt de auto
    map[y][x] = 'A';
    //maakt de weg
    map[y][linksbinnen] = '#';
    map[y][rechtsbinnen] = '#';
    map[i][j] = ' ';

    bepalingbocht();
    //print weg en auto
    for( j = 0 ; j < 21 ; ++j )
    {
        for( i = 0 ; i < 75 ; ++i )
        {
            cout << map[j][i];
            if( i >= 74 )
            {
                cout << endl;
            }
        }
    }
}
