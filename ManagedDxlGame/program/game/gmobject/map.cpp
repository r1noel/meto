#include "../dxlib_ext/dxlib_ext.h"
#include "map.h"

Map::Map() {

	//�X�e�[�W�w�i�摜�n���h��
	bg_gpc_hdl_ = LoadGraph("graphics/bochi3.jpg");
	//�}�b�v�`�b�v�摜�n���h��
	gpc_map_chip_hdls_pass_ = "graphics/mapchip.png";

	//�}�b�v�`�b�v�̏�����
	map_chip_width_ = 48;
	map_chip_height_ = 48;
	map_chip_x_size_ = 5;
	map_chip_y_size_ = 9;
	map_chip_all_size_ = map_chip_x_size_ * map_chip_y_size_;
	gpc_map_chip_hdls_ = new int[map_chip_all_size_];

	//�}�b�v�`�b�v�摜�Ǎ�
	LoadDivGraph(gpc_map_chip_hdls_pass_.c_str(),
		map_chip_all_size_,
		map_chip_x_size_,
		map_chip_y_size_,
		map_chip_width_,
		map_chip_height_,
		gpc_map_chip_hdls_);
	//�}�b�vCSV�f�[�^�̃��[�h
	map_data_csv_pass_ = "csv/map2.csv";
	//�}�b�v�f�[�^��CSV�̏�����������
	map_data_ = tnl::LoadCsv<int>(map_data_csv_pass_);

	mapChipList.resize(map_data_.size());
	voidGraph = LoadGraph("graphics/blue.bmp");

	//�}�b�v�`�b�vCSV�f�[�^�̌Ăяo��
	for (int y = 0; y < map_data_.size();++y) {
		for (int x = 0; x < map_data_[y].size();++x) {
			
			int chipNum = map_data_[y][x];

			int handle = 0;
			if (chipNum == -1) {
				handle = voidGraph;
			}
			else {
				handle = gpc_map_chip_hdls_[chipNum];
			}

			auto mapchip = new MapChip(tnl::Vector3(x * map_chip_width_, y * map_chip_height_, 0), handle, chipNum);
			mapChipList[y].emplace_back(mapchip);


			if (chipNum == -1) continue;
				map_list_.emplace_back(new MapChip(tnl::Vector3(x * map_chip_width_, y * map_chip_height_, 0), gpc_map_chip_hdls_[map_data_[y][x]],chipNum));
			
		}
	}

}

void Map::draw(const Shared<Camera> camera) {

	for (int i = 0; i < mapChipList.size(); ++i) {
		for (int k = 0; k < mapChipList[i].size();++k) {
			auto& chip = mapChipList[i][k];
			chip->draw(camera);
		}
	}

	//�X�e�[�W�̕\��
	//auto it = map_list_.begin();
	//while (it != map_list_.end()) {

	//	(*it)->draw(camera);

	//	DrawRotaGraph((*it)->draw_pos.x, (*it)->draw_pos.y, 1.0, 0,(*it)-> map_chip_gpc_hdl_, true);

	//	//DrawBoxEx((*it)->draw_pos, MapChip::CHIP_SIZE, MapChip::CHIP_SIZE, false);
	//	++it;
	//}
}

//void Map::update(float delta_time, const Shared<Camera> camera) {
//
//	//auto it = map_list_.begin();
//	//while (it != map_list_.end()) {
//
//	//	
//	//	++it;
//	//}
//
//}

int Map::getWidth() {

	return map_chip_width_;

}

int Map::getHeight() {

	return map_chip_height_;

}

int Map::getGpcHdl() {

	return bg_gpc_hdl_;

}

std::vector < std::vector <int>> Map::getMapData() {

	return map_data_ = tnl::LoadCsv<int>(map_data_csv_pass_);
}

MapChip* Map::getMapChip(int xPos, int yPos) {
	MapChip* ret = nullptr;

	//0~48��������0��Ԃ�,49~96��������1��Ԃ�
	int xIndex = (xPos / 48) - 1;
	int yIndex = (yPos / 48) - 1;

	if (xIndex < 0 || yIndex < 0 || 300 < xIndex || 200 < yIndex) {
		//�G���[
		//tnl::DebugTrace("�z��O�Q��");
	}

	ret = mapChipList[yIndex][xIndex];

	return ret;
}