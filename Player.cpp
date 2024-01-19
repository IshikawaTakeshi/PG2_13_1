#include "Player.h"
#include "Novice.h"


Player::Player(Vector2 pos, Vector2 size, float speed) {
	pos_ = pos;
	size_ = size;
	speed_ = speed;
	for (int i = 0; i < 10; i++) {
		bullet_[i] = new Bullet({ -20.0f,-20.0f }, { 8.0f,8.0f }, 8.0f);
	}
}

void Player::Update(char* keys, char* preKeys) {
	//移動
	if (keys[DIK_W]) {
		pos_.y -= speed_;
	}
	if (keys[DIK_S]) {
		pos_.y += speed_;
	}
	if (keys[DIK_A]) {
		pos_.x -= speed_;
	}
	if (keys[DIK_D]) {
		pos_.x += speed_;
	}

	//射撃
	for (int i = 0; i < 10; i++) {
		bullet_[i]->Update();
	}

	if (keys[DIK_SPACE] && preKeys[DIK_SPACE] == 0) {
		for (int i = 0; i < 10; i++) {
			if (bullet_[i]->GetIsShot() == false) {
				bullet_[i]->SetPos({ pos_.x,pos_.y });
				bullet_[i]->SetIsShot(true);
				break;
			}
		}
	}
}

void Player::Draw() {
	//弾の描画
	for (int i = 0; i < 10; i++) {
		bullet_[i]->Draw();
	}
	//プレイヤーの描画
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

Bullet* Player::GetBullet(int i) {
		return bullet_[i];
}


