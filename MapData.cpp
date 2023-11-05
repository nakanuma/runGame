#include "MapData.h"

int MapData::map[kMapColumn][kMapRow];
int MapData::floorGH;
int MapData::blockGH;

void MapData::Draw()
{
	for (int i = 0; i < kMapColumn; i++) {
		for (int j = 0; j < kMapRow; j++) {
			// 床の描画
			if (map[i][j] == 1) {
				Novice::DrawSprite(
					j * kBlockSize, i * kBlockSize,
					floorGH,
					1.0f, 1.0f,
					0.0f,
					0xFFFFFFFF
				);
			}
			// ブロックの描画
			if (map[i][j] == 2) {
				Novice::DrawSprite(
					j * kBlockSize, i * kBlockSize,
					blockGH,
					1.0f, 1.0f,
					0.0f,
					0xFFFFFFFF
				);
			}
		}
	}
}

void MapData::Init()
{
	floorGH = Novice::LoadTexture("./Resources/images/floor.png");
	blockGH = Novice::LoadTexture("./Resources/images/block.png");
}
