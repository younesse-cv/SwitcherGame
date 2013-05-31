#ifndef _STATE_BASE_H_
#define _STATE_BASE_H_

// All states - e.g. game framework states (such as "showingSplash")
// and game specific states (such as "Firing Weapon")
// are derived from this base class.

// All entities in the game including the Game itself, is derived
// from the GameBaseObject.
template <class GameBaseObject>
class State
{
  virtual ~State;

  // stuff to do when entering this state.
  // i.e. make sure everything initialised to execute this state.
  virtual void Enter(GameBaseObject*)=0;

  virtual void Execute(GameBaseObject*)=0;

  virtual void Exit(GameBaseObject*)=0;
};



#endif