#ifndef STG_IMAGE_H
#define STG_IMAGE_H

#include <filesystem>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include "Directory.h"

//�e�X�g��
//�t�@�C�����Q�Ƃ��Ď����I�ɃI�u�W�F�N�g�i�[������

//�摜�N���X
class Image final :public Directory {
private:
	std::map<std::string, int> images;
	//�ǂݍ��ݏ���
	int MyLoadImage(std::string _filePath, std::string _fileName);
public:
	//����������
	bool Init();
	//�摜���擾���鏈��
	int GetGraph(std::string _imageName);
};

#endif // !STG_IMAGE_H