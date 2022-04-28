#include "PixelShader.h"

namespace engine
{
	bool PixelShader::CreateShader()
	{
		if (FAILED(DirectXGraphics::GetInstance()->GetDevice()->CreatePixelShader(m_data, m_size, nullptr, &m_interfaace)))
		{
			return false;
		}

		return true;
	}

	void PixelShader::DeleteShader()
	{
		//delete[] m_data;

		if (m_interfaace != nullptr) { return; }
		m_interfaace->Release();
	}
}


