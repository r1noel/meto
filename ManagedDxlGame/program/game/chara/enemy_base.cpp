#include "../dxlib_ext/dxlib_ext.h"
#include "enemy_base.h"

void EnemyBase::draw(const Shared<Camera> camera){

	e_draw_pos_ = e_pos_ - camera->target_ + tnl::Vector3(DXE_WINDOW_WIDTH >> 1, DXE_WINDOW_HEIGHT >> 1, 0);

}
