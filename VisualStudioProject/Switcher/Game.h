#ifndef _GRID_H_
#define _GRID_H_

#include <vector>
#include "State.h"
#include "Engine.h"
#include "Sprite.h"
#include "TextureMgr.h"
#include "SDL.h"
#include "Slot.h"
#include "RNG.h"
#include "Countdown.h"

class Game
{
public:
  Game(SDL_Surface *pVideo);
	
  void LoadTextures();
  
  void ChangeState(State<Game>* state); // new function
	void PushState(State<Game>* state); // new function
	void PopState();
	
	void HandleEvents(Engine* engine);
	void Update(Engine* engine);
	void Draw();

  SDL_Surface * GetScreen() { return m_pGameScreen; }
  void Quit();


  void InitialiseGridPositions();
  void CreateBackgroundSprites();
  void CreateJewelSprites();
  

  Sprite * GetJewelSprite(JewelType t);

  void ShowSlot(int iColumn, int iRow);
  void HideSlot(int iColumn, int iRow);

  void SelectSlot(std::pair<int, int> pos);
  void DeselectSlot(std::pair<int, int> pos);

  Slot * GetSlot(int iColumn, int iRow);

  void SetChoices(std::pair<int,int>, std::pair<int,int>);
  std::pair<int,int> GetChoice(int iWhich);

  void DrawBackground();
  void DrawCountdown();
  void DrawScore();
  void DrawGridSprites();

  void Populate();

  void StartCountdown();
  std::pair<int, int> MouseToSlot(int,int);
private:
  
	std::vector<State<Game>*> states;
  SDL_Surface* m_pGameScreen;
  bool bInitialised;

  // Grid
  // A Column is a vector of pointers to Slot 
  typedef std::vector<Slot *> Column;

  // the grid is implemented as a vector of Column
  std::vector<Column> columns;

  // Sprites
  bool bBackgroundDrawn;
  bool bScoreUpdated;
  bool bTimerUpdated;
  bool bGridNeedsRedraw;
  Sprite * pBkg;
  Sprite * pScoreSprite;
  Sprite * pTimeLeftSprite;
  Sprite * pMarker;
  Sprite * pEmpty;

  // Jewels
  std::vector<Sprite *> jewel_sprites;

  // Random Number Generator
  RandomNumberGenerator * rng;

  // Countdown
  Countdown * pClock;
  int iOldTime;
  int iCurrentTime;
  int iFrameTime;

  // Chosen jewels
  std::pair<int,int> chosen[2];
};
#endif