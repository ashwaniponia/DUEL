		//glutTimerFunc(100, Canvas::Update, 100);
		cout << "COlor is:" << endl;
		cout << "R:" << color.r << "G:" << color.g << "B:" << color.b << endl;
		
		void Player::MoveForward()
{
	state = FORWARD;
}
void Player::MoveBackward()
{
	state = BACKWARD;
}
void Player::MoveUpward()
{
	state = UPWARD;
}

void Player::MoveDownward()
{
	state = DOWNWARD;
}
void Player::Jump()
{
	state = JUMP;
}

//Color(float r=1,float g=0,float b=0)
	//{
	//	this->r = r;
	//	this->g = g;
	//	this->b = b;
	//}



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
	

	
	//case 32: // space
		// P1->Jump();
		//break;
	}



			Canvas::DisplayText("P2 HITS P1",width/2,height/2);



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

//display projectiles;

for (int i = 0; i < P1Bullet.size(); i++)//player 1 bullets
{
	P1Bullet[i]->UpdatePos();
	P1Bullet[i]->Draw();
}