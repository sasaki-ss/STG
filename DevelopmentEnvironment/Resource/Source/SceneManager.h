#ifndef STG_SCENEMANAGER_H
#define STG_SCENEMANAGER_H

#include <stack>
#include <memory>
#include "Task.h"
#include "ISceneChanger.h"
#include "Scene.h"
#include "SceneData.h"
#include "ShareParameter.h"
#include "CloseSystem.h"

//�V�[���Ǘ��N���X
class SceneManager final :public ISceneChanger, Task, CloseSystem {
private:
	eScene nowScene;	//���݂̃V�[��
	std::stack<std::shared_ptr<Scene>> scenes;	//�V�[���̃X�^�b�N
	ShareParameter* shareParameter;	//���L�p�����[�^
public:
	//�R���X�g���N�^
	SceneManager(GameSystem* _gameSystem);
	//�f�X�g���N�^
	~SceneManager() {}
	//�X�V����
	void Update(GameSystem* _gameSystem);
	//�`�揈��
	void Draw(GameSystem* _gameSystem);
	//�V�[���؂�ւ�����
	void SceneChange(eScene _nextScene, ShareParameter* _parameter,
		GameSystem* _gameSystem, const bool _isStack, const bool _isBack);
	//���݂̃V�[�����擾
	eScene GetNowScene()const { return nowScene; }
	//���L�p�����[�^�̃C���X�^���X���擾
	ShareParameter* GetParameter()const { return shareParameter; }
};

#endif // !STG_SCENEMANAGER_H