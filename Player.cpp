#include "Player.h"

Player::Player()
{
}

Player::~Player()
{
}

void Player::Update()
{
	// y座標の更新（プレイヤーの重力による落下）
	pos_.y -= static_cast<int>(velocity_.y);
	// 毎フレーム加速度を加算
	velocity_.y += accelerator_.y;
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
}
