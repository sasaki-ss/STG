#ifndef STG_BULLETMANAGER_H
#define STG_BULLETMANAGER_H

#include <string>
#include "Task.h"
#include "GameSystem.h"
#include "Bullet.h"

using namespace std;

enum class eBulletType {
	Player,
	Enemy_Normal
};

//�e�Ǘ��N���X
class BulletManager final :public Task {
private:
	static const int MAX_BULLET_NUM = 1000;	//�e�̍ő吔
	Bullet* bullets[MAX_BULLET_NUM];		//�e�N���X

	int activeCount;	//�A�N�e�B�u�Ȓe�̐�

	//��������
	void Organize();
	//�폜����
	void Destroy();
public:
	//�R���X�g���N�^
	BulletManager();
	//�f�X�g���N�^
	~BulletManager();
	//�X�V����
	void Update(GameSystem* _gameSystem);
	//�`�揈��
	void Draw(GameSystem* _gameSystem);
	//�e��������
	void CreateBullet(float _x, float _y, eBulletType _type);
	//�A�N�e�B�u�Ȓe�̐����擾
	int GetActiveCount() { return activeCount; }
	//���W���擾����
	Pos GetPos(int _num);
	//�������擾����
	float GetWidth(int _num);
	//�������擾����
	float GetHeight(int _num);
	//�A�N�e�B�u��Ԃ��擾����
	bool GetIsActive(int _num);
	//�^�O���擾����
	string GetTag(int _num);
	//�A�N�e�B�u�t���O���Z�b�g����
	void SetIsActive(int _num, bool _isActive);
};

#endif // !STG_BULLETMANAGER_H