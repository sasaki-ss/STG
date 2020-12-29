#include <DxLib.h>
#include "Menu.h"

//コンストラクタ
Menu::Menu(ISceneChanger* _sceneChanger, ShareParameter* _shareParameter) :
	Scene(_sceneChanger, _shareParameter) {

}

//更新処理
void Menu::Update(GameSystem* _gameSystem) {
	DrawString(0, 150, "メニュークラスの更新処理実行中", GetColor(255, 255, 255));
}

//描画処理
void Menu::Draw(GameSystem* _gameSystem) {
	DrawString(0, 200, "メニュークラスの描画処理実行中", GetColor(255, 255, 255));
}