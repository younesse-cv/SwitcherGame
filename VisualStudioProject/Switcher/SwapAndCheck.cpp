#include "SwapAndCheck.h"

#include "Game.h"
#include <iostream>

void SwapAndCheck::Enter(Game* pGame)
{
  // Initialise our vars
  chosen[0] = pGame->GetChoice(0);
  chosen[1] = pGame->GetChoice(1);

  // Hide those slots
  pGame->HideSlot(chosen[0].first, chosen[0].second);
  pGame->HideSlot(chosen[1].first, chosen[1].second);
  std::cout << "Swap and Check - Enter Successful!\n";

  // Create 2 GameObjects

}

void SwapAndCheck::Exit(Game* pGame)
{
  std::cout << "SwapAndCheck Exit Successful\n";
}

// Just pressing the mouse button will start the game 
void SwapAndCheck::HandleEvents(Game * pGame)
{
  SDL_Event event;
  
  if(SDL_PollEvent(&event))
  {
    
  }
}

void SwapAndCheck::Update(Game* pGame)
{
   
}

// Blit any sprites for this state
void SwapAndCheck::Draw(Game *pGame)
{
  
}

SwapAndCheck SwapAndCheck::m_SwapAndCheck;