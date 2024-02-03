#pragma once
#include "m_chip.h"
#include "../camera/camera.h"
#include <list>

class Map {
private:

	Shared<MapChip> map_chip_;

	std::string gpc_map_chip_hdls_pass_;						//�摜�p�X
	int map_chip_width_;										//�}�b�v�`�b�v�̕�
	int map_chip_height_;										//�}�b�v�`�b�v�̍���
	int map_chip_all_size_;										//�}�b�v�`�b�v�̑��t���[����
	int map_chip_x_size_;										//�}�b�v�`�b�v�̉��t���[����
	int map_chip_y_size_;										//�}�b�v�`�b�v�̏c�t���[����
	int* gpc_map_chip_hdls_;									//�摜�f�[�^�i�[

	int bg_gpc_hdl_ = 0;										//�w�i

	std::string map_data_csv_pass_;								//�}�b�vCSV�f�[�^�p�X
	std::vector < std::vector <int>> map_data_;					//�}�b�v�f�[�^

	

	tnl::Vector3 pos_;

public:

	Map();

	void update(float delta_time, const std::shared_ptr<Camera> camera);
	void draw(const std::shared_ptr<Camera> camera);
	std::list<MapChip*> map_list_;
	
	int getWidth();
	int getHeight();
	int getGpcHdl();

};