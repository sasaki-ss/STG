#include "InputManager.h"

//コンストラクタ
InputManager::InputManager() {
	keyboard = new Keyboard();
}

//デストラクタ
InputManager::~InputManager() {
	delete keyboard;
}

//操作キーのセッター
bool InputManager::SetKey(eOperationType _type, int _setKey) {
	switch (_type) {
	//前進の操作の場合
	case eOperationType::Up:
		operationKey.upKey = _setKey;
		break;
	//後退の操作の場合
	case eOperationType::Down:
		operationKey.downKey = _setKey;
		break;
	//左の操作の場合
	case eOperationType::Left:
		operationKey.leftKey = _setKey;
		break;
	//右の操作の場合
	case eOperationType::Right:
		operationKey.rightKey = _setKey;
		break;
	//発射の操作の場合
	case eOperationType::Shot:
		operationKey.shotKey = _setKey;
		break;
	//ボムの操作の場合
	case eOperationType::Bomb:
		operationKey.bombKey = _setKey;
		break;
	//それ以外の場合
	default:
		return false;
	}

	return true;
}

//操作キーのゲッター
int InputManager::GetKey(eOperationType _type) {
	switch (_type) {
	//前進の操作の場合
	case eOperationType::Up:
		return operationKey.upKey;
	//後退の操作の場合
	case eOperationType::Down:
		return operationKey.downKey;
	//左の操作の場合
	case eOperationType::Left:
		return operationKey.leftKey;
	//右の操作の場合
	case eOperationType::Right:
		return operationKey.rightKey;
	//発射の操作の場合
	case eOperationType::Shot:
		return operationKey.shotKey;
	//ボムの操作の場合
	case eOperationType::Bomb:
		return operationKey.bombKey;
	}

	//それ以外の場合は-1を返す
	return -1;
}