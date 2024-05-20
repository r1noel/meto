#pragma once
#include "../gmobject/map.h"
#include "../gmobject/m_chip.h"
#include "../camera/camera.h"
#include "enemy_base.h"
#include "enemy.h"
#include <list>

class EnemyManager {
public:

	EnemyManager();
	virtual ~EnemyManager() {};
	void update(float delta_time);
	void draw(const Shared<Camera> camera);


	//std::list<MapChip*> map_list_;
	//std::list<Shared<EnemyBase>> enemies_list_;
	std::list<Shared<TrackingEnemy>> enemies_list_;
	
	

private:

	bool sortDistanceList(Shared<EnemyBase>& enemy1, Shared<EnemyBase>& enemy2);

	Shared<Map> map_ = nullptr;

	Shared<TrackingEnemy> t_enemy_ = nullptr;
	Shared<ShootEnemy> s_enemy_ = nullptr;

	std::vector < std::vector <int>> map_data_;
	std::string gpc_map_chip_hdls_pass_;						//画像パス
	int map_chip_width_;										//マップチップの幅
	int map_chip_height_;										//マップチップの高さ
	int map_chip_all_size_;										//マップチップの総フレーム数
	int map_chip_x_size_;										//マップチップの横フレーム数
	int map_chip_y_size_;										//マップチップの縦フレーム数
	int* gpc_map_chip_hdls_;									//画像データ格納

};