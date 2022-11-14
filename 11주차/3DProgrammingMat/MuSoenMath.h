#pragma once
#include <iostream>

#define PI 3.1415926 //sin cos���� ���� ���̰�

class vec3;
class vec4;
class vec1x3;
class vec1x4;

class mat3;
class mat4;

class vec3 // 3*1 ���� Ŭ����
{
public:
	float x, y, z;

	vec3() //vec3 ������ �ƹ��͵� �Է¾��� ��  x y z ���� 0���� �ʱ�ȭ
	{
		x = 0;
		y = 0;
		z = 0;
	}
	vec3(float x, float y, float z) //vec3 ������ x y z���� �Է��Ͽ� ����
	{
		this->x = x;
		this->y = y;
		this->z = z;
	}
};

class vec1x3 // 1*3 ���� Ŭ����
{
public:
	float num[3][1] = { 0 };

	vec1x3() //vec3 ������ �ƹ��͵� �Է¾��� ��  x y z ���� 0���� �ʱ�ȭ
	{
	}
	vec1x3(float x, float y, float z) //vec3 ������ x y z���� �Է��Ͽ� ����
	{
		num[0][0] = x;
		num[1][0] = y;
		num[2][0] = z;
	}
};

class vec4 // 4*1 ���� Ŭ����
{
public:
	float x, y, z, w;

	vec4() //vec3 ������ �ƹ��͵� �Է¾��� ��  x y z w ���� 0���� �ʱ�ȭ
	{
		x = 0;
		y = 0;
		z = 0;
		w = 0;
	}
	vec4(float x, float y, float z, float w) //vec3 ������ x y z���� �Է��Ͽ� ����
	{
		this->x = x;
		this->y = y;
		this->z = z;
		this->w = w;
	}
};

class vec1x4 // 1*4 ���� Ŭ����
{
public:
	float num[4][1] = {};

	vec1x4() //vec3 ������ �ƹ��͵� �Է¾��� ��  x y z w ���� 0���� �ʱ�ȭ
	{
	}
	vec1x4(float x, float y, float z, float w) //vec3 ������ x y z���� �Է��Ͽ� ����
	{
		num[0][0] = x;
		num[1][0] = y;
		num[2][0] = z;
		num[3][0] = w;
	}
};

class mat3 //3x3 ��� Ŭ����
{
public:
	float num[3][3] = {}; //�����Ҷ� 0���� �ʱ�ȭ

	mat3() //�����Ҷ� 0���� �ʱ�ȭ ������ ���� X
	{
	}

	mat3(float _00, float _01, float _02, 
		float _10, float _11, float _12,
		float _20, float _21, float _22) //���� �Է��Ͽ� �ʱ�ȭ �ϴ� ������
	{
		num[0][0] = _00;
		num[0][1] = _01;
		num[0][2] = _02;
		num[1][0] = _10;
		num[1][1] = _11;
		num[1][2] = _12;
		num[2][0] = _20;
		num[2][1] = _21;
		num[2][2] = _22;
	}

	mat3 Identity() //������� ��ȯ
	{
		return mat3(1, 0, 0,
					0, 1, 0,
					0, 0, 1);
	}

	mat3 Transpose() //��ġ��� ��ȯ
	{
		mat3 result;

		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				result.num[i][j] = num[j][i];
			}
		}

		return result;
	}
};

class mat4 //4x4 ��� Ŭ����
{
public:
	float num[4][4] = {}; //�����Ҷ� 0���� �ʱ�ȭ

	mat4() //�����Ҷ� 0���� �ʱ�ȭ ������ ���� X
	{
	}

	mat4(float _00, float _01, float _02, float _03,
		float _10, float _11, float _12, float _13,
		float _20, float _21, float _22, float _23,
		float _30, float _31, float _32, float _33) //���� �Է��Ͽ� �ʱ�ȭ �ϴ� ������
	{
		num[0][0] = _00; num[0][1] = _01; num[0][2] = _02; num[0][3] = _03;
		num[1][0] = _10; num[1][1] = _11; num[1][2] = _12; num[1][3] = _13;
		num[2][0] = _20; num[2][1] = _21; num[2][2] = _22; num[2][3] = _23;
		num[3][0] = _30; num[3][1] = _31; num[3][2] = _32; num[3][3] = _33;
	}

	mat4 Identity() //������� ��ȯ
	{
		return mat4(1, 0, 0, 0,
					0, 1, 0, 0,
					0, 0, 1, 0,
					0, 0, 0, 1);
	}

	mat4 Transpose() //��ġ��� ��ȯ
	{
		mat4 result;

		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				result.num[i][j] = num[j][i];
			}
		}

		return result;
	}
};

const vec3 operator + (const vec3& vec, const vec3& ref) //vec3������ ����
{
	vec3 result;

	result.x = vec.x + ref.x;
	result.y = vec.y + ref.y;
	result.z = vec.z + ref.z;

	return result;
}

const vec3 operator - (const vec3& vec, const vec3& ref) //vec3������ ����
{
	vec3 result;

	result.x = vec.x - ref.x;
	result.y = vec.y - ref.y;
	result.z = vec.z - ref.z;

	return result;
}

const vec3 operator * (const vec3& vec, const vec3& ref) //vec3�� 3x3����� ���� ����
{
	vec3 result;

	result.x = vec.x * ref.x;
	result.y = vec.y * ref.y;
	result.z = vec.z * ref.z;

	return result;
}

const vec3 operator * (const vec3& vec, const int& ref) //vec3�� ����� ��
{
	vec3 result;

	result.x = vec.x * ref;
	result.y = vec.y * ref;
	result.z = vec.z * ref;

	return result;
}

const vec3 operator / (const vec3& vec, const int& ref) //vec3�� 3x3����� ���� ����
{
	vec3 result;

	result.x = vec.x / ref;
	result.y = vec.y / ref;
	result.z = vec.z / ref;

	return result;
}

const vec3 operator * (const vec3& vec, const mat3& ref) //vec3�� 3x3����� ���� ����
{
	vec3 result;

	result.x = ref.num[0][0] * vec.x + ref.num[0][1] * vec.y + ref.num[0][2] * vec.z;
	result.y = ref.num[1][0] * vec.x + ref.num[1][1] * vec.y + ref.num[1][2] * vec.z;
	result.z = ref.num[2][0] * vec.x + ref.num[2][1] * vec.y + ref.num[2][2] * vec.z;

	return result;
}

const vec3 operator * (const mat3& ref,const vec3& vec) //vec3�� 3x3����� ���� ����
{
	vec3 result;
	mat3 mat = ref; 
	mat = mat.Transpose(); //��Ŀ� ������ ���̱⿡ ��ġ��ķ� ��ȯ �Ͽ� ������ݴϴ�.

	result.x = mat.num[0][0] * vec.x + mat.num[0][1] * vec.y + mat.num[0][2] * vec.z;
	result.y = mat.num[1][0] * vec.x + mat.num[1][1] * vec.y + mat.num[1][2] * vec.z;
	result.z = mat.num[2][0] * vec.x + mat.num[2][1] * vec.y + mat.num[2][2] * vec.z;

	return result;
}

const vec4 operator + (const vec4& vec, const vec4& ref) //vec4������ ����
{
	vec4 result;

	result.x = vec.x + ref.x;
	result.y = vec.y + ref.y;
	result.z = vec.z + ref.z;
	result.w = vec.w + ref.w;

	return result;
}

const vec4 operator - (const vec4& vec, const vec4& ref) //vec4������ ����
{
	vec4 result;

	result.x = vec.x - ref.x;
	result.y = vec.y - ref.y;
	result.z = vec.z - ref.z;
	result.w = vec.w - ref.w;

	return result;
}

const vec4 operator * (const vec4& vec, const int& ref) //vec4�� ����� ��
{
	vec4 result;

	result.x = vec.x * ref;
	result.y = vec.y * ref;
	result.z = vec.z * ref;
	result.w = vec.w * ref;

	return result;
}

const vec4 operator / (const vec4& vec, const int& ref) //vec4�� ����� ������
{
	vec4 result;

	result.x = vec.x / ref;
	result.y = vec.y / ref;
	result.z = vec.z / ref;
	result.w = vec.w / ref;

	return result;
}

const mat3 operator * (const mat3& mat, const mat3& ref) //3x3��� ������ ���� ����
{
	mat3 result;

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 3; k++) {
				result.num[i][j] += mat.num[i][k] * ref.num[k][j];
			}
		}
	}

	return result;
}

const mat3 operator + (const mat3& mat, const mat3& ref) //3x3��� ������ ������ ����
{
	mat3 result;

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
				result.num[i][j] = mat.num[i][j] + ref.num[i][j];
			}
		}

	return result;
}

const mat3 operator - (const mat3& mat, const mat3& ref) //3x3��� ������ ������ ����
{
	mat3 result;

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			result.num[i][j] = mat.num[i][j] - ref.num[i][j];
		}
	}

	return result;
}

const mat4 operator * (const mat4& mat, const mat4& ref) //4x4��� ������ ���� ����
{
	mat4 result;

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			for (int k = 0; k < 4; k++) {
				result.num[i][j] += mat.num[i][k] * ref.num[k][j];
			}
		}
	}

	return result;
}

const mat4 operator + (const mat4& mat, const mat4& ref) //4x4��� ������ ������ ����
{
	mat4 result;

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			result.num[i][j] = mat.num[i][j] + ref.num[i][j];
		}
	}

	return result;
}

const mat4 operator - (const mat4& mat, const mat4& ref) //4x4��� ������ ������ ����
{
	mat4 result;

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			result.num[i][j] = mat.num[i][j] - ref.num[i][j];
		}
	}

	return result;
}