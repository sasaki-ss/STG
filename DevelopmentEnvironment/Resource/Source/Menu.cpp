#include <DxLib.h>
#include "Menu.h"

//�R���X�g���N�^
Menu::Menu(ISceneChanger* _sceneChanger, ShareParameter* _shareParameter,
	GameSystem* _gameSystem) :
	Scene(_sceneChanger, _shareParameter, _gameSystem) {

}

//�X�V����
void Menu::Update() {
	DrawString(0, 150, "���j���[�N���X�̍X�V�������s��", GetColor(255, 255, 255));
}

//�`�揈��
void Menu::Draw() {
	DrawString(0, 200, "���j���[�N���X�̕`�揈�����s��", GetColor(255, 255, 255));
}