#ifndef STG_SCENE_H
#define STG_SCENE_H

#include "Task.h"
#include "ISceneChanger.h"
#include "ShareParameter.h"
#include "GameSystem.h"

//シーンクラス
class Scene : public Task, public virtual GameSystem {
protected:
	ISceneChanger* sceneChanger;	//シーン切り替えを使うための変数
	ShareParameter* shareParameter;	//データ共有クラス
public:
	//コンストラクタ
	Scene(ISceneChanger* _sceneChanger, ShareParameter* _shareParameter);
	//初期化処理
	virtual void Init() {}
	//終了処理
	virtual void Final() {}
	//更新処理
	virtual void Update() = 0;
	//描画処理
	virtual void Draw() = 0;
};

#endif // !STG_SCENE_H