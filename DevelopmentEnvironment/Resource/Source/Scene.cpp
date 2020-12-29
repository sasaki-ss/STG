#include "Scene.h"

//コンストラクタ
Scene::Scene(ISceneChanger* _sceneChanger, ShareParameter* _shareParameter) {
	sceneChanger = _sceneChanger;
	shareParameter = _shareParameter;
}