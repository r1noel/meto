#pragma once
#include "../camera/camera.h"

class MapChip {
public:

	MapChip(const tnl::Vector3& pos, int gpc_hdl,int Chipnum) : map_chip_pos_(pos), map_chip_gpc_hdl_(gpc_hdl),chipNum(Chipnum){};

	static constexpr float CHIP_SIZE = 48;

	int map_chip_gpc_hdl_ = 0;

	tnl::Vector3 map_chip_pos_ {0, 0, 0};

	void draw(const Shared<Camera> camera);
	tnl::Vector3 draw_pos;

	int GetChipNum() { return chipNum; }

private:

	int chipNum = -1;
	
};