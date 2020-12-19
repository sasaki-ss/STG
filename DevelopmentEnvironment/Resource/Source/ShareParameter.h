#ifndef STG_SHAREPARAMETER_H
#define STG_SHAREPARAMETER_H

#include <map>
#include <string>

//共有パラメータクラス
class ShareParameter final {
private:
	std::map<std::string, int>shareDatum;
public:
	//コンストラクタ
	ShareParameter() = default;
	//デストラクタ
	~ShareParameter() = default;
	//データのセット
	void SetData(std::string _key, int _val);
	//データの取得
	int GetData(std::string _key)const;
};

#endif // !STG_SHAREPARAMETER_H