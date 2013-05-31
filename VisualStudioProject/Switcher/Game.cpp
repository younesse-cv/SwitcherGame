#include "Game.h"
#include <iostream>
#include "IntroMenu.h"
#include "defines.h"

// Initialise the game
// Load Images,
// Create sprites
// Set up positioning
// And change to the first Game state
Game::Game(SDL_Surface * pVideo):
  m_pGameScreen(pVideo),
  pBkg(NULL),
  pScoreSprite(NULL),
  pTimeLeftSprite(NULL)
{
  bInitialised = false;

  // Initialise Random Number Generator
  rng = RandomNumberGenerator::Instance();  
  rng->Initialise(9999, 0, NUMJEWELTYPES);

  pClock = new Countdown(MAX_TIME, m_pGameScreen, TIMER_X, TIMER_Y);

  iOldTime = 0;
  iCurrentTime = 0;
  iFrameTime = 0;

  LoadTextures();
  InitialiseGridPositions();
  CreateBackgroundSprites();
  CreateJewelSprites();
  Populate();

  bInitialised = true;
  ChangeState(IntroMenu::Instance());

  bBackgroundDrawn = false;
  bScoreUpdated = false;
  bTimerUpdated = false;
  bGridNeedsRedraw = false;
}

void Game::LoadTextures()
{
  int i = 0;
  
  while(textures[i].ID != -1)
  {
    TextureMgr::Instance()->LoadTexture(textures[i].pFilename, textures[i].ID);
    i++;
  }
}

// Populate the Grid
// Top Left is 0, 0 so we are increasing down and to right.
void Game::InitialiseGridPositions()
{
  // there are only NUM_COLUMNS x positions
  // and only NUM_ROWS y positions
  // to calculate - just do this once.

  // calculate possible x values  
  std::vector<int> x;
  std::vector<int> xCentre;
  for(int i = 0; i < NUM_COLUMNS; i++)
  {
    int iTopLeftX = GRID_START_X + (SLOT_WIDTH * i);
	  x.push_back(iTopLeftX);

    int iCentreX = iTopLeftX + (SLOT_WIDTH/2);
	  xCentre.push_back(iCentreX);
  }


  // calculate possible y coords
  std::vector<int> y;
  std::vector<int> yCentre;
  for(int i = 0; i < NUM_COLUMNS; i++)
  {
    int iTopLeftY = GRID_START_Y + (SLOT_WIDTH * i);
	  y.push_back(iTopLeftY);

    int iCentreY = iTopLeftY + (SLOT_WIDTH/2);
	  yCentre.push_back(iCentreY);
  }

  // Now populate each slot with the relevant 
  // combination of coordinates.
  for(int i = 0; i < NUM_COLUMNS; i++)
  {
	  Column col;
    
    // Now make each of the Slot pointers point to a valid Slot
    for(int j = 0; j < NUM_ROWS; j++)
    {
	    Slot * s = new Slot(x[i], y[j], xCentre[i], yCentre[j]);
	    col.push_back(s);
    }
	  columns.push_back(col);
  }
}

/************************************************************/

void Game::Populate()
{
  std::cout << "Populating grid!"<< std::endl;

  for(int i = 0; i < NUM_COLUMNS; i++)
  {
	  std::cout << "Column: ";
    // Now make each of the Slot pointers point to a valid Slot
    for(Column::iterator it = columns[i].begin(); it != columns[i].end(); it++)
    {
	  Slot * s = *it;
	  int r = rng->Random();
	  std::cout << r << ", ";
	  s->SetJewel(static_cast<JewelType>(r));
    }
	  std::cout << "\n";
  }
}

/************************************************************/

void Game::CreateJewelSprites()
{
  std::cout << "Creating Jewel Sprites!\n";
  for(int i = JEWEL_START_ID; i < JEWEL_START_ID+NUMJEWELTYPES; i++)
  {
    HTEXTURE tex = TextureMgr::Instance()->GetTexture(i);
    
    // create a new sprite, the width and height of the jewel image, and put it's anchor point at the centre.
    Sprite * jewel = new Sprite(tex, 0, 0, tex->w, tex->h);
    jewel->SetAnchorPoint((tex->w)/2, (tex->h)/2);
    jewel_sprites.push_back(jewel);
  }

  HTEXTURE tex = TextureMgr::Instance()->GetTexture(SELECTED_JEWEL);
  pMarker = new Sprite(tex, 0, 0, tex->w, tex->h);
}

/************************************************************/


void Game::CreateBackgroundSprites()
{
  HTEXTURE hBkg = TextureMgr::Instance()->GetTexture(BACKGROUND);
  pBkg = new Sprite(hBkg, 0, 0, hBkg->w, hBkg->h);

  HTEXTURE hScore = TextureMgr::Instance()->GetTexture(SCOREBOARD);
  pScoreSprite = new Sprite(hScore, 0, 0, hScore->w, hScore->h);

  HTEXTURE hTimeLeft = TextureMgr::Instance()->GetTexture(TIMELEFT);
  pTimeLeftSprite = new Sprite(hTimeLeft, 0, 0, hTimeLeft->w, hTimeLeft->h);
}


/************************************************************/


void Game::ShowSlot(int iColumn, int iRow)
{
  Slot * s = columns[iColumn][iRow];
  s->Show();
  bGridNeedsRedraw = true;
}

/************************************************************/
void Game::SelectSlot(std::pair<int, int> pos)
{
  if( pos.first != -1 && pos.second != -1)
  {
    Slot * s = columns[pos.first][pos.second];
    s->Select();
    bGridNeedsRedraw = true;
  }
}

/************************************************************/
void Game::DeselectSlot(std::pair<int, int> pos)
{
  if( pos.first != -1 && pos.second != -1)
  {
    Slot * s = columns[pos.first][pos.second];
    s->Deselect();
    bGridNeedsRedraw = true;
  }
}

/************************************************************/
void Game::SetChoices(std::pair<int,int> one, std::pair<int,int> two)
{
  chosen[0] = one;
  chosen[1] = two;
}

/************************************************************/
std::pair<int,int> Game::GetChoice(int iWhich)
{
  return chosen[iWhich];
}
/************************************************************/
std::pair<int, int> Game::MouseToSlot(int iX, int iY)
{
  // check for a hit
  if( iX > GRID_START_X && iY > GRID_START_Y )
  {
    std::cout << " Column: " << (iX-GRID_START_X) / SLOT_WIDTH << " Row: " << (iY-GRID_START_Y) / SLOT_HEIGHT << "\n";
    return std::make_pair((iX-GRID_START_X) / SLOT_WIDTH, (iY-GRID_START_Y) / SLOT_HEIGHT );
  }
  else
  {
    return std::make_pair(-1,-1);
  }
}


/************************************************************/

void Game::StartCountdown()
{
  pClock->Start();
}

void Game::ChangeState(State<Game>* state)
{
	if( !states.empty() )
	{
		states.back()->Exit(this);
		states.pop_back();
	}

	// store and init the new state
	states.push_back(state);
	states.back()->Enter(this);
}

void Game::PushState(State<Game>* state)
{
	if(!states.empty())
	{
		states.back()->Pause();
	}

	// store and init the new state
	states.push_back(state);
	states.back()->Enter(this);
}

void Game::PopState()
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
	
void Game::HandleEvents(Engine * engine)
{
  states.back()->HandleEvents(this);
}

void Game::Update(Engine* engine)
{

   // Update the timing information
  iOldTime = iCurrentTime;
  iCurrentTime = SDL_GetTicks();
  iFrameTime = (iCurrentTime - iOldTime);

  
  // update the clock - returns true if it needs redraw
  bTimerUpdated = pClock->SubtractTimeElapsed(iFrameTime);
  

  states.back()->Update(this);
}

/************************************************************/

void Game::DrawBackground()
{
  pBkg->Blit(m_pGameScreen, 0, 0);
  pTimeLeftSprite->Blit(m_pGameScreen, TIMELEFT_X, TIMELEFT_Y);
  pScoreSprite->Blit(m_pGameScreen, SCOREBOX_X, SCOREBOX_Y);
  bBackgroundDrawn = true;
}

/************************************************************/

void Game::DrawCountdown()
{
  pClock->Draw();
}

/************************************************************/
void Game::DrawScore()
{

}

/************************************************************/

void Game::DrawGridSprites()
{
  // Blit stationary jewels
  for(int i = 0; i < NUM_COLUMNS; i++)
  {
    // Now make each of the Slot pointers point to a valid Slot
    for(Column::iterator it = columns[i].begin(); it != columns[i].end(); it++)
    {
	    Slot * s = *it;
	    if(s->Visible() && s->Occupied())
	    {
	      int iType = static_cast<int>(s->GetType());
	      jewel_sprites[iType]->Blit(m_pGameScreen, s->CentreX(), s->CentreY());

        if(s->Selected())
        {
          pMarker->Blit(m_pGameScreen, s->CentreX(), s->CentreY());
        }
      }
    }
  }
}

/************************************************************/

void Game::Draw()
{
  // Draw any sprites
  if( !bBackgroundDrawn )
  {
    DrawBackground();
  }

  if(bScoreUpdated)
  {
    DrawScore();
  }

  if(bTimerUpdated)
  {
    DrawCountdown();
  }

  if(bGridNeedsRedraw)
  {
    DrawGridSprites();
  }

  states.back()->Draw(this);		
}

void Game::Quit()
{

}
