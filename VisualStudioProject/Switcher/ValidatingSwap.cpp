#include "ValidatingSwap.h"
#include <iostream>
#include "defines.h"
#include "ValidatingSwap.h"

void ValidatingSwap::Enter(Game* pGame)
{
  // go ahead and validate
  if( pGame->ValidSwap() )
  {
    
  }
}

void ValidatingSwap::Exit(Game* pGame)
{
  std::cout << "ValidatingSwap Exit Successful\n";
}

// Just pressing the mouse button will start the game 
void ValidatingSwap::HandleEvents(Game * pGame)
{
  SDL_Event event;
  
  if(SDL_PollEvent(&event))
  {
    std::cout << "ValidatingSwap handle event\n";
    switch(event.type)
	  {
      case SDL_MOUSEBUTTONDOWN:
      {
        
     
      }
      break;
      default:
        break;
    }
  }
}

void ValidatingSwap::Update(Game* pGame)
{
   
}

// Blit any sprites for this state
void ValidatingSwap::Draw(Game *pGame)
{
  
}

ValidatingSwap ValidatingSwap::m_ValidatingSwap;