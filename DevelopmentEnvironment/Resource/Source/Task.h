#ifndef STG_TASK_H
#define STG_TASK_H

//�^�X�N�N���X
class Task {
public:
	//����������
	virtual void Init(){}
	//�I������
	virtual void Final(){}
	//�X�V����
	virtual void Update() = 0;
	//�`�揈��
	virtual void Draw() = 0;
};

#endif // !STG_TASK_H