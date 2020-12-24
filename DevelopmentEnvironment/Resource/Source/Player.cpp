#include <DxLib.h>
#include "Player.h"

#include "BulletManager.h"

//コンストラクタ
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

//更新処理
void Player::Update(GameSystem* _gameSystem) {
	//移動処理
	Move(_gameSystem);
	//弾発射処理
	Shot(_gameSystem);

	pos.cx = pos.x + (width / 2);
	pos.cy = pos.y + (height / 2);
}

//描画処理
void Player::Draw(GameSystem* _gameSystem) {
	DrawGraph(pos.x, pos.y, _gameSystem->GetImage()->GetGraph("Player.png"), TRUE);
}

//移動処理
void Player::Move(GameSystem* _gameSystem) {
	//キー関連の処理この後実装する
	//移動制御ものちに加える

	//前進
	if (_gameSystem->GetInputManager()->GetKeyboard()->GetPressCount(
		_gameSystem->GetInputManager()->GetKey(eOperationType::Up)) != 0) {
		pos.y -= moveSpeed;
	}

	//左
	if (_gameSystem->GetInputManager()->GetKeyboard()->GetPressCount(
		_gameSystem->GetInputManager()->GetKey(eOperationType::Left)) != 0) {
		pos.x -= moveSpeed;
	}

	//後退
	if (_gameSystem->GetInputManager()->GetKeyboard()->GetPressCount(
		_gameSystem->GetInputManager()->GetKey(eOperationType::Down)) != 0) {
		pos.y += moveSpeed;
	}

	//右
	if (_gameSystem->GetInputManager()->GetKeyboard()->GetPressCount(
		_gameSystem->GetInputManager()->GetKey(eOperationType::Right)) != 0) {
		pos.x += moveSpeed;
	}
}

//弾発射処理
void Player::Shot(GameSystem* _gameSystem) {

	//弾を発射
	if (_gameSystem->GetInputManager()->GetKeyboard()->GetPressCount(
		_gameSystem->GetInputManager()->GetKey(eOperationType::Shot)) % 10 == 1) {
		//弾を生成する
		_gameSystem->GetGameObjects().bulletManager->CreateBullet(
			pos.cx, pos.y, eBulletType::Player);
	}
}