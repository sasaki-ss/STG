#ifndef STG_RUNSYSTEM_H
#define STG_RUNSYSTEM_H

#include "CloseSystem.h"

//���s�V�X�e���N���X
class RunSystem final :public CloseSystem {
public:
	//����������
	void Init();
	//���s����
	void Run();
	//�I������
	void End();
};

#endif // !STG_RUNSYSTEM_H