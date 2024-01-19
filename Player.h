#pragma once
#include "Vector2.h"
#include "Bullet.h"

class Player {
public:
	Player(Vector2 pos, Vector2 size, float speed);
	void Update(char* keys, char* preKeys);
	void Draw();
	Bullet* GetBullet(int i);

private:
	Bullet* bullet_[10];
	Vector2 pos_;
	Vector2 size_;
	float speed_;
};


