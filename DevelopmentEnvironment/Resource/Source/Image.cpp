#include <DxLib.h>
#include <filesystem>
#include <iostream>
#include "Image.h"

//‰Šú‰»ˆ—
bool Image::Init() {
	path = std::filesystem::absolute("./Resource/Image");
	
	Directory::GetFileNames(path.string(), filenames);

	return true;
}