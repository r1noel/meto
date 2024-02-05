#pragma once
namespace unl {
	int IsIntersectRectToCorrectPosition(tnl::Vector3& a_now_p, const tnl::Vector3 a_prev_p, const int a_rect_size_w, const int a_rect_size_h,
		const tnl::Vector3& b_pos, const int b_rect_size_w, const int b_rect_size_h, const float correct_space =1.0f);
}