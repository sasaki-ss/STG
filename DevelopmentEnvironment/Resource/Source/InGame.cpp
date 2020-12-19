#include <DxLib.h>
#include "InGame.h"

//コンストラクタ
InGame::InGame(ISceneChanger* _sceneChanger, ShareParameter* _shareParameter) :
	Scene(_sceneChanger, _shareParameter) {

}

//更新処理
void InGame::Update() {
	DrawString(0, 150, "インゲームクラスの更新処理実行中", GetColor(255, 255, 255));
}

//描画処理
void InGame::Draw() {
	DrawString(0, 200, "インゲームクラスの描画処理実行中", GetColor(255, 255, 255));
}