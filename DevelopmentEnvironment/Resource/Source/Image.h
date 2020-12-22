#ifndef STG_IMAGE_H
#define STG_IMAGE_H

#include <filesystem>
#include <iostream>
#include <vector>
#include <string>
#include "Directory.h"

//テスト版
//ファイルを参照して自動的にオブジェクト格納したい

//画像クラス
class Image final :public Directory {
private:
	std::filesystem::path path;
	std::vector<std::string> filenames;
public:
	//初期化処理
	bool Init();

	std::filesystem::path GetPath() { return path; }
	std::string GetFileName(int i) { return filenames[i]; }
};

#endif // !STG_IMAGE_H