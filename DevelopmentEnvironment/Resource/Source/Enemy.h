#ifndef STG_ENEMY_H
#define STG_ENEMY_H

#include "Object.h"

//エネミークラス
class Enemy :public virtual Object {
protected:
	float moveSpeed;

	//移動処理
	virtual void Move(GameSystem* _gameSystem) {}
	//発射処理
	virtual void Shot(GameSystem* _gameSystem);
public:
	//コンストラクタ
	Enemy(float _x, float _y, float _width, float _height, float _moveSpeed);
	//デストラクタ
	virtual ~Enemy() {}
	//更新処理
	virtual void Update(GameSystem* _gameSystem);
	//描画処理
	virtual void Draw(GameSystem* _gameSystem);
};

#endif // !STG_ENEMY_H