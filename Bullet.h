#pragma once
#include "Vector2.h"


class Bullet {
public:
	Bullet(Vector2 pos, Vector2 size, float speed);
	~Bullet();
	void Update();
	void Draw();

	Vector2 GetPos() { return pos_; }
	void SetPos(Vector2 pos) { pos_ = pos; }
	Vector2 GetSize() { return size_; }
	bool GetIsShot() { return isShot_; }
	void SetIsShot(bool isShot) { isShot_ = isShot; }

private:
	Vector2 pos_;
	Vector2 size_;
	Vector2 direction_;
	float speed_;
	bool isShot_;
};

