#ifndef STG_GAMEMANAGER_H
#define STG_GAMEMANAGER_H

#include "Task.h"

class GameManager final :public Task {
private:
	bool isGameOver;	//ゲームオーバーフラグ

	//四角の当たり判定
	bool CollisionSqare(float _fX, float _fY, float _fW, float _fH,
		float _sX, float _sY, float _sW, float _sH);
	//円の当たり判定
	bool CollisionCircle(float _fX, float _fY, float _fR,
		float _sX, float _sY, float _sR);
	//プレイヤーが当たった時の処理
	void PlayerHitProc(GameSystem* _gameSystem);
public:
	//コンストラクタ
	GameManager();
	//初期化処理
	void Init();
	//更新処理
	void Update(GameSystem* _gameSystem);
	//描画処理(※Taskで純粋仮想関数にしてるため書いてます)
	void Draw(GameSystem* _gameSystem){}
	//ゲームオーバーフラグを取得する
	bool GetIsGameOver() { return isGameOver; }
};

#endif // !STG_GAMEMANAGER_H