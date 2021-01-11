#ifndef STG_ENEMY_H
#define STG_ENEMY_H

#include "Object.h"

//エネミークラス
class Enemy :public virtual Object {
protected:
	float moveSpeed;	//移動速度
	float fireRate;		//発射速度
	float fireCount;	//発射カウント
	int hp;				//体力

	//移動処理
	virtual void Move(GameSystem* _gameSystem) {}
	//発射処理
	virtual void Shot(GameSystem* _gameSystem);
public:
	//コンストラクタ
	Enemy(float _x, float _y, float _width, float _height,
		float _moveSpeed, int _hp, float _fireRate);
	//デストラクタ
	virtual ~Enemy() {}
	//更新処理
	virtual void Update(GameSystem* _gameSystem);
	//描画処理
	virtual void Draw(GameSystem* _gameSystem);
	//ダメージ処理
	void Damage(int _damageAmount);
};

#endif // !STG_ENEMY_H