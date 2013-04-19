#include <iostream>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
//#include "ball.h"
#include "board.h"
#include "SDL/SDL_mixer.h"
using namespace std;

//music
Mix_Music *start = NULL;
int main(){

    //splash screen
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Surface *scr = SDL_SetVideoMode(500,1000,32,SDL_SWSURFACE);
    Board board(500,1000,scr); 
    //Initialize SDL_mixer
    if( Mix_OpenAudio( 22050, MIX_DEFAULT_FORMAT, 2, 4096 ) == -1 )
    {
        cout << "Error with initializing SDL mixer"
        return 1;
    }
    
    //Load  music
    start = Mix_LoadMUS( "time.wav" );

    //If problem loading  music
    if( start == NULL )
    {
        return false;
    }
    
    //Play the music
    if( Mix_PlayMusic( start, -1 ) == -1 )
    {
        return 1;
    }
    //(while want to play)
    board.play();
    // endwhile;
    
    //Free music
    Mix_FreeMusic( start );
    //Free music
    Mix_FreeMusic( music );
    //Quit SDL_mixer
    Mix_CloseAudio();
}
