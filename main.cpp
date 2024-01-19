#include <Novice.h>
#include "Player.h"
#include "Enemy.h"

const char kWindowTitle[] = "LC1B_02_イシカワタケシ_PG2_13_1";

bool Enemy::isAlive_;

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	Player* player = new Player({ 640.0f,360.0f }, { 32.0f,32.0f }, 8.0f);

	Enemy* enemy1 = new Enemy({ 100.0f,100.0f }, { 32.0f,32.0f }, 8.0f);
	Enemy* enemy2 = new Enemy({ 200.0f,150.0f }, { 32.0f,32.0f }, 8.0f);
	Enemy* enemy3 = new Enemy({ 300.0f,200.0f }, { 32.0f,32.0f }, 8.0f);


	// キー入力結果を受け取る箱
	char keys[256] = { 0 };
	char preKeys[256] = { 0 };

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

		player->Update(keys, preKeys);
		enemy1->Update();
		enemy2->Update();
		enemy3->Update();
		for (int i = 0; i < 10; i++) {
			enemy1->Respawn(player->GetBullet(i), keys, preKeys);
			enemy2->Respawn(player->GetBullet(i), keys, preKeys);
			enemy3->Respawn(player->GetBullet(i), keys, preKeys);
		}

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///

		player->Draw();
		enemy1->Draw();
		enemy2->Draw();
		enemy3->Draw();

		//デバッグ用文字列
		Novice::ScreenPrintf(10, 10, "WASD:Move");
		Novice::ScreenPrintf(10, 40, "R:Respawn");
		Novice::ScreenPrintf(10, 70, "SPACE:Shoot");


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

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
