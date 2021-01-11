#include <string.h>
#include "GameManager.h"

#include "Player.h"
#include "EnemyManager.h"
#include "BulletManager.h"

using namespace std;

GameManager::GameManager() {
	//����������
	GameManager::Init();
}

void GameManager::Init() {
	//����������
	isGameOver = false;
}

//�X�V����
void GameManager::Update(GameSystem* _gameSystem) {
	/*�����ɂ��ׂĂ̍��W�A�����A�����A�^�O���擾*/

	//�v���C���[��x���W
	float px = _gameSystem->GetPlayerObj()->GetPos().x;
	//�v���C���[��y���W
	float py = _gameSystem->GetPlayerObj()->GetPos().y;
	//�v���C���[�̉���
	float pw = _gameSystem->GetPlayerObj()->GetWidth();
	//�v���C���[�̍���
	float ph = _gameSystem->GetPlayerObj()->GetHeight();

	float ex[100] = { 0.0f };	//�G�l�~�[��x���W
	float ey[100] = { 0.0f };	//�G�l�~�[��y���W
	float ew[100] = { 0.0f };	//�G�l�~�[�̉���
	float eh[100] = { 0.0f };	//�G�l�~�[�̍���

	float bx[1000] = { 0.0f };		//�e��x���W
	float by[1000] = { 0.0f };		//�e��y���W
	float bw[1000] = { 0.0f };		//�e�̉���
	float bh[1000] = { 0.0f };		//�e�̍���
	string bulletTag[1000] = {""};	//�e�̃^�O

	//�G�l�~�[�̃A�N�e�B�u�Ȑ�
	int eActCount = _gameSystem->GetEnemyManagerObj()->GetActiveCount();
	//�e�̃A�N�e�B�u�Ȑ�
	int bActCount = _gameSystem->GetBulletManagerObj()->GetActiveCount();

	//�G�l�~�[�̍��W�A�����A�������擾����
	for (int i = 0; i < eActCount; i++) {
		ex[i] = _gameSystem->GetEnemyManagerObj()->GetPos(i).x;
		ey[i] = _gameSystem->GetEnemyManagerObj()->GetPos(i).y;
		ew[i] = _gameSystem->GetEnemyManagerObj()->GetWidth(i);
		eh[i] = _gameSystem->GetEnemyManagerObj()->GetHeight(i);
	}

	//�e�̍��W�A�����A�����A�^�O���擾����
	for (int i = 0; i < bActCount; i++) {
		bx[i] = _gameSystem->GetBulletManagerObj()->GetPos(i).x;
		by[i] = _gameSystem->GetBulletManagerObj()->GetPos(i).y;
		bw[i] = _gameSystem->GetBulletManagerObj()->GetWidth(i);
		bh[i] = _gameSystem->GetBulletManagerObj()->GetHeight(i);
		bulletTag[i] = _gameSystem->GetBulletManagerObj()->GetTag(i);
	}

	//�v���C���[�̔��˂����e�ƓG�̓����蔻��
	//�G�̔��˂����e�ƃv���C���[�̓����蔻��
	for (int i = 0; i < bActCount; i++) {

		//�G�l�~�[�̒e���v���C���[�����G��Ԃ̏ꍇ�����蔻����s��Ȃ�
		if (bulletTag[i] == "Enemy" &&
			_gameSystem->GetPlayerObj()->GetIsInvincible())continue;

		//�������e�̃^�O��������ꍇswitch���ɕύX����

		//�v���C���[�̒e�ƃG�l�~�[�̓����蔻��
		if (bulletTag[i] == "Player") {
			for (int j = 0; j < eActCount; j++) {
				if (GameManager::CollisionSqare(
					bx[i], by[i], bw[i], bh[i], ex[j], ey[j], ew[j], eh[j])) {
					//�G�l�~�[�Ƀ_���[�W��^����
					_gameSystem->GetEnemyManagerObj()->Damage(j, 50);

					//���������e���A�N�e�B�u��������
					_gameSystem->GetBulletManagerObj()->SetIsActive(i, false);
					break;
				}
			}
		}
		//�G�l�~�[�̒e�ƃv���C���[�̓����蔻��
		else {
			if (GameManager::CollisionSqare(
				bx[i], by[i], bw[i], bh[i], px, py, pw, ph)) {
				GameManager::PlayerHitProc(_gameSystem);

				//���������e���A�N�e�B�u��������
				_gameSystem->GetBulletManagerObj()->SetIsActive(i, false);
			}
		}
	}

	//�v���C���[�ƓG�̓����蔻��
	for (int i = 0; i < eActCount; i++) {

		//���G��Ԃ̏ꍇ�����蔻����s��Ȃ�
		if (_gameSystem->GetPlayerObj()->GetIsInvincible())break;

		//�������Ă��ꍇ�v���C���[�̎c������炷
		if (GameManager::CollisionSqare(
			px, py, pw, ph, ex[i], ey[i], ew[i], eh[i])) {
			GameManager::PlayerHitProc(_gameSystem);
		}
	}
}

//�l�p�`�Ǝl�p�`�̓����蔻��
bool GameManager::CollisionSqare(float _fX, float _fY, float _fW, float _fH,
	float _sX, float _sY, float _sW, float _sH) {

	//���������ꍇ
	if (_fX + _fW >= _sX && _fX <= _sX + _sW &&
		_fY + _fH >= _sY && _fY <= _sY + _sH) {
		return true;
	}

	//�������ĂȂ��ꍇ
	return false;
}

//�~�Ɖ~�̓����蔻��
bool GameManager::CollisionCircle(float _fX, float _fY, float _fR,
	float _sX, float _sY, float _sR) {

	/************************
	���������ꍇ
	(a*a)+ (b*b) = (c*c)(�O�����̒藝)
	************************/
	if (((_sX - _fX) * (_sX - _fX)) + ((_sY - _fY) * (_sY - _fY) <= (_fR + _sR) * (_fR + _sR))) {
		return true;
	}

	//�������ĂȂ��ꍇ
	return false;
}

//�v���C���[�������������̏���
void GameManager::PlayerHitProc(GameSystem* _gameSystem) {
	//�v���C���[�̎c������炷
	_gameSystem->GetPlayerObj()->Damage();

	//��������
	if (_gameSystem->GetPlayerObj()->GetIsActive() == false) {
		isGameOver = true;
	}
}