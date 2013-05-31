#include "Countdown.h"
#include <iostream>

Countdown::Countdown(int iQ, SDL_Surface * pBlitTo, int iX, int iY):
 iQuota(iQ),
 bRunning(false),
 iMillisecondsLeft(0),
 iMillisecondsElapsed(0),
 iHours(0),
 iMinutes(0),
 iSeconds(0),
 pScreen(pBlitTo)
{
  tex = TextureMgr::Instance()->GetTexture(NUMBERS);
  Sprite * pTens = new Sprite(tex, digit_x_offset[0], 0, DIGIT_WIDTH, DIGIT_HEIGHT);
  Sprite * pUnits = new Sprite(tex, digit_x_offset[0], 0, DIGIT_WIDTH, DIGIT_HEIGHT);

  // work out coords based on iX and iY
  iTensX = iX-DIGIT_WIDTH;
  iTensY = iY-DIGIT_WIDTH/2;

  iUnitsX = iX;
  iUnitsY = iTensY;
}

void Countdown::Start()
{ 
  iMillisecondsLeft = iQuota;
  bRunning = true;
}

void Countdown::Reset()
{
  iMillisecondsLeft = iQuota;
  bRunning = false;
  iMillisecondsElapsed = 0;
  iHours = 0;
  iMinutes = 0;
  iSeconds = 0;

}

bool Countdown::SubtractTimeElapsed(int iElapsed)
{
  
  bool bRedraw = false;
  if(bRunning)
  {
    iMillisecondsLeft -= iElapsed;

    if(iMillisecondsLeft < 0)
    {
      iMillisecondsLeft = 0;
    }

    // do we update the sprite?
    if(iElapsed > 1000)
    {
      bRedraw = true;

      iSeconds = (iMillisecondsLeft % MILLISECONDS_IN_A_MIN) / MILLISECONDS_IN_A_SECOND;

      if(iSeconds > 9)
      {
        int iTens = iSeconds / 10;
        pTens->SetTexture(tex, digit_x_offset[iTens], 0, DIGIT_WIDTH, DIGIT_HEIGHT);
      }

      int iUnits = iSeconds % 10;
      pUnits->SetTexture(tex, digit_x_offset[iUnits], 0, DIGIT_WIDTH, DIGIT_HEIGHT);
    }

    if(iMillisecondsLeft == 0)
    {
      bRunning = false;
    }
  }
  return bRedraw;
}

void Countdown::Draw()
{
  pTens->Blit(pScreen, iTensX, iTensY);
  pUnits->Blit(pScreen, iUnitsX, iUnitsY);
}
