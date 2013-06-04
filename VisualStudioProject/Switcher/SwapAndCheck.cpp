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

  // Set their current positions and target positions
  topXY = std::make_pair(t->CentreX(), t->CentreY());
  bottXY = std::make_pair(b->CentreX(), b->CentreY());

  targetTopXY = std::make_pair(b->CentreX(), b->CentreY());
  targetBottXY = std::make_pair(t->CentreX(), t->CentreY());

  // Set the velocity vector depending on orientation 
  // ( we're talking vector not magnitude )
  
  if( targetTopXY.first == topXY.first )
  {
    // stays vertical - but which direction?
    if( targetTopXY.second < topXY.second )
    {
      // top going up (but y coords decrease the further up you go)
      // bottom down.
      top->SetVelocity(STAY_VERTICAL, SWAP_SPEED * -1);
      bottom->SetVelocity(STAY_VERTICAL, SWAP_SPEED);
    }
    else
    {
      // top is going down, bottom is going up.
      top->SetVelocity(STAY_VERTICAL, SWAP_SPEED);
      bottom->SetVelocity(STAY_VERTICAL, SWAP_SPEED * -1);
    }
  }
  else
  if( targetTopXY.second == topXY.second )
  {
    // movement is horizontal ( y's are equal )
    // but which direction?
    if( targetTopXY.first < topXY.first )
    {
      // top going left 
      // bottom goes to right
      top->SetVelocity(SWAP_SPEED * -1, STAY_HORIZONTAL);
      bottom->SetVelocity(SWAP_SPEED, STAY_VERTICAL);
    }
    else
    {
      // top goes right, 
      // bottom goes left.
      top->SetVelocity(SWAP_SPEED, STAY_HORIZONTAL);
      bottom->SetVelocity(SWAP_SPEED * -1, STAY_VERTICAL);
    }
  }

  top->SetPosition(topXY.first, topXY.second);
  bottom->SetPosition(bottXY.first, bottXY.second);

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
  top->Update(pGame->GetElapsedTime());
  bottom->Update(pGame->GetElapsedTime());
}

// Blit any sprites for this state
void SwapAndCheck::Draw(Game *pGame)
{
  // draw these two GameObjects we created
  top->Draw(pGameScreen);
  bottom->Draw(pGameScreen);
}

SwapAndCheck SwapAndCheck::m_SwapAndCheck;