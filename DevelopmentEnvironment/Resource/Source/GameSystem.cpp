#include "GameSystem.h"

//�R���X�g���N�^
GameSystem::GameSystem() {
	image = new Image();
}

//�f�X�g���N�^
GameSystem::~GameSystem() {
	delete image;
}

//����������
bool GameSystem::Init() {
	//�摜�N���X�̏���������
	if (!image->Init()) {
		return false;
	}

	return true;
}