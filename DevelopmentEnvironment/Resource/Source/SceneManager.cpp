#include <DxLib.h>
#include "SceneManager.h"

#include "Title.h"
#include "InGame.h"
#include "Menu.h"

//コンストラクタ
SceneManager::SceneManager(GameSystem* _gameSystem) {
	shareParameter = new ShareParameter();
	scenes.push(std::make_shared<InGame>(this, shareParameter, _gameSystem));
	nowScene = eScene::Title;
}

//更新処理
void SceneManager::Update() {
	//シーンの更新処理
	scenes.top()->Update();
	DrawFormatString(0, 50, GetColor(255, 255, 255), "シーンマネージャー更新中");
}

//描画処理
void SceneManager::Draw() {
	//シーンの描画処理
	scenes.top()->Draw();
	DrawFormatString(0, 100, GetColor(255, 255, 255), "シーンマネージャー描画中");
}

//シーン切り替え処理
void SceneManager::SceneChange(eScene _nextScene, ShareParameter* _parameter,
	GameSystem* _gameSystem, const bool _isStack, const bool _isBack) {
	//次のシーン情報を現在のシーン情報に格納する
	nowScene = _nextScene;

	//一つ前のシーンにする処理
	if (_isBack) {
		scenes.pop();
		return;
	}

	//scenesの中身をすべて削除する
	if (!_isStack) {
		while (!scenes.empty()) {
			scenes.pop();
		}
	}

	//シーンを新たに生成する
	switch (_nextScene) {
	//タイトルシーン
	case eScene::Title:
		scenes.push(std::make_shared<Title>(this, _parameter,_gameSystem));
		break;
	//メニューシーン
	case eScene::Menu:
		scenes.push(std::make_shared<Menu>(this, _parameter,_gameSystem));
		break;
	//インゲームシーン
	case eScene::InGame:
		scenes.push(std::make_shared<InGame>(this, _parameter, _gameSystem));
		break;
	default:
		CloseSystem::ExitSystem(eCloseType::Abnormal_Close);
		shareParameter->SetData("IS_RUN_GAME", 0);
		return;
	}
}