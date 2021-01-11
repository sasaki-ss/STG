#ifndef STG_ENEMY_H
#define STG_ENEMY_H

#include "Object.h"

//�G�l�~�[�N���X
class Enemy :public virtual Object {
protected:
	float moveSpeed;	//�ړ����x
	float fireRate;		//���ˑ��x
	float fireCount;	//���˃J�E���g
	int hp;				//�̗�

	//�ړ�����
	virtual void Move(GameSystem* _gameSystem) {}
	//���ˏ���
	virtual void Shot(GameSystem* _gameSystem);
public:
	//�R���X�g���N�^
	Enemy(float _x, float _y, float _width, float _height,
		float _moveSpeed, int _hp, float _fireRate);
	//�f�X�g���N�^
	virtual ~Enemy() {}
	//�X�V����
	virtual void Update(GameSystem* _gameSystem);
	//�`�揈��
	virtual void Draw(GameSystem* _gameSystem);
	//�_���[�W����
	void Damage(int _damageAmount);
};

#endif // !STG_ENEMY_H