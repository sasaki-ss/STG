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
	residue = 2;
	invincibleTime = 60.0f;
	isInvincible = false;
}

//更新処理
void Player::Update(GameSystem* _gameSystem) {
	//無敵フラグがオンの場合無敵に無敵処理を行う
	if (isInvincible) {
		Invincible();
	}

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
		_gameSystem->GetBulletManagerObj()->CreateBullet(
			pos.cx, pos.y, eBulletType::Player);
	}
}

//ダメージ処理
void Player::Damage() {
	//残基を１減らす
	residue--;
	//無敵状態にする
	isInvincible = true;

	//残基が0以下の場合
	if (residue <= 0) {
		isActive = false;
	}
}

//無敵処理
void Player::Invincible() {
	static float time = 0;

	//時間が無敵時間を超えた場合無敵フラグをオフにする
	if (time >= invincibleTime)isInvincible = false;

	time++;
}