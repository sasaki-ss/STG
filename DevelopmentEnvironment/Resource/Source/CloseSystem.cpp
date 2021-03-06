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
	//異常が発生した場合の処理
	case eCloseType::Abnormal_Close:
		MessageBox(NULL, TEXT("Forced termination."), "System Error", MB_OK | MB_ICONERROR);
		break;
	//読み込みエラーが発生した場合
	case eCloseType::Read_Error:
		MessageBox(NULL, TEXT("Forced termination."), "Read failure", MB_OK | MB_ICONERROR);
		break;
	//初期化エラーの強制終了処理
	case eCloseType::Init_Error:
		MessageBox(NULL, TEXT("Forced termination."), "Initialize Error", MB_OK | MB_ICONERROR);
		break;
	}

	return true;
}