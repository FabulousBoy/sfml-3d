#ifndef ARRAY_MATH_H
#define ARRAY_MATH_H

#include <stdio.h>

#include "Vector_Math.h"

class Array4x4
{

	float _arr[4][4]{};

	Array4x4 static RotationX(float x)
	{
		Array4x4 Rx{};

		float c = cos(x);
		float s = sin(x);

		Rx._arr[0][0] = 1.0f;

		Rx._arr[1][1] = c;
		Rx._arr[1][2] = -s;

		Rx._arr[2][1] = s;
		Rx._arr[2][2] = c;

		Rx._arr[3][3] = 1.0f;

		return Rx;
	}
	Array4x4 static RotationY(float y)
	{
		Array4x4 Ry{};

		float c = cos(y);
		float s = sin(y);

		Ry._arr[1][1] = 1.0f;

		Ry._arr[0][0] = c;
		Ry._arr[0][2] = s;

		Ry._arr[2][0] = -s;
		Ry._arr[2][2] = c;

		Ry._arr[3][3] = 1.0f;

		Ry._arr;

		return Ry;
	}
	Array4x4 static RotationZ(float z)
	{
		Array4x4 Rz{};

		float c = cos(z);
		float s = sin(z);

		Rz._arr[2][2] = 1.0f;

		Rz._arr[0][0] = c;
		Rz._arr[1][0] = -s;

		Rz._arr[0][1] = s;
		Rz._arr[1][1] = c;

		Rz._arr[3][3] = 1.0f;

		return Rz;
	}

public:
	Array4x4() = default;

	Array4x4 static Identity()
	{
		Array4x4 result;

		result._arr[0][0] = 1.0f;
		result._arr[1][1] = 1.0f;
		result._arr[2][2] = 1.0f;
		result._arr[3][3] = 1.0f;

		return result;
	}
	Array4x4 static Constant(float value)
	{
		Array4x4 result;
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++)
				result._arr[i][j] = value;

		return result;
	}

	Array4x4 static Scale(Vector3D factor)
	{
		Array4x4 S;

		S._arr[0][0] = factor.x();
		S._arr[1][1] = factor.y();
		S._arr[2][2] = factor.z();

		S._arr[3][3] = 1.0f;

		return S;
	}
	Array4x4 static Translation(Vector3D v)
	{
		Array4x4 T;

		T._arr[0][0] = 1.0f;
		T._arr[1][1] = 1.0f;
		T._arr[2][2] = 1.0f;
		T._arr[3][3] = 1.0f;

		T._arr[0][3] = v.x();
		T._arr[1][3] = v.y();
		T._arr[2][3] = v.z();

		return T;
	}

	Vector3D x() { return Vector3D(_arr[0][0], _arr[1][0], _arr[2][0]); }
	Vector3D y() { return Vector3D(_arr[0][1], _arr[1][1], _arr[2][1]); }
	Vector3D z() { return Vector3D(_arr[0][2], _arr[1][2], _arr[2][2]); }
	Vector3D w() { return Vector3D(_arr[0][3], _arr[1][3], _arr[2][3]); }

	Array4x4 operator * (const Array4x4 other)
	{
		Array4x4 result;

		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++)
				for (int k = 0; k < 4; k++)
					result._arr[i][j] += _arr[i][k] * other._arr[k][j];

		return result;
	}
	Vector4D operator * (Vector4D &vec)
	{
		return Vector4D
		(
			_arr[0][0] * vec.x() + _arr[0][1] * vec.y() + _arr[0][2] * vec.z() + _arr[0][3] * vec.w(),
			_arr[1][0] * vec.x() + _arr[1][1] * vec.y() + _arr[1][2] * vec.z() + _arr[1][3] * vec.w(),
			_arr[2][0] * vec.x() + _arr[2][1] * vec.y() + _arr[2][2] * vec.z() + _arr[2][3] * vec.w(),
			_arr[3][0] * vec.x() + _arr[3][1] * vec.y() + _arr[3][2] * vec.z() + _arr[3][3] * vec.w()
		);
	}
	Vector3D operator * (Vector3D &vec)
	{
		return Vector3D
		(
			_arr[0][0] * vec.x() + _arr[0][1] * vec.y() + _arr[0][2] * vec.z(),
			_arr[1][0] * vec.x() + _arr[1][1] * vec.y() + _arr[1][2] * vec.z(),
			_arr[2][0] * vec.x() + _arr[2][1] * vec.y() + _arr[2][2] * vec.z()
		);
	}

	Array4x4 static Rotation(Vector3D v)
	{
		return RotationX(v.x())*RotationY(v.y())*RotationZ(v.z());
	}

	Array4x4 static Screen(int sw, int sh)
	{
		Array4x4 S;

		S._arr[0][0] = -0.5*sw;
		S._arr[1][1] = -0.5*sh;

		S._arr[0][3] = 0.5*sw;
		S._arr[1][3] = 0.5*sh;

		S._arr[2][2] = 1;
		S._arr[3][3] = 1;

		return S;
	}
	Array4x4 static Projection_Array(float F, float A, int ZF, int ZN)
	{
		Array4x4 P;

		const float PI = 3.14159;

		float t = tanf(PI*F*0.5 / 180);

		P._arr[0][0] = 1 / t * A;
		P._arr[1][1] = 1 / t;

		P._arr[2][2] = ZF / (ZF - ZN);
		P._arr[2][3] = -ZF * ZN / (ZF - ZN);

		P._arr[3][2] = 1.0f;

		return P;
	}

	void GetArr()
	{
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
				printf("%10g", _arr[i][j]);
			printf("\n");
		}
	}

};

#endif