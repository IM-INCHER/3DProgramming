#pragma once
#include <iostream>

#define PI 3.1415926 //sin cos값을 위한 파이값

class mat3 //3x3 행렬 클래스
{
public:
	float num[3][3] = {}; //생성할때 0으로 초기화

	mat3() //생성할때 0으로 초기화 함으로 내용 X
	{
	}

	mat3(float _00, float _01, float _02, 
		float _10, float _11, float _12,
		float _20, float _21, float _22) //값을 입력하여 초기화 하는 생성자
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

	mat3 Identity() //항등행렬 반환
	{
		return mat3(1, 0, 0,
					0, 1, 0,
					0, 0, 1);
	}

	mat3 Transpose() //전치행렬 반환
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

class vec3 // 3*1 백터 클래스
{
public:
	float x, y, z;

	vec3() //vec3 생성자 아무것도 입력안할 시  x y z 값은 0으로 초기화
	{
		x = 0;
		y = 0;
		z = 0;
	}
	vec3(float x, float y, float z) //vec3 생성자 x y z값을 입력하여 생성
	{
		this->x = x;
		this->y = y;
		this->z = z;
	}
};

const vec3 operator * (const mat3& ref,const vec3& vec) //vec3와 3x3행렬의 곱을 구현
{
	vec3 result;
	mat3 mat = ref; 
	mat = mat.Transpose(); //백터와 행렬의 곱이기에 전치행렬로 변환 하여 계산해줍니다.

	result.x = mat.num[0][0] * vec.x + mat.num[0][1] * vec.y + mat.num[0][2] * vec.z;
	result.y = mat.num[1][0] * vec.x + mat.num[1][1] * vec.y + mat.num[1][2] * vec.z;
	result.z = mat.num[2][0] * vec.x + mat.num[2][1] * vec.y + mat.num[2][2] * vec.z;

	return result;
}

const vec3 operator * (const vec3& vec, const mat3& ref) //vec3와 3x3행렬의 곱을 구현
{
	vec3 result;
	mat3 mat = ref; 
	mat = mat.Transpose(); //백터와 행렬의 곱이기에 전치행렬로 변환 하여 계산해줍니다.

	result.x = mat.num[0][0] * vec.x + mat.num[0][1] * vec.y + mat.num[0][2] * vec.z;
	result.y = mat.num[1][0] * vec.x + mat.num[1][1] * vec.y + mat.num[1][2] * vec.z;
	result.z = mat.num[2][0] * vec.x + mat.num[2][1] * vec.y + mat.num[2][2] * vec.z;

	return result;
}

const mat3 operator * (const mat3& mat, const mat3& ref) //3x3행렬 끼리의 곱을 구현
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