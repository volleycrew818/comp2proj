#include <iostream>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
//#include "ball.h"
#include "board.h"
#include "SDL/SDL_mixer.h"
using namespace std;

int main(){

    //splash screen
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Surface *scr = SDL_SetVideoMode(500,1000,32,SDL_SWSURFACE);
    Board board(500,1000,scr); 
    
    //(while want to play)
    board.play();
    // endwhile;

}
