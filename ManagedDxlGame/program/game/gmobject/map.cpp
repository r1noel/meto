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
	map_data_csv_pass_ = "csv/map1.csv";
	//�}�b�v�f�[�^��CSV�̏�����������
	map_data_ = tnl::LoadCsv<int>(map_data_csv_pass_);

	maphit_data_csv_pass_ = "csv/maphit.csv";

	maphit_data_ = tnl::LoadCsv<int>(maphit_data_csv_pass_);

	mapChipList.resize(map_data_.size());
	maphitChipList.resize(maphit_data_.size());
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

			

			
		}
	}

	for (int y = 0; y < maphit_data_.size();++y) {
		for (int x = 0; x < maphit_data_.size();++x) {

			int chipNum2 = maphit_data_[y][x];
			int handle2 = 0;
		
			auto maphitchip = new MapChip(tnl::Vector3(x * map_chip_width_, y * map_chip_height_, 0), handle2, chipNum2);
			maphitChipList[y].emplace_back(maphitchip);
			if (chipNum2 == -1) continue;
			map_list_.emplace_back(new MapChip(tnl::Vector3(x * map_chip_width_, y * map_chip_height_, 0), gpc_map_chip_hdls_[maphit_data_[y][x]], chipNum2));
		}
	}
}

void Map::draw(const Shared<Camera> camera) {
	//�X�e�[�W�̕\��
	for (int i = 0; i < mapChipList.size(); ++i) {
		for (int k = 0; k < mapChipList[i].size();++k) {
			auto& chip = mapChipList[i][k];
			chip->draw(camera);
		}
	}
	//for (int i = 0; i < maphitChipList.size(); ++i) {
	//	for (int k = 0; k < maphitChipList[i].size();++k) {
	//		auto& chip = maphitChipList[i][k];
	//		chip->draw(camera);
	//	}
	//}

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