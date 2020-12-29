#ifndef STG_OBJECT_H
#define STG_OBJECT_H

#include "Task.h"
#include "GameSystem.h"

//�I�u�W�F�N�g�N���X
//�S�ẴQ�[���I�u�W�F�N�g�Ɍp��������
class Object :public Task {
private:
	//���W�\����
	typedef struct {
		float x;
		float y;
		float cx;
		float cy;
	}Pos;
protected:
	Pos pos;		//���W
	float width;	//����
	float height;	//����
	bool isActive;	//�A�N�e�B�u�t���O
public:
	//����������
	virtual void Init(){}
	//�I������
	virtual void Final(){}
	//�X�V����
	virtual void Update(GameSystem* _gameSystem) = 0;
	//�`�揈��
	virtual void Draw(GameSystem* _gameSystem) = 0;
	//���W���擾����
	Pos GetPos() { return pos; }
	//�������擾
	float GetWidth() { return width; }
	//�������擾
	float GetHeight() { return height; }
	//�A�N�e�B�u�t���O���擾
	bool GetIsActive() { return isActive; }
};

#endif // !STG_OBJECT_H