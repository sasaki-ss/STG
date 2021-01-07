#ifndef STG_PLAYER_H
#define STG_PLAYER_H

#include "Object.h"

//※複数Playerを作る想定でObjectにvirtualをつけている
//※複数作らない場合virtualを外す
class Player :public virtual Object {
private:
	float moveSpeed;		//移動速度
	int residue;			//残基
	float invincibleTime;	//無敵時間
	bool isInvincible;		//無敵フラグ

	//移動処理
	void Move(GameSystem* _gameSystem);
	//弾発射処理
	void Shot(GameSystem* _gameSystem);
	//無敵処理
	void Invincible();
public:
	//コンストラクタ
	Player(float _x, float _y, float _width, float _height,
		float _moveSpeed);
	//更新処理
	void Update(GameSystem* _gameSystem);
	//描画処理
	void Draw(GameSystem* _gameSystem);
	//ダメージ処理
	void Damage();
	//残基を取得する
	int GetResidue() { return residue; }
	//無敵フラグを取得する
	bool GetIsInvincible() { return isInvincible; }
};

#endif // !STG_PLAYER_H