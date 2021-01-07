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
	static const int WINDOW_WIDTH = 1280;	//ウィンドウの横幅
	static const int WINDOW_HEIGHT = 960;	//ウィンドウの高さ
	static const float GAME_WIDTH;			//ゲーム画面の横幅
	static const float GAME_HEIGHT;			//ゲーム画面の高さ

	//リソース
	Image* image;					//画像クラス

	//入力関連
	InputManager* inputManager;		//入力管理クラス

	//ゲームオブジェクト
	BulletManager* bulletManager;
	EnemyManager* enemyManager;
	Player* player;
public:
	//コンストラクタ
	GameSystem();
	//デストラクタ
	~GameSystem();
	//初期化処理
	bool Init();

	//画面の横幅を取得
	int GetWindow_Width()const { return WINDOW_WIDTH; }
	//画面の高さを取得
	int GetWindow_Height()const { return WINDOW_HEIGHT; }
	//画像クラスを取得する
	Image* GetImage()const { return image; }
	//入力管理クラスを取得
	InputManager* GetInputManager()const { return inputManager; }
	//弾管理クラスを取得する
	BulletManager* GetBulletManagerObj()const { return bulletManager; }
	//敵管理クラスを取得
	EnemyManager* GetEnemyManagerObj()const { return enemyManager; }
	//プレイヤークラスを取得
	Player* GetPlayerObj()const { return player; }
	//弾管理クラスをセットする
	void SetBulletManagerObj(BulletManager* _bulletManager) {
		bulletManager = _bulletManager;
	}
	//敵管理クラスをセットする
	void SetEnemyManagerObj(EnemyManager* _enemyManager) {
		enemyManager = _enemyManager;
	}
	//プレイヤークラスをセットする
	void SetPlayerObj(Player* _player) { player = _player; }
};

#endif // !STG_GAMESYSTEM_H