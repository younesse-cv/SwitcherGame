#ifndef _SLOT_H_
#define _SLOT_H_

#include "defines.h"

class Slot
{
public:
  Slot( int iXTopLeft, int iYTopLeft, 
		    int iXCentre, int iYCentre, 
		    bool bVis = false, 
		    bool bOcc = false, 
        bool bSel = false,
		    JewelType eType = JEWELTYPE_NONE );
  void SetJewel(JewelType eType);
  void Show();
  void Hide();
  void Select();
  void Deselect();
  bool Selected() { return bSelected; }
  bool Visible() { return bVisible; }
  bool Occupied() { return bOccupied; }
  JewelType GetType() { return eJewelType; }
  int  CentreX() { return iCentreX; }
  int  CentreY() { return iCentreY; }
  int  X() { return iX; }
  int  Y() { return iY; }
private:

  int iX;
  int iY;
  int iCentreX;
  int iCentreY;
  bool bVisible;
  bool bOccupied;
  bool bSelected;
  JewelType eJewelType;
};


#endif