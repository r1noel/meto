#include "../dxlib_ext/dxlib_ext.h"
#include "gm_manager.h"
#include "gm_scene_base.h"
#include"../chara/player.h"
#include"../gmobject/m_chip.h"
#include"../gmobject/map.h"
#include<math.h>
#include"../chara/enemy.h"
#include"../chara/enemy_base.h"
#include"../chara/enemy_manager.h"


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

Shared<Player> GameManager::getPlayer() {

	//�v���C���[�������ĂȂ����������Ă���Ԃ�
	if (player_ == nullptr) {
		player_ = std::make_shared<Player>();
	}
	return player_;

}

Shared<Map> GameManager::getMap() {

	//�}�b�v�������ĂȂ����������Ă���Ԃ�
	if (map_ == nullptr) {
		map_ = std::make_shared<Map>();
	}
	return map_;

}

Shared<EnemyManager> GameManager::getEnemyManager() {

	//�G�l�~�[�������ĂȂ����������Ă���Ԃ�
	if (enemyManager_ == nullptr) {
		enemyManager_ = std::make_shared<EnemyManager>();
	}
	return enemyManager_;

}

MapChip* GameManager::getMapChip(int x, int y) {

	if (map_ == nullptr)
		return nullptr;
	return map_->getMapChip(x, y);

}
//�v���C���[�ƃG�l�~�[�̋����擾
float GameManager::GetPlayerDistance(tnl::Vector3& enemyPos) {

	float ret = 0.0f;

	auto playerPos = player_->getPlayerPos();

	float xDif = playerPos.x - enemyPos.x;
	float yDif = playerPos.y - enemyPos.y;

	//���� =sqrt( (x1-x2)^2 +(y1-y2)^2 )
	ret = std::sqrt(xDif * xDif + yDif * yDif);

	return ret;

}
//�v���C���[�G�l�~�[��������
bool GameManager::isIntersectPlayerAndEnemy() {

	auto& enemyList = enemyManager_->enemies_list_;
	
	for (auto& enemy : enemyList) {


		float distance = GetPlayerDistance(enemy->getEnemyPos());

		//����������5�ȉ���������
		if (distance <= 25) {

			return true;
		}

	}

	return false;
}
void GameManager::deathPlayer() {

	player_->setDeathFlag(true);

}