#pragma once
#include "struct.h"
class Enemy
{
public:
	Enemy(Vector2 pos, int speed);
	~Enemy();
	Vector2 pos_;
	int speed_;
	float radius;
	bool isAlive;
	void Move();
	void Draw();
public:
	static int EnemyCount;
};

