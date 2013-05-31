#ifndef JEWEL_SPRITE_H
#define JEWEL_SPRITE_H

class JewelSprite : public Sprite
{
public:
  JewelSprite(int x, int y, int targetX, int targetY, int xVel, int vel);
  int Move();

private:
  int iScreenX;
  int iScreenY;
  int iTargetScreenX;
  int iTargetScreenY;
  int iVelX;
  int iVelY;
};

#endif