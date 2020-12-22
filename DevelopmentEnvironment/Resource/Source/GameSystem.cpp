#include "GameSystem.h"

//コンストラクタ
GameSystem::GameSystem() {
	image = new Image();
}

//デストラクタ
GameSystem::~GameSystem() {
	delete image;
}

//初期化処理
bool GameSystem::Init() {
	//画像クラスの初期化処理
	if (!image->Init()) {
		return false;
	}

	return true;
}