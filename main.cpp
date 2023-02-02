#include <Novice.h>
#include "Player.h"
#include "Enemy.h"
#include <math.h>

const char kWindowTitle[] = "LC1B_08_コバヤシダイスケ";
int Enemy::EnemyCount;
//typedef struct Vector2 {
//	float x;
//	float y;
//};
float Distance(const Vector2& a, const Vector2& b) {
	Vector2 c = { a.x - b.x,a.y - b.y };
	return sqrtf(c.x * c.x + c.y * c.y);
}
bool CircleCollisinHit(const Vector2& a, const float aSize, const  Vector2& b, const   float bSize) {
	float c = Distance(a, b);
	float d = aSize + bSize;
	if (c <= d) {
		return true;
	}
	else {
		return false;
	}
}
// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	// キー入力結果を受け取る箱
	char keys[256] = { 0 };
	char preKeys[256] = { 0 };
	Player* player = new Player(300, 700, 4);
	Enemy* enemy[2];
	enemy[0] = new Enemy({ 300, 200 }, 4);
	enemy[1] = new Enemy({ 500, 400 }, -4);
	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///
		player->Move(keys, preKeys);
		if (Enemy::EnemyCount <1) {
			for (int i = 0; i < 2; i++) {
				enemy[i]->Move();

				for (int j = 0; j < 5; j++) {
					if (CircleCollisinHit(player->Classbullet[j]->pos_, player->Classbullet[j]->radius_, enemy[i]->pos_, enemy[i]->radius) == true) {
						delete enemy[i];
					}
				}
			}
		}
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///
		if (Enemy::EnemyCount < 1) {
			for (int i = 0; i < 2; i++) {
				enemy[i]->Draw();
			}
		}
		player->Draw();
		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}
	delete player;

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
