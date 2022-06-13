#ifndef  __characters__
#define  __characters__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "colors.h"

enum names
{
   RegetniMune  = 1,
   TaolfRalacs,
   DiovFi,
   RofOtog,
   IicsaNiam,
   Srotarepo
};

typedef struct{
    char *name;
    unsigned short health, position, side;
    unsigned int color;
} player;

//function to allocate memory for a string name and poplate it
void loadName(char *name, player *plr)
{
    plr->name = malloc(sizeof(char) * strlen(name));
    strcpy(plr->name, name);
}

//function to poplulate a player datatype
int createPlayer(int plrName, short side, player *plr)
{
    if (plrName && side && plr)
    {
        switch (side){
            case 1: plr->position = 2;      break;
            case 2: plr->position = 78;     break;
            default: printf("error setting up position");   return 0;
        }

        switch (plrName){
            case RegetniMune:   loadName("Regetni Mune", plr);  
                                plr->color = BLACK;
                                plr->health = 100;
                                break;
            case TaolfRalacs:   loadName("Taolf Ralacs", plr);
                                plr->color = WHITE;
                                plr->health = 100;
                                break;
            case DiovFi:        loadName("Diov Fi", plr);
                                plr->color = RED;
                                plr->health = 140;
                                break;
            case RofOtog:       loadName("Rof Otog", plr);      
                                plr->color = GREEN;
                                plr->health = 80;
                                break;
            case IicsaNiam:     loadName("Iicsa Niam", plr);    
                                plr->color = BLUE;
                                plr->health = 120;
                                break;
            case Srotarepo:     loadName("Srotarepo", plr);     
                                plr->color = MAGENTA;
                                plr->health = 90;
                                break;
            default: printf("error creating the name");         return 0;
        }
    }
    else return 0;
    
    return 1;
}

#endif  // __characters__