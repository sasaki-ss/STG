#ifndef STG_PLAYER_H
#define STG_PLAYER_H

#include "Object.h"

//������Player�����z���Object��virtual�����Ă���
//���������Ȃ��ꍇvirtual���O��
class Player :public virtual Object {
private:
	float moveSpeed;		//�ړ����x
	int residue;			//�c��
	float invincibleTime;	//���G����
	bool isInvincible;		//���G�t���O

	//�ړ�����
	void Move(GameSystem* _gameSystem);
	//�e���ˏ���
	void Shot(GameSystem* _gameSystem);
	//���G����
	void Invincible();
public:
	//�R���X�g���N�^
	Player(float _x, float _y, float _width, float _height,
		float _moveSpeed);
	//�X�V����
	void Update(GameSystem* _gameSystem);
	//�`�揈��
	void Draw(GameSystem* _gameSystem);
	//�_���[�W����
	void Damage();
	//�c����擾����
	int GetResidue() { return residue; }
	//���G�t���O���擾����
	bool GetIsInvincible() { return isInvincible; }
};

#endif // !STG_PLAYER_H