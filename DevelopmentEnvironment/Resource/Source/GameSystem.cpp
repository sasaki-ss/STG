#include <DxLib.h>
#include "GameSystem.h"

const float GameSystem::GAME_WIDTH = 1280;
const float GameSystem::GAME_HEIGHT = 960;

//�R���X�g���N�^
GameSystem::GameSystem() {
	image = new Image();
	inputManager = new InputManager();
}

//�f�X�g���N�^
GameSystem::~GameSystem() {
	delete image;
	delete inputManager;
}

//����������
bool GameSystem::Init() {
	//�摜�N���X�̏���������
	if (!image->Init()) {
		return false;
	}

	//���u��
	inputManager->SetKey(eOperationType::Up, KEY_INPUT_UP);
	inputManager->SetKey(eOperationType::Down, KEY_INPUT_DOWN);
	inputManager->SetKey(eOperationType::Left, KEY_INPUT_LEFT);
	inputManager->SetKey(eOperationType::Right, KEY_INPUT_RIGHT);
	inputManager->SetKey(eOperationType::Shot, KEY_INPUT_Z);
	inputManager->SetKey(eOperationType::Bomb, KEY_INPUT_X);

	return true;
}