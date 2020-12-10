#ifndef STG_RUNSYSTEM_H
#define STG_RUNSYSTEM_H

#include "CloseSystem.h"

//実行システムクラス
class RunSystem final :public CloseSystem {
public:
	//初期化処理
	void Init();
	//実行処理
	void Run();
	//終了処理
	void End();
};

#endif // !STG_RUNSYSTEM_H