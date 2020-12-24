#include <DxLib.h>
#include "Menu.h"

//コンストラクタ
Menu::Menu(ISceneChanger* _sceneChanger, ShareParameter* _shareParameter,
	GameSystem* _gameSystem) :
	Scene(_sceneChanger, _shareParameter, _gameSystem) {

}

//更新処理
void Menu::Update() {
	DrawString(0, 150, "メニュークラスの更新処理実行中", GetColor(255, 255, 255));
}

//描画処理
void Menu::Draw() {
	DrawString(0, 200, "メニュークラスの描画処理実行中", GetColor(255, 255, 255));
}