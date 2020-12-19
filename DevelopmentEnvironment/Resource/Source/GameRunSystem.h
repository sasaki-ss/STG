#ifndef STG_GAMERUNSYSTEM_H
#define STG_GAMERUNSYSTEM_H

#include "SceneManager.h"
#include "CloseSystem.h"

//�Q�[�����s�V�X�e���N���X
class GameRunSystem final :public CloseSystem {
private:
	//�Q�[�����s�̏��
	enum class GameRunState {
		Exit,	//�I��
		Run		//���s��
	};

	SceneManager sceneManager;	//�V�[���}�l�[�W���[
public:
	bool Init();
	//���s����
	bool Run();
};

#endif // !STG_GAMERUNSYSTEM_H