#ifndef STG_TASK_H
#define STG_TASK_H

#include "GameSystem.h"

//�^�X�N�N���X
class Task {
public:
	//����������
	virtual void Init(){}
	//�I������
	virtual void Final(){}
	//�X�V����
	virtual void Update(GameSystem* _gameSystem) = 0;
	//�`�揈��
	virtual void Draw(GameSystem* _gameSystem) = 0;
};

#endif // !STG_TASK_H