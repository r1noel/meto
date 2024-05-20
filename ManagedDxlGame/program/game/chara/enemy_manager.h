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
	std::string gpc_map_chip_hdls_pass_;						//�摜�p�X
	int map_chip_width_;										//�}�b�v�`�b�v�̕�
	int map_chip_height_;										//�}�b�v�`�b�v�̍���
	int map_chip_all_size_;										//�}�b�v�`�b�v�̑��t���[����
	int map_chip_x_size_;										//�}�b�v�`�b�v�̉��t���[����
	int map_chip_y_size_;										//�}�b�v�`�b�v�̏c�t���[����
	int* gpc_map_chip_hdls_;									//�摜�f�[�^�i�[

};