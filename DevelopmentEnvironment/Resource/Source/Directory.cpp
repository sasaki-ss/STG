#include "Directory.h"

//指定したフォルダ内のファイル名取得処理
bool Directory::GetFileNames(std::string _folderPath, std::vector<std::string>& _file_names) {

	std::filesystem::directory_iterator iter(_folderPath);

	//指定したフォルダ内のすべてのファイル名を取得
	for (auto file : iter) {
		try {
			_file_names.push_back(file.path().string());
		}
		catch (...) {
			CloseSystem::ExitSystem(eCloseType::Read_Error);
			return false;
		}
	}

	return true;
}