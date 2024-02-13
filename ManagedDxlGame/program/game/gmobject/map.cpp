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

	//�}�b�v�`�b�vCSV�f�[�^�̌Ăяo��
	for (int y = 0; y < map_data_.size();++y) {
		for (int x = 0; x < map_data_[y].size();++x) {
			
			if (map_data_[y][x] == -1) continue;
				map_list_.emplace_back(new MapChip(tnl::Vector3(x * map_chip_width_, y * map_chip_height_, 0)));

			
		}
	}
}

void Map::draw(const Shared<Camera> camera) {

	//�X�e�[�W�̕\��
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