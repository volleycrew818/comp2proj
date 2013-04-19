/* Zach Lipp 3/27/13
Splash Screen driver

reference gpwiki.org for SDL syntax
 */

#include <SDL/SDL.h>
#include "splashScreen.h"
#include <SDL/SDL_image.h>
#include <iostream>
#include <SDL/SDL_ttf.h>
#include "instructions.h"
#include "SDL/SDL_mixer.h"
#include <deque>
using namespace std;

//music
Mix_Music *music = NULL;
//music to be used
Mix_Chunk *tune = NULL;
int main(int argc, char* args[]) 
{
  //initializes SDL
  if(SDL_Init(SDL_INIT_VIDEO) != 0)
    {
      cout<<"Unable to initialize SDL: "<< SDL_GetError()<<endl;
      return 1;
    }

  SDL_Surface *screen;

  //initializes screen
  screen = SDL_SetVideoMode(640,480,16,SDL_SWSURFACE);
  if (screen==NULL)
    {
      cout<<"Unable to set video mode: "<<SDL_GetError()<<endl;
      return 1;
    }
    
    //Initialize SDL_mixer
    if( Mix_OpenAudio( 22050, MIX_DEFAULT_FORMAT, 2, 4096 ) == -1 )
    {
    	cout<<"Unable to initialize SDL_mixer: "<<SDL_GetError()<<endl;
        return 1;
    }
    //Load  music
    music = Mix_LoadMUS( "clinthammer.wav" );
    //If problem loading  music
    if( music == NULL )
    {
    	cout<<"Problem Loading Music: "<<SDL_GetError()<<endl;
        return 1;
    }
  deque<string> n;
  n.push_back("Zach");
  n.push_back("Kaitlin");
  n.push_back("Kevin");

  deque<int> s;
  s.push_back(15);
  s.push_back(12);
  s.push_back(17);    

  //creates a splashScreen object and displays
  splashScreen ss;
  ss.setNames(&n);
  ss.setScores(&s);
  ss.display(screen); 

  instructions i;

  while(ss.getSelection()!=3)//while quit not selected
    {
    	//Play the music
       if( Mix_PlayMusic( music, -1 ) == -1 )
       {
       	return 1;
       }
      switch( ss.getSelection() )
      {
	    case 1: //play game
	      cout<<"Play pressed"<<endl;
	      n.push_front("Kyle");
	      s.push_front(26);
	      break;
	  case 2: //instructions
	    i.display(screen);
	    break;
	}
      ss.display(screen);
    }
    //Free music
    Mix_FreeMusic( music );
    //Quit SDL_mixer
    Mix_CloseAudio();
  SDL_Quit();

  return 0;
}
