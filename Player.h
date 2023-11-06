#include <Novice.h>

// MyDeta //
#include "MyStruct.h"

class Player {
public:
	// コンストラクタとデストラクタ
	Player();
	~Player();

	// 更新処理と描画処理
	void Update(char* keys);
	void Draw();


	// プレイヤーのマップ座標を更新する関数
	void UpdateMapPos();

private:
	// プレイヤーの画像
	int gh_ = Novice::LoadTexture("./Resources/images/player.png");

	// プレイヤーの情報
	const int size_ = 64;
	Vector2 <int>pos_ = { size_ * 6,size_ * 8 };
	Vector2 <float>velocity_ = { 0.0f,0.0f };
	Vector2 <float>accelerator_ = { 0.0f,2.0f };

	bool isPlayerOnGround_ = false;

	// プレイヤーの4点のマップ座標を取得
	Vector2 <int>LeftTop_ = {
		pos_.x / size_,
		pos_.y / size_
	};

	Vector2 <int>RightTop_ = {
		(pos_.x + size_) / size_,
		pos_.y / size_
	};

	Vector2 <int>LeftBottom_ = {
		pos_.x / size_,
		(pos_.y + size_) / size_
	};

	Vector2 <int>RightBottom_ = {
		(pos_.x + size_) / size_,
		(pos_.y + size_) / size_
	};
};