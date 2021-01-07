#ifndef STG_GAMEMANAGER_H
#define STG_GAMEMANAGER_H

#include "Task.h"

class GameManager final :public Task {
private:
	bool isGameOver;	//�Q�[���I�[�o�[�t���O

	//�l�p�̓����蔻��
	bool CollisionSqare(float _fX, float _fY, float _fW, float _fH,
		float _sX, float _sY, float _sW, float _sH);
	//�~�̓����蔻��
	bool CollisionCircle(float _fX, float _fY, float _fR,
		float _sX, float _sY, float _sR);
	//�v���C���[�������������̏���
	void PlayerHitProc(GameSystem* _gameSystem);
public:
	//�R���X�g���N�^
	GameManager();
	//����������
	void Init();
	//�X�V����
	void Update(GameSystem* _gameSystem);
	//�`�揈��(��Task�ŏ������z�֐��ɂ��Ă邽�ߏ����Ă܂�)
	void Draw(GameSystem* _gameSystem){}
	//�Q�[���I�[�o�[�t���O���擾����
	bool GetIsGameOver() { return isGameOver; }
};

#endif // !STG_GAMEMANAGER_H