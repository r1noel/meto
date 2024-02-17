#pragma once


class Camera;


class Player {
public:

	Player();
	void update(float delta_time);
	void draw(const Shared<Camera> camera);
	void jump();
	tnl::Vector3& getPlayerPos();
	int getWidthSize();
	int getHeightSize();
	float getSpeed();
	float getDropTime();
	int getJumpCount();

private:

	//プレイヤー情報
	std::string player_name_ = "";				//キャラネーム
	int player_hp_ = 0;							//プレイヤーの体力
	int player_atk_ = 0;						//プレイヤーの攻撃力
	tnl::Vector3 player_pos_ {150,9350,0};	//プレイヤーの位置
	int jump_count_ = 0;						//ジャンプの回数
	//プレイヤーサイズ
	const int width_ = 46;						//幅
	const int height_ = 48;						//高さ
	
	float speed_ = 0.0f;						//プレイヤー速度
	float acceleration_ = 1.0f;					//重力加速度
	float drop_time_ = 0.0f;					//滞空時間

	bool player_jump_flag_ = false;				//ジャンプをしているかの判定

	//プレイヤーアニメーション種類（向き）
	enum PlayerAnime {
		DIR_RIGHT,
		DIR_LEFT,
		DIR_MAX
	};

	float anim_time_count_ = 0;
	//プレイヤーアニメーション向き
	int anim_ctrl_dir_ = DIR_RIGHT;
	//プレイヤーアニメーションフレーム数
	int anim_ctr_frame_ = 0;
	//プレイヤーアニメーションハンドル
	int anim_hdls_[DIR_MAX][3];

	float effect_time_count_ = 0;
	int effect_ctrl_fream_ = 0;
	int atk_effect_hdl_[15];
	bool effect_flag_ = true;


};