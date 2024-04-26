#include "../dxlib_ext/dxlib_ext.h"
#include "enemy_manager.h"
#include <algorithm>
#include"../chara/enemy.h"
#include "../common/gm_manager.h"

EnemyManager::EnemyManager(){

	//マップ情報取得
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
			//if (map_data_[y][x] == 99) {
			//	s_enemy_ = std::make_shared<ShootEnemy>(tnl::Vector3(x * map_chip_width_, y * map_chip_height_, 0), gpc_map_chip_hdls_[map_data_[y][x]]);
			//}
			
		}
	}
	
}

void EnemyManager::draw(const Shared<Camera> camera) {

	//auto it = enemies_list_.begin();
	//while (it != enemies_list_.end()) {

	//	(*it)->draw(camera);
	//	DrawRotaGraph((*it)->e_draw_pos_.x,(*it)-> e_draw_pos_.y, 1.0f, 0, 0, t_enemy_->getAnimeHdls(), true);

	//	s_enemy_->draw(camera);

	//	++it;
	//}

	for (auto& enemy : enemies_list_) {

		enemy->draw(camera);

	}


}

bool EnemyManager::sortDistanceList(Shared<EnemyBase>& enemy1, Shared<EnemyBase>& enemy2) {

	auto pos1 = enemy1->e_draw_pos_;
	float distance1 = GameManager::GetInstance()->GetPlayerDistance(pos1);
	auto pos2 = enemy2->e_draw_pos_;
	float distance2 = GameManager::GetInstance()->GetPlayerDistance(pos2);

	return distance1 < distance2;

}
void EnemyManager::update(float delta_time) {

	for (auto& enemy : enemies_list_) {

		//プレイヤーとの当たり判定	
		bool isEnemyHit = GameManager::GetInstance()->isIntersectPlayerAndEnemy();

		if (isEnemyHit)
			GameManager::GetInstance()->deathPlayer();
	}

	for (auto& enemy : enemies_list_) {

		enemy->update(delta_time);
	}

}