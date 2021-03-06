#pragma once
//#6.
//This File is Responsible For Drawing on The Screen.

class Canvas
{
	static bool flag;
private:
	static void Clear();
	static void CheckWin();
	//static void DeathAnimation(Player*);
public:
	static void DisplayText(const char*,int,int,const Color&);
	static void Update(int);
};
bool Canvas::flag = false;

void Canvas:: Clear()
{
	glClearColor((double)57 / 255, (double)64 / 255, (double)62 / 255, 1);
	glClear(GL_COLOR_BUFFER_BIT);
}

void Canvas::DisplayText(const char* text, int x, int y,const Color& c=Color::RED())
{
	Color textColor = c;
	textColor.SetGLColor();

	glRasterPos2f(x, y);
	size_t len = strlen(text);
	for (int i = 0; i < len; i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, (int)text[i]);
	
}

void  Canvas::Update(int time=100)
{
	if (!isGameRunning && flag)
	{
		Color winColor(0,0,0);
		if (P1Alive)
		{
			winColor = P1->GetPlayerColor();
			DisplayText("P1 WINS",width/2-60-1,height/2+50,Color::TEAL());
			DisplayText("P1 WINS",width/2-60,height/2+50,Color::TEAL());
		}
		else
		{
			winColor = P2->GetPlayerColor();
			DisplayText("P2 WINS", width / 2 - 60-1, height / 2 + 50, Color::TEAL());
			DisplayText("P2 WINS", width / 2 - 60, height / 2 + 50, Color::TEAL());
		}
		DisplayText("PRESS 'r' to Restart", width / 2 - 120 - 1, height / 2, winColor);
		DisplayText("PRESS 'r' to Restart",width/2-120,height/2,winColor);
		glFlush();
		return; 
	}
	if (!isGameRunning)
		flag = true;
	else
		flag = false;
	Canvas::Clear();
		
	if (P1 != NULL)
	{
		P1->UpdatePos();
		P1->Draw();

		for (int i = 0; i < P1Bullet.size(); i++)//player 1 bullets
		{
			P1Bullet[i]->UpdatePos();
			P1Bullet[i]->Draw();
		}
	}

	if (P2 != NULL)
	{
		P2->UpdatePos();
		P2->Draw();
		for (int i = 0; i < P2Bullet.size(); i++)//player 2 bullets
		{
			P2Bullet[i]->UpdatePos();
			P2Bullet[i]->Draw();
		}
	}
	
	Canvas::CheckWin();

	glutSwapBuffers();
	glutTimerFunc(4,Update,0);
}

//this func checks who wins P1 or P2
void Canvas::CheckWin()
{

	if (P1 == NULL || P2 == NULL) return;//defence
	Vector2 bPoint;//bullet Point
	int bSize;
	
	auto p1Point=P1->GetCentre();
	auto p1Size = P1->GetSize();

	auto p2Point=P2->GetCentre();
	auto p2Size = P2->GetSize();

	auto P1BulletCount = P1Bullet.size();
	auto P2BulletCount = P2Bullet.size();

	for (int i = 0; i < P1BulletCount; i++)//player 1 bullets
	{
		bPoint = P1Bullet[i]->GetCentre();
		bSize = P1Bullet[i]->GetSize();

		//check whether i bullet hit the P2 player
		bool hit = false;
		int x = bPoint.x + bSize / 2;
		int y = bPoint.y;

		if (y > (p2Point.y - p2Size) && y < (p2Point.y + p2Size))//bullet y is in range of P2
		{
			if (x > (p2Point.x - p2Size))
			{
				hit = true;
				P2->ReduceSize();
			}
		}
		
		if (x > p2Point.x || hit)
		{
			P1Bullet.erase(P1Bullet.begin() + i);
			P1BulletCount--;
		}
		
		if (hit && ++P2HitTaken >= maxHit)//P2 Loses
		{
			cout << "P1 WINS" << endl;

			P2Alive = false;
			P2Bullet.clear();
			P2 = NULL;
			isGameRunning = false;
			return;
		}
	}//P1 Wins Or not

	for (int i = 0; i < P2BulletCount; i++)//player 2 bullets
	{
		bPoint = P2Bullet[i]->GetCentre();
		bSize = P2Bullet[i]->GetSize();

		//check whether i bullet hit the P2 player
		bool hit = false;
		int x = bPoint.x - bSize / 2;
		int y = bPoint.y;

		if (y > (p1Point.y - p1Size) && y < (p1Point.y + p1Size))//bullet y is in range of P2
		{
			if (x < (p1Point.x + p1Size))
			{
				hit = true;
				P1->ReduceSize();
			}
		}
		if (x <p1Point.x || hit)//to vanish unused bullets of P2
		{
			P2Bullet.erase(P2Bullet.begin() + i);
			P2BulletCount--;
		}

		//p1 loses and p2 wins
		if (hit && ++P1HitTaken >= maxHit)//P1 loses
		{
			cout << "P2 WINS" << endl;

			P1Alive = false;
			P1 = NULL;
			P1Bullet.clear();
			isGameRunning = false;
			return;
		}

	}//P2 Wins Or Not
}



