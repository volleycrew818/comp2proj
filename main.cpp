#include <iostream>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "ball.h"
#include "SDL/SDL_mixer.h"
using namespace std;

SDL_Surface *screen = NULL;
SDL_Event event;

int main(){
    SDL_Init(SDL_INIT_EVERYTHING);
    screen = SDL_SetVideoMode(500,500,32,SDL_SWSURFACE);
    Ball ball;
    SDL_FillRect( screen, &screen->clip_rect, SDL_MapRGB( screen->format, 0xFF, 0xFF, 0xFF ) );
    cout << "check it" << endl;
    ball.draw(screen);
    SDL_Flip(screen);
    while (1){
        if (SDL_PollEvent(&event)){
            switch (event.type){
                case SDL_QUIT:
                    exit(0);
            }
        }
    
    //printf("truly this is working");
        ball.draw(screen);
        SDL_Flip(screen);
        SDL_FillRect( screen, &screen->clip_rect, SDL_MapRGB( screen->format, 0xFF, 0xFF, 0xFF ) );
        ball.move();
    } 
    
}
