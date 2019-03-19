#pragma once
#include "essentials.h"

class Player
{
	Vector2 centre;
	Color pColor;
	int size;
	int state;
public:
	
	Player(double x=0,double y=0)
	{
		size = 20;
		centre.x = x;
		centre.y = y;
	}

	void SetPlayerColor(int,int,int);
	void Draw();
	void MoveForward();
	void MoveBackward();
	void MoveUpward();
	void MoveDownward();
	void Jump();
	void UpdatePlayerPos();
	int GetState() { return state; }
};

//---------------------~>[ Set Player Color ]<~---------------------
void Player:: SetPlayerColor(int r,int g,int b)
{
	pColor.SetColor(r,g,b);
}

//---------------------~>[ Draw ]<~---------------------
void Player::Draw()
{
	this->pColor.SetGLColor();
	glBegin(GL_QUADS);
	glVertex2i(centre.x-size, centre.y-size);
	glVertex2i(centre.x+size, centre.y-size);
	glVertex2i(centre.x+size, centre.y+size);
	glVertex2i(centre.x-size, centre.y+size);
	glEnd();
}

//---------------------~>[ Move Forward ]<~---------------------
void Player::MoveForward()
{
	state = FORWARD;
}

//---------------------~>[ Move Backward ]<~---------------------
void Player::MoveBackward()
{
	state = BACKWARD;
}
//---------------------~>[ Move Upward ]<~---------------------
void Player::MoveUpward()
{
	state = UPWARD;
}

//---------------------~>[ Move Downward ]<~---------------------
void Player::MoveDownward()
{
	state = DOWNWARD;
}
//---------------------~>[ JUMP ]<~---------------------
void Player::Jump()
{
	state = JUMP;
}

//---------------------~>[ UPDATE POSITION ]<~---------------------
void Player::UpdatePlayerPos()
{
	switch(state)
	{
	case FORWARD:
		if(centre.x<1000-size)
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
		if (centre.y < 400 - size)
			centre.y++;
		break;
	case JUMP:
		break;
	}
}