#ifndef _COUNTDOWN_H_
#define _COUNTDOWN_H_

#include "defines.h"
#include "Sprite.h"
#include <vector>

class Countdown
{
public:
  Countdown::Countdown(int iQ, SDL_Surface * pBlitTo, int iX, int iY);
  void Start();
  void Reset();
  bool SubtractTimeElapsed(int iElapsed);
  void Draw();

private:
  int iQuota;
  int iMillisecondsElapsed;
  int iMillisecondsLeft;
  int iHours;
  int iMinutes;
  int iSeconds;

  int iTensX;
  int iTensY;

  int iUnitsX;
  int iUnitsY;

  bool bRunning;
  
  Sprite * pTens;
  Sprite * pUnits;

  SDL_Surface * pScreen;
  HTEXTURE tex;
};


#endif