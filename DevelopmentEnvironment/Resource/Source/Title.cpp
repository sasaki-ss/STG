#include <DxLib.h>
#include "Title.h"

//�R���X�g���N�^
Title::Title(ISceneChanger* _sceneChanger, ShareParameter* _shareParameter) :
	Scene(_sceneChanger, _shareParameter) {

}

//�X�V����
void Title::Update(GameSystem* _gameSystem) {
	//�X�y�[�X�L�[����͂����ۂɎ��s
	if (CheckHitKey(KEY_INPUT_SPACE) != 0) {
		sceneChanger->SceneChange(eScene::InGame, shareParameter, _gameSystem, true, false);
	}

	if (CheckHitKey(KEY_INPUT_W) != 0) {
		sceneChanger->SceneChange(eScene::Menu, shareParameter, _gameSystem, true, false);
	}

	DrawString(0, 150, "�^�C�g���N���X�̍X�V�������s��", GetColor(255, 255, 255));
}

//�`�揈��
void Title::Draw(GameSystem* _gameSystem) {
	DrawString(0, 200, "�^�C�g���N���X�̕`�揈�����s��", GetColor(255, 255, 255));

	//DrawGraph(0, 0, gameSystem.GetImage()->GetImage("Image_001.png"),TRUE);
	DrawGraph(0, 0, _gameSystem->GetImage()->GetGraph("Image_02.png"), TRUE);

}