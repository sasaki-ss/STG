#include "ShareParameter.h"

//データのセット
void ShareParameter::SetData(std::string _key, int _val) {
	//連想配列に格納
	shareDatum[_key] = _val;
}

//データの取得
int ShareParameter::GetData(std::string _key)const {
	//指定キーを取得
	auto it = shareDatum.find(_key);

	//指定キーの要素が存在しない場合
	if (shareDatum.end() == it) {
		return -1;
	}

	return it->second;
}