#ifndef STG_CLOSESYSTEM_H
#define STG_CLOSESYSTEM_H

//�I���^�C�v
enum class eCloseType {
	Normal_Close,		//����I��
	Abnormal_Close,		//�ُ�I��
	Read_Error,			//�ǂݍ��ݎ��s
	Init_Error			//����������
};

//�I���V�X�e���N���X                                                      
class CloseSystem {
public:
	//�I������
	bool ExitSystem(eCloseType _closeType);
};

#endif // !STG_CLOSESYSTEM_H