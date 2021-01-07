#include <DxLib.h>
#include "BulletP.h"

//�R���X�g���N�^
BulletP::BulletP(float _x, float _y, float _width, float _height,
	float _moveSpeed, string _tag) :
	Bullet(_x, _y, _width, _height, _moveSpeed, _tag) {

}

//�X�V����
void BulletP::Update(GameSystem* _gameSystem) {
	//��ʊO�ɒe���o���ꍇ
	if (pos.y + height <= 0) {
		isActive = false;
		return;
	}

	pos.y -= moveSpeed;
}

//�`�揈��
void BulletP::Draw(GameSystem* _gameSystem) {
	DrawGraph(pos.x, pos.y, _gameSystem->GetImage()->GetGraph("Bullet_01.png"), TRUE);
}