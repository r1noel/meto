#pragma once
#include "../chara/player.h"
#include "../camera/camera.h"

enum class CHIPTYPE {

	SPACE = -1,
	GROUND = 12,
	SOIL1 = 4,
	SOIL2 = 9,
	BEDROCK = 14,
	MAX = 0

};

class MapChip {
public:

	MapChip(const tnl::Vector3& pos) : map_chip_pos_(pos){};

	static constexpr float CHIP_SIZE = 48;

	tnl::Vector3 map_chip_pos_ {0, 0, 0};

	void update(float delta_time, const Shared<Camera> camera);
	CHIPTYPE chipType_ = CHIPTYPE::MAX;
	tnl::Vector3 draw_pos;

private:
	
};