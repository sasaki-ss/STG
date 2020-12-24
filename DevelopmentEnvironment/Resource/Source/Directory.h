#ifndef STG_DIRECTORY_H
#define STH_DIRECTORY_H

#include <filesystem>
#include <iostream>
#include <vector>
#include "CloseSystem.h"

class Directory :CloseSystem {
private:
	//�t�@�C���p�X��\\��/�ɒu�������鏈��
	std::string ChangeFilePath(std::string _filePath);
	//�t�@�C���p�X����t�@�C�����𔲂��o������
	std::string ExtractFileName(std::string _filePath);
protected:
	//�w�肵���t�H���_���̃t�@�C�����擾����
	bool GetFileNames(std::string _folderPath, std::vector<std::string>& _file_Names,
		std::vector<std::string>& _file_Path);
};

#endif // !STG_DIRECTORY_H