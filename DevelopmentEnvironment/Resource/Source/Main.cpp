#include <DxLib.h>
#include "RunSystem.h"

/******************************************************************************
����� �@�@�@  : ���X�؊C��(��������[)
Project�J�n��  : 2020/12/8
�o�[�W�������� :

******************************************************************************/

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpCmdLine, int nCmdShow) {
	
	RunSystem runSystem;	//���s�V�X�e���N���X�̃C���X�^���X

	//����������
	runSystem.Init();
	//���s����
	runSystem.Run();
	//�I������
	runSystem.End();

	return 0;
}