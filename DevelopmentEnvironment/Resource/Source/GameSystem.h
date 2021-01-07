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
	static const int WINDOW_WIDTH = 1280;	//�E�B���h�E�̉���
	static const int WINDOW_HEIGHT = 960;	//�E�B���h�E�̍���
	static const float GAME_WIDTH;			//�Q�[����ʂ̉���
	static const float GAME_HEIGHT;			//�Q�[����ʂ̍���

	//���\�[�X
	Image* image;					//�摜�N���X

	//���͊֘A
	InputManager* inputManager;		//���͊Ǘ��N���X

	//�Q�[���I�u�W�F�N�g
	BulletManager* bulletManager;
	EnemyManager* enemyManager;
	Player* player;
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
	Image* GetImage()const { return image; }
	//���͊Ǘ��N���X���擾
	InputManager* GetInputManager()const { return inputManager; }
	//�e�Ǘ��N���X���擾����
	BulletManager* GetBulletManagerObj()const { return bulletManager; }
	//�G�Ǘ��N���X���擾
	EnemyManager* GetEnemyManagerObj()const { return enemyManager; }
	//�v���C���[�N���X���擾
	Player* GetPlayerObj()const { return player; }
	//�e�Ǘ��N���X���Z�b�g����
	void SetBulletManagerObj(BulletManager* _bulletManager) {
		bulletManager = _bulletManager;
	}
	//�G�Ǘ��N���X���Z�b�g����
	void SetEnemyManagerObj(EnemyManager* _enemyManager) {
		enemyManager = _enemyManager;
	}
	//�v���C���[�N���X���Z�b�g����
	void SetPlayerObj(Player* _player) { player = _player; }
};

#endif // !STG_GAMESYSTEM_H