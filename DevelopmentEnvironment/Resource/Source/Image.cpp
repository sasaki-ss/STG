#include <DxLib.h>
#include <filesystem>
#include <iostream>
#include "Image.h"

//初期化処理
bool Image::Init() {
	path = std::filesystem::absolute("./Resource/Image");
	
	Directory::GetFileNames(path.string(), filenames);

	return true;
}