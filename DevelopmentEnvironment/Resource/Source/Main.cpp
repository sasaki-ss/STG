#include <DxLib.h>
#include "RunSystem.h"

/******************************************************************************
制作者 　　　  : 佐々木海星(かいちょー)
Project開始日  : 2020/12/8
バージョン履歴 :

******************************************************************************/

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpCmdLine, int nCmdShow) {
	
	RunSystem runSystem;	//実行システムクラスのインスタンス

	//初期化処理
	runSystem.Init();
	//実行処理
	runSystem.Run();
	//終了処理
	runSystem.End();

	return 0;
}