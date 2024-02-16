#pragma once
#include "../common/gm_scene_base.h"
#include "../gmobject/map.h"
#include "../chara/player.h"
#include "../chara/enemy.h"
#include "../gmobject/bullet.h"

class ScenePlay : public SceneBase {
public:

	//�v���C�V�[���̃R���X�g���N�^
	ScenePlay();
	//�v���C�V�[���̃f�X�g���N�^
	~ScenePlay();
	void update(float delta_time) override;
	void draw() override;


private:

	Shared<Map> map_ = nullptr;
	Shared<Player> player_ = nullptr;
	Shared<Camera> camera_ = nullptr;
	Shared<TrackingEnemy> t_enemy_ = nullptr;
	Shared<ShootEnemy> s_enemy_ = nullptr;

};
