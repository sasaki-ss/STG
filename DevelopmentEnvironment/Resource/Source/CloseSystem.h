#ifndef STG_CLOSESYSTEM_H
#define STG_CLOSESYSTEM_H

//終了タイプ
enum class eCloseType {
	Normal_Close,		//正常終了
	Abnormal_Close,		//異常終了
	Read_Error,			//読み込み失敗
	Init_Error			//初期化処理
};

//終了システムクラス                                                      
class CloseSystem {
public:
	//終了処理
	bool ExitSystem(eCloseType _closeType);
};

#endif // !STG_CLOSESYSTEM_H