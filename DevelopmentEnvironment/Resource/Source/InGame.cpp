#include <DxLib.h>
#include "InGame.h"

//�R���X�g���N�^
InGame::InGame(ISceneChanger* _sceneChanger, ShareParameter* _shareParameter) :
	Scene(_sceneChanger, _shareParameter) {
	//�I�u�W�F�N�g�𐶐�
	player = new Player(500, 500, 32, 64, 10);
	bulletManager = new BulletManager();
	enemyManager = new EnemyManager(0);
}

//����������
void InGame::Init(GameSystem* _gameSystem) {
	//�e�I�u�W�F�N�g���I�u�W�F�N�g�\���̂֊i�[����
	_gameSystem->SetObjectsPlayer(player);
	_gameSystem->SetObjectsBulletManager(bulletManager);
	_gameSystem->SetObjectsEnemyManager(enemyManager);
}

//�X�V����
void InGame::Update(GameSystem* _gameSystem) {
	player->Update(_gameSystem);
	bulletManager->Update(_gameSystem);
	enemyManager->Update(_gameSystem);
}

//�`�揈��
void InGame::Draw(GameSystem* _gameSystem) {
	player->Draw(_gameSystem);
	bulletManager->Draw(_gameSystem);
	enemyManager->Draw(_gameSystem);

	//�f�o�b�N�p
	DrawFormatString(1000, 0, GetColor(255, 255, 255), "bullets�̃A�N�e�B�u�� : %d",
		bulletManager->GetActiveCount());
	DrawFormatString(1000, 25, GetColor(255, 255, 255), "enemys�̃A�N�e�B�u�� : %d",
		enemyManager->GetActiveCount());
}