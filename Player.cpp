#include "Player.h"

Player::Player()
{
}

Player::~Player()
{
}

void Player::Update()
{
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
