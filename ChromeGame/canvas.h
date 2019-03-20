#pragma once
Player *P1 = NULL;
Player *P2 = NULL;
vector<Projectile*> P1Bullet;
vector<Projectile*> P2Bullet;
int projectileCount = 5;//how much bullet Players can Shoot

class Canvas
{
	static void Clear();
	static void CheckWin();
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

	for (int i = 0; i < P1Bullet.size(); i++)//player 1 bullets
	{
		P1Bullet[i]->UpdateProjectilePos();
		P1Bullet[i]->Draw();
	}
	for (int i = 0; i < P2Bullet.size(); i++)//player 2 bullets
	{
		P2Bullet[i]->UpdateProjectilePos();
		P2Bullet[i]->Draw();
	}
	
	Canvas::CheckWin();

	glutSwapBuffers();
	glutTimerFunc(3,Update,0);
}

void Canvas::CheckWin()
{
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
		bPoint = P1Bullet[i]->GetX();
		bSize = P1Bullet[i]->GetSize();

		//check whether i bullet hit the P2 player
		bool hit = false;
		int x = bPoint.x + bSize / 2;
		int y = bPoint.y;

		if (y > (p2Point.y - p2Size) && y < (p2Point.y + p2Size))//bullet y is in range of P2
		{
			if (x > (p2Point.x - p2Size))
				hit = true;
		}
		
		if (x > (p2Point.x - p2Size))
		{
			P1Bullet.erase(P1Bullet.begin() + i);
			P1BulletCount--;
		}
		if (hit)//p2 loses and p1 wins
		{
			cout << "P1 WINS" << endl;
			cout << "HOORAY" << endl;
			return;
		}
	}

	for (int i = 0; i < P2BulletCount; i++)//player 2 bullets
	{
		bPoint = P2Bullet[i]->GetX();
		bSize = P2Bullet[i]->GetSize();

		//check whether i bullet hit the P2 player
		bool hit = false;
		int x = bPoint.x + bSize / 2;
		int y = bPoint.y;

		if (y > (p1Point.y - p1Size) && y < (p1Point.y + p1Size))//bullet y is in range of P2
		{
			if (x < (p1Point.x + p1Size))
				hit = true;
		}
		if (x < (p1Point.x + p1Size))//to vanish unused bullets of P2
		{
			P2Bullet.erase(P2Bullet.begin() + i);
			P2BulletCount--;
		}

		if (hit)//p1 loses and p2 wins
		{
			cout << "P2 WINS" << endl;
			cout << "HOORAY" << endl;
			return;
		}
	}
}