#include <DxLib.h>
#include "RunSystem.h"

#include "Fps.h"

//����������
void RunSystem::Init() {
	//���O�o�͂��s��Ȃ�
	SetOutApplicationLogValidFlag(FALSE);
	//�E�B���h�E���[�h�ɕύX
	ChangeWindowMode(TRUE);
	//�E�B���h�E�̃^�C�g����ύX
	SetMainWindowText("STG");
	//��ʉ𑜓x��ύX
	SetGraphMode(1280, 960, 32);
	//DX���C�u����
	if (DxLib_Init()) {
		CloseSystem::ExitSystem(eCloseType::Init_Error);
		RunSystem::End();
		return;
	}

	//����ʏ�����ݒ肷��
	SetDrawScreen(DX_SCREEN_BACK);
}

//���s����
void RunSystem::Run() {
	Fps fps;

	while (!ProcessMessage()) {
		//�I���m�F����
		if (CheckHitKey(KEY_INPUT_ESCAPE) != 0) {
			if (CloseSystem::ExitSystem(eCloseType::Normal_Close)) {
				RunSystem::End();
				return;
			}
		}

		//��ʂ��N���A����
		ClearDrawScreen();

		//FPS�̍X�V
		fps.Update();

		//����ʂ𔽉f������
		ScreenFlip();

		//������ҋ@����
		fps.Wait();
	}
}

//�I������
void RunSystem::End() {
	//DX���C�u�������I��������
	DxLib_End();
}