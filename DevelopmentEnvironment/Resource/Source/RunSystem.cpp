#include <DxLib.h>
#include "RunSystem.h"

#include "Fps.h"
#include "GameRunSystem.h"

//����������
void RunSystem::Init() {
	//���O�o�͂��s��Ȃ�
	SetOutApplicationLogValidFlag(FALSE);
	//�E�B���h�E���[�h�ɕύX
	ChangeWindowMode(TRUE);
	//�E�B���h�E�̃^�C�g����ύX
	SetMainWindowText("STG");
	//��ʉ𑜓x��ύX
	SetGraphMode(gameSystem.GetWindow_Width(), gameSystem.GetWindow_Height(), 32);
	//DX���C�u����
	if (DxLib_Init()) {
		CloseSystem::ExitSystem(eCloseType::Init_Error);
		RunSystem::End();
		return;
	}

	//����ʏ�����ݒ肷��
	SetDrawScreen(DX_SCREEN_BACK);

	//�Q�[���V�X�e����������
	if (!gameSystem.Init()) {
		CloseSystem::ExitSystem(eCloseType::Init_Error);
		RunSystem::End();
		return;
	}
}

//���s����
void RunSystem::Run() {
	Fps fps;
	GameRunSystem gRunSystem;

	//�Q�[�����s�V�X�e���̏���������
	if (!gRunSystem.Init(&gameSystem)) {
		CloseSystem::ExitSystem(eCloseType::Init_Error);
		RunSystem::End();
		return;
	}

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

		//�Q�[���̏���
		if (!gRunSystem.Run(&gameSystem)) {
			return;
		}

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