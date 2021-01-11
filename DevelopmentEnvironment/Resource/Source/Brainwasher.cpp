#include <DxLib.h>
#include "Brainwasher.h"

#include "BulletManager.h"

//コンストラクタ
Brainwasher::Brainwasher(float _x, float _y, float _width, float _height,
	float _moveSpeed, int _hp, float _fireRate) :
	Enemy(_x, _y, _width, _height, _moveSpeed, _hp, _fireRate) {

}

//更新処理
void Brainwasher::Update(GameSystem* _gameSystem) {
	Brainwasher::Move(_gameSystem);
	Brainwasher::Shot(_gameSystem);

	if (pos.y > _gameSystem->GetGameArea().down) {
		isActive = false;
	}
}

//描画処理
void Brainwasher::Draw(GameSystem* _gameSystem) {
	DrawGraph(pos.x, pos.y, _gameSystem->GetImage()->GetGraph("Enemy_01.png"), TRUE);
}

//移動処理
void Brainwasher::Move(GameSystem* _gameSystem) {
	pos.y += moveSpeed;
}

//発射処理
void Brainwasher::Shot(GameSystem* _gameSystem) {

	if (fireCount > fireRate)fireCount = 0.0f;

	if (fireCount == fireRate) {
		_gameSystem->GetBulletManagerObj()->CreateBullet(
			pos.cx, pos.y, eBulletType::Enemy_Normal);
	}

	fireCount++;
}