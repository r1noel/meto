#pragma once
#include "../gmobject/map.h"
#include "../gmobject/m_chip.h"
#include "enemy_base.h"
#include "enemy.h"
#include <list>

class EnemyManager {
public:

	EnemyManager();
	~EnemyManager();
	void update(float delta_time);

	std::list<MapChip*> map_list_;
	std::list<EnemyBase*> enemies_list_;
	
	

private:

	Shared<Map> map_ = nullptr;
	std::vector < std::vector <int>> map_data_;


};