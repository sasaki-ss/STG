#ifndef STG_ENEMYMANAGER_H
#define STG_ENEMYMANAGER_H

#include "Task.h"
#include "GameSystem.h"
#include "Enemy.h"

class EnemyManager final :public Task {
private:
	static const int MAX_ENEMY_NUM = 100;	//�G�l�~�[�̍ő吔
	Enemy* enemys[MAX_ENEMY_NUM];			//�G�l�~�[�N���X

	int activeCount;	//�G�l�~�[�̃A�N�e�B�u��

	//��������
	void Organize();
	//�폜����
	void Destroy();
public:
	//�R���X�g���N�^
	EnemyManager(int _difficulty);
	//�f�X�g���N�^
	~EnemyManager();
	//�X�V����
	virtual void Update(GameSystem* _gameSystem);
	//�`�揈��
	virtual void Draw(GameSystem* _gameSystem);
	//�A�N�e�B�u�Ȓe�̐����擾
	int GetActiveCount() { return activeCount; }

	//����Ȃ��q
	void Update(){}
	void Draw(){}
};

#endif // !STG_ENEMYMANAGER_H