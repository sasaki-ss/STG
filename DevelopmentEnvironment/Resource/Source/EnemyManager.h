#ifndef STG_ENEMYMANAGER_H
#define STG_ENEMYMANAGER_H

#include "Task.h"
#include "GameSystem.h"
#include "Enemy.h"

class EnemyManager final :public Task {
private:
	static const int MAX_ENEMY_NUM = 100;	//エネミーの最大数
	Enemy* enemys[MAX_ENEMY_NUM];			//エネミークラス

	int activeCount;	//エネミーのアクティブ数

	//整理処理
	void Organize();
	//削除処理
	void Destroy();
public:
	//コンストラクタ
	EnemyManager(int _difficulty);
	//デストラクタ
	~EnemyManager();
	//更新処理
	virtual void Update(GameSystem* _gameSystem);
	//描画処理
	virtual void Draw(GameSystem* _gameSystem);
	//アクティブな弾の数を取得
	int GetActiveCount() { return activeCount; }

	//いらない子
	void Update(){}
	void Draw(){}
};

#endif // !STG_ENEMYMANAGER_H