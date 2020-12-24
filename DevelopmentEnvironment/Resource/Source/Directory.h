#ifndef STG_DIRECTORY_H
#define STH_DIRECTORY_H

#include <filesystem>
#include <iostream>
#include <vector>
#include "CloseSystem.h"

class Directory :CloseSystem {
private:
	//ファイルパスの\\を/に置き換える処理
	std::string ChangeFilePath(std::string _filePath);
	//ファイルパスからファイル名を抜き出す処理
	std::string ExtractFileName(std::string _filePath);
protected:
	//指定したフォルダ内のファイル名取得処理
	bool GetFileNames(std::string _folderPath, std::vector<std::string>& _file_Names,
		std::vector<std::string>& _file_Path);
};

#endif // !STG_DIRECTORY_H