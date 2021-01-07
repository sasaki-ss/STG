#include <DxLib.h>
#include "GameSystem.h"

const float GameSystem::GAME_WIDTH = 1280;
const float GameSystem::GAME_HEIGHT = 960;

//コンストラクタ
GameSystem::GameSystem() {
	image = new Image();
	inputManager = new InputManager();
}

//デストラクタ
GameSystem::~GameSystem() {
	delete image;
	delete inputManager;
}

//初期化処理
bool GameSystem::Init() {
	//画像クラスの初期化処理
	if (!image->Init()) {
		return false;
	}

	//仮置き
	inputManager->SetKey(eOperationType::Up, KEY_INPUT_UP);
	inputManager->SetKey(eOperationType::Down, KEY_INPUT_DOWN);
	inputManager->SetKey(eOperationType::Left, KEY_INPUT_LEFT);
	inputManager->SetKey(eOperationType::Right, KEY_INPUT_RIGHT);
	inputManager->SetKey(eOperationType::Shot, KEY_INPUT_Z);
	inputManager->SetKey(eOperationType::Bomb, KEY_INPUT_X);

	return true;
}