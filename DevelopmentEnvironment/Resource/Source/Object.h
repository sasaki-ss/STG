#ifndef STG_OBJECT_H
#define STG_OBJECT_H

#include "Task.h"
#include "GameSystem.h"

//オブジェクトクラス
//全てのゲームオブジェクトに継承させる
class Object :public Task {
private:
	//座標構造体
	typedef struct {
		float x;
		float y;
		float cx;
		float cy;
	}Pos;
protected:
	Pos pos;		//座標
	float width;	//横幅
	float height;	//高さ
	bool isActive;	//アクティブフラグ
public:
	//初期化処理
	virtual void Init(){}
	//終了処理
	virtual void Final(){}
	//更新処理
	virtual void Update(GameSystem* _gameSystem) = 0;
	//描画処理
	virtual void Draw(GameSystem* _gameSystem) = 0;
	//座標を取得する
	Pos GetPos() { return pos; }
	//横幅を取得
	float GetWidth() { return width; }
	//高さを取得
	float GetHeight() { return height; }
	//アクティブフラグを取得
	bool GetIsActive() { return isActive; }
};

#endif // !STG_OBJECT_H