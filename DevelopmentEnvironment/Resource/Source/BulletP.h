#ifndef STG_BULLETP_H
#define STG_BULLETP_H

#include "Bullet.h"

class BulletP final :public Bullet {
public:
	//コンストラクタ
	BulletP(float _x, float _y, float _width, float _height,
		float _moveSpeed, string _tag);
	//更新処理
	void Update(GameSystem* _gameSystem);
	//描画処理
	void Draw(GameSystem* _gameSystem);
};

#endif // !STG_BULLETP_H