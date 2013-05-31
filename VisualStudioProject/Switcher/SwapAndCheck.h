#ifndef _SWAPANDCHECK_H
#define _SWAPANDCHECK_H

#include "SDL.h"
#include "State.h"
#include "Sprite.h"
#include "Game.h"

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

  Sprite * first;
  Sprite * second;
};

#endif