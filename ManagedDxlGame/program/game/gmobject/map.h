#pragma once
#include "m_chip.h"
#include "../camera/camera.h"
#include <list>

class Map {
private:

	Shared<MapChip> map_chip_;

	std::string gpc_map_chip_hdls_pass_;						//画像パス
	int map_chip_width_;										//マップチップの幅
	int map_chip_height_;										//マップチップの高さ
	int map_chip_all_size_;										//マップチップの総フレーム数
	int map_chip_x_size_;										//マップチップの横フレーム数
	int map_chip_y_size_;										//マップチップの縦フレーム数
	int* gpc_map_chip_hdls_;									//画像データ格納

	int bg_gpc_hdl_ = 0;										//背景

	std::string map_data_csv_pass_;								//マップCSVデータパス
	std::vector < std::vector <int>> map_data_;					//マップデータ

	

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