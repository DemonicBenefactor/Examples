/******************************************************************************
Abstract Fighting Game
*******************************************************************************/
#include "characters.h"
#include "game.h"

int main(int argc, char* argv[])
{
    player playerOne, playerTwo;
    gameState state = MENU;

    while (state != EXIT)
    {
        clrscr();
        update(&playerOne, &playerTwo, &state);
    }
    
    return 0;
}


/*
if (getch() == '\033') { // if the first value is esc
    getch(); // skip the [
    switch(getch()) { // the real value
        case 'A':
            // code for arrow up
            break;
        case 'B':
            // code for arrow down
            break;
        case 'C':
            // code for arrow right
            break;
        case 'D':
            // code for arrow left
            break;
    }
}
*/

