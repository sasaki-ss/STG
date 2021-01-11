#include <DxLib.h>
#include "Enemy.h"

#include "BulletManager.h"

//�R���X�g���N�^
Enemy::Enemy(float _x, float _y, float _width, float _height,
	float _moveSpeed, int _hp, float _fireRate) {
	pos.x = _x;
	pos.y = _y;
	width = _width;
	height = _height;
	pos.cx = pos.x + (width / 2);
	pos.cy = pos.y + (height / 2);
	moveSpeed = _moveSpeed;
	isActive = true;
	hp = _hp;
	fireRate = _fireRate;
	fireCount = fireRate;
}

//�X�V����
void Enemy::Update(GameSystem* _gameSystem) {
	//���ˏ���
	Enemy::Shot(_gameSystem);

	pos.y += moveSpeed;

	if (pos.y >= 960) {
		isActive = false;
	}
}

//�`�揈��
void Enemy::Draw(GameSystem* _gameSystem) {
	DrawGraph(pos.x, pos.y, _gameSystem->GetImage()->GetGraph("Enemy.png"), TRUE);
}

//���ˏ���
void Enemy::Shot(GameSystem* _gameSystem) {
	static int count = 40;

	if (count > 40)count = 0;

	if (count == 40) {
		_gameSystem->GetBulletManagerObj()->CreateBullet(
			pos.cx, pos.y, eBulletType::Enemy_Normal);
	}

	count++;
}

void Enemy::Damage(int _damageAmount) {
	//�̗͂��_���[�W�ʕ����炷
	hp -= _damageAmount;

	//�c�0�ȉ��̏ꍇ
	if (hp <= 0) {
		isActive = false;
	}
}