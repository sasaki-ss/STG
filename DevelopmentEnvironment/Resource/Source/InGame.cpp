#include <DxLib.h>
#include "InGame.h"

//�R���X�g���N�^
InGame::InGame(ISceneChanger* _sceneChanger, ShareParameter* _shareParameter) :
	Scene(_sceneChanger, _shareParameter) {

}

//�X�V����
void InGame::Update() {
	DrawString(0, 150, "�C���Q�[���N���X�̍X�V�������s��", GetColor(255, 255, 255));
}

//�`�揈��
void InGame::Draw() {
	DrawString(0, 200, "�C���Q�[���N���X�̕`�揈�����s��", GetColor(255, 255, 255));
}