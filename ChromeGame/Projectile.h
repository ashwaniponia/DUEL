#pragma once

class Projectile
{
	int state;
	Vector2 centre;
	int size;
	Color color;

public:
	Projectile(double x=0,double y=0)
	{
		size = 26;
		centre.x = x;
		centre.y = y;
	}

	void Draw();
	void MoveForward();
	void MoveBackward();
	void UpdateProjectilePos();
};


void Projectile::Draw()
{
	switch (state)
	{
	case FORWARD:
		glBegin(GL_LINES);
		glVertex2d(centre.x,centre.y);
		glVertex2d(centre.x-size/2,centre.y);

		glVertex2d(centre.x, centre.y+1);
		glVertex2d(centre.x - size / 2, centre.y+1);
		
		glVertex2d(centre.x, centre.y-1);
		glVertex2d(centre.x - size / 2, centre.y-1);

		glVertex2d(centre.x, centre.y);
		glVertex2d((centre.x + size / 2)-10, centre.y);

		glVertex2d(centre.x, centre.y-1);
		glVertex2d((centre.x + size / 2) - 10, centre.y-1);

		glVertex2d(centre.x, centre.y+1);
		glVertex2d((centre.x + size / 2) - 10, centre.y+1);


		glEnd();

		glBegin(GL_TRIANGLES);
		
		glVertex2d(centre.x + size / 2, centre.y);
		glVertex2d((centre.x + size / 2)-10, centre.y+10);
		glVertex2d((centre.x + size / 2)-10, centre.y-10);
		
		glEnd();
		break;
	case BACKWARD:
		
		
		break;
	}
}

//---------------------~>[ Move Forward ]<~---------------------
void Projectile:: MoveForward()
{
	state = FORWARD;
}

//---------------------~>[ Move Backard ]<~---------------------
void Projectile::MoveBackward()
{
	state = BACKWARD;
}

//---------------------~>[ UPDATE POSITION ]<~---------------------
void Projectile::UpdateProjectilePos()
{
	switch (state)
	{
	case FORWARD:
		if (centre.x < 1000 - size)
			centre.x++;
		break;
	case BACKWARD:
		if (centre.x > size)
			centre.x--;
		break;
	/*case DOWNWARD:
		if (centre.y > size)
			centre.y--;
		break;
	case UPWARD:
		if (centre.y < 400 - size)
			centre.y++;
		break;*/
	}
}