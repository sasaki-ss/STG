#ifndef STG_GAMESYSTEM_H
#define STG_GAMESYSTEM_H

#include "Image.h"
#include "InputManager.h"

//ゲームオブジェクト
class BulletManager;
class EnemyManager;
class Player;

//ゲームシステムクラス
class GameSystem {
private:
	static const int GAME_WIDTH = 1280;
	static const int GAME_HEIGHT = 960;
	typedef struct {
		BulletManager* bulletManager;
		EnemyManager* enemyManager;
		Player* player;
	}GameObjects;

	Image* image;					//画像クラス
	InputManager* inputManager;		//入力管理クラス

	GameObjects gameObjects;	//ゲームオブジェクト
public:
	//コンストラクタ
	GameSystem();
	//デストラクタ
	~GameSystem();
	//初期化処理
	bool Init();

	//画像クラスを取得する
	Image* GetImage() { return image; }
	//入力管理クラスを取得
	InputManager* GetInputManager() { return inputManager; }
	//ゲームオブジェクト構造体を取得する
	GameObjects GetGameObjects() { return gameObjects; }
	//プレイヤーをゲームオブジェクト構造体に格納する
	void SetObjectsPlayer(Player* _player) { gameObjects.player = _player; }
	//弾管理クラスをゲームオブジェクト構造体に格納する
	void SetObjectsBulletManager(BulletManager* _bulletMangaer){
		gameObjects.bulletManager = _bulletMangaer;
	}
	//エネミー管理クラスをゲームオブジェクト構造体に格納する
	void SetObjectsEnemyManager(EnemyManager* _enemyManager) {
		gameObjects.enemyManager = _enemyManager;
	}
};

#endif // !STG_GAMESYSTEM_H