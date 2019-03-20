#pragma once
//int width, height;

enum STATE
{
	FORWARD=1,BACKWARD,JUMP,UPWARD,DOWNWARD
};

struct Vector2
{
	double x, y;
	Vector2(double x = 0, double y = 0)
	{
		this->x = x;
		this->y = y;
	}
};

struct Color
{
	float r, g, b;
	
	//Color(float r=1,float g=0,float b=0)
	//{
	//	this->r = r;
	//	this->g = g;
	//	this->b = b;
	//}

	Color(int r=255,int g=0,int b=0)
	{
		this->r = (float)r/255;
		this->g = (float)g/255;
		this->b = (float)b/255;
	}

	void SetColor(int r = 255, int g = 0, int b = 0)
	{
		this->r = (float)r / 255;
		this->g = (float)g / 255;
		this->b = (float)b / 255;
	}

	void SetGLColor()
	{
		glColor3f(r,g,b);
	}
};