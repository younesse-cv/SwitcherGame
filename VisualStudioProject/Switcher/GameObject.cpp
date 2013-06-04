#include "GameObject.h"
#include <iostream>

/************************************************************/
GameObject::GameObject(Sprite * s):
  iXPos(0),
  iYPos(0),
  iXVel(0),
  iYVel(0)
{
  pSprite = s;
}
/************************************************************/
void GameObject::SetVelocity(int xvel, int yvel)
{
  iXVel = xvel;
  iYVel = yvel;
}
/************************************************************/
void GameObject::SetY(int y)
{
  iYPos = y;
}
/************************************************************/
void GameObject::SetX(int x)
{
  iXPos = x;
}
/************************************************************/
void GameObject::SetPosition(int x, int y)
{
  iXPos = x;
  iYPos = y;
}
/************************************************************/
int  GameObject::GetX()
{
  return pSprite->GetX();
}

/************************************************************/
int  GameObject::GetY()
{
  return pSprite->GetY();
}
/************************************************************/
void GameObject::Update(int iElapsedMS)
{
  std::cout << "update Game Object\n";
  iXPos += iElapsedMS * (iXVel/1000);
  iYPos += iElapsedMS * (iYVel/1000);
}
/************************************************************/
void GameObject::Draw(SDL_Surface * pSurface)
{
  pSprite->Blit(pSurface, iXPos, iYPos);
}
