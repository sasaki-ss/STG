#ifndef STG_BULLETMANAGER_H
#define STG_BULLETMANAGER_H

#include "Task.h"
#include "GameSystem.h"
#include "Bullet.h"

enum class eBulletType {
	Player,
	Enemy1
};

//�e�Ǘ��N���X
class BulletManager final :public Task {
private:
	static const int MAX_BULLET_NUM = 1000;	//�e�̊Ǘ��̍ő吔
	Bullet* bullets[MAX_BULLET_NUM];		//�e�N���X

	int activeCount;	//�A�N�e�B�u�Ȓe�̐�

	//��������
	void Organize();
	//�폜����
	void Destroy();
public:
	BulletManager();
	~BulletManager();
	//�X�V����
	void Update(GameSystem* _gameSystem);
	//�`�揈��
	void Draw(GameSystem* _gameSystem);
	//�e��������
	void CreateBullet(float _x, float _y, eBulletType _type);
	//�A�N�e�B�u�Ȓe�̐����擾
	int GetActiveCount() { return activeCount; }

	//����Ȃ��q
	void Update() {}
	void Draw() {}
};

#endif // !STG_BULLETMANAGER_H