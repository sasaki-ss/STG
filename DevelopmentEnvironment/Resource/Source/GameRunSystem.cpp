#include <DxLib.h>
#include "GameRunSystem.h"

bool GameRunSystem::Init(GameSystem* _gameSystem) {
	sceneManager = new SceneManager(_gameSystem);

	sceneManager->GetParameter()->SetData("IS_RUN_GAME", 1);

	return true;
}

//���s����
bool GameRunSystem::Run(GameSystem* _gameSystem) {
	//�ǂ����ŃG���[�����������ۏI��������
	if (sceneManager->GetParameter()->GetData("IS_RUN_GAME") ==
		static_cast<int>(GameRunState::Exit)) {
		return false;
	}

	_gameSystem->GetInputManager()->GetKeyboard()->Update();

	DrawFormatString(0, 0, GetColor(255, 255, 255), "�Q�[�����s�V�X�e���N���X���s����");
	DrawFormatString(0, 25, GetColor(255, 255, 255), "%d", static_cast<int>(sceneManager->GetNowScene()));

	//�V�[���̍X�V����
	sceneManager->Update(_gameSystem);
	//�V�[���̕`�揈��
	sceneManager->Draw(_gameSystem);

	return true;
}