#pragma once
Player *P1 = NULL;
Player *P2 = NULL;
Projectile *test;

class Canvas
{
	static void Clear();
public:
	static void Update(int);
};

void Canvas:: Clear()
{
	glClearColor((double)57 / 255, (double)64 / 255, (double)62 / 255, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	//glutSwapBuffers();
}

void  Canvas::Update(int time=100)
{
	if (P1 == NULL || P2==NULL)  return;//defence
	//std::cout << "kill";
	Canvas::Clear();
	
	P1->UpdatePlayerPos();
	P1->Draw();

	P2->UpdatePlayerPos();
	P2->Draw();

	test->UpdateProjectilePos();
	test->Draw();
	glutSwapBuffers();
	glutTimerFunc(3,Update,0);
}
