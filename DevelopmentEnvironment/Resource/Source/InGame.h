#ifndef STG_INGAME_H
#define STG_INGAME_H

#include "Scene.h"
#include "ISceneChanger.h"

//�^�C�g���N���X
class InGame :public Scene {
public:
	InGame(ISceneChanger* _sceneChanger, ShareParameter* _shareParameter);
	//�X�V����
	void Update();
	//�`�揈��
	void Draw();
};

#endif // !STG_INGAME_H