#ifndef STG_SCENE_H
#define STG_SCENE_H

#include "Task.h"
#include "ISceneChanger.h"
#include "ShareParameter.h"
#include "GameSystem.h"

//�V�[���N���X
class Scene : public Task {
protected:
	ISceneChanger* sceneChanger;	//�V�[���؂�ւ����g�����߂̕ϐ�
	ShareParameter* shareParameter;	//�f�[�^���L�N���X
	GameSystem* gameSystem;			//�Q�[���̃��\�[�X�Ȃǂ̑����Ǘ��N���X
public:
	//�R���X�g���N�^
	Scene(ISceneChanger* _sceneChanger, ShareParameter* _shareParameter,
		GameSystem* _gameSystem);
	//����������
	virtual void Init() {}
	//�I������
	virtual void Final() {}
	//�X�V����
	virtual void Update() = 0;
	//�`�揈��
	virtual void Draw() = 0;
};

#endif // !STG_SCENE_H