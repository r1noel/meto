#include "../dxlib_ext/dxlib_ext.h"
#include "m_chip.h"

void MapChip::update(float delta_time, const Shared<Camera> camera) {

	for (auto mpc : map_chips) {
		DrawBoxEx(mpc->map_chip_pos_, MapChip::CHIP_SIZE, MapChip::CHIP_SIZE, false);
	}

	draw_pos = map_chip_pos_ - camera->target_+ tnl::Vector3(DXE_WINDOW_WIDTH >> 1, DXE_WINDOW_HEIGHT >> 1, 0);
}