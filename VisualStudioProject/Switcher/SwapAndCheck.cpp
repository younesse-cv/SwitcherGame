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

  Slot * t = pGame->GetSlot(chosen[0].first, chosen[0].second);
  Slot * b = pGame->GetSlot(chosen[1].first, chosen[1].second);

  // Create 2 GameObjects
  top = new GameObject(pGame->GetJewelSprite(t->GetType()));
  bottom = new GameObject(pGame->GetJewelSprite(b->GetType()));

  // Set their positions
  top->SetX(t->X());
  top->SetY(t->Y());

  bottom->SetX(b->X());
  bottom->SetY(b->Y());

  pGameScreen = pGame->GetScreen();
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
  // draw these two GameObjects we created
  top->Draw(pGameScreen);
  bottom->Draw(pGameScreen);
}

SwapAndCheck SwapAndCheck::m_SwapAndCheck;