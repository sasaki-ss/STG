#include <DxLib.h>
#include "InGame.h"

//�R���X�g���N�^
InGame::InGame(ISceneChanger* _sceneChanger, ShareParameter* _shareParameter) :
	Scene(_sceneChanger, _shareParameter) {
	//�I�u�W�F�N�g�𐶐�
	player = new Player(500, 500, 32, 64, 10);
	bulletManager = new BulletManager();
	enemyManager = new EnemyManager(0);
	gameManager = new GameManager();
}

//����������
void InGame::Init(GameSystem* _gameSystem) {
	//�e�I�u�W�F�N�g���Q�[���V�X�e���ɓo�^����
	_gameSystem->SetBulletManagerObj(bulletManager);
	_gameSystem->SetEnemyManagerObj(enemyManager);
	_gameSystem->SetPlayerObj(player);
}

//�X�V����
void InGame::Update(GameSystem* _gameSystem) {
	//�Q�[�����s���̏���
	if (!gameManager->GetIsGameOver()) {
		player->Update(_gameSystem);
		bulletManager->Update(_gameSystem);
		enemyManager->Update(_gameSystem);

		gameManager->Update(_gameSystem);
	}
	//�Q�[���I�[�o�[���̏���
	else {
	}
}

//�`�揈��
void InGame::Draw(GameSystem* _gameSystem) {
	//�w�i�̕`��
	buckground.Draw(_gameSystem);

	//UI�̕`��
	ui.Draw(_gameSystem);

	//�Q�[�����s���̏���
	if (!gameManager->GetIsGameOver()) {
		bulletManager->Draw(_gameSystem);
		player->Draw(_gameSystem);
		enemyManager->Draw(_gameSystem);
	}
	//�Q�[���I�[�o�[���̏���
	else {
		DrawString(300, 300, "GAME OVER", GetColor(255, 255, 255));
	}

	//�Q�[����ʂ̘g�g�݂�\��
	DrawGraph(0, 0, _gameSystem->GetImage()->GetGraph("InGame_Front_BG.png"), TRUE);


	//�f�o�b�N�p
	DrawFormatString(1000, 0, GetColor(255, 255, 255), "player�̎c��@�@�@�@  : %d",
		player->GetResidue());
	DrawFormatString(1000, 25, GetColor(255, 255, 255), "bullets�̃A�N�e�B�u�� : %d",
		bulletManager->GetActiveCount());
	DrawFormatString(1000, 50, GetColor(255, 255, 255), "enemys�̃A�N�e�B�u���@: %d",
		enemyManager->GetActiveCount());
}