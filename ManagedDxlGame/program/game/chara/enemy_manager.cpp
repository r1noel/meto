#include "../dxlib_ext/dxlib_ext.h"
#include "enemy_manager.h"

EnemyManager::EnemyManager(){

	//ƒ}ƒbƒvî•ñæ“¾
	map_ = std::make_shared<Map>();
	map_data_ = map_->getMapData();

	//t_enemy_ = std::make_shared<TrackingEnemy>();
	//s_enemy_ = std::make_shared<ShootEnemy>();

	map_chip_width_ = 48;
	map_chip_height_ = 48;
	map_chip_x_size_ = 5;
	map_chip_y_size_ = 9;
	map_chip_all_size_ = map_chip_x_size_ * map_chip_y_size_;
	gpc_map_chip_hdls_ = new int[map_chip_all_size_];

	for (int y = 0; y < map_data_.size();++y) {
		for (int x = 0; x < map_data_[y].size();++x) {

			if (map_data_[y][x] == 98) {
				enemies_list_.emplace_back(std::make_shared<TrackingEnemy>(tnl::Vector3(x * map_chip_width_, y * map_chip_height_, 0), gpc_map_chip_hdls_[map_data_[y][x]]));
			}
			if (map_data_[y][x] == 99) {
				s_enemy_ = std::make_shared<ShootEnemy>(tnl::Vector3(x * map_chip_width_, y * map_chip_height_, 0), gpc_map_chip_hdls_[map_data_[y][x]]);
			}
			
		}
	}
	
}

void EnemyManager::draw(const Shared<Camera> camera) {

	auto it = enemies_list_.begin();
	while (it != enemies_list_.end()) {

		(*it)->draw(camera);
		DrawRotaGraph((*it)->e_draw_pos_.x,(*it)-> e_draw_pos_.y, 1.0f, 0, 0, t_enemy_->getAnimeHdls(), true);

		s_enemy_->draw(camera);

		++it;
	}


}

void EnemyManager::update(float delta_time) {

	t_enemy_->update(delta_time);
	s_enemy_->update(delta_time);
	//auto it = enemies_list_.begin();
	//while (it != enemies_list_.end()) {

	//	(*it)->update(delta_time, camera);
	//	//if (!(*it)->getAliveFlag()) {

	//	//}

	//	++it;
	//}

}