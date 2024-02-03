#pragma once

class Camera;

class Player {
public:
	Player();
	void update(float delta_time);
	void draw(const std::shared_ptr<Camera> camera);
	void jump();
	tnl::Vector3& getPlayerPos();
	int getWidthSize();
	int getHeightSize();
	float getSpeed();
	float getDropTime();
	int getJumpCount();
private:
	//�v���C���[���
	std::string player_name_ = "";				//�L�����l�[��
	int player_hp_ = 0;							//�v���C���[�̗̑�
	int player_atk_ = 0;						//�v���C���[�̍U����
	tnl::Vector3 player_pos_ {100,9350,0};	//�v���C���[�̈ʒu
	int jump_count_ = 0;						//�W�����v�̉�
	//�v���C���[�T�C�Y
	const int width_ = 50;						//��
	const int height_ = 50;						//����

	float speed_ = 0.0f;						//�v���C���[���x
	float acceleration_ = 1.0f;					//�d�͉����x
	float drop_time_ = 0.0f;					//�؋󎞊�

	bool player_jump_flag_ = false;				//�W�����v�����Ă��邩�̔���

	enum PlayerAnime {
		DIR_LEFT,
		DIR_RIGHT,
		DIR_MAX
	};

	float anim_time_count_ = 0;
	int anim_ctrl_dir_ = DIR_RIGHT;
	int anim_ctr_frame_ = 0;
	int anim_hdls_[DIR_MAX][2];

};