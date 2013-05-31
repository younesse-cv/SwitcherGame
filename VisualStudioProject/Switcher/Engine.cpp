#include "SDL.h"
#include "Engine.h"
#include "State.h"
#include "PlayingGame.h"
#include <iostream>
#include "Sprite.h"
#include "SDL_image.h"

Engine::Engine()
{

}


void Engine::Draw()
{
  states.back()->Draw(this);		
	SDL_Flip(m_pCanvas);
}

void Engine::Start(const char* title, int width, int height, bool fullscreen)
{ 
	int flags = 0;

	SDL_Init(SDL_INIT_EVERYTHING);

	SDL_WM_SetCaption(title, title);

	//    load support for the JPG and PNG image formats
    flags=IMG_INIT_JPG|IMG_INIT_PNG;
    int initted=IMG_Init(flags);
    if(initted&flags != flags) {
     std::cout << "IMG_Init: Failed to init required jpg and png support!\n";
     std::cout << "IMG_Init:" << IMG_GetError();
    // handle error
    }

	if( fullscreen )
	{
	  flags = SDL_FULLSCREEN;
	}

	
	m_pCanvas = SDL_SetVideoMode(width, height, 32, SDL_SWSURFACE);

	m_bFullscreen = fullscreen;

	m_bRunning = true;

	std::cout << "Engine Initialised" << std::endl;

	ChangeState(PlayingGame::Instance());

	while(Running())
	{
	  EngineLoop();
	}

	// cleanup the Engine
	CleanUp();
}


void Engine::EngineLoop()
{
  HandleEvents();
  Update();
  Draw();
}

void Engine::HandleEvents()
{
  states.back()->HandleEvents(this);
}


void Engine::Update()
{
  //std::cout << "Engine::Update()" << std::endl;
  states.back()->Update(this);
}



void Engine::CleanUp()
{
  while(!states.empty())
  {
    states.back()->Exit(this);
	  states.pop_back();
  } 

  // shutdown SDL
  SDL_Quit();
}
 
bool Engine::Running()
{
  return m_bRunning;
}

void Engine::Quit()
{
  m_bRunning = false;
}

void Engine::ChangeState(State<Engine>* state)
{
  // cleanup the current state
	if( !states.empty() )
	{
		states.back()->Exit(this);
		states.pop_back();
	}

	// store and init the new state
	states.push_back(state);
	states.back()->Enter(this);


}

void Engine::PushState(State<Engine>* state)
{
	if(!states.empty())
	{
		states.back()->Pause();
	}

	// store and init the new state
	states.push_back(state);
	states.back()->Enter(this);
}

/* 
 Remove and resume previous state
 */
void Engine::PopState()
{
  if(!states.empty())
  {
    states.back()->Exit(this);
	  states.pop_back();
  }

  if(!states.empty())
  {
    states.back()->Resume();
  }
}

