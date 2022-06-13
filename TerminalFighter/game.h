#ifndef __graphics__
#define __graphics__

//This is a platform nutral way to clear the console 
#ifdef _WIN32
#include <conio.h>
#else
#define clrscr() printf("\e[1;1H\e[2J");
#endif

#define WIDTH   80
#define HEIGHT  22

typedef enum GAMESTATE {
    EXIT,
    MENU,
    CHARSELECT,
    GAME,
    OPTIONS
} gameState;

void update(player* pOne, player* pTwo, gameState *state);
void drawMenu(gameState *state);
void drawCharacterSelect();
void drawGame();
void drawOptions();
int roundNo(float num);

int roundNo(float num)
{
    return num < 0 ? num - 0.5 : num + 0.5;
}

void update(player* pOne, player* pTwo, gameState *state)
{
    switch (*state){
        case MENU:
            drawMenu(state);
            break;
        case CHARSELECT:
            drawCharacterSelect();
            break;
        case GAME:
            drawGame();
            break;
        case OPTIONS:
            drawOptions();
            break;
        default: state = EXIT;
    }
}

void drawMenu(gameState *state)
{
    short w, h;
    char quit;
    char startup[] = "START GAME";
    char shutdown[] = "EXIT TO CONSOLE";
    
    printf(SGRY);
    for (h = 0; h < HEIGHT; h++)
    {
        for (w = 0; w < WIDTH; w++)
        {
            if (h == roundNo(HEIGHT * .4) && w == roundNo(WIDTH * .3))
            {
                printf(TNRM);
                printf(startup);
                printf(SGRY);
                w += sizeof(startup) / sizeof(char) - 1;
            }
            if (h == roundNo(HEIGHT * .6) && w == roundNo(WIDTH * .3))
            {
                printf(TNRM);
                printf(shutdown);
                printf(SGRY);
                w += sizeof(shutdown) / sizeof(char) - 1;
            }
            printf("#");
        }
        printf("\n");
    }
    printf(TNRM);
    
    quit = getchar();
    if (quit == 'q'){*state = EXIT;}
}

void drawCharacterSelect()
{
   /*if (createPlayer(RofOtog, 1, &playerOne)
        && createPlayer(Srotarepo, 2, &playerTwo))
    {
        printf( TBCYN"Players created successfully.  gratz\n\n"TNRM);
    }
    else 
    {
        printf("Failed to create Players,  something is wrong.\n\n");
        return 0;
    }*/
}

void drawGame()
{
    
}

void drawOptions()
{
    
}

/*  sketch pad for the graphics

CHARACTER SELECT
################################################################################
#                                                                              #
#                                                                              #
#                                                                              #
#                                                                              #
#                                                                              #
#                                                                              #
#                                                                              #
#                                                                              #
#                                                                              #
#                                                                              #
#                                                                              #
#                                                                              #
#                                                                              #
#                                                                              #
#                                                                              #
#                                                                              #
#                                                                              #
#                                                                              #
#                                                                              #
#                                                                              #
################################################################################

STAGE
OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
################################################################################
################################################################################
################################################################################
################################################################################
################################################################################

*/

#endif //__graphics__