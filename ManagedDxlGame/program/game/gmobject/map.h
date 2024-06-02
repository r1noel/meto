#pragma once
#include "m_chip.h"
#include "../camera/camera.h"
#include <list>
#include <vector>

class Map {
private:

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
	std::string maphit_data_csv_pass_;							//�}�b�v�����蔻��pCSV�f�[�^�p�X
	std::vector < std::vector <int>> maphit_data_;				//�}�b�v�����蔻��p�f�[�^

	//tnl::Vector3 pos_;

	int voidGraph = 0;

public:

	Map();

	void update(float delta_time);
	void draw(const Shared<Camera> camera);
	std::list<MapChip*> map_list_;

	std::vector<std::vector<MapChip*>> mapChipList;
	std::vector<std::vector<MapChip*>> maphitChipList;
	
	int getWidth();
	int getHeight();
	int getGpcHdl();
	std::vector < std::vector <int>> getMapData();

	MapChip* getMapChip(int xPos, int yPos);

};