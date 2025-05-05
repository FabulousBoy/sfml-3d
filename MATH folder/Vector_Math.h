#ifndef VECTOR_MATH_H
#define VECTOR_MATH_H

#include <cmath>

class Vector4D
{
	float _arr[4]{};
public:
	float x() { return _arr[0]; }
	float y() { return _arr[1]; }
	float z() { return _arr[2]; }
	float w() { return _arr[3]; }

	Vector4D() = default;
	Vector4D(float x, float y = 0.0, float z = 0.0, float w = 0.0)
	{
		_arr[0] = x;
		_arr[1] = y;
		_arr[2] = z;
		_arr[3] = w;
	}

	Vector4D operator *(float value)
	{
		Vector4D result;

		for (int i = 0; i < 4; i++)
			result._arr[i]  = _arr[i] * value;

		return result;
	}
	Vector4D operator /(float value)
	{
		Vector4D result;

		for (int i = 0; i < 4; i++)
			result._arr[i] = _arr[i] / value;

		return result;
	}

	Vector4D operator + (Vector4D other)
	{
		Vector4D result;

		for (int i = 0; i < 4; i++)
			result._arr[i] = _arr[i] + other._arr[i];

		return result;
	}
	Vector4D operator - (Vector4D other)
	{
		Vector4D result;

		for (int i = 0; i < 4; i++)
			result._arr[i] = _arr[i] - other._arr[i];

		return result;
	}

};

class Vector3D
{
	float _arr[3]{};
public:
	float x() { return _arr[0]; }
	float y() { return _arr[1]; }
	float z() { return _arr[2]; }

	Vector3D() = default;
	Vector3D(float x, float y = 0, float z = 0)
	{
		_arr[0] = x;
		_arr[1] = y;
		_arr[2] = z;
	}
	Vector3D(Vector4D V)
	{
		_arr[0] = V.x();
		_arr[1] = V.y();
		_arr[2] = V.z();
	}

	Vector3D operator * (float value)
	{
		Vector3D result;

		for (int i = 0; i < 3; i++)
			result._arr[i] = _arr[i] * value;
		return result;
	}
	Vector3D operator / (float value)
	{
		Vector3D result;

		for (int i = 0; i < 3; i++)
			result._arr[i] = _arr[i] / value;
		return result;
	}

	Vector3D operator + (Vector3D other)
	{
		return Vector3D{
			x() + other.x(),
			y() + other.y(),
			z() + other.z()
		};
	}
	Vector3D operator - (Vector3D other)
	{
		Vector3D result;

		for (int i = 0; i < 3; i++)
			result._arr[i] = _arr[i] - other._arr[i];
		return result;
	}

	Vector3D cross(Vector3D V)
	{
		return Vector3D
		(
			y()*V.z() - z()*V.y(),
			z()*V.x() - x()*V.z(),
			x()*V.y() - y()*V.x()
		);
	}

	void GetArr()
	{
		printf("%2g", x());
		printf("%2g", y());
		printf("%2g", z());
		printf("\n");
	}

};

class Vector2D
{
	float _arr[2];
public:
	float x() { return _arr[0]; }
	float y() { return _arr[1]; }

	Vector2D() = default;
	Vector2D(float x, float y)
	{
		_arr[0] = x;
		_arr[1] = y;
	}
	Vector2D(Vector4D V)
	{
		_arr[0] = V.x();
		_arr[1] = V.y();
	}

	Vector2D operator * (float value)
	{
		Vector2D result;

		for (int i = 0; i < 2; i++)
			result._arr[i] * value;
		return result;
	}
	Vector2D operator / (float value)
	{
		Vector2D result;

		for (int i = 0; i < 2; i++)
			result._arr[i] / value;
		return result;
	}

	Vector2D operator + (Vector2D other)
	{
		Vector2D result;

		for (int i = 0; i < 2; i++)
			result._arr[i] = _arr[i] + other._arr[i];
		return result;
	}
	Vector2D operator - (Vector2D other)
	{
		Vector2D result;

		for (int i = 0; i < 2; i++)
			result._arr[i] = _arr[i] - other._arr[i];
		return result;
	}
};

#endif