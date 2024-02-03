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

	int IsIIntersectRectToCorrectPosition(tnl::Vector3& a_now,const tnl::Vector3 a_prev,const int a_rect_size_w,const int a_rect_size_h,
		const tnl::Vector3& b)

private:

	std::shared_ptr<Map> map_ = nullptr;
	std::shared_ptr<Player> player_ = nullptr;
	std::shared_ptr<Camera> camera_ = nullptr;
	
};
