#include <string.h>
#include "GameManager.h"

#include "Player.h"
#include "EnemyManager.h"
#include "BulletManager.h"

using namespace std;

GameManager::GameManager() {
	//初期化処理
	GameManager::Init();
}

void GameManager::Init() {
	//初期化処理
	isGameOver = false;
}

//更新処理
void GameManager::Update(GameSystem* _gameSystem) {
	/*さきにすべての座標、横幅、高さ、タグを取得*/

	//プレイヤーのx座標
	float px = _gameSystem->GetPlayerObj()->GetPos().x;
	//プレイヤーのy座標
	float py = _gameSystem->GetPlayerObj()->GetPos().y;
	//プレイヤーの横幅
	float pw = _gameSystem->GetPlayerObj()->GetWidth();
	//プレイヤーの高さ
	float ph = _gameSystem->GetPlayerObj()->GetHeight();

	float ex[100] = { 0.0f };	//エネミーのx座標
	float ey[100] = { 0.0f };	//エネミーのy座標
	float ew[100] = { 0.0f };	//エネミーの横幅
	float eh[100] = { 0.0f };	//エネミーの高さ

	float bx[1000] = { 0.0f };		//弾のx座標
	float by[1000] = { 0.0f };		//弾のy座標
	float bw[1000] = { 0.0f };		//弾の横幅
	float bh[1000] = { 0.0f };		//弾の高さ
	string bulletTag[1000] = {""};	//弾のタグ

	//エネミーのアクティブな数
	int eActCount = _gameSystem->GetEnemyManagerObj()->GetActiveCount();
	//弾のアクティブな数
	int bActCount = _gameSystem->GetBulletManagerObj()->GetActiveCount();

	//エネミーの座標、横幅、高さを取得する
	for (int i = 0; i < eActCount; i++) {
		ex[i] = _gameSystem->GetEnemyManagerObj()->GetPos(i).x;
		ey[i] = _gameSystem->GetEnemyManagerObj()->GetPos(i).y;
		ew[i] = _gameSystem->GetEnemyManagerObj()->GetWidth(i);
		eh[i] = _gameSystem->GetEnemyManagerObj()->GetHeight(i);
	}

	//弾の座標、横幅、高さ、タグを取得する
	for (int i = 0; i < bActCount; i++) {
		bx[i] = _gameSystem->GetBulletManagerObj()->GetPos(i).x;
		by[i] = _gameSystem->GetBulletManagerObj()->GetPos(i).y;
		bw[i] = _gameSystem->GetBulletManagerObj()->GetWidth(i);
		bh[i] = _gameSystem->GetBulletManagerObj()->GetHeight(i);
		bulletTag[i] = _gameSystem->GetBulletManagerObj()->GetTag(i);
	}

	//プレイヤーの発射した弾と敵の当たり判定
	//敵の発射した弾とプレイヤーの当たり判定
	for (int i = 0; i < bActCount; i++) {

		//エネミーの弾かつプレイヤーが無敵状態の場合当たり判定を行わない
		if (bulletTag[i] == "Enemy" &&
			_gameSystem->GetPlayerObj()->GetIsInvincible())continue;

		//※もし弾のタグが増える場合switch文に変更する

		//プレイヤーの弾とエネミーの当たり判定
		if (bulletTag[i] == "Player") {
			for (int j = 0; j < eActCount; j++) {
				if (GameManager::CollisionSqare(
					bx[i], by[i], bw[i], bh[i], ex[j], ey[j], ew[j], eh[j])) {
					//エネミーにダメージを与える
					_gameSystem->GetEnemyManagerObj()->Damage(j, 50);

					//当たった弾を非アクティブ化させる
					_gameSystem->GetBulletManagerObj()->SetIsActive(i, false);
					break;
				}
			}
		}
		//エネミーの弾とプレイヤーの当たり判定
		else {
			if (GameManager::CollisionSqare(
				bx[i], by[i], bw[i], bh[i], px, py, pw, ph)) {
				GameManager::PlayerHitProc(_gameSystem);

				//当たった弾を非アクティブ化させる
				_gameSystem->GetBulletManagerObj()->SetIsActive(i, false);
			}
		}
	}

	//プレイヤーと敵の当たり判定
	for (int i = 0; i < eActCount; i++) {

		//無敵状態の場合当たり判定を行わない
		if (_gameSystem->GetPlayerObj()->GetIsInvincible())break;

		//当たってた場合プレイヤーの残基を減らす
		if (GameManager::CollisionSqare(
			px, py, pw, ph, ex[i], ey[i], ew[i], eh[i])) {
			GameManager::PlayerHitProc(_gameSystem);
		}
	}
}

//四角形と四角形の当たり判定
bool GameManager::CollisionSqare(float _fX, float _fY, float _fW, float _fH,
	float _sX, float _sY, float _sW, float _sH) {

	//当たった場合
	if (_fX + _fW >= _sX && _fX <= _sX + _sW &&
		_fY + _fH >= _sY && _fY <= _sY + _sH) {
		return true;
	}

	//当たってない場合
	return false;
}

//円と円の当たり判定
bool GameManager::CollisionCircle(float _fX, float _fY, float _fR,
	float _sX, float _sY, float _sR) {

	/************************
	当たった場合
	(a*a)+ (b*b) = (c*c)(三平方の定理)
	************************/
	if (((_sX - _fX) * (_sX - _fX)) + ((_sY - _fY) * (_sY - _fY) <= (_fR + _sR) * (_fR + _sR))) {
		return true;
	}

	//当たってない場合
	return false;
}

//プレイヤーが当たった時の処理
void GameManager::PlayerHitProc(GameSystem* _gameSystem) {
	//プレイヤーの残基を減らす
	_gameSystem->GetPlayerObj()->Damage();

	//生存判定
	if (_gameSystem->GetPlayerObj()->GetIsActive() == false) {
		isGameOver = true;
	}
}