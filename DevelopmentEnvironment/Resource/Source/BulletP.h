#ifndef STG_BULLETP_H
#define STG_BULLETP_H

#include "Bullet.h"

class BulletP final :public Bullet {
public:
	//�R���X�g���N�^
	BulletP(float _x, float _y, float _width, float _height,
		float _moveSpeed, string _tag);
	//�X�V����
	void Update(GameSystem* _gameSystem);
	//�`�揈��
	void Draw(GameSystem* _gameSystem);
};

#endif // !STG_BULLETP_H