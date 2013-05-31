#include "Choosing.h"
#include <iostream>
#include "defines.h"
#include "SwapAndCheck.h"

void Choosing::Enter(Game* pGame)
{
  // Initialise our vars
  chosen[0] = std::make_pair(-1,-1);
  chosen[1] = std::make_pair(-1,-1);
  iChoice = 0;
  bUpdate = false;
}

void Choosing::Exit(Game* pGame)
{
  std::cout << "Choosing Exit Successful\n";
}

// Just pressing the mouse button will start the game 
void Choosing::HandleEvents(Game * pGame)
{
  SDL_Event event;
  
  if(SDL_PollEvent(&event))
  {
    std::cout << "Choosing handle event\n";
    switch(event.type)
	  {
      case SDL_MOUSEBUTTONDOWN:
      {
        std::cout << "Mouse button pressed at (" << event.button.x << "," << event.button.y << ")\n";
        // is it inside the grid?
        int iX = event.button.x;
        int iY = event.button.y;
        
        std::pair<int, int> hit = pGame->MouseToSlot(event.button.x, event.button.y);  

        if( hit.first != -1 && hit.second != -1 )
        {
            // make sure we haven't already chosen it
            if(chosen[0].first != hit.first || chosen[0].second != hit.second)
            {
              // then we definitely didn't choose this already
              bUpdate = true;
           
              // hit something
              chosen[iChoice] = hit;
            
              // tell the game 
              pGame->SelectSlot(chosen[iChoice]);

              if( iChoice == 0 )
              {
                iChoice++; // next choice is the second one.
              }
              else
              {
                bool bAdjacent = false;
                // we have chosen two so now check if they are adjacent
                if(chosen[0].first == chosen[1].first )
                {
                  // same column but are they next to each other?
                  if( abs(chosen[0].second - chosen[1].second) == 1)
                  {
                    bAdjacent = true;
                  }
                } 

                if(chosen[0].second == chosen[1].second)
                {
                  // same row but are they next to each other?
                  if( abs(chosen[0].first - chosen[1].first) == 1)
                  {
                    bAdjacent = true;
                  }
                }
                  
                if(bAdjacent)
                {
                   // tell the game
                  pGame->SetChoices(chosen[0], chosen[1]);

                  // Swap them and check
                  pGame->ChangeState(SwapAndCheck::Instance());
                }
                else
                {
                  // Deselect our choices ( tell grid to update )
                  pGame->DeselectSlot(chosen[0]);
                  pGame->DeselectSlot(chosen[1]);

                  // Reset vars
                  chosen[0].first = -1;
                  chosen[0].second = -1;
                  chosen[1].first = -1;
                  chosen[1].second = -1;
                  iChoice = 0;
                  bUpdate = true;
                }
              }
            }
         }
      }
      break;
      default:
        break;
    }
  }
}

void Choosing::Update(Game* pGame)
{
   
}

// Blit any sprites for this state
void Choosing::Draw(Game *pGame)
{
  
}

Choosing Choosing::m_Choosing;