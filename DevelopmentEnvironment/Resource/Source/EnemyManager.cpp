#include <DxLib.h>
#include "EnemyManager.h"

#include "Brainwasher.h"

//�R���X�g���N�^
EnemyManager::EnemyManager(int _difficulty) {
	//������
	for (int i = 0; i < MAX_ENEMY_NUM; i++) {
		enemys[i] = nullptr;
	}

	activeCount = 0;

	//enemys[0] = new Enemy(500, 0, 32, 32, 3, 100);
	enemys[0] = new Brainwasher(64, 0, 32, 32, 2.0f, 100, 120);
	enemys[1] = new Brainwasher(164, 0, 32, 32, 2.0f, 100, 120);
	enemys[2] = new Brainwasher(264, 0, 32, 32, 2.0f, 100, 120);
	enemys[3] = new Brainwasher(364, 0, 32, 32, 2.0f, 100, 120);
	enemys[4] = new Brainwasher(464, 0, 32, 32, 2.0f, 100, 120);
	enemys[5] = new Brainwasher(564, 0, 32, 32, 2.0f, 100, 120);
	enemys[6] = new Brainwasher(664, 0, 32, 32, 2.0f, 100, 120);
	enemys[7] = new Brainwasher(764, 0, 32, 32, 2.0f, 100, 120);

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

//�_���[�W����
void EnemyManager::Damage(int _num, int _damageAmount) {
	//enemys[_num]����łȂ��ꍇ
	if (enemys[_num] != nullptr) {
		enemys[_num]->Damage(_damageAmount);
	}
}

//���W���擾����
Pos EnemyManager::GetPos(int _num) {
	//enemys[_num]����łȂ��ꍇ
	if (enemys[_num] != nullptr) {
		return enemys[_num]->GetPos();
	}
}

//�������擾
float EnemyManager::GetWidth(int _num) {
	//enemys[_num]����łȂ��ꍇ
	if (enemys[_num] != nullptr) {
		return enemys[_num]->GetWidth();
	}
}

//�������擾
float EnemyManager::GetHeight(int _num) {
	//enemys[_num]����łȂ��ꍇ
	if (enemys[_num] != nullptr) {
		return enemys[_num]->GetHeight();
	}
}

//�A�N�e�B�u��Ԃ��擾����
bool EnemyManager::GetIsActive(int _num) {
	//enemys[_num]����łȂ��ꍇ
	if (enemys[_num] != nullptr) {
		return enemys[_num]->GetIsActive();
	}
}