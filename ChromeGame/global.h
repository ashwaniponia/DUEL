#pragma once
//#7.
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
	if (P1Alive)
	{
		switch (key)
		{
		case 'w':
			P1->MoveUpward();
			break;

		case 'x':
			P1->MoveDownward();
			break;

		case 's'://P1 Shoots
			if (P1Bullet.size() < projectileCount)
			{
				P1Bullet.push_back(new Projectile(P1->GetCentre()));//P1 bullet based on the curr location of P1
				P1Bullet[P1Bullet.size() - 1]->MoveForward();
				P1Bullet[P1Bullet.size() - 1]->SetColor(P1->GetPlayerColor());
			}
			break;
		}
	}//P1 Alive

	if (P2Alive)
	{
		switch (key)
		{
			case '8':
				P2->MoveUpward();
				break;
			case '2':
				P2->MoveDownward();
				break;
			case '5'://P2 Shoots
				if (P2Bullet.size() < projectileCount)
				{
					P2Bullet.push_back(new Projectile(P2->GetCentre()));//P1 bullet based on the curr location of P1
					P2Bullet[P2Bullet.size() - 1]->MoveBackward();
					P2Bullet[P2Bullet.size() - 1]->SetColor(P2->GetPlayerColor());
				}
				break;
		}
	}//P2 Alive

	switch (key)
	{
	case 'r':
		if(!isGameRunning)
		ResetGame();
		break;
	}
}


//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
//					:~>  GAME_AREA <~:
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

void ResetGame()
{
	if (P1) delete P1;
	if (P2) delete P2;

	P1Bullet.clear();
	P2Bullet.clear();

	P1HitTaken = 0;
	P2HitTaken = 0;

	P1 = new Player(20, 150);
	P1->SetColor(0, 255, 120);
	P1->Draw();
	P1Alive = true;

	P2 = new Player(width - 20, 150);
	P2->SetColor(166, 3, 63);
	P2->Draw();
	P2Alive = true;

	glFlush();
	isGameRunning = true;
	Canvas::Update();
}