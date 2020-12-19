#include <DxLib.h>
#include "RunSystem.h"

#include "Fps.h"
#include "GameRunSystem.h"

//初期化処理
void RunSystem::Init() {
	//ログ出力を行わない
	SetOutApplicationLogValidFlag(FALSE);
	//ウィンドウモードに変更
	ChangeWindowMode(TRUE);
	//ウィンドウのタイトルを変更
	SetMainWindowText("STG");
	//画面解像度を変更
	SetGraphMode(1280, 960, 32);
	//DXライブラリ
	if (DxLib_Init()) {
		CloseSystem::ExitSystem(eCloseType::Init_Error);
		RunSystem::End();
		return;
	}

	//裏画面処理を設定する
	SetDrawScreen(DX_SCREEN_BACK);
}

//実行処理
void RunSystem::Run() {
	Fps fps;
	GameRunSystem gRunSystem;

	//ゲーム実行システムの初期化処理
	if (!gRunSystem.Init()) {
		CloseSystem::ExitSystem(eCloseType::Init_Error);
		RunSystem::End();
		return;
	}

	while (!ProcessMessage()) {
		//終了確認処理
		if (CheckHitKey(KEY_INPUT_ESCAPE) != 0) {
			if (CloseSystem::ExitSystem(eCloseType::Normal_Close)) {
				RunSystem::End();
				return;
			}
		}

		//画面をクリアする
		ClearDrawScreen();

		//FPSの更新
		fps.Update();

		//ゲームの処理
		if (!gRunSystem.Run()) {
			return;
		}

		//裏画面を反映させる
		ScreenFlip();

		//処理を待機する
		fps.Wait();
	}
}

//終了処理
void RunSystem::End() {
	//DXライブラリを終了させる
	DxLib_End();
}