#include <DxLib.h>
#include "Player.h"

#include "BulletManager.h"

//�R���X�g���N�^
Player::Player(float _x, float _y, float _width, float _height,
	float _moveSpeed) {
	pos.x = _x;
	pos.y = _y;
	width = _width;
	height = _height;
	pos.cx = pos.x + (width / 2);
	pos.cy = pos.y + (height / 2);
	moveSpeed = _moveSpeed;
	isActive = true;
	residue = 2;
	invincibleTime = 60.0f;
	isInvincible = false;
}

//�X�V����
void Player::Update(GameSystem* _gameSystem) {
	//���G�t���O���I���̏ꍇ���G�ɖ��G�������s��
	if (isInvincible) {
		Invincible();
	}

	//�ړ�����
	Move(_gameSystem);
	//�e���ˏ���
	Shot(_gameSystem);

	pos.cx = pos.x + (width / 2);
	pos.cy = pos.y + (height / 2);
}

//�`�揈��
void Player::Draw(GameSystem* _gameSystem) {
	DrawGraph(pos.x, pos.y, _gameSystem->GetImage()->GetGraph("Player.png"), TRUE);
}

//�ړ�����
void Player::Move(GameSystem* _gameSystem) {

	//�O�i
	if (_gameSystem->GetInputManager()->GetKeyboard()->GetPressCount(
		_gameSystem->GetInputManager()->GetKey(eOperationType::Up)) != 0) {
		pos.y -= moveSpeed;

		//�ړ�����
		if (pos.y < _gameSystem->GetGameArea().up) {
			pos.y = _gameSystem->GetGameArea().up;
		}
	}

	//��
	if (_gameSystem->GetInputManager()->GetKeyboard()->GetPressCount(
		_gameSystem->GetInputManager()->GetKey(eOperationType::Left)) != 0) {
		pos.x -= moveSpeed;

		//�ړ�����
		if (pos.x < _gameSystem->GetGameArea().left) {
			pos.x = _gameSystem->GetGameArea().left;
		}
	}

	//���
	if (_gameSystem->GetInputManager()->GetKeyboard()->GetPressCount(
		_gameSystem->GetInputManager()->GetKey(eOperationType::Down)) != 0) {
		pos.y += moveSpeed;

		//�ړ�����
		if (pos.y + height > _gameSystem->GetGameArea().down) {
			pos.y = _gameSystem->GetGameArea().down - height;
		}
	}

	//�E
	if (_gameSystem->GetInputManager()->GetKeyboard()->GetPressCount(
		_gameSystem->GetInputManager()->GetKey(eOperationType::Right)) != 0) {
		pos.x += moveSpeed;

		//�ړ�����
		if (pos.x + width > _gameSystem->GetGameArea().right) {
			pos.x = _gameSystem->GetGameArea().right - width;
		}
	}
}

//�e���ˏ���
void Player::Shot(GameSystem* _gameSystem) {

	//�e�𔭎�
	if (_gameSystem->GetInputManager()->GetKeyboard()->GetPressCount(
		_gameSystem->GetInputManager()->GetKey(eOperationType::Shot)) % 10 == 1) {
		//�e�𐶐�����
		_gameSystem->GetBulletManagerObj()->CreateBullet(
			pos.cx, pos.y, eBulletType::Player);
	}
}

//�_���[�W����
void Player::Damage() {
	//�c����P���炷
	residue--;
	//���G��Ԃɂ���
	isInvincible = true;

	//�c�0�ȉ��̏ꍇ
	if (residue <= 0) {
		isActive = false;
	}
}

//���G����
void Player::Invincible() {
	static float time = 0;

	//���Ԃ����G���Ԃ𒴂����ꍇ���G�t���O���I�t�ɂ���
	if (time >= invincibleTime)isInvincible = false;

	time++;
}