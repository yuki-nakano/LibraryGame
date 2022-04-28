#include "Matrix.h"

#include "Camera.h"

namespace engine
{
	Matrix::Matrix()
	{
	}

	Matrix::~Matrix()
	{
	}

	DirectX::XMMATRIX Matrix::CreateWorldMatrix(Vec3f pos_, Vec3f rote_, Vec3f scale_)
	{
		DirectX::XMMATRIX transrate = DirectX::XMMatrixTranslation(pos_.x, pos_.y, pos_.z);
		DirectX::XMMATRIX rotateX = DirectX::XMMatrixRotationX(DirectX::XMConvertToRadians(rote_.x));
		DirectX::XMMATRIX rotateY = DirectX::XMMatrixRotationY(DirectX::XMConvertToRadians(rote_.y));
		DirectX::XMMATRIX rotateZ = DirectX::XMMatrixRotationZ(DirectX::XMConvertToRadians(rote_.z));
		DirectX::XMMATRIX scale = DirectX::XMMatrixScaling(scale_.x, scale_.y, scale_.z);

		return scale * rotateX * rotateY * rotateZ * transrate;
	}

	DirectX::XMMATRIX Matrix::CreateViewMatrix()
	{
		Camera::View view = Camera::GetInstance()->GetView();
		return DirectX::XMMatrixLookAtLH(view.vecPos, view.vecFocus, view.vecUp);
	}

	DirectX::XMMATRIX Matrix::CreateProjMatrix()
	{
		Camera::Proj proj = Camera::GetInstance()->GetProj();
		return DirectX::XMMatrixPerspectiveFovLH(proj.fov, (viewport.x / viewport.y), proj.nearZ, proj.farZ);
	}

	DirectX::XMFLOAT4 Matrix::GetViewportMatrix()
	{
		return DirectX::XMFLOAT4(viewport.x, viewport.y, 0.0f, 1.0f);
	}
}