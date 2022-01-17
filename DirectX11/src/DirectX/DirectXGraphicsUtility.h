#ifndef DIRECTX_GRAPHICS_UTILITY_H
#define DIRECTX_GRAPHICS_UTILITY_H

namespace engine
{
	struct Vec3
	{
		Vec3(float x_ = 0, float y_ = 0, float z_ = 0)
			: X(x_)
			, Y(y_)
			, Z(z_)
		{
		}

		float X;
		float Y;
		float Z;
	};

	struct Vec3f
	{
		Vec3f(int x_ = 0, int y_ = 0, int z_ = 0)
			: X(x_)
			, Y(y_)
			, Z(z_)
		{
		}

		int X;
		int Y;
		int Z;
	};


}

#endif // !DIRECTX_GRAPHICS_UTILITY_H
