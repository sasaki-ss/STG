#ifndef STG_BULLETMANAGER_H
#define STG_BULLETMANAGER_H

#include "Task.h"
#include "GameSystem.h"
#include "Bullet.h"

enum class eBulletType {
	Player,
	Enemy1
};

//弾管理クラス
class BulletManager final :public Task {
private:
	static const int MAX_BULLET_NUM = 1000;	//弾の管理の最大数
	Bullet* bullets[MAX_BULLET_NUM];		//弾クラス

	int activeCount;	//アクティブな弾の数

	//整理処理
	void Organize();
	//削除処理
	void Destroy();
public:
	BulletManager();
	~BulletManager();
	//更新処理
	void Update(GameSystem* _gameSystem);
	//描画処理
	void Draw(GameSystem* _gameSystem);
	//弾生成処理
	void CreateBullet(float _x, float _y, eBulletType _type);
	//アクティブな弾の数を取得
	int GetActiveCount() { return activeCount; }

	//いらない子
	void Update() {}
	void Draw() {}
};

#endif // !STG_BULLETMANAGER_H