#include <DxLib.h>
#include "Keyboard.h"

//コンストラクタ
Keyboard::Keyboard() {
	//キーカウンタのメモリを確保
	memset(keyPressCount, 0, sizeof(keyPressCount));
}

//更新処理
void Keyboard::Update() {
	char tmpKey[KEY_NUM];	//現在の入力状態を格納する

	//全てのキーの入力状態を得る
	GetHitKeyStateAll(tmpKey);

	for (int i = 0; i < KEY_NUM; i++) {
		//i番目のキーが押されている場合
		if (tmpKey[i] != 0) {
			keyPressCount[i]++;
		}
		//押されていない場合
		else {
			keyPressCount[i] = 0;
		}
	}
}

//キーの押されカウンタを取得する
int Keyboard::GetPressCount(int _keyCode) {
	//キーコードが対応してない場合
	if (!Keyboard::IsAvailableCode(_keyCode)) {
		return -1;
	}

	return keyPressCount[_keyCode];
}

//キーが有効なキー番号か問う
bool Keyboard::IsAvailableCode(int _keyCode) {
	//キーコードが0~KEY_NUMじゃない場合
	if (!(0 <= _keyCode && _keyCode < KEY_NUM)) {
		return false;
	}

	return true;
}