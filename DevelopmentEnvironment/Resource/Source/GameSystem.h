#ifndef STG_GAMESYSTEM_H
#define STG_GAMESYSTEM_H

#include "Image.h"

/*
����
�p������`�ɂ���ꍇ������������p����̃I�u�W�F�N�g���j�����ꂽ�ۂɃ��\�[�X��Ԃ���...?
*/

//�Q�[���V�X�e���N���X
class GameSystem {
private:
	Image* image;	//�摜�N���X
public:
	//�R���X�g���N�^
	GameSystem();
	//�f�X�g���N�^
	virtual ~GameSystem();
	//����������
	bool Init();

	//�摜�N���X���擾����
	Image* GetImage() { return image; }
};

#endif // !STG_GAMESYSTEM_H