#pragma once
#include "essentials.h"

class Player:public GameObject
{
public:
	
	Player(double x=0,double y=0)
	{
		size = 20;
		centre.x = x;
		centre.y = y;
	}
	Player(const Vector2 point)
	{
		size = 20;
		centre = point;
	}

	void MoveForward()  { state = FORWARD; }
	void MoveBackward() { state = BACKWARD; }
	void MoveUpward()   { state = UPWARD; }
	void MoveDownward() { state = DOWNWARD; }
	//void Jump()         { state = JUMP; }   //plans to use on some other Projects ;)

	void ReduceSize();

	//overrided func
	void Draw();
	void UpdatePos();
};

//---------------------~>[ Draw ]<~---------------------
void Player::Draw()
{
	this->color.SetGLColor();

	glBegin(GL_QUADS);
	glVertex2i(centre.x-size, centre.y-size);
	glVertex2i(centre.x+size, centre.y-size);
	glVertex2i(centre.x+size, centre.y+size);
	glVertex2i(centre.x-size, centre.y+size);
	glEnd();
}

//---------------------~>[ UPDATE POSITION ]<~---------------------
void Player::UpdatePos()
{
	switch(state)
	{
	case FORWARD:
		if(centre.x<width-size)
		centre.x++;
		break;
	case BACKWARD:
		if(centre.x>size)
		centre.x--;
		break;
	case DOWNWARD:
		if (centre.y > size)
			centre.y--;
		break;
	case UPWARD:
		if (centre.y < height - size)
			centre.y++;
		break;
	//case JUMP:
	//	break;
	}
}

void Player:: ReduceSize()
{
	if (size > 10)
	{
		size -= 2;
		if (centre.x < width / 2)//P1
			centre.x -= 2;
		else					//P2
			centre.x += 2;
	}
}