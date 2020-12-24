#ifndef STG_PLAYER_H
#define STG_PLAYER_H

#include "Object.h"

//※複数Playerを作る想定でObjectにvirtualをつけている
//※複数作らない場合virtualを外す
class Player :public virtual Object {
private:
	float moveSpeed;
	//移動処理
	void Move(GameSystem* _gameSystem);
	//弾発射処理
	void Shot(GameSystem* _gameSystem);
public:
	//コンストラクタ
	Player(float _x, float _y, float _width, float _height,
		float _moveSpeed);
	//更新処理
	void Update(GameSystem* _gameSystem);
	//描画処理
	void Draw(GameSystem* _gameSystem);
};

#endif // !STG_PLAYER_H