﻿#ifndef BULLET_H
#define BULLET_H

#include "ObjBase.h"

#include <string>

namespace Game
{
	/// 弾の種類
	enum class BulletType
	{
		Player,
		Enemy,
	};

	/**
	* @brief 弾のステータス
	*/
	struct BulletState
	{
		BulletType m_bulletType{};
		float m_speed{ 10.0f };		// 速度
		int m_deleteTime{ 300 };	// 生存時間
		int m_coolTime{ 60 };		// クールタイム
		std::string m_objName{ "star" };	/// オブジェ描画時の名前
	};

	/**
	* @brief 弾クラス
	*/
	class Bullet : public ObjBase
	{
	public:
		Bullet(const BulletState& bullet_state);
		~Bullet() = default;

	public:
		void Update();

		void Draw();

		void Hit(ObjBase* obj_base_);

		// アクセサ

		BulletState GetState() { return m_bulletState; }
		int GetDeleteTime() { return m_bulletState.m_deleteTime; }

	private:
		BulletState m_bulletState{};		/// 弾のステータス
	};
}

#endif // !BULLET_H
