#include "Player.h"
#include "MapData.h"

Player::Player()
{
}

Player::~Player()
{
}

void Player::Update(char* keys)
{
	// Wキーを押したかつ、地面の上にいる場合ジャンプする（初速度を与える）
	if (keys[DIK_W] && isPlayerOnGround_) {
		velocity_.y = 20.0f;
	}

	// プレイヤーが地面の上にいない場合は重力を受ける
	if (!isPlayerOnGround_) {
		velocity_.y -= accelerator_.y;
	}

	// プレイヤーのy座標の更新処理
	pos_.y -= static_cast<int>(velocity_.y);

	// プレイヤーのx座標の更新処理（デバッグ用）
	pos_.x += 4;

	// 4点のマップ座標を更新
	UpdateMapPos();

	// プレイヤーの下にブロックがある場合
	if (MapData::map[LeftBottom_.y][LeftBottom_.x] != 0 || MapData::map[RightBottom_.y][RightBottom_.x] != 0) {

		// 地面の上にいることにする
		isPlayerOnGround_ = true;

		// 埋まっている場合は押し戻す
		while (MapData::map[LeftBottom_.y][LeftBottom_.x] != 0 || MapData::map[RightBottom_.y][RightBottom_.x] != 0) {
			pos_.y--;

			// 4点のマップ座標を更新
			UpdateMapPos();
		}
		// 空中にいる場合はfalse
	} else {
		isPlayerOnGround_ = false;
	}
}

void Player::Draw()
{
	Novice::DrawSprite(
		pos_.x, pos_.y,
		gh_,
		1.0f, 1.0f,
		0.0f,
		0xFFFFFFFF
	);

	// デバッグ用（後で消す）
	Novice::ScreenPrintf(0, 0, "LeftTop[%d][%d]", LeftTop_.x, LeftTop_.y);
	Novice::ScreenPrintf(200, 0, "RightTop[%d][%d]", RightTop_.x, RightTop_.y);
	Novice::ScreenPrintf(0, 20, "LeftBottom[%d][%d]", LeftBottom_.x, LeftBottom_.y);
	Novice::ScreenPrintf(200, 20, "RightBottom[%d][%d]", RightBottom_.x, RightBottom_.y);

	Novice::ScreenPrintf(0, 60, "posX:%d posY:%d", pos_.x,pos_.y);
	Novice::ScreenPrintf(0, 80, "velocity_Y:%f", velocity_.y);
	Novice::ScreenPrintf(0, 100, "isPlayerOnGround:%d", isPlayerOnGround_);

}

void Player::UpdateMapPos()
{
	LeftTop_ = {
		pos_.x / size_,
		pos_.y / size_
	};

	RightTop_ = {
		(pos_.x + size_ - 1) / size_,
		pos_.y / size_
	};

	LeftBottom_ = {
		pos_.x / size_,
		(pos_.y + size_ - 1) / size_
	};

	RightBottom_ = {
		(pos_.x + size_ - 1) / size_,
		(pos_.y + size_ - 1) / size_
	};
}
