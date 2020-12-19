#include <DxLib.h>
#include "Title.h"

//コンストラクタ
Title::Title(ISceneChanger* _sceneChanger, ShareParameter* _shareParameter) :
	Scene(_sceneChanger, _shareParameter) {

}

//更新処理
void Title::Update() {
	//スペースキーを入力した際に実行
	if (CheckHitKey(KEY_INPUT_SPACE) != 0) {
		sceneChanger->SceneChange(eScene::InGame, shareParameter, true, false);
	}

	if (CheckHitKey(KEY_INPUT_W) != 0) {
		sceneChanger->SceneChange(eScene::Menu, shareParameter, true, false);
	}

	DrawString(0, 150, "タイトルクラスの更新処理実行中", GetColor(255, 255, 255));
}

//描画処理
void Title::Draw() {
	DrawString(0, 200, "タイトルクラスの描画処理実行中", GetColor(255, 255, 255));
}