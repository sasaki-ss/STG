#ifndef STG_INGAME_H
#define STG_INGAME_H

#include "Scene.h"
#include "ISceneChanger.h"
#include "Player.h"
#include "BulletManager.h"
#include "EnemyManager.h"

//タイトルクラス
class InGame final :public Scene {
private:
	Player* player;					//プレイヤー
	BulletManager* bulletManager;	//弾管理クラス
	EnemyManager* enemyManager;		//エネミー管理クラス
public:
	//コンストラクタ
	InGame(ISceneChanger* _sceneChanger, ShareParameter* _shareParameter);
	//初期化処理
	void Init(GameSystem* _gameSystem);
	//更新処理
	void Update(GameSystem* _gameSystem);
	//描画処理
	void Draw(GameSystem* _gameSystem);
};

#endif // !STG_INGAME_H