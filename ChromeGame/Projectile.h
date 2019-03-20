#pragma once

class Projectile:public GameObject
{
	int pWidth;			//width of Projectile
	double speed;
	void init()
	{
		speed = 1.5;
		size = 26;
		pWidth = 2;
	}
public:
	Projectile(double x=0,double y=0)
	{
		centre.x = x;
		centre.y = y;
		init();
	}
	Projectile(const Vector2 &point)
	{
		centre = point;
		init();
	}

	void MoveForward()  {state = FORWARD; }
	void MoveBackward() {state = BACKWARD; }
	
	//overrided func
	void Draw();
	void UpdatePos();
};

//---------------------~>[ Draw ]<~---------------------
void Projectile::Draw()
{
	this->color.SetGLColor();

	switch (state)
	{
	case FORWARD:
		glBegin(GL_QUADS);//back of arrow
		
		glVertex2d(centre.x-size/2,centre.y+pWidth/2);
		glVertex2d(centre.x-size/2,centre.y-pWidth/2);
		glVertex2d(centre.x+size/2-10,centre.y-pWidth/2);
		glVertex2d(centre.x+size/2-10,centre.y+ pWidth/2);
		glEnd();

		glBegin(GL_TRIANGLES);//arrowhead
		
		glVertex2d(centre.x + size / 2, centre.y);
		glVertex2d((centre.x + size / 2)-10, centre.y+10);
		glVertex2d((centre.x + size / 2)-10, centre.y-10);
		
		glEnd();
		break;
	case BACKWARD:
		glBegin(GL_QUADS);//back of arrow

		glVertex2d(centre.x - size / 2+10, centre.y + pWidth / 2);
		glVertex2d(centre.x - size / 2+10, centre.y - pWidth / 2);
		glVertex2d(centre.x + size / 2, centre.y - pWidth / 2);
		glVertex2d(centre.x + size / 2, centre.y + pWidth / 2);
		glEnd();

		glBegin(GL_TRIANGLES);//arrowhead

		glVertex2d(centre.x - size / 2, centre.y);
		glVertex2d((centre.x - size / 2) + 10, centre.y + 10);
		glVertex2d((centre.x - size / 2) + 10, centre.y - 10);

		glEnd();
		break;
	}
}

//---------------------~>[ UPDATE POSITION ]<~---------------------
void Projectile::UpdatePos()
{
	switch (state)
	{
	case FORWARD:
		if (centre.x < width)
			centre.x+=speed;
		break;
	case BACKWARD:
		if (centre.x > 0)
			centre.x-=speed;
		break;
	}
}