#include <DxLib.h>
#include "InGame.h"

//�R���X�g���N�^
InGame::InGame(ISceneChanger* _sceneChanger, ShareParameter* _shareParameter,
	GameSystem* _gameSystem) :
	Scene(_sceneChanger, _shareParameter, _gameSystem) {
	//�I�u�W�F�N�g�𐶐�
	player = new Player(500, 500, 32, 64, 10);
	bulletManager = new BulletManager();
	enemyManager = new EnemyManager(0);

	//�e�I�u�W�F�N�g���I�u�W�F�N�g�\���̂֊i�[����
	gameSystem->SetObjectsPlayer(player);
	gameSystem->SetObjectsBulletManager(bulletManager);
	gameSystem->SetObjectsEnemyManager(enemyManager);
}

//�X�V����
void InGame::Update() {
	player->Update(gameSystem);
	bulletManager->Update(gameSystem);
	enemyManager->Update(gameSystem);
}

//�`�揈��
void InGame::Draw() {
	player->Draw(gameSystem);
	bulletManager->Draw(gameSystem);
	enemyManager->Draw(gameSystem);

	//�f�o�b�N�p
	DrawFormatString(1000, 0, GetColor(255, 255, 255), "bullets�̃A�N�e�B�u�� : %d",
		bulletManager->GetActiveCount());
	DrawFormatString(1000, 25, GetColor(255, 255, 255), "enemys�̃A�N�e�B�u�� : %d",
		enemyManager->GetActiveCount());
}