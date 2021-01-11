#ifndef STG_BRAINWASHER_H
#define STG_BRAINWASHER_H

#include "Enemy.h"

//洗脳兵クラス
class Brainwasher :public Enemy {
private:
	//移動処理
	void Move(GameSystem* _gameSystem);
	//発射処理
	void Shot(GameSystem* _gameSystem);
public:
	//コンストラクタ
	Brainwasher(float _x, float _y, float _width, float _height,
		float _moveSpeed, int _hp, float _fireRate);
	//デストラクタ
	~Brainwasher(){}
	//更新処理
	void Update(GameSystem* _gameSystem);
	//描画処理
	void Draw(GameSystem* _gameSystem);
};

#endif // !STG_BRAINWASHER_H