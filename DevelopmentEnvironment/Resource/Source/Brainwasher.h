#ifndef STG_BRAINWASHER_H
#define STG_BRAINWASHER_H

#include "Enemy.h"

//���]���N���X
class Brainwasher :public Enemy {
private:
	//�ړ�����
	void Move(GameSystem* _gameSystem);
	//���ˏ���
	void Shot(GameSystem* _gameSystem);
public:
	//�R���X�g���N�^
	Brainwasher(float _x, float _y, float _width, float _height,
		float _moveSpeed, int _hp, float _fireRate);
	//�f�X�g���N�^
	~Brainwasher(){}
	//�X�V����
	void Update(GameSystem* _gameSystem);
	//�`�揈��
	void Draw(GameSystem* _gameSystem);
};

#endif // !STG_BRAINWASHER_H