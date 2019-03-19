#include "pch.h"
#include <iostream>
#include<vector>
#include<GL/glut.h>

#include "essentials.h"
#include "player.h"
#include "Projectile.h"
#include "canvas.h"
#include "global.h"


int main(int argc,char **argv)
{
	glutInit(&argc,argv);
	Init();
	InitCallbackFunc();
	
	P1 = new Player(20, 150);
	P1->SetPlayerColor(0, 255, 120);
	P1->Draw();
	
	P2 = new Player(980, 150);
	P2->SetPlayerColor(166, 3, 63);
	P2->Draw();
	
	glColor3ub(166, 3, 63);
	test=new Projectile(40, 150);
	test->MoveForward();
	test->Draw();

	glFlush();
	Canvas::Update();
	glutMainLoop();
	return 0;
}
