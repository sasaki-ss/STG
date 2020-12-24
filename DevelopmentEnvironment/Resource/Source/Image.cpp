#include <DxLib.h>
#include <filesystem>
#include <iostream>
#include "Image.h"

//初期化処理
bool Image::Init() {
	std::filesystem::path path;
	std::vector<std::string> fileNames;
	std::vector<std::string> filePaths;

	path = std::filesystem::absolute("./Resource/Image");
	
	Directory::GetFileNames(path.string(), fileNames, filePaths);

	for (int i = 0; i < filePaths.size(); i++) {
		if (MyLoadImage(filePaths[i], fileNames[i]) == -1) {
			return false;
		}
	}

	return true;
}

//読み込み処理
int Image::MyLoadImage(std::string _filePath, std::string _fileName) {
	//ファイルを読み込む
	int tmp = LoadGraph(_filePath.c_str());

	//エラー発生時
	if (tmp == -1) {
		return 0;
	}

	//画像を格納
	images[_fileName] = tmp;

	return tmp;
}

//画像を取得する処理
int Image::GetGraph(std::string _imageName) {
	//指定キーを取得
	auto it = images.find(_imageName);

	//指定キーの要素が存在しない場合
	if (images.end() == it) {
		return -1;
	}

	return it->second;
}