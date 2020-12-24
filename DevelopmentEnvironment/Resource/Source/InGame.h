#ifndef STG_INGAME_H
#define STG_INGAME_H

#include "Scene.h"
#include "ISceneChanger.h"
#include "Player.h"
#include "BulletManager.h"
#include "EnemyManager.h"

//�^�C�g���N���X
class InGame final :public Scene {
private:
	Player* player;					//�v���C���[
	BulletManager* bulletManager;	//�e�Ǘ��N���X
	EnemyManager* enemyManager;		//�G�l�~�[�Ǘ��N���X
public:
	//�R���X�g���N�^
	InGame(ISceneChanger* _sceneChanger, ShareParameter* _shareParameter,
		GameSystem* _gameSystem);
	//�X�V����
	void Update();
	//�`�揈��
	void Draw();
};

#endif // !STG_INGAME_H