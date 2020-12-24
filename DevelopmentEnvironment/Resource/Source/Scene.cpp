#include "Scene.h"

//コンストラクタ
Scene::Scene(ISceneChanger* _sceneChanger, ShareParameter* _shareParameter,
	GameSystem* _gameSystem) {
	sceneChanger = _sceneChanger;
	shareParameter = _shareParameter;
	gameSystem = _gameSystem;
}