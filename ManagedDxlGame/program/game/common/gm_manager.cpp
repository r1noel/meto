#include "../dxlib_ext/dxlib_ext.h"
#include "gm_manager.h"
#include "gm_scene_base.h"

GameManager::GameManager(SceneBase* start_scene) : now_scene_(start_scene) {

}

GameManager* GameManager::GetInstance(SceneBase* start_scene) {

	static GameManager* instance = nullptr;
	if (!instance) {
		instance = new GameManager(start_scene);

	}
	return instance;
}

void GameManager::Destroy() {

	delete GetInstance();
}

void GameManager::changeScene(SceneBase* next_scene) {

	next_scene_ = next_scene;
	now_scene_ = next_scene_;

}

void GameManager::update(float delta_time) {

	if (now_scene_) now_scene_->update(delta_time);
	if (now_scene_) now_scene_->draw();

	//DrawStringEx(10, 10, -1, "%x", GetInstance());


	
}