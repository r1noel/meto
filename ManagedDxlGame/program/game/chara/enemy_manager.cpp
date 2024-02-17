#include "../dxlib_ext/dxlib_ext.h"
#include "enemy_manager.h"

EnemyManager::EnemyManager(){

	map_ = std::make_shared<Map>();
	map_data_ = map_->getMapData();

	for (int y = 0; y < map_data_.size();++y) {
		for (int x = 0; x < map_data_[y].size();++x) {

			if (map_data_[y][x] == 98) {
				enemies_list_.emplace_back(std::make_shared<TrackingEnemy>());
			}
			if (map_data_[y][x] == 99) {
				enemies_list_.emplace_back(std::make_shared<ShootEnemy>());
			}
		
		}
	}
	
}
void EnemyManager::update(float delta_time) {

	auto it = enemies_list_.begin();
	while (it != enemies_list_.end()) {

		if (!(*it)->getAliveFlag()) {

		}
	}
}