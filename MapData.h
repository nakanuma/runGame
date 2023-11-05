#pragma once
#include <Novice.h>

class MapData {
public:
	static void Draw();
	static void Init();

	static int floorGH;

	const static int kMapColumn = 12; // マップの高さ
	const static int kMapRow = 200; // マップの横幅

	const static int kBlockSize = 64;

	// マップの配列
	static int map[kMapColumn][kMapRow];
};
