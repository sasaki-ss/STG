#ifndef STG_MENU_H
#define STG_MENU_H

#include "Scene.h"
#include "ISceneChanger.h"

//�^�C�g���N���X
class Menu :public Scene {
public:
	Menu(ISceneChanger* _sceneChanger, ShareParameter* _shareParameter);
	//�X�V����
	void Update();
	//�`�揈��
	void Draw();
};

#endif // !STG_MENU_H