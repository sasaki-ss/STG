#include "DxLib.h"
#include "Fps.h"

//�R���X�g���N�^
Fps::Fps() {
	startTime = 0;
	count = 0;
}

//�X�V����
void Fps::Update() {
	if (count == 0) {
		startTime = GetNowCount();
	}
	if (count == 60) {
		int t = GetNowCount();
		count = 0;
		startTime = t;
	}
	count++;
}

//�ҋ@����
void Fps::Wait() {
	//�����������Ԃ��Z�o
	int tookTime = GetNowCount() - startTime;

	//�ҋ@���鎞�Ԃ��Z�o
	int waitTime = count * 1000 / 60 - tookTime;

	//�ҋ@���鎞�Ԃ�0�ȏ�Ȃ�ҋ@����
	if (waitTime > 0) {
		Sleep(waitTime);
	}
}