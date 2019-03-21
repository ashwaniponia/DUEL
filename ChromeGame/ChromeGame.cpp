//#8.
//this is the main file.
//Please Don't change the order of Header Files included as Program Will not Work Properly(eopPGcg).

#include "pch.h"			//remove this line if not using Visual Studio
#include <iostream>
using namespace std;
#include<vector>
#include<GL/glut.h>

#include "essentials.h"
#include "object.h"
#include "player.h"
#include "Projectile.h"

#include "GameArea.h"
#include "canvas.h"
#include "global.h"

int main(int argc,char **argv)
{
	glutInit(&argc,argv);
	Init();
	InitCallbackFunc();
	
	//initialize Player 1
	P1 = new Player(20, 150);
	P1->SetColor(0, 255, 120);
	P1->Draw();
	
	//initialize Player 2
	P2 = new Player(width-20, 150);
	P2->SetColor(166, 3, 63);
	P2->Draw();

	glFlush();
	Canvas::Update();
	glutMainLoop();
	return 0;
}

//HOPE YOU ENJOYED THE GAME
//		THANKYOU
//CREATED BY: SHUBAM SHARMA