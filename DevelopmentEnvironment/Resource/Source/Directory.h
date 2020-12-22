#ifndef STG_DIRECTORY_H
#define STH_DIRECTORY_H

#include <filesystem>
#include <iostream>
#include <vector>
#include "CloseSystem.h"

class Directory :CloseSystem {
protected:
	//�w�肵���t�H���_���̃t�@�C�����擾����
	bool GetFileNames(std::string _folderPath, std::vector<std::string>& _file_names);
};

#endif // !STG_DIRECTORY_H