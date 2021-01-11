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
	//ゲーム画面の座標構造体
	typedef struct {
		int left;	//左端
		int right;	//右端
		int up;		//上端
		int down;	//下端
	}GameArea;

	static const int WINDOW_WIDTH = 1280;	//ウィンドウの横幅
	static const int WINDOW_HEIGHT = 960;	//ウィンドウの高さ
	static const int GAME_WIDTH = 768;		//ゲーム画面の横幅
	static const int GAME_HEIGHT = 896;		//ゲーム画面の高さ

	const GameArea gameArea = { 64,832,32,928 };	//ゲーム画面の座標

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
	//ゲーム画面の座標を取得する
	GameArea GetGameArea()const { return gameArea; }
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