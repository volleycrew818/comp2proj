#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "circlebumper.h"
#include <iostream>
#include "SDL/SDL_mixer.h"
using namespace std;
//The sound effects that will be used
Mix_Chunk *bump = NULL;

CircleBumper::CircleBumper(int Score,int Size, int xloc, int yloc) {
      bump = Mix_LoadWAV( "bellHat.wav" );

    //If there was a problem loading the sound effects
    if( bump == NULL )
    {
        cout << "problem with bumper sound"<<endl;
        return 1;
    }
    /*//Play effect-- bumper sound
    if( Mix_PlayChannel( -1, scratch, 0 ) == -1 )
    {
        return 1;
     }*/
    x = xloc;
    y = yloc;
    islit = 0;
    SDL_Surface* loaded = IMG_Load("bumperoff.bmp");
    if (loaded == NULL) { cout << "well shit then"<<endl;}
    image = SDL_DisplayFormat(loaded);
    if (image == NULL) cout<< "double shit" << endl;
    
   //Freesound effects
    Mix_FreeChunk( bump );

    //Quit SDL_mixer
    Mix_CloseAudio();
}

char CircleBumper::getClass(){
    return 'b';
}

void CircleBumper::draw(SDL_Surface *screen){
    SDL_Rect offset;
    offset.x = x;
    offset.y = y;
    SDL_BlitSurface(image, NULL, screen, &offset);
}
