#ifndef STG_INGAME_H
#define STG_INGAME_H

#include "Scene.h"
#include "ISceneChanger.h"

//タイトルクラス
class InGame :public Scene {
public:
	InGame(ISceneChanger* _sceneChanger, ShareParameter* _shareParameter);
	//更新処理
	void Update();
	//描画処理
	void Draw();
};

#endif // !STG_INGAME_H