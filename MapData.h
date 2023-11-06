#pragma once
#include <Novice.h>

class MapData {
public:

	enum BlockType {
		NONE,
		FLOOR,
		BLOCK,
	};

	static void Draw();
	static void Init();

	static int floorGH;
	static int blockGH;

	const static int kMapColumn = 12; // マップの高さ
	const static int kMapRow = 200; // マップの横幅

	const static int kBlockSize = 64;

	// マップの配列
	static int map[kMapColumn][kMapRow];
};
