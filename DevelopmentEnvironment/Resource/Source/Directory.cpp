#include "Directory.h"

//�w�肵���t�H���_���̃t�@�C�����擾����
bool Directory::GetFileNames(std::string _folderPath, std::vector<std::string>& _file_names) {

	std::filesystem::directory_iterator iter(_folderPath);

	//�w�肵���t�H���_���̂��ׂẴt�@�C�������擾
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