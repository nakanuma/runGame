#include "MapLoader.h"
#include "MapData.h"
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

// inputの文字列をdelimiterの文字で分割して配列にして返す
std::vector<std::string> Split(const std::string& input,char delimiter) {
	std::istringstream stream(input);
	std::string field;
	std::vector <std::string> result;

	while (std::getline(stream, field, delimiter)) {
		result.push_back(field);
	}

	return result;
}

void MapLoader::LoadMap()
{
	std::wstring directoryPath = L"./Resources/stage/";
	std::wstring filePrefix = L"map_";
	std::wstring ext = L".csv";

	const int widthPerFile = 20;
	const int heightPerFile = 12;

	// 読み込むファイルの数
	const int fileCount = MapData::kMapRow / widthPerFile;

	// 読み込むマップの数だけ
	for (int i = 0; i < fileCount; i++) {
		std::wstring filePath = directoryPath + filePrefix + std::to_wstring(i) + ext;
		std::ifstream ifs(filePath);

		// 読み込み失敗なら以下の処理を無視
		if (!ifs) {
			continue;
		}

		std::string line;
		for (int y = 0; y < heightPerFile; y++) {
			std::getline(ifs, line);
			std::vector <std::string> splitDeta = Split(line, ',');
			for (int x = 0; x < widthPerFile; x++) {
				MapData::map[y][x + i * widthPerFile] = std::stoi(splitDeta[x]);
			}
		}
	}
}
