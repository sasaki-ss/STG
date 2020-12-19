#include <DxLib.h>
#include "SceneManager.h"

#include "Title.h"
#include "InGame.h"
#include "Menu.h"

//�R���X�g���N�^
SceneManager::SceneManager() {
	shareParameter = new ShareParameter();
	scenes.push(std::make_shared<Title>(this, shareParameter));
	nowScene = eScene::Title;
}

//�X�V����
void SceneManager::Update() {
	//�V�[���̍X�V����
	scenes.top()->Update();
	DrawFormatString(0, 50, GetColor(255, 255, 255), "�V�[���}�l�[�W���[�X�V��");
}

//�`�揈��
void SceneManager::Draw() {
	//�V�[���̕`�揈��
	scenes.top()->Draw();
	DrawFormatString(0, 100, GetColor(255, 255, 255), "�V�[���}�l�[�W���[�`�撆");
}

//�V�[���؂�ւ�����
void SceneManager::SceneChange(eScene _nextScene, ShareParameter* _parameter,
	const bool _isStack, const bool _isBack) {
	//���̃V�[���������݂̃V�[�����Ɋi�[����
	nowScene = _nextScene;

	//��O�̃V�[���ɂ��鏈��
	if (_isBack) {
		scenes.pop();
		return;
	}

	//scenes�̒��g�����ׂč폜����
	if (!_isStack) {
		while (!scenes.empty()) {
			scenes.pop();
		}
	}

	//�V�[����V���ɐ�������
	switch (_nextScene) {
	//�^�C�g���V�[��
	case eScene::Title:
		scenes.push(std::make_shared<Title>(this, shareParameter));
		break;
	//���j���[�V�[��
	case eScene::Menu:
		scenes.push(std::make_shared<Menu>(this, shareParameter));
		break;
	//�C���Q�[���V�[��
	case eScene::InGame:
		scenes.push(std::make_shared<InGame>(this, shareParameter));
		break;
	default:
		CloseSystem::ExitSystem(eCloseType::Abnormal_Close);
		shareParameter->SetData("IS_RUN_GAME", 0);
		return;
	}
}