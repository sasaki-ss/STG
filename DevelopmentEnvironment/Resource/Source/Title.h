#ifndef STG_TITLE_H
#define STG_TITLE_H

#include "Scene.h"
#include "ISceneChanger.h"

//タイトルクラス
class Title :public Scene {
public:
	Title(ISceneChanger* _sceneChanger, ShareParameter* _shareParameter);
	//初期化処理
	void Init(GameSystem* _gameSystem) {}
	//更新処理
	void Update(GameSystem* _gameSystem);
	//描画処理
	void Draw(GameSystem* _gameSystem);
};

#endif // !STG_TITLE_H