#ifndef STG_MENU_H
#define STG_MENU_H

#include "Scene.h"
#include "ISceneChanger.h"

//�^�C�g���N���X
class Menu :public Scene {
public:
	Menu(ISceneChanger* _sceneChanger, ShareParameter* _shareParameter);
	//����������
	void Init(GameSystem* _gameSystem) {}
	//�X�V����
	void Update(GameSystem* _gameSystem);
	//�`�揈��
	void Draw(GameSystem* _gameSystem);
};

#endif // !STG_MENU_H