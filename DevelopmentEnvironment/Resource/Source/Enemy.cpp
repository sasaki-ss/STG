#include <DxLib.h>
#include "Enemy.h"

#include "BulletManager.h"

//コンストラクタ
Enemy::Enemy(float _x, float _y, float _width, float _height, float _moveSpeed) {
	pos.x = _x;
	pos.y = _y;
	width = _width;
	height = _height;
	pos.cx = pos.x + (width / 2);
	pos.cy = pos.y + (height / 2);
	moveSpeed = _moveSpeed;
	isActive = true;
}

//更新処理
void Enemy::Update(GameSystem* _gameSystem) {
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

void Enemy::Shot(GameSystem* _gameSystem) {
	static int count = 0;

	if (count > 20)count = 0;

	if (count == 20) {
		_gameSystem->GetGameObjects().bulletManager->CreateBullet(
			pos.cx, pos.y, eBulletType::Enemy1);
	}

	count++;
}