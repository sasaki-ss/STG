#ifndef STG_SHAREPARAMETER_H
#define STG_SHAREPARAMETER_H

#include <map>
#include <string>

//���L�p�����[�^�N���X
class ShareParameter final {
private:
	std::map<std::string, int>shareDatum;
public:
	//�R���X�g���N�^
	ShareParameter() = default;
	//�f�X�g���N�^
	~ShareParameter() = default;
	//�f�[�^�̃Z�b�g
	void SetData(std::string _key, int _val);
	//�f�[�^�̎擾
	int GetData(std::string _key)const;
};

#endif // !STG_SHAREPARAMETER_H