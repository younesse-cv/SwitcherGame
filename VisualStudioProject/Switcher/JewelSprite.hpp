#ifndef _JEWEL_SPRITE_HPP
#define _JEWEL_SPRITE_HPP

class JewelSprite
{
public:
  JewelSprite(int xVel, int yVel, 
	          int destX, int destY, 
			  int startX, int startY,
			  int JewelType);
private:
  int xVel;
  int yVel;
  int destX;
  int destY;
  int xPos;
  int yPos; 
  int jewelType;
};

#endif