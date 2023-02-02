#include "Enemy.h"
#include "Novice.h"
Enemy::Enemy(Vector2 pos, int speed)
{
	pos_.x = pos.x;
	pos_.y = pos.y;
	speed_ = speed;
	radius = 16;
}
Enemy::~Enemy() {
	EnemyCount += 1;
}
void Enemy::Move() {
	pos_.x += speed_;
	if (pos_.x >= 1280) {
		speed_ *= -1;
	}
	if (pos_.x <= 0) {
		speed_ *= -1;
	}
}
void Enemy::Draw() {
	Novice::DrawEllipse(pos_.x, pos_.y, 16, 16, 0, RED, kFillModeSolid);
}

