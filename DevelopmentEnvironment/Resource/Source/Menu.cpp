#include <DxLib.h>
#include "Menu.h"

//�R���X�g���N�^
Menu::Menu(ISceneChanger* _sceneChanger, ShareParameter* _shareParameter) :
	Scene(_sceneChanger, _shareParameter) {

}

//�X�V����
void Menu::Update(GameSystem* _gameSystem) {
	DrawString(0, 150, "���j���[�N���X�̍X�V�������s��", GetColor(255, 255, 255));
}

//�`�揈��
void Menu::Draw(GameSystem* _gameSystem) {
	DrawString(0, 200, "���j���[�N���X�̕`�揈�����s��", GetColor(255, 255, 255));
}