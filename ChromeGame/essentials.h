#pragma once
//This File Contains All the Essential Structs And enums Used in the game.

int width = 650;
int height=400;

enum STATE
{
	FORWARD=1,BACKWARD,UPWARD,DOWNWARD, DEAD
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

	Color(int r=255,int g=0,int b=0)
	{
		this->r = (float)r/255;
		this->g = (float)g/255;
		this->b = (float)b/255;
	}

	//set color of object
	void SetColor(int r = 255, int g = 0, int b = 0)
	{
		this->r = (float)r / 255;
		this->g = (float)g / 255;
		this->b = (float)b / 255;
	}

	//change color of OpenGL
	void SetGLColor()
	{
		glColor3f(r,g,b);
	}
};