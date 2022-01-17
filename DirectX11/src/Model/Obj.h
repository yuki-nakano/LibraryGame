#ifndef OBJ_H
#define OBJ_H

#include <array>
#include <vector>
#include <map>
#include <string>
#include <d3d11.h>

#include "../DirectX/DirectXGraphics.h"
#include "../DirectX/DirectXGraphicsUtility.h"

namespace engine
{
	using vecesData = std::array<int, 3>;
	using nomalData = std::array<int, 3>;
	using elementsData = std::array<std::array<int, 3>, 4>;

	class ObjManager
	{
	private:
		struct ObjData
		{
			std::vector<vecesData> vecesDataList;
			std::vector<nomalData> nomalDataList;
			std::vector<elementsData> elementsDataList;
		};

		struct BufferData
		{
			ID3D11Buffer* vertexBuffer;
		};

	public:
		ObjManager(DirectXGraphics* direct_graphics_);
		~ObjManager();

		/**
		* @brief objファイルの読み込み
		*/
		bool LoadObj(const std::string& name_, const std::string& file_name_);

		void RenderObj(const std::string& name_);

	private:
		bool AnalyzeData(const std::string& file_name_, ObjData& obj_data_);

		bool CreateVertexBuffer(const std::string& name_, ObjData& obj_data_);

		bool CreateIndexBuffer();

	private:
		ID3D11Device* m_device;
		ID3D11DeviceContext* m_context;
		std::map<std::string, BufferData> bufferData;
	};
}

#endif // !OBJ_H
