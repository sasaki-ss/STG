#ifndef STG_IMAGE_H
#define STG_IMAGE_H

#include <filesystem>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include "Directory.h"

//テスト版
//ファイルを参照して自動的にオブジェクト格納したい

//画像クラス
class Image final :public Directory {
private:
	std::map<std::string, int> images;
	//読み込み処理
	int MyLoadImage(std::string _filePath, std::string _fileName);
public:
	//初期化処理
	bool Init();
	//画像を取得する処理
	int GetGraph(std::string _imageName);
};

#endif // !STG_IMAGE_H