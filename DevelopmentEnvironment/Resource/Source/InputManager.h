#ifndef STG_INPUTMANAGER_H
#define STG_INPUTMANAGER_H

#include "Keyboard.h"

//����^�C�v
enum class eOperationType {
	Up,		//�O�i
	Down,	//���
	Left,	//��
	Right,	//�E
	Shot,	//����
	Bomb,	//�{��
};

//�L�[�Ƃ��̐ݒ�ύX��o�^������(��])
class InputManager final {
private:
	//����L�[�̍\����
	typedef struct {
		int upKey;
		int downKey;
		int leftKey;
		int rightKey;
		int shotKey;
		int bombKey;
	}OperationKey;

	OperationKey operationKey;	//����L�[
	Keyboard* keyboard;	//�L�[�{�[�h�N���X
public:
	//�R���X�g���N�^
	InputManager();
	//�f�X�g���N�^
	~InputManager();
	//�L�[�{�[�h�N���X���擾
	Keyboard* GetKeyboard() { return keyboard; }
	//����L�[�̃Z�b�^�[
	bool SetKey(eOperationType _type, int _setKey);
	//����L�[�̃Q�b�^�[
	int GetKey(eOperationType _type);
};

#endif // !STG_INPUTMANAGER_H