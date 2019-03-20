#pragma once

class Projectile
{
	int state;
	Vector2 centre;
	int size;
	int width;
	Color color;

public:
	Projectile(double x=0,double y=0)
	{
		size = 26;
		width = 2;
		centre.x = x;
		centre.y = y;
	}
	Projectile(const Vector2 &point)
	{
		size = 26;
		width = 2;
		centre = point;
	}
	void Draw();
	void MoveForward();
	void MoveBackward();
	void UpdateProjectilePos();
	void SetProjectileColor(int r, int g, int b);
	void SetProjectileColor(const Color& c)	{color = c;}
	
	//getters
	Vector2 GetX() { return centre; }
	int GetSize() { return size; }
};


void Projectile::Draw()
{
	this->color.SetGLColor();

	switch (state)
	{
	case FORWARD:
		glBegin(GL_QUADS);//back of arrow
		
		glVertex2d(centre.x-size/2,centre.y+width/2);
		glVertex2d(centre.x-size/2,centre.y-width/2);
		glVertex2d(centre.x+size/2-10,centre.y-width/2);
		glVertex2d(centre.x+size/2-10,centre.y+width/2);
		glEnd();

		glBegin(GL_TRIANGLES);//arrowhead
		
		glVertex2d(centre.x + size / 2, centre.y);
		glVertex2d((centre.x + size / 2)-10, centre.y+10);
		glVertex2d((centre.x + size / 2)-10, centre.y-10);
		
		glEnd();
		break;
	case BACKWARD:
		glBegin(GL_QUADS);//back of arrow

		glVertex2d(centre.x - size / 2+10, centre.y + width / 2);
		glVertex2d(centre.x - size / 2+10, centre.y - width / 2);
		glVertex2d(centre.x + size / 2, centre.y - width / 2);
		glVertex2d(centre.x + size / 2, centre.y + width / 2);
		glEnd();

		glBegin(GL_TRIANGLES);//arrowhead

		glVertex2d(centre.x - size / 2, centre.y);
		glVertex2d((centre.x - size / 2) + 10, centre.y + 10);
		glVertex2d((centre.x - size / 2) + 10, centre.y - 10);

		glEnd();
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

void Projectile::SetProjectileColor(int r, int g, int b)
{
	color.SetColor(r, g, b);
}