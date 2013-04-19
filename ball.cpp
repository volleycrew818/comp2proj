#include "ball.h"
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <iostream>
using namespace std;

Ball::Ball(){
    x = 0;
    y = 0;
    xv = 3, yv = 5;
    SDL_Surface* loaded = IMG_Load("ball.bmp");
    if (loaded == NULL) { cout << "well shit"<<endl; exit(1);}
    image = SDL_DisplayFormat(loaded);
    if (image == NULL) cout<< "double shit" << endl;
}

void Ball::move() {
    x += xv;
    y += yv;
        //left wall and start area
    if (x>460 || x<0) xv = -xv;
    //top curve (bounce off block of space), bottom of board
    if (y>760 || y<118) yv = -yv;
    //part of blocks
    if (x>270 && y > 888 || x<190 && y > 888) 
    {
        xv=-xv;
    	yv=-yv;
    }
    //part of blocks
    if (x>270 && y > 724 || x<190 && y > 724) 
    {
    	xv=-xv;
    	
}

void Ball::draw(SDL_Surface* screen){
    SDL_Rect offset;
    offset.x = x;
    offset.y = y;
    SDL_BlitSurface(image, NULL, screen, &offset);
//    SDL_FillRect( screen, &screen->clip_rect, SDL_MapRGB( screen->format, 0xFF, 0xFF, 0x0 ) );
}

