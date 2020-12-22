#ifndef STG_GAMESYSTEM_H
#define STG_GAMESYSTEM_H

#include "Image.h"

/*
メモ
継承する形にする場合もしかしたら継承先のオブジェクトが破棄された際にリソース飛ぶかも...?
*/

//ゲームシステムクラス
class GameSystem {
private:
	Image* image;	//画像クラス
public:
	//コンストラクタ
	GameSystem();
	//デストラクタ
	virtual ~GameSystem();
	//初期化処理
	bool Init();

	//画像クラスを取得する
	Image* GetImage() { return image; }
};

#endif // !STG_GAMESYSTEM_H