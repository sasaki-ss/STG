#ifndef STG_IMAGE_H
#define STG_IMAGE_H

#include <filesystem>
#include <iostream>
#include <vector>
#include <string>
#include "Directory.h"

//�e�X�g��
//�t�@�C�����Q�Ƃ��Ď����I�ɃI�u�W�F�N�g�i�[������

//�摜�N���X
class Image final :public Directory {
private:
	std::filesystem::path path;
	std::vector<std::string> filenames;
public:
	//����������
	bool Init();

	std::filesystem::path GetPath() { return path; }
	std::string GetFileName(int i) { return filenames[i]; }
};

#endif // !STG_IMAGE_H