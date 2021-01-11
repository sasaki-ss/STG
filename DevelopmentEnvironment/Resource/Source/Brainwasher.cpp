#include <DxLib.h>
#include "Brainwasher.h"

#include "BulletManager.h"

//�R���X�g���N�^
Brainwasher::Brainwasher(float _x, float _y, float _width, float _height,
	float _moveSpeed, int _hp, float _fireRate) :
	Enemy(_x, _y, _width, _height, _moveSpeed, _hp, _fireRate) {

}

//�X�V����
void Brainwasher::Update(GameSystem* _gameSystem) {
	Brainwasher::Move(_gameSystem);
	Brainwasher::Shot(_gameSystem);

	if (pos.y > _gameSystem->GetGameArea().down) {
		isActive = false;
	}
}

//�`�揈��
void Brainwasher::Draw(GameSystem* _gameSystem) {
	DrawGraph(pos.x, pos.y, _gameSystem->GetImage()->GetGraph("Enemy_01.png"), TRUE);
}

//�ړ�����
void Brainwasher::Move(GameSystem* _gameSystem) {
	pos.y += moveSpeed;
}

//���ˏ���
void Brainwasher::Shot(GameSystem* _gameSystem) {

	if (fireCount > fireRate)fireCount = 0.0f;

	if (fireCount == fireRate) {
		_gameSystem->GetBulletManagerObj()->CreateBullet(
			pos.cx, pos.y, eBulletType::Enemy_Normal);
	}

	fireCount++;
}