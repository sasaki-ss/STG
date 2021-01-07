#ifndef STG_ENEMYE_NORMAL_H
#define STG_ENEMYE_NORMAL_H

#include "Bullet.h"

class BulletE_Normal final :public Bullet {
public:
	//コンストラクタ
	BulletE_Normal(float _x, float _y, float _width, float _height,
		float _moveSpeed, string _tag);
	//更新処理
	void Update(GameSystem* _gameSystem);
	//描画処理
	void Draw(GameSystem* _gameSystem);
};


#endif // !STG_ENEMYE_NORMAL_H