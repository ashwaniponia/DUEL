#pragma once
//this File is Responsible for all the Initialization and registering GLUT callbacks.


//width and height already defined in essentials.h
//int width = 650;
//int height = 400;


//callbacks
void Reshape(int,int);
void Display();
void Keyboard(unsigned char,int,int);

//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
//					:~>  INITIALIZERS <~:
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

//---------------------~>[ INIT ]<~---------------------
void Init()
{
	//initialize window
	glutInitWindowPosition(150,150);
	glutInitWindowSize(width,height);
	glutCreateWindow("DUEL");

	//initialize viewport
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0, width, 0, height);

	//set bg color
	glClearColor((double)57/255, (double)64/255, (double)62/255,1);
	glClear(GL_COLOR_BUFFER_BIT);
	glFlush();
}

//---------------------~>[ CLEAR ]<~---------------------
void Clear()
{
	glClearColor((double)57 / 255, (double)64 / 255, (double)62 / 255, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	glFlush();
}

//---------------------~>[ CALL_BACKS ]<~---------------------
void InitCallbackFunc()
{
	glutReshapeFunc(Reshape);
	glutDisplayFunc(Display);
	glutKeyboardFunc(Keyboard);
}

//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
//					:~>  CALLBACKS <~:
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

//---------------------~>[ Reshape ]<~---------------------
void Reshape(int x,int y)
{
	if (width == x && height == y) return;
	
	//preventing user from reshaping the window :)
	glutReshapeWindow(width,height);
	Clear();
}

//---------------------~>[ Dispaly ]<~---------------------
void Display(){}

//---------------------~>[ Keyboard ]<~---------------------
void Keyboard(unsigned char key, int, int)
{
	//std::cout << (int)key;
	switch (key)
	{
	case 27://esc key
		exit(0);
	case 'd':
		//P1->MoveForward();
		break;
	case 'a':
		//P1->MoveBackward();
		break;
	case 'w':
		P1->MoveUpward();
		break;
	case 'x':
		P1->MoveDownward();
		break;

	case 'p':
		P2->MoveUpward();
		break;
	case 'l':
		P2->MoveDownward();
		break;

		//shooting
	case 's':
		if (P1Bullet.size() < projectileCount)
		{
			P1Bullet.push_back(new Projectile(P1->GetCentre()));//P1 bullet based on the curr location of P1
			P1Bullet[P1Bullet.size() - 1]->MoveForward();
			P1Bullet[P1Bullet.size() - 1]->SetColor(P1->GetPlayerColor());
		}
		break;
	case 'o':
		if (P2Bullet.size() < projectileCount)
		{
			P2Bullet.push_back(new Projectile(P2->GetCentre()));//P1 bullet based on the curr location of P1
			P2Bullet[P2Bullet.size() - 1]->MoveBackward();
			P2Bullet[P2Bullet.size() - 1]->SetColor(P2->GetPlayerColor());
		}
		break;
	//case 32: // space
		// P1->Jump();
		//break;
	}
}