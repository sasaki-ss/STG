#ifndef STG_MENU_H
#define STG_MENU_H

#include "Scene.h"
#include "ISceneChanger.h"

//タイトルクラス
class Menu :public Scene {
public:
	Menu(ISceneChanger* _sceneChanger, ShareParameter* _shareParameter);
	//更新処理
	void Update();
	//描画処理
	void Draw();
};

#endif // !STG_MENU_H