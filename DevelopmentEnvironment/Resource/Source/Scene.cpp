#include "Scene.h"

//�R���X�g���N�^
Scene::Scene(ISceneChanger* _sceneChanger, ShareParameter* _shareParameter,
	GameSystem* _gameSystem) {
	sceneChanger = _sceneChanger;
	shareParameter = _shareParameter;
	gameSystem = _gameSystem;
}