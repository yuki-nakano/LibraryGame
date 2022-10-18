﻿#ifndef OBJECT_BASE_H
#define OBJECT_BASE_H

#include "../../Library/DirectX/DirectXUtility.h"

namespace Game
{
	/**
	* @brief オブジェクトのステータス
	*/
	struct ObjState
	{
		int hp{};
		int damage{};
		float hitRadius{};
	};

	/**
	* @brief オブジェクトの継承元
	*/
	class ObjBase
	{
	public:
		ObjBase() = default;
		~ObjBase() = default;

	public:
		/**
		* @brief 更新
		*/
		virtual void Update() = 0;

		/**
		* @brief 描画
		*/
		virtual void Draw() = 0;

		/**
		* @brief 接触時に呼び出す
		*/
		virtual void Hit(ObjBase* obj_base_) = 0;

		// アクセサ

		engine::Vec3f GetPos() { return m_pos; }
		engine::Vec3f GetRote() { return m_rote; }
		engine::Vec3f GetScale() { return m_scale; }
		ObjState GetState() { return m_objState; }

		void SetPos(const engine::Vec3f& pos_) { m_pos = pos_; }
		void SetRote(const engine::Vec3f& rote_) { m_rote = rote_; }
		void SetScale(const engine::Vec3f& scale_) { m_scale = scale_; }
		void SetState(const ObjState& state_) { m_objState = state_; }

	protected:
		/// オブジェクトのステータス
		ObjState m_objState{};

		engine::Vec3f m_pos{};	/// 座標
		engine::Vec3f m_rote{};	/// 回転
		engine::Vec3f m_scale{ 1.0f, 1.0f, 1.0f };	/// 拡縮
	};
}

#endif // !OBJECT_BASE_H
