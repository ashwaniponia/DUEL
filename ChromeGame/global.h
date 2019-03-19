#pragma once
int width = 1000;
int height = 400;

//Game variables
//Player *P1 = NULL;


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
	glutCreateWindow("DINO");

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
	//glutIdleFunc(Canvas::Update);
}

//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
//					:~>  CALLBACKS <~:
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

//---------------------~>[ Reshape ]<~---------------------
void Reshape(int x,int y)
{
	if (width == x && height == y) return;
	
	glutReshapeWindow(width,height);
	Clear();
}

//---------------------~>[ Dispaly ]<~---------------------
void Display()
{
	
}

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
	case 's':
		P1->MoveDownward();
		break;
	case 'o':
		P2->MoveUpward();
		break;
	case 'l':
		P2->MoveDownward();
		break;
	case 32: // space
		// P1->Jump();
		break;
	}
}