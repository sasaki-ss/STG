#include "InputManager.h"

//�R���X�g���N�^
InputManager::InputManager() {
	keyboard = new Keyboard();
}

//�f�X�g���N�^
InputManager::~InputManager() {
	delete keyboard;
}

//����L�[�̃Z�b�^�[
bool InputManager::SetKey(eOperationType _type, int _setKey) {
	switch (_type) {
	//�O�i�̑���̏ꍇ
	case eOperationType::Up:
		operationKey.upKey = _setKey;
		break;
	//��ނ̑���̏ꍇ
	case eOperationType::Down:
		operationKey.downKey = _setKey;
		break;
	//���̑���̏ꍇ
	case eOperationType::Left:
		operationKey.leftKey = _setKey;
		break;
	//�E�̑���̏ꍇ
	case eOperationType::Right:
		operationKey.rightKey = _setKey;
		break;
	//���˂̑���̏ꍇ
	case eOperationType::Shot:
		operationKey.shotKey = _setKey;
		break;
	//�{���̑���̏ꍇ
	case eOperationType::Bomb:
		operationKey.bombKey = _setKey;
		break;
	//����ȊO�̏ꍇ
	default:
		return false;
	}

	return true;
}

//����L�[�̃Q�b�^�[
int InputManager::GetKey(eOperationType _type) {
	switch (_type) {
	//�O�i�̑���̏ꍇ
	case eOperationType::Up:
		return operationKey.upKey;
	//��ނ̑���̏ꍇ
	case eOperationType::Down:
		return operationKey.downKey;
	//���̑���̏ꍇ
	case eOperationType::Left:
		return operationKey.leftKey;
	//�E�̑���̏ꍇ
	case eOperationType::Right:
		return operationKey.rightKey;
	//���˂̑���̏ꍇ
	case eOperationType::Shot:
		return operationKey.shotKey;
	//�{���̑���̏ꍇ
	case eOperationType::Bomb:
		return operationKey.bombKey;
	}

	//����ȊO�̏ꍇ��-1��Ԃ�
	return -1;
}