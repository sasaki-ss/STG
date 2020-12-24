#ifndef STG_INPUTMANAGER_H
#define STG_INPUTMANAGER_H

#include "Keyboard.h"

//操作タイプ
enum class eOperationType {
	Up,		//前進
	Down,	//後退
	Left,	//左
	Right,	//右
	Shot,	//発射
	Bomb,	//ボム
};

//キーとかの設定変更を登録したい(願望)
class InputManager final {
private:
	//操作キーの構造体
	typedef struct {
		int upKey;
		int downKey;
		int leftKey;
		int rightKey;
		int shotKey;
		int bombKey;
	}OperationKey;

	OperationKey operationKey;	//操作キー
	Keyboard* keyboard;	//キーボードクラス
public:
	//コンストラクタ
	InputManager();
	//デストラクタ
	~InputManager();
	//キーボードクラスを取得
	Keyboard* GetKeyboard() { return keyboard; }
	//操作キーのセッター
	bool SetKey(eOperationType _type, int _setKey);
	//操作キーのゲッター
	int GetKey(eOperationType _type);
};

#endif // !STG_INPUTMANAGER_H