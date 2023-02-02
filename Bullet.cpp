#include "Bullet.h"
#include "Novice.h"
Bullet::Bullet() {
	pos_.x = 0;
	pos_.y = 0;
	speed_ = 4;
	radius_ = 8;
	isALive_ = false;
}
void Bullet::Draw() {
	if (isALive_ == true) {
		Novice::DrawEllipse(pos_.x, pos_.y, radius_, radius_, 0, RED, kFillModeSolid);
	}
}