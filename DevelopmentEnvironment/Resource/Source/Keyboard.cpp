#include <DxLib.h>
#include "Keyboard.h"

//�R���X�g���N�^
Keyboard::Keyboard() {
	//�L�[�J�E���^�̃��������m��
	memset(keyPressCount, 0, sizeof(keyPressCount));
}

//�X�V����
void Keyboard::Update() {
	char tmpKey[KEY_NUM];	//���݂̓��͏�Ԃ��i�[����

	//�S�ẴL�[�̓��͏�Ԃ𓾂�
	GetHitKeyStateAll(tmpKey);

	for (int i = 0; i < KEY_NUM; i++) {
		//i�Ԗڂ̃L�[��������Ă���ꍇ
		if (tmpKey[i] != 0) {
			keyPressCount[i]++;
		}
		//������Ă��Ȃ��ꍇ
		else {
			keyPressCount[i] = 0;
		}
	}
}

//�L�[�̉�����J�E���^���擾����
int Keyboard::GetPressCount(int _keyCode) {
	//�L�[�R�[�h���Ή����ĂȂ��ꍇ
	if (!Keyboard::IsAvailableCode(_keyCode)) {
		return -1;
	}

	return keyPressCount[_keyCode];
}

//�L�[���L���ȃL�[�ԍ����₤
bool Keyboard::IsAvailableCode(int _keyCode) {
	//�L�[�R�[�h��0~KEY_NUM����Ȃ��ꍇ
	if (!(0 <= _keyCode && _keyCode < KEY_NUM)) {
		return false;
	}

	return true;
}