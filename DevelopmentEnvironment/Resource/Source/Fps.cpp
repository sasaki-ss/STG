#include "DxLib.h"
#include "Fps.h"

//コンストラクタ
Fps::Fps() {
	startTime = 0;
	count = 0;
}

//更新処理
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

//待機処理
void Fps::Wait() {
	//かかった時間を算出
	int tookTime = GetNowCount() - startTime;

	//待機する時間を算出
	int waitTime = count * 1000 / 60 - tookTime;

	//待機する時間が0以上なら待機する
	if (waitTime > 0) {
		Sleep(waitTime);
	}
}