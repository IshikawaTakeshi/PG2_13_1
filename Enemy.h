#pragma once
#include "Vector2.h"
#include "Bullet.h"

class Enemy {
public:
	Enemy(Vector2 pos, Vector2 size, float speed);
	~Enemy();
	void Update();
	void Draw();
	void Length(Bullet* bullet);
	void Respawn(Bullet* bullet,char* keys, char* preKeys);

private:
	Vector2 pos_;
	Vector2 size_;
	Vector2 direction_;
	float length_;
	float speed_;
	static bool isAlive_;
};


