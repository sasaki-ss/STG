#ifndef STG_ISCENECHANGER_H
#define STG_ISCENECHANGER_H

#include "SceneData.h"
#include "ShareParameter.h"
#include "GameSystem.h"

//シーン切り替え処理
class ISceneChanger {
public:
	//コンストラクタ
	ISceneChanger() = default;
	//デストラクタ
	virtual ~ISceneChanger() = default;
	//シーン切り替え処理
	virtual void SceneChange(eScene _nextScene, ShareParameter* _parameter,
		GameSystem* _gameSystem, const bool _isStack, const bool _isBack) = 0;
};

#endif // !STG_ISCENECHANGER_H