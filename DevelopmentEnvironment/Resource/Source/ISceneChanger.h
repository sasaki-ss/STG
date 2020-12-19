#ifndef STG_ISCENECHANGER_H
#define STG_ISCENECHANGER_H

#include "SceneData.h"
#include "ShareParameter.h"

//�V�[���؂�ւ�����
class ISceneChanger {
public:
	//�R���X�g���N�^
	ISceneChanger() = default;
	//�f�X�g���N�^
	virtual ~ISceneChanger() = default;
	//�V�[���؂�ւ�����
	virtual void SceneChange(eScene _nextScene, ShareParameter* _parameter,
		const bool _isStack, const bool _isBack) = 0;
};

#endif // !STG_ISCENECHANGER_H