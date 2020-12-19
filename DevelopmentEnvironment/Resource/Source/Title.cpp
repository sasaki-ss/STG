#include <DxLib.h>
#include "Title.h"

//�R���X�g���N�^
Title::Title(ISceneChanger* _sceneChanger, ShareParameter* _shareParameter) :
	Scene(_sceneChanger, _shareParameter) {

}

//�X�V����
void Title::Update() {
	//�X�y�[�X�L�[����͂����ۂɎ��s
	if (CheckHitKey(KEY_INPUT_SPACE) != 0) {
		sceneChanger->SceneChange(eScene::InGame, shareParameter, true, false);
	}

	if (CheckHitKey(KEY_INPUT_W) != 0) {
		sceneChanger->SceneChange(eScene::Menu, shareParameter, true, false);
	}

	DrawString(0, 150, "�^�C�g���N���X�̍X�V�������s��", GetColor(255, 255, 255));
}

//�`�揈��
void Title::Draw() {
	DrawString(0, 200, "�^�C�g���N���X�̕`�揈�����s��", GetColor(255, 255, 255));
}