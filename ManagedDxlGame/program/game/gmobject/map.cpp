#include "../dxlib_ext/dxlib_ext.h"
#include "map.h"

Map::Map() {

	//ステージ背景画像ハンドル
	bg_gpc_hdl_ = LoadGraph("graphics/bochi3.jpg");
	//マップチップ画像ハンドル
	gpc_map_chip_hdls_pass_ = "graphics/mapchip.png";

	//マップチップの情報入力
	map_chip_width_ = 48;
	map_chip_height_ = 48;
	map_chip_x_size_ = 5;
	map_chip_y_size_ = 9;
	map_chip_all_size_ = map_chip_x_size_ * map_chip_y_size_;
	gpc_map_chip_hdls_ = new int[map_chip_all_size_];

	//マップチップ画像読込
	LoadDivGraph(gpc_map_chip_hdls_pass_.c_str(),
		map_chip_all_size_,
		map_chip_x_size_,
		map_chip_y_size_,
		map_chip_width_,
		map_chip_height_,
		gpc_map_chip_hdls_);

	//マップCSVデータのロード
	map_data_csv_pass_ = "csv/map2.csv";
	//マップデータにCSVの情報を持たせる
	map_data_ = tnl::LoadCsv<int>(map_data_csv_pass_);

	//マップチップCSVデータの呼び出し
	for (int y = 0; y < map_data_.size();++y) {
		for (int x = 0; x < map_data_[y].size();++x) {
			
			if (map_data_[y][x] == -1) continue;
				map_list_.emplace_back(new MapChip(tnl::Vector3(x * map_chip_width_, y * map_chip_height_, 0)));

			
		}
	}
}

void Map::draw(const Shared<Camera> camera) {

	//ステージの表示
	auto it = map_list_.begin();
	while (it != map_list_.end()) {

		DrawRotaGraph((*it)->draw_pos.x, (*it)->draw_pos.y, 1.0, 0, gpc_map_chip_hdls_[static_cast<int>((*it)->chipType_)], true);
		
		DrawBoxEx((*it)->draw_pos, MapChip::CHIP_SIZE, MapChip::CHIP_SIZE, false);
		++it;
	}
}

void Map::update(float delta_time, const Shared<Camera> camera) {

	auto it = map_list_.begin();
	while (it != map_list_.end()) {

		(*it)->update(delta_time, camera);

		++it;
	}

}

int Map::getWidth() {

	return map_chip_width_;

}

int Map::getHeight() {

	return map_chip_height_;

}

int Map::getGpcHdl() {

	return bg_gpc_hdl_;

}