#include "Slot.h"
#include <iostream>

// Slot Constructor
Slot::Slot( int iXTopLeft, int iYTopLeft, 
		  int iXCentre, int iYCentre, 
		  bool bVis, 
		  bool bOcc, 
      bool bSel,
		  JewelType eType):
   iX(iXTopLeft),
   iY(iYTopLeft),
   iCentreX(iXCentre),
   iCentreY(iYCentre),
   bVisible(bVis),
   bOccupied(bOcc),
   bSelected(bSel),
   eJewelType(eType)
{
  std::cout << "Creating slot iX " << iX << "iY: " << iY << " \n";
}

void Slot::SetJewel(JewelType eType)
{ 
  eJewelType = eType; 
  bOccupied = true;
}

void Slot::Show()
{
  bVisible = true;
}
 
void Slot::Hide()
{
  bVisible = false;
}

void Slot::Select()
{
  bSelected = true;
}

void Slot::Deselect()
{
  bSelected = false;
}