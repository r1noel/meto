#pragma once
#include "../common/gm_scene_base.h"
#include "../gmobject/map.h"
#include "../chara/player.h"

class ScenePlay : public SceneBase {
public:
	//プレイシーンのコンストラクタ
	ScenePlay();
	//プレイシーンのデストラクタ
	~ScenePlay();
	void update(float delta_time) override;
	void draw() override;
	//当たり判定と補正
	int IsIIntersectRectToCorrectPosition(tnl::Vector3& a_now_p, const tnl::Vector3 a_prev_p, const int a_rect_size_w, const int a_rect_size_h,
		const tnl::Vector3& b_pos, const int b_rect_size_w, const int b_rect_size_h, const float correct_space) {

		const int NO_HIT = 0;
		const int CORRECT_LEFT = 1;
		const int CORRECT_RIGHT = 2;
		const int CORRECT_UP = 3;
		const int CORRECT_DOWN = 4;

		if (!tnl::IsIntersectRect(a_now_p, a_rect_size_w, a_rect_size_h, b_pos, b_rect_size_w, b_rect_size_h)) return NO_HIT;

		tnl::Vector3 a_near = tnl::GetNearestRectPoint(a_prev_p, (float)a_rect_size_w, (float)a_rect_size_h, b_pos);
		tnl::eRegionPtRect n = tnl::GetRegionPointAndRect(a_near, b_pos, b_rect_size_w, b_rect_size_h);

	}

private:

	std::shared_ptr<Map> map_ = nullptr;
	std::shared_ptr<Player> player_ = nullptr;
	std::shared_ptr<Camera> camera_ = nullptr;
	
};
