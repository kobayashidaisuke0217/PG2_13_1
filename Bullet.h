#pragma once
#include "struct.h"
class Bullet
{
public:
	Bullet();
	Vector2 pos_;
	int radius_;
	bool isALive_;
	int speed_;
	void Draw();
};

