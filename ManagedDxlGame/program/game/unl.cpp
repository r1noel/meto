#include "../dxlib_ext/dxlib_ext.h"
#include "unl.h"
namespace unl {
int IsIntersectRectToCorrectPosition(tnl::Vector3& a_now_p, const tnl::Vector3 a_prev_p, const int a_rect_size_w, const int a_rect_size_h,
	const tnl::Vector3& b_pos, const int b_rect_size_w, const int b_rect_size_h, const float correct_space) {

		const int NO_HIT = 0;
		const int CORRECT_LEFT = 1;
		const int CORRECT_RIGHT = 2;
		const int CORRECT_UP = 3;
		const int CORRECT_DOWN = 4;

		if (!tnl::IsIntersectRect(a_now_p, a_rect_size_w, a_rect_size_h, b_pos, b_rect_size_w, b_rect_size_h)) return NO_HIT;

		tnl::Vector3 a_near = tnl::GetNearestRectPoint(a_prev_p, (float)a_rect_size_w, (float)a_rect_size_h, b_pos);
		tnl::eRegionPtRect n = tnl::GetRegionPointAndRect(a_near, b_pos, b_rect_size_w, b_rect_size_h);

		if (tnl::eRegionPtRect::UP == n) {
			float y = (a_now_p - a_prev_p).y; 
			// �������Ɉړ����Ă���ꍇ�͏�ɕ␳
			if (y >= 0) {
				a_now_p.y = b_pos.y - (b_rect_size_h / 2) - (a_rect_size_h / 2) - correct_space;
				return CORRECT_UP;
			}
			// ������Ɉړ����Ă���ꍇ�͍��E�ǂ��炩�ɕ␳
			else {
				// �E�ɕ␳
				if (a_now_p.x > b_pos.x) {
					a_now_p.x = b_pos.x + (b_rect_size_w / 2) + (a_rect_size_w / 2) + correct_space;
					return CORRECT_RIGHT;
				}
				// ���ɕ␳
				else {
					a_now_p.x = b_pos.x - (b_rect_size_w / 2) - (a_rect_size_w / 2) - correct_space;
					return CORRECT_LEFT;
				}
			}
		}
		else if (tnl::eRegionPtRect::DOWN == n) {
			float y = (a_now_p - a_prev_p).y;
			// ������Ɉړ����Ă���ꍇ�͉��ɕ␳
			if (y <= 0) {
				a_now_p.y = b_pos.y + (b_rect_size_h / 2) + (a_rect_size_h / 2) + correct_space;
				return CORRECT_DOWN;
			}
			// ������Ɉړ����Ă���ꍇ�͍��E�ǂ��炩�ɕ␳
			else {
				// �E�ɕ␳
				if (a_now_p.x > b_pos.x) {
					a_now_p.x = b_pos.x + (b_rect_size_w / 2) + (a_rect_size_w / 2) + correct_space;
					return CORRECT_RIGHT;
				}
				// ���ɕ␳
				else {
					a_now_p.x = b_pos.x - (b_rect_size_w / 2) - (a_rect_size_w / 2) - correct_space;
					return CORRECT_LEFT;
				}
			}
		}
		else if (tnl::eRegionPtRect::RIGHT == n) {
			float x = (a_now_p - a_prev_p).x;
			// �������Ɉړ����Ă���ꍇ�͉E�ɕ␳
			if (x <= 0) {
				a_now_p.x = b_pos.x + (b_rect_size_w / 2) + (a_rect_size_w / 2) + correct_space;
				return CORRECT_RIGHT;
			}
			// �E�����Ɉړ����Ă���ꍇ�͏㉺�ǂ��炩�ɕ␳
			else {
				// ��ɕ␳
				if (a_now_p.y < b_pos.y) {
					a_now_p.y = b_pos.y - (b_rect_size_h / 2) - (a_rect_size_h / 2) - correct_space;
					return CORRECT_UP;
				}
				// ���ɕ␳
				else {
					a_now_p.y = b_pos.y + (b_rect_size_h / 2) + (a_rect_size_h / 2) + correct_space;
					return CORRECT_DOWN;
				}
			}
		}
		else if (tnl::eRegionPtRect::LEFT == n) {
			float x = (a_now_p - a_prev_p).x;
			// �E�����Ɉړ����Ă���ꍇ�͍��ɕ␳
			if (x >= 0) {
				a_now_p.x = b_pos.x - (b_rect_size_w / 2) - (a_rect_size_w / 2) - correct_space;
				return CORRECT_LEFT;
			}
			// �������Ɉړ����Ă���ꍇ�͏㉺�ǂ��炩�ɕ␳
			else {
				// ��ɕ␳
				if (a_now_p.y < b_pos.y) {
					a_now_p.y = b_pos.y - (b_rect_size_h / 2) - (a_rect_size_h / 2) - correct_space;
					return CORRECT_UP;
				}
				// ���ɕ␳
				else {
					a_now_p.y = b_pos.y + (b_rect_size_h / 2) + (a_rect_size_h / 2) + correct_space;
					return CORRECT_DOWN;
				}
			}
		}
		return NO_HIT;
	}
}