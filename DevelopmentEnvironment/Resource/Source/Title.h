#ifndef STG_TITLE_H
#define STG_TITLE_H

#include "Scene.h"
#include "ISceneChanger.h"

//タイトルクラス
class Title :public Scene {
public:
	Title(ISceneChanger* _sceneChanger, ShareParameter* _shareParameter,
		GameSystem* _gameSystem);
	//更新処理
	void Update();
	//描画処理
	void Draw();
};

#endif // !STG_TITLE_H