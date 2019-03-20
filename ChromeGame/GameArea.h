#pragma once
//This File Contains All The Information about Game.
//for e.g No. of Players,BulletCount,etc

Player *P1 = NULL;
Player *P2 = NULL;
bool P1Alive = true;
bool P2Alive = true;
vector<Projectile*> P1Bullet;
vector<Projectile*> P2Bullet;
int projectileCount = 6;//how much bullet Players can Shoot