#ifndef STG_BACKGROUND_H
#define STG_BACKGROUND_H

#include "Task.h"

//�Q�[����ʂɕ\������Background�N���X
class Background final {
private:

public:
	//�X�V����
	void Update(GameSystem* _gameSystem);
	//�`�揈��
	void Draw(GameSystem* _gameSystem);
};

#endif // !STG_BACKGROUND_H
