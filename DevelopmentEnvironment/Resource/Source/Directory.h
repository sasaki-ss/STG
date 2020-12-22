#ifndef STG_DIRECTORY_H
#define STH_DIRECTORY_H

#include <filesystem>
#include <iostream>
#include <vector>
#include "CloseSystem.h"

class Directory :CloseSystem {
protected:
	//指定したフォルダ内のファイル名取得処理
	bool GetFileNames(std::string _folderPath, std::vector<std::string>& _file_names);
};

#endif // !STG_DIRECTORY_H