#include "Player.h"
#include <Novice.h>

Player::Player(int x, int y, int speed) {
	posX_ = x;
	posY_ = y;
	speed_ = speed;
	isAlive = true;
	for (int i = 0; i < 5; i++) {
		Classbullet[i] = new Bullet();
	}

}
Player::~Player() {

}
void Player::Move(char* keys, char* preKeys) {
	if (keys[DIK_W]) {
		posY_ -= speed_;
	}
	if (keys[DIK_S]) {
		posY_ += speed_;
	}
	if (keys[DIK_A]) {
		posX_ -= speed_;
	}
	if (keys[DIK_D]) {
		posX_ += speed_;
	}
	for (int i = 0; i < 5; i++) {
		if (keys[DIK_SPACE] && preKeys[DIK_SPACE] == 0) {
			if (Classbullet[i]->isALive_ == false) {
				Classbullet[i]->isALive_ = true;
				Classbullet[i]->pos_.x = posX_;
				Classbullet[i]->pos_.y = posY_;
				break;
			}
		}
		if (Classbullet[i]->isALive_ == true) {
			Classbullet[i]->pos_.y -= Classbullet[i]->speed_;
			if (Classbullet[i]->pos_.y <= 0) {
				Classbullet[i]->isALive_ = false;
			}
		}
	}

}
void Player::Draw() {
	if (isAlive == true) {
		Novice::DrawEllipse(posX_, posY_, 16, 16, 0, WHITE, kFillModeSolid);

	}
	for (int i = 0; i < 5; i++) {
		Classbullet[i]->Draw();
	}
}
//void Player:: SetBullet(Bullet* bullet) {
//	for (int i = 0; i < 5; i++) {
//		
//	}
//}