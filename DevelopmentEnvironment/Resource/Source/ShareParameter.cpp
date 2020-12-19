#include "ShareParameter.h"

//�f�[�^�̃Z�b�g
void ShareParameter::SetData(std::string _key, int _val) {
	//�A�z�z��Ɋi�[
	shareDatum[_key] = _val;
}

//�f�[�^�̎擾
int ShareParameter::GetData(std::string _key)const {
	//�w��L�[���擾
	auto it = shareDatum.find(_key);

	//�w��L�[�̗v�f�����݂��Ȃ��ꍇ
	if (shareDatum.end() == it) {
		return -1;
	}

	return it->second;
}