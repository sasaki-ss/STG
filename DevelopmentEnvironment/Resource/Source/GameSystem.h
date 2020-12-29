#ifndef STG_GAMESYSTEM_H
#define STG_GAMESYSTEM_H

#include "Image.h"
#include "InputManager.h"

//�Q�[���I�u�W�F�N�g
class BulletManager;
class EnemyManager;
class Player;

//�Q�[���V�X�e���N���X
class GameSystem {
private:
	static const int WINDOW_WIDTH = 1280;
	static const int WINDOW_HEIGHT = 960;
	static const int GAME_WIDTH = 1280;
	static const int GAME_HEIGHT = 960;
	typedef struct {
		BulletManager* bulletManager;
		EnemyManager* enemyManager;
		Player* player;
	}GameObjects;

	Image* image;					//�摜�N���X
	InputManager* inputManager;		//���͊Ǘ��N���X

	GameObjects gameObjects;	//�Q�[���I�u�W�F�N�g
public:
	//�R���X�g���N�^
	GameSystem();
	//�f�X�g���N�^
	~GameSystem();
	//����������
	bool Init();

	//��ʂ̉������擾
	int GetWindow_Width()const { return WINDOW_WIDTH; }
	//��ʂ̍������擾
	int GetWindow_Height()const { return WINDOW_HEIGHT; }
	//�摜�N���X���擾����
	Image* GetImage() { return image; }
	//���͊Ǘ��N���X���擾
	InputManager* GetInputManager() { return inputManager; }
	//�Q�[���I�u�W�F�N�g�\���̂��擾����
	GameObjects GetGameObjects() { return gameObjects; }
	//�v���C���[���Q�[���I�u�W�F�N�g�\���̂Ɋi�[����
	void SetObjectsPlayer(Player* _player) { gameObjects.player = _player; }
	//�e�Ǘ��N���X���Q�[���I�u�W�F�N�g�\���̂Ɋi�[����
	void SetObjectsBulletManager(BulletManager* _bulletMangaer){
		gameObjects.bulletManager = _bulletMangaer;
	}
	//�G�l�~�[�Ǘ��N���X���Q�[���I�u�W�F�N�g�\���̂Ɋi�[����
	void SetObjectsEnemyManager(EnemyManager* _enemyManager) {
		gameObjects.enemyManager = _enemyManager;
	}
};

#endif // !STG_GAMESYSTEM_H