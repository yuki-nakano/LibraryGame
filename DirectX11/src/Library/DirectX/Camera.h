#ifndef CAMERA_H
#define CAMERA_H

#include <DirectXMath.h>

#include "DirectXUtility.h"
#include "../Utility/Singleton.h"

namespace engine
{
	class Camera : public Singleton<Camera>
	{
	public:
		struct View
		{
			DirectX::XMVECTOR vecPos;
			DirectX::XMVECTOR vecFocus;
			DirectX::XMVECTOR vecUp;
		};

		struct Proj
		{
			float fov;
			float nearZ;
			float farZ;
		};

	private:
		friend class Singleton<Camera>;

		Camera();
		~Camera();

	public:
		void SetPos(Vec4f pos_) { pos = pos_; view.vecPos = DirectX::XMVectorSet(pos.x, pos.y, pos.z, pos.w); }
		void SetFocus(Vec4f focus_) { focus = focus_; view.vecFocus = DirectX::XMVectorSet(focus.x, focus.y, focus.z, focus.w); }
		void SetFOV(float fov_) { proj.fov = DirectX::XMConvertToRadians(fov_); }
		void SetZ(float near_, float far_) { if (near_ < far_) { return; }; proj.nearZ = near_; proj.farZ = far_; }

		Vec4f GetPos() { return pos; }
		Vec4f GetFocus() { return focus; }
		Vec4f GetUp() { return up; }
		View GetView() { return view; }
		Proj GetProj() { return proj; }

	private:
		Vec4f pos;
		Vec4f focus;
		Vec4f up;
		View view;
		Proj proj;
	};
}

#endif // !CAMERA_H
