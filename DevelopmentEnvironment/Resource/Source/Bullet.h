#ifndef STG_BULLET_H
#define STG_BULLET_H

#include "Object.h"

class Bullet :public virtual Object {
private:
	float moveSpeed;
public:
	Bullet(float _x, float _y, float _width, float _height, float _moveSpeed);

	virtual void Update(GameSystem* _gameSystem);
	virtual void Draw(GameSystem* _gameSystem);
};

#endif // !STG_BULLET_H