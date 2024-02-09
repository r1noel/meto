#pragma once

namespace unl {
	//-----------------------------------------------------------------------------------------------------
// 矩形と矩形の衝突検知 & 座標補正
// arg1...矩形Aの現在座標( 補正対象の座標変数 )
// arg2...矩形Aの移動前の座標
// arg3...矩形Aの幅
// arg4...矩形Aの高さ
// arg5...矩形Bの座標
// arg6...矩形Bの幅
// arg7...矩形Bの高さ
// arg8...補正の追加スペース( 省略可 デフォルト 1.0f )
// ret....[ 衝突していない : 0 ] 
//        [ 対象を左に補正 : 1 ] 
//        [ 対象を右に補正 : 2 ]
//        [ 対象を上に補正 : 3 ]
//        [ 対象を下に補正 : 4 ]
// tips...矩形Aが補正対象のオブジェクト
//        矩形Bは壁等の移動しないオブジェクトを想定しています
	int IsIntersectRectToCorrectPosition(tnl::Vector3& a_now_p, const tnl::Vector3 a_prev_p, const int a_rect_size_w, const int a_rect_size_h,
		const tnl::Vector3& b_pos, const int b_rect_size_w, const int b_rect_size_h, const float correct_space =1.0f);

	extern bool jump_reset_flag_ ;

	extern bool side_flag_ ;
}