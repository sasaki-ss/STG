#include "BulletManager.h"

//�R���X�g���N�^
BulletManager::BulletManager() {
	//������
	for (int i = 0; i < MAX_BULLET_NUM; i++) {
		bullets[i] = nullptr;
	}

	activeCount = 0;
}

//�f�X�g���N�^
BulletManager::~BulletManager() {
	delete[] bullets;
}

//�X�V����
void BulletManager::Update(GameSystem* _gameSystem) {
	//�폜����
	BulletManager::Destroy();
	//��������
	BulletManager::Organize();
	//�X�V����
	for (int i = 0; i < activeCount; i++) {
		//bullets[i]����łȂ��ꍇ
		if (bullets[i] != nullptr) {
			//�X�V����
			bullets[i]->Update(_gameSystem);
		}
	}
}

//�`�揈��
void BulletManager::Draw(GameSystem* _gameSystem) {
	for (int i = 0; i < activeCount; i++) {
		//bullets[i]����łȂ��ꍇ
		if (bullets[i] != nullptr) {
			//�`�揈��
			bullets[i]->Draw(_gameSystem);
		}
	}
}

//�e��������
void BulletManager::CreateBullet(float _x, float _y, eBulletType _type) {
	for (int i = 0; i < MAX_BULLET_NUM; i++) {
		//�e����̏ꍇ
		if (bullets[i] == nullptr) {
			switch (_type) {
			//�v���C���[�̒e�𐶐�
			case eBulletType::Player:
				bullets[i] = new Bullet(_x - (16 / 2), _y, 16, 16, 5);
				return;
			case eBulletType::Enemy1:
				bullets[i] = new Bullet(_x - (16 / 2), _y, 16, 16, 5);
				return;
			default:
				break;
			}
		}
	}
}

//��������
void BulletManager::Organize() {
	int organizeCount = 0;	//�����J�E���^
	activeCount = 0;

	//�A�N�e�B�u�Ȓe�̐������߂�
	for (int i = 0; i < MAX_BULLET_NUM; i++) {
		//bullets[i]����łȂ��ꍇ
		if (bullets[i] != nullptr) {
			//bullets[i]���A�N�e�B�u�ȏꍇ
			if (bullets[i]->GetIsActive()) {
				//�A�N�e�B�u�J�E���^�����Z
				activeCount++;
			}
		}
	}

	//�����̏���
	for (int i = 0; i < MAX_BULLET_NUM - 1; i++) {
		//bullets[i]����̏ꍇ
		if (bullets[i] == nullptr) {
			for (int j = i + 1; j < MAX_BULLET_NUM; j++) {
				//bullets[j]����łȂ��ꍇ
				if (bullets[j] != nullptr) {
					//����ւ�����
					Bullet* tmpBullet = bullets[i];
					bullets[i] = bullets[j];
					bullets[j] = tmpBullet;

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
void BulletManager::Destroy() {
	for (int i = 0; i < activeCount; i++) {
		//bullets[i]����łȂ��ꍇ
		if (bullets[i] != nullptr) {
			//bullets[i]���A�N�e�B�u�łȂ��ꍇ
			if (!bullets[i]->GetIsActive()) {
				delete bullets[i];
				bullets[i] = nullptr;
			}
		}
	}
}