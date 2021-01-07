#ifndef STG_BULLET_H
#define STG_BULLET_H

#include <string>
#include "Object.h"

using namespace std;

class Bullet :public virtual Object {
protected:
	float moveSpeed;	//移動速度
	string tag;			//タグ
public:
	//コンストラクタ
	Bullet(float _x, float _y, float _width, float _height,
		float _moveSpeed, string _tag);
	//更新処理
	virtual void Update(GameSystem* _gameSystem);
	//描画処理
	virtual void Draw(GameSystem* _gameSystem);
	//タグを取得する
	string GetTag() { return tag; }
	//アクティブフラグをセットする
	void SetIsActive(bool _isActive) { isActive = _isActive; }
};

#endif // !STG_BULLET_H