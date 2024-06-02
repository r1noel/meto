#pragma once
#include "m_chip.h"
#include "../camera/camera.h"
#include <list>
#include <vector>

class Map {
private:

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
	std::string maphit_data_csv_pass_;							//マップ当たり判定用CSVデータパス
	std::vector < std::vector <int>> maphit_data_;				//マップ当たり判定用データ

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