#include "Bullet.h"
#include "Novice.h"

Bullet::Bullet(Vector2 pos, Vector2 size, float speed) {
	pos_ = pos;
	size_ = size;
	speed_ = speed;
	direction_ = { 0,0 };
	isShot_ = false;
}

Bullet::~Bullet() {}

void Bullet::Update() {
	pos_.y -= speed_;
	if (pos_.y <= -10) {
		isShot_ = false;
	}
}

void Bullet::Draw() {
	Novice::DrawEllipse(
		static_cast<int>(pos_.x),
		static_cast<int>(pos_.y),
		static_cast<int>(size_.x),
		static_cast<int>(size_.y),
		0.0f,
		0xff0000ff,
		kFillModeSolid
	);
}