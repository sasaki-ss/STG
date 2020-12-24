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
}

//�X�V����
void Player::Update(GameSystem* _gameSystem) {
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
	//�L�[�֘A�̏������̌��������
	//�ړ�������̂��ɉ�����

	//�O�i
	if (_gameSystem->GetInputManager()->GetKeyboard()->GetPressCount(
		_gameSystem->GetInputManager()->GetKey(eOperationType::Up)) != 0) {
		pos.y -= moveSpeed;
	}

	//��
	if (_gameSystem->GetInputManager()->GetKeyboard()->GetPressCount(
		_gameSystem->GetInputManager()->GetKey(eOperationType::Left)) != 0) {
		pos.x -= moveSpeed;
	}

	//���
	if (_gameSystem->GetInputManager()->GetKeyboard()->GetPressCount(
		_gameSystem->GetInputManager()->GetKey(eOperationType::Down)) != 0) {
		pos.y += moveSpeed;
	}

	//�E
	if (_gameSystem->GetInputManager()->GetKeyboard()->GetPressCount(
		_gameSystem->GetInputManager()->GetKey(eOperationType::Right)) != 0) {
		pos.x += moveSpeed;
	}
}

//�e���ˏ���
void Player::Shot(GameSystem* _gameSystem) {

	//�e�𔭎�
	if (_gameSystem->GetInputManager()->GetKeyboard()->GetPressCount(
		_gameSystem->GetInputManager()->GetKey(eOperationType::Shot)) % 10 == 1) {
		//�e�𐶐�����
		_gameSystem->GetGameObjects().bulletManager->CreateBullet(
			pos.cx, pos.y, eBulletType::Player);
	}
}