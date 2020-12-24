#include "Directory.h"

//指定したフォルダ内のファイル名取得処理
bool Directory::GetFileNames(std::string _folderPath, std::vector<std::string>& _file_Names,
	std::vector<std::string>& _file_Path) {

	std::filesystem::directory_iterator iter(_folderPath);

	//指定したフォルダ内のすべてのファイル名、ファイルパスを取得
	for (auto file : iter) {
		try {
			_file_Names.push_back(Directory::ExtractFileName(file.path().string()));
			_file_Path.push_back(Directory::ChangeFilePath(file.path().string()));
		}
		catch (...) {
			CloseSystem::ExitSystem(eCloseType::Read_Error);
			return false;
		}
	}

	return true;
}

//ファイルパスの\\を/に置き換える処理
std::string Directory::ChangeFilePath(std::string _filePath) {
	//ファイルパスから\\をサーチ
	std::string::size_type pos(_filePath.find("\\"));

	//ファイルパスのすべての\\を/に置き換える
	while (pos != std::string::npos) {
		_filePath.replace(pos, 1, "/");
		//\\を再サーチ
		pos = _filePath.find("\\", pos + 1);
	}

	return _filePath;
}

//ファイルパスからファイル名を抜き出す処理
std::string Directory::ExtractFileName(std::string _filePath) {
	std::vector<std::string> splitFilePaths;	//分割したファイルパス
	std::string tmpSplitPath = "";				//分割用の仮置き文字列
	char searchString = '\\';					//サーチする文字

	//ファイルパスを分割
	for (int i = 0; i < _filePath.length(); i++) {
		//_filePath[i]が\\か判定し、\\じゃない場合
		if (_filePath[i] != searchString) {
			tmpSplitPath += _filePath[i];

			//最後のループじゃない場合
			if (i != _filePath.length() - 1)continue;
		}
		
		//仮置きの文字列を分割したファイルパスへ格納する
		splitFilePaths.push_back(tmpSplitPath);

		//仮置きの文字列を初期化
		tmpSplitPath = "";
	}

	return splitFilePaths[splitFilePaths.size() - 1];
}