#pragma once
#include "Bullet.h"
#include "struct.h"
class Player
{
public:
	Player(int x, int y, int speed);
	~Player();
	int posX_;
	int posY_;
	int speed_;
	bool isAlive;
	void Move(char* keys, char* preKeys);
	void Draw();

	Bullet* Classbullet[5];

	/*for (int i = 0; i < 5; i++) {
		Classbullet[i] = new Bullet();
	}*/
};

