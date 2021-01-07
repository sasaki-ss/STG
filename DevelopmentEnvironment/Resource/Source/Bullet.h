#ifndef STG_BULLET_H
#define STG_BULLET_H

#include <string>
#include "Object.h"

using namespace std;

class Bullet :public virtual Object {
protected:
	float moveSpeed;	//�ړ����x
	string tag;			//�^�O
public:
	//�R���X�g���N�^
	Bullet(float _x, float _y, float _width, float _height,
		float _moveSpeed, string _tag);
	//�X�V����
	virtual void Update(GameSystem* _gameSystem);
	//�`�揈��
	virtual void Draw(GameSystem* _gameSystem);
	//�^�O���擾����
	string GetTag() { return tag; }
	//�A�N�e�B�u�t���O���Z�b�g����
	void SetIsActive(bool _isActive) { isActive = _isActive; }
};

#endif // !STG_BULLET_H