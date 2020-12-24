#ifndef STG_PLAYER_H
#define STG_PLAYER_H

#include "Object.h"

//������Player�����z���Object��virtual�����Ă���
//���������Ȃ��ꍇvirtual���O��
class Player :public virtual Object {
private:
	float moveSpeed;
	//�ړ�����
	void Move(GameSystem* _gameSystem);
	//�e���ˏ���
	void Shot(GameSystem* _gameSystem);
public:
	//�R���X�g���N�^
	Player(float _x, float _y, float _width, float _height,
		float _moveSpeed);
	//�X�V����
	void Update(GameSystem* _gameSystem);
	//�`�揈��
	void Draw(GameSystem* _gameSystem);
};

#endif // !STG_PLAYER_H