#ifndef _GRIDSTATE_H_
#define _GRIDSTATE_H_

#include "Game.h"
#include "Grid.h"

class GridState
{
public:
	virtual void Enter() = 0;
	virtual void Exit() = 0;
	
	virtual void HandleEvents(Grid * grid) = 0;
	virtual void Update(Grid* grid) = 0;
	virtual void Draw(Grid* grid) = 0;

	void ChangeState(Grid* grid, GridState* state) 
	{
		grid->ChangeState(state);
	}
protected:
	GridState() {}
};

#endif

