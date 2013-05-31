#ifndef _PLAYING_Engine_H_
#define _PLAYING_Engine_H_

#include "Engine.h"
#include "State.h"
#include "Game.h"

class PlayingGame : public State<Engine>
{
public:
  void Enter(Engine *);
  void Exit(Engine *);

  void Pause();
  void Resume();

  void HandleEvents(Engine * pOwner);
  void Update(Engine * pOwner);
  void Draw(Engine * pOwner);

  // Singleton pattern
  static PlayingGame* Instance()
  {
    return &m_PlayingGame;
  }
protected:
	PlayingGame() {}

private:
	static PlayingGame m_PlayingGame;
	Game * m_pGame;
};

#endif