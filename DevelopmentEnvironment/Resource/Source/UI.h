#ifndef STG_UI_H
#define STG_UI_H

#include "Task.h"

//�Q�[����ʂɕ\������UI�N���X
class UI final {
private:

public:
	//�X�V����
	void Update(GameSystem* _gameSystem);
	//�`�揈��
	void Draw(GameSystem* _gameSystem);
};

#endif // !STG_UI_H