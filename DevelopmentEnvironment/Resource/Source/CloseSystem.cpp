#include <DxLib.h>
#include "CloseSystem.h"

//�I������
bool CloseSystem::ExitSystem(eCloseType _closeType) {

	int id = 0;	//�I�����ꂽID���i�[����ϐ�

	switch (_closeType) {
	//�ʏ�I���̏���
	case eCloseType::Normal_Close:
		id = MessageBox(NULL, TEXT("Do you want to quit ?"), "Question", MB_OKCANCEL | MB_ICONQUESTION);
		if (id == IDCANCEL) {
			return false;
		}
		break;
	case eCloseType::Abnormal_Close:
		break;
	case eCloseType::Read_Error:
		break;
	//�������G���[�̋����I������
	case eCloseType::Init_Error:
		MessageBox(NULL, TEXT("Forced termination."), "Initialize Error", MB_OK | MB_ICONERROR);
		break;
	}

	return true;
}