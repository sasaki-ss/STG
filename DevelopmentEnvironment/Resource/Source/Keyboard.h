#ifndef STG_KEYBOARD_H
#define STG_KEYBOARD_H

class Keyboard final {
private:
	static const int KEY_NUM = 256;	//�L�[�̑���
	int keyPressCount[KEY_NUM];		//�L�[�̉�����J�E���^

	//�L�[���L���ȃL�[�ԍ����₤
	bool IsAvailableCode(int _keyCode);
public:
	//�R���X�g���N�^
	Keyboard();
	//�X�V����
	void Update();
	//�L�[�̉�����J�E���^���擾����
	int GetPressCount(int _keyCode);
};

#endif // !STG_KEYBOARD_H