#ifndef STG_KEYBOARD_H
#define STG_KEYBOARD_H

class Keyboard final {
private:
	static const int KEY_NUM = 256;	//キーの総数
	int keyPressCount[KEY_NUM];		//キーの押されカウンタ

	//キーが有効なキー番号か問う
	bool IsAvailableCode(int _keyCode);
public:
	//コンストラクタ
	Keyboard();
	//更新処理
	void Update();
	//キーの押されカウンタを取得する
	int GetPressCount(int _keyCode);
};

#endif // !STG_KEYBOARD_H