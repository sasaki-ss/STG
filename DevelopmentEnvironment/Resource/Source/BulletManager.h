#ifndef STG_BULLETMANAGER_H
#define STG_BULLETMANAGER_H

#include <string>
#include "Task.h"
#include "GameSystem.h"
#include "Bullet.h"

using namespace std;

enum class eBulletType {
	Player,
	Enemy_Normal
};

//弾管理クラス
class BulletManager final :public Task {
private:
	static const int MAX_BULLET_NUM = 1000;	//弾の最大数
	Bullet* bullets[MAX_BULLET_NUM];		//弾クラス

	int activeCount;	//アクティブな弾の数

	//整理処理
	void Organize();
	//削除処理
	void Destroy();
public:
	//コンストラクタ
	BulletManager();
	//デストラクタ
	~BulletManager();
	//更新処理
	void Update(GameSystem* _gameSystem);
	//描画処理
	void Draw(GameSystem* _gameSystem);
	//弾生成処理
	void CreateBullet(float _x, float _y, eBulletType _type);
	//アクティブな弾の数を取得
	int GetActiveCount() { return activeCount; }
	//座標を取得する
	Pos GetPos(int _num);
	//横幅を取得する
	float GetWidth(int _num);
	//高さを取得する
	float GetHeight(int _num);
	//アクティブ状態を取得する
	bool GetIsActive(int _num);
	//タグを取得する
	string GetTag(int _num);
	//アクティブフラグをセットする
	void SetIsActive(int _num, bool _isActive);
};

#endif // !STG_BULLETMANAGER_H