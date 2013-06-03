#ifndef _GAME_OBJECT_H_
#define _GAME_OBJECT_H_

#include <SDL.h>
#include "Sprite.h"


class GameObject
{

  public:
    GameObject(Sprite * s);

    void SetVelocity(int xvel, int yvel);
    void SetPosition(int x, int y);

    void SetY(int y);
    void SetX(int x);

    int  GetX();
    int  GetY();

    void Update(int iElapsedMS);
    void Draw(SDL_Surface * pSurface);

  private:
    int iXVel;
    int iYVel;
    int iXPos;
    int iYPos;
    Sprite * pSprite;
};

#endif

