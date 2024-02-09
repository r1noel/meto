#pragma once

namespace unl {
	//-----------------------------------------------------------------------------------------------------
// ��`�Ƌ�`�̏Փˌ��m & ���W�␳
// arg1...��`A�̌��ݍ��W( �␳�Ώۂ̍��W�ϐ� )
// arg2...��`A�̈ړ��O�̍��W
// arg3...��`A�̕�
// arg4...��`A�̍���
// arg5...��`B�̍��W
// arg6...��`B�̕�
// arg7...��`B�̍���
// arg8...�␳�̒ǉ��X�y�[�X( �ȗ��� �f�t�H���g 1.0f )
// ret....[ �Փ˂��Ă��Ȃ� : 0 ] 
//        [ �Ώۂ����ɕ␳ : 1 ] 
//        [ �Ώۂ��E�ɕ␳ : 2 ]
//        [ �Ώۂ���ɕ␳ : 3 ]
//        [ �Ώۂ����ɕ␳ : 4 ]
// tips...��`A���␳�Ώۂ̃I�u�W�F�N�g
//        ��`B�͕Ǔ��̈ړ����Ȃ��I�u�W�F�N�g��z�肵�Ă��܂�
	int IsIntersectRectToCorrectPosition(tnl::Vector3& a_now_p, const tnl::Vector3 a_prev_p, const int a_rect_size_w, const int a_rect_size_h,
		const tnl::Vector3& b_pos, const int b_rect_size_w, const int b_rect_size_h, const float correct_space =1.0f);

	extern bool jump_reset_flag_ ;

	extern bool side_flag_ ;
}