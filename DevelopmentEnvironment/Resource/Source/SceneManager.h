#ifndef STG_SCENEMANAGER_H
#define STG_SCENEMANAGER_H

#include <stack>
#include <memory>
#include "Task.h"
#include "ISceneChanger.h"
#include "Scene.h"
#include "SceneData.h"
#include "ShareParameter.h"
#include "CloseSystem.h"

//シーン管理クラス
class SceneManager final :public ISceneChanger, Task, CloseSystem {
private:
	eScene nowScene;	//現在のシーン
	std::stack<std::shared_ptr<Scene>> scenes;	//シーンのスタック
	ShareParameter* shareParameter;	//共有パラメータ
public:
	//コンストラクタ
	SceneManager(GameSystem* _gameSystem);
	//デストラクタ
	~SceneManager() {}
	//更新処理
	void Update(GameSystem* _gameSystem);
	//描画処理
	void Draw(GameSystem* _gameSystem);
	//シーン切り替え処理
	void SceneChange(eScene _nextScene, ShareParameter* _parameter,
		GameSystem* _gameSystem, const bool _isStack, const bool _isBack);
	//現在のシーンを取得
	eScene GetNowScene()const { return nowScene; }
	//共有パラメータのインスタンスを取得
	ShareParameter* GetParameter()const { return shareParameter; }
};

#endif // !STG_SCENEMANAGER_H