#include <Novice.h>

// MyDeta //
#include "MyStruct.h"

class Player {
public:
	Player();
	~Player();

	void Update();
	void Draw();

private:
	int gh_ = Novice::LoadTexture("./Resources/images/player.png");

	int size_ = 64;

	Vector2 <int>pos_ = { size_ * 6,size_ * 6 };
	Vector2 <float>velocity_ = { 0.0f,0.0f };
	Vector2 <float>accelerator_ = { 0.0f,-1.2f };
};