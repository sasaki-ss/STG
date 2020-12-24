#include "Directory.h"

//�w�肵���t�H���_���̃t�@�C�����擾����
bool Directory::GetFileNames(std::string _folderPath, std::vector<std::string>& _file_Names,
	std::vector<std::string>& _file_Path) {

	std::filesystem::directory_iterator iter(_folderPath);

	//�w�肵���t�H���_���̂��ׂẴt�@�C�����A�t�@�C���p�X���擾
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

//�t�@�C���p�X��\\��/�ɒu�������鏈��
std::string Directory::ChangeFilePath(std::string _filePath) {
	//�t�@�C���p�X����\\���T�[�`
	std::string::size_type pos(_filePath.find("\\"));

	//�t�@�C���p�X�̂��ׂĂ�\\��/�ɒu��������
	while (pos != std::string::npos) {
		_filePath.replace(pos, 1, "/");
		//\\���ăT�[�`
		pos = _filePath.find("\\", pos + 1);
	}

	return _filePath;
}

//�t�@�C���p�X����t�@�C�����𔲂��o������
std::string Directory::ExtractFileName(std::string _filePath) {
	std::vector<std::string> splitFilePaths;	//���������t�@�C���p�X
	std::string tmpSplitPath = "";				//�����p�̉��u��������
	char searchString = '\\';					//�T�[�`���镶��

	//�t�@�C���p�X�𕪊�
	for (int i = 0; i < _filePath.length(); i++) {
		//_filePath[i]��\\�����肵�A\\����Ȃ��ꍇ
		if (_filePath[i] != searchString) {
			tmpSplitPath += _filePath[i];

			//�Ō�̃��[�v����Ȃ��ꍇ
			if (i != _filePath.length() - 1)continue;
		}
		
		//���u���̕�����𕪊������t�@�C���p�X�֊i�[����
		splitFilePaths.push_back(tmpSplitPath);

		//���u���̕������������
		tmpSplitPath = "";
	}

	return splitFilePaths[splitFilePaths.size() - 1];
}