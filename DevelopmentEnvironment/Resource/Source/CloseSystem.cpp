#include <DxLib.h>
#include "CloseSystem.h"

//終了処理
bool CloseSystem::ExitSystem(eCloseType _closeType) {

	int id = 0;	//選択されたIDを格納する変数

	switch (_closeType) {
	//通常終了の処理
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
	//初期化エラーの強制終了処理
	case eCloseType::Init_Error:
		MessageBox(NULL, TEXT("Forced termination."), "Initialize Error", MB_OK | MB_ICONERROR);
		break;
	}

	return true;
}