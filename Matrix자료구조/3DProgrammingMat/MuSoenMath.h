#pragma once
#include <iostream>

#define PI 3.1415926 //sin cos���� ���� ���̰�

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

	mat3 Identity() //�׵���� ��ȯ
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

const vec3 operator * (const mat3& ref,const vec3& vec) //vec3�� 3x3����� ���� ����
{
	vec3 result;
	mat3 mat = ref; 
	mat = mat.Transpose(); //���Ϳ� ����� ���̱⿡ ��ġ��ķ� ��ȯ �Ͽ� ������ݴϴ�.

	result.x = mat.num[0][0] * vec.x + mat.num[0][1] * vec.y + mat.num[0][2] * vec.z;
	result.y = mat.num[1][0] * vec.x + mat.num[1][1] * vec.y + mat.num[1][2] * vec.z;
	result.z = mat.num[2][0] * vec.x + mat.num[2][1] * vec.y + mat.num[2][2] * vec.z;

	return result;
}

const vec3 operator * (const vec3& vec, const mat3& ref) //vec3�� 3x3����� ���� ����
{
	vec3 result;
	mat3 mat = ref; 
	mat = mat.Transpose(); //���Ϳ� ����� ���̱⿡ ��ġ��ķ� ��ȯ �Ͽ� ������ݴϴ�.

	result.x = mat.num[0][0] * vec.x + mat.num[0][1] * vec.y + mat.num[0][2] * vec.z;
	result.y = mat.num[1][0] * vec.x + mat.num[1][1] * vec.y + mat.num[1][2] * vec.z;
	result.z = mat.num[2][0] * vec.x + mat.num[2][1] * vec.y + mat.num[2][2] * vec.z;

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