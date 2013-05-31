#ifndef _VALIDATINGSWAP_H
#define _VALIDATINGSWAP_H

#include "SDL.h"
#include "State.h"
#include "Sprite.h"
#include "Game.h"

class ValidatingSwap : public State<Game>
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
  static ValidatingSwap* Instance()
  {
    return &m_ValidatingSwap;
  }

protected:
  static ValidatingSwap m_ValidatingSwap;
	ValidatingSwap() {}
private:
  bool bUpdate;
  int iChoice;
  std::pair<int,int> chosen[2];
  Sprite * first;
  Sprite * second;
};

#endif