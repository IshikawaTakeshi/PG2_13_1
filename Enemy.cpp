#include "Enemy.h"
#include "Novice.h"
#define USE_MATH_DEFINES
#include <math.h>

//コンストラクタ
Enemy::Enemy(Vector2 pos, Vector2 size, float speed) {
	pos_ = pos;
	size_ = size;
	speed_ = speed;
	direction_ = { 0,0 };
	length_ = 0;
	isAlive_ = true;
}

//デストラクタ
Enemy::~Enemy() {}

//移動処理
void Enemy::Update() {
	pos_.x += speed_;
	if (pos_.x >= 1280 || pos_.x <= 0) {
		speed_ = -speed_;
	} 
}

//描画処理
void Enemy::Draw() {
	if (isAlive_ == true) {
		Novice::DrawEllipse(
			static_cast<int>(pos_.x),
			static_cast<int>(pos_.y),
			static_cast<int>(size_.x),
			static_cast<int>(size_.y),
			0.0f,
			0xffffffff,
			kFillModeSolid
		);
	}
}

//弾とエネミーの距離を測る関数
void Enemy::Length(Bullet* bullet) {
	direction_.x = pos_.x - bullet->GetPos().x;
	direction_.y = pos_.y - bullet->GetPos().y;
	length_ = sqrtf(direction_.x * direction_.x + direction_.y * direction_.y);
}

//死亡・復帰処理
void Enemy::Respawn(Bullet* bullet,char* keys, char* preKeys) {
	Length(bullet);
	if (length_ <= size_.x + bullet->GetSize().x) {
		isAlive_ = false;
	}
	if (isAlive_ == false) {
		if (keys[DIK_R] && preKeys[DIK_R] == 0) {
			isAlive_ = true;
		}
	}
}


