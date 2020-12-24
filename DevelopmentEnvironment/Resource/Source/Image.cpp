#include <DxLib.h>
#include <filesystem>
#include <iostream>
#include "Image.h"

//����������
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

//�ǂݍ��ݏ���
int Image::MyLoadImage(std::string _filePath, std::string _fileName) {
	//�t�@�C����ǂݍ���
	int tmp = LoadGraph(_filePath.c_str());

	//�G���[������
	if (tmp == -1) {
		return 0;
	}

	//�摜���i�[
	images[_fileName] = tmp;

	return tmp;
}

//�摜���擾���鏈��
int Image::GetGraph(std::string _imageName) {
	//�w��L�[���擾
	auto it = images.find(_imageName);

	//�w��L�[�̗v�f�����݂��Ȃ��ꍇ
	if (images.end() == it) {
		return -1;
	}

	return it->second;
}