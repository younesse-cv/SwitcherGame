#include "Clock.h"

const int MILLISECONDS_IN_AN_HOUR = 3600000;
const int MILLISECONDS_IN_A_MIN = 60000;
const int MILLISECONDS_IN_A_SECOND = 1000;

Clock::Clock():
 iMillisecondsElapsed(0),
 iHours(0),
 iMinutes(0),
 iSeconds(0)
{
  // pMarkerSprite = Sprite::Load("test.bmp");
}

int Clock::GetMinutesElapsed()
{
  return iMinutes;
}

int Clock::GetSecondsElapsed()
{
  return iSeconds;
}

int Clock::GetHourseElapsed()
{
  return iHours;
}

void Clock::Reset(int iNewTime)
{
  iMillisecondsElapsed = iNewTime;
}

void Clock::AddTimeElapsed(int iMS)
{
  iMillisecondsElapsed += iMS;

  iHours = iMillisecondsElapsed / MILLISECONDS_IN_AN_HOUR;
  iMinutes = (iMillisecondsElapsed % MILLISECONDS_IN_AN_HOUR) / MILLISECONDS_IN_A_MIN;
  iSeconds = (iMillisecondsElapsed % MILLISECONDS_IN_A_MIN) / MILLISECONDS_IN_A_SECOND;
  
  std::cout << "Time is " << iHours << ":" << iMinutes << ":" << iSeconds << "\n";
}

