#ifndef _CLOCK_H_
#define _CLOCK_H_

#include <string>
#include <iostream>

#include "Sprite.h"

class Clock
{
public:
  Clock();
  void Reset(int iNewTime = 0);
  void AddTimeElapsed(int iMS);
  int GetMinutesElapsed();
  int GetSecondsElapsed();
  int GetHourseElapsed();
private:
  int iMillisecondsElapsed;
  int iHours;
  int iMinutes;
  int iSeconds;
};

#endif