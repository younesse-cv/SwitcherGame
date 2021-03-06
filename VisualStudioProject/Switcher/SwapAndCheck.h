#ifndef _SWAPANDCHECK_H
#define _SWAPANDCHECK_H

#include "SDL.h"
#include "State.h"
#include "Sprite.h"
#include "Game.h"
#include "GameObject.h"

class SwapAndCheck : public State<Game>
{
public:
  void Enter(Game*);
	void Exit(Game*) ;
	
	void HandleEvents(Game * game);
	void Update(Game * game);
	void Draw(Game* game);

  // Not used
  void Pause(){}
  void Resume(){}

  // Singleton pattern
  static SwapAndCheck* Instance()
  {
    return &m_SwapAndCheck;
  }

protected:

  static SwapAndCheck m_SwapAndCheck;
	SwapAndCheck() {}

private:
  
  std::pair<int,int> chosen[2];
  SDL_Surface* pGameScreen;
  GameObject * top;
  GameObject * bottom;

  std::pair<int, int> topXY;
  std::pair<int, int> bottXY;

  std::pair<int, int> targetTopXY;
  std::pair<int, int> targetBottXY;
};

#endif