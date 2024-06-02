#include "../dxlib_ext/dxlib_ext.h"
#include "m_chip.h"

void MapChip::draw(const Shared<Camera> camera) {

	draw_pos = map_chip_pos_ - camera->target_+ tnl::Vector3(DXE_WINDOW_WIDTH >> 1, DXE_WINDOW_HEIGHT >> 1, 0);

	DrawRotaGraph(draw_pos.x, draw_pos.y, 1.0, 0, map_chip_gpc_hdl_, true);

	//DrawStringEx(0, 500, -1, "%.2f %.2f", m_map_chip_pos_.x, m_map_chip_pos_.y);
}