#include <DxLib.h>
#include "Title.h"

//コンストラクタ
Title::Title(ISceneChanger* _sceneChanger, ShareParameter* _shareParameter,
	GameSystem* _gameSystem) :
	Scene(_sceneChanger, _shareParameter, _gameSystem) {

}

//更新処理
void Title::Update() {
	//スペースキーを入力した際に実行
	if (CheckHitKey(KEY_INPUT_SPACE) != 0) {
		sceneChanger->SceneChange(eScene::InGame, shareParameter, gameSystem, true, false);
	}

	if (CheckHitKey(KEY_INPUT_W) != 0) {
		sceneChanger->SceneChange(eScene::Menu, shareParameter, gameSystem, true, false);
	}

	DrawString(0, 150, "タイトルクラスの更新処理実行中", GetColor(255, 255, 255));
}

//描画処理
void Title::Draw() {
	DrawString(0, 200, "タイトルクラスの描画処理実行中", GetColor(255, 255, 255));

	//DrawGraph(0, 0, gameSystem.GetImage()->GetImage("Image_001.png"),TRUE);
	DrawGraph(0, 0, gameSystem->GetImage()->GetGraph("Image_02.png"), TRUE);

}