#ifndef BULLET_BASE_H
#define BULLET_BASE_H

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
		std::string m_objName{ "star" };	/// オブジェ描画時の名前
	};

	/**
	* @brief 弾クラス
	*/
	class BulletBase : public ObjBase
	{
	public:
		BulletBase(const BulletState& bullet_state_, const engine::Vec3f& pos_, const engine::Vec3f& rote_, const engine::Vec3f& scale_)
			: m_bulletState(bullet_state_)
			, ObjBase(pos_, rote_, scale_)
		{
		}
		virtual ~BulletBase() = default;

	public:
		/**
		* @brief 描画関数
		*/
		virtual void Draw() = 0;

		/**
		* @brief 弾の死亡判定
		* @return 弾の生存時間が0以下になるとtrue
		*/
		bool IsDead() { return (m_bulletState.m_deleteTime <= 0); }

		// アクセサ

		BulletState GetBulletState() { return m_bulletState; }

	protected:
		BulletState m_bulletState{};	/// 弾のステータス
	};
}

#endif // !BULLET_BASE_H
