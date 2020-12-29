#include "EnemyManager.h"

//�R���X�g���N�^
EnemyManager::EnemyManager(int _difficulty) {
	//������
	for (int i = 0; i < MAX_ENEMY_NUM; i++) {
		enemys[i] = nullptr;
	}

	activeCount = 0;

	enemys[0] = new Enemy(500, 0, 32, 32, 3);
	activeCount++;
}

//�f�X�g���N�^
EnemyManager::~EnemyManager() {
	delete[] enemys;
}

//�X�V����
void EnemyManager::Update(GameSystem* _gameSystem) {
	//�폜����
	EnemyManager::Destroy();
	//��������
	EnemyManager::Organize();

	//�X�V����
	for (int i = 0; i < activeCount; i++) {
		//enemys[i]����łȂ��ꍇ
		if (enemys[i] != nullptr) {
			//�X�V����
			enemys[i]->Update(_gameSystem);
		}
	}
}

//�`�揈��
void EnemyManager::Draw(GameSystem* _gameSystem) {
	for (int i = 0; i < activeCount; i++) {
		//enemys[i]����łȂ��ꍇ
		if (enemys[i] != nullptr) {
			//�`�揈��
			enemys[i]->Draw(_gameSystem);
		}
	}
}

//��������
void EnemyManager::Organize() {
	int organizeCount = 0;	//�����J�E���^
	activeCount = 0;

	//�A�N�e�B�u�Ȓe�̐������߂�
	for (int i = 0; i < MAX_ENEMY_NUM; i++) {
		//enemys[i]����łȂ��ꍇ
		if (enemys[i] != nullptr) {
			//enemys[i]���A�N�e�B�u�ȏꍇ
			if (enemys[i]->GetIsActive()) {
				//�A�N�e�B�u�J�E���^�����Z
				activeCount++;
			}
		}
	}

	//�����̏���
	for (int i = 0; i < MAX_ENEMY_NUM - 1; i++) {
		//enemys[i]����̏ꍇ
		if (enemys[i] == nullptr) {
			for (int j = i + 1; j < MAX_ENEMY_NUM; j++) {
				//enemys[j]����łȂ��ꍇ
				if (enemys[j] != nullptr) {
					//����ւ�����
					Enemy* tmpEnemy = enemys[i];
					enemys[i] = enemys[j];
					enemys[j] = tmpEnemy;

					//�����J�E���^�����Z
					organizeCount++;
					break;
				}
			}

			//�A�N�e�B�u�J�E���^�̐��܂Ő��������烋�[�v�𔲂���
			if (organizeCount == activeCount)break;
		}
	}
}

//�폜����
void EnemyManager::Destroy() {
	for (int i = 0; i < activeCount; i++) {
		//enemys[i]����łȂ��ꍇ
		if (enemys[i] != nullptr) {
			//enemys[i]���A�N�e�B�u�łȂ��ꍇ
			if (!enemys[i]->GetIsActive()) {
				delete enemys[i];
				enemys[i] = nullptr;
			}
		}
	}
}