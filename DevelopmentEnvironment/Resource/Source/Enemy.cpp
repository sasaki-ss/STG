#include <DxLib.h>
#include "Enemy.h"

#include "BulletManager.h"

//コンストラクタ
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

//更新処理
void Enemy::Update(GameSystem* _gameSystem) {
	//発射処理
	Enemy::Shot(_gameSystem);

	pos.y += moveSpeed;

	if (pos.y >= 960) {
		isActive = false;
	}
}

//描画処理
void Enemy::Draw(GameSystem* _gameSystem) {
	DrawGraph(pos.x, pos.y, _gameSystem->GetImage()->GetGraph("Enemy.png"), TRUE);
}

//発射処理
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
	//体力をダメージ量分減らす
	hp -= _damageAmount;

	//残基が0以下の場合
	if (hp <= 0) {
		isActive = false;
	}
}