#ifndef STG_ENEMY_H
#define STG_ENEMY_H

#include "Object.h"

//�G�l�~�[�N���X
class Enemy :public virtual Object {
protected:
	float moveSpeed;

	//�ړ�����
	virtual void Move(GameSystem* _gameSystem) {}
	//���ˏ���
	virtual void Shot(GameSystem* _gameSystem);
public:
	//�R���X�g���N�^
	Enemy(float _x, float _y, float _width, float _height, float _moveSpeed);
	//�f�X�g���N�^
	virtual ~Enemy() {}
	//�X�V����
	virtual void Update(GameSystem* _gameSystem);
	//�`�揈��
	virtual void Draw(GameSystem* _gameSystem);
};

#endif // !STG_ENEMY_H