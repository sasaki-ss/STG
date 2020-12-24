#ifndef STG_TITLE_H
#define STG_TITLE_H

#include "Scene.h"
#include "ISceneChanger.h"

//�^�C�g���N���X
class Title :public Scene {
public:
	Title(ISceneChanger* _sceneChanger, ShareParameter* _shareParameter,
		GameSystem* _gameSystem);
	//�X�V����
	void Update();
	//�`�揈��
	void Draw();
};

#endif // !STG_TITLE_H