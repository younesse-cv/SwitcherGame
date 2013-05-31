#ifndef _BASE_GAME_OBJECT_H_
#define _BASE_GAME_OBJECT_H_

class BaseGameObject
{
private:
	int m_ID;

	void SetID(int val);

public:
	BaseGameObject(int id)
	{
	  SetID(id);
	}

	virtual ~BaseGameObject(){}

	// all Game objects must implement an update function
	virtual void Update() = 0;

	int ID() const { return m_ID; }
};

#endif