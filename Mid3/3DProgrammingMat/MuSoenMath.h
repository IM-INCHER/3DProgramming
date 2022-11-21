#pragma once

#define PI 3.1415926 //sin cos값을 위한 파이값

class vec3;
class vec4;
class vec1x3;
class vec1x4;

class mat3;
class mat4;

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

class vec1x3 // 1*3 백터 클래스
{
public:
	float num[3][1] = { 0 };

	vec1x3() //vec3 생성자 아무것도 입력안할 시  x y z 값은 0으로 초기화
	{
	}
	vec1x3(float x, float y, float z) //vec3 생성자 x y z값을 입력하여 생성
	{
		num[0][0] = x;
		num[1][0] = y;
		num[2][0] = z;
	}
};

class vec4 // 4*1 백터 클래스
{
public:
	float x, y, z, w;

	vec4() //vec3 생성자 아무것도 입력안할 시  x y z w 값은 0으로 초기화
	{
		x = 0;
		y = 0;
		z = 0;
		w = 0;
	}
	vec4(float x, float y, float z, float w) //vec3 생성자 x y z값을 입력하여 생성
	{
		this->x = x;
		this->y = y;
		this->z = z;
		this->w = w;
	}
};

class vec1x4 // 1*4 백터 클래스
{
public:
	float num[4][1] = {};

	vec1x4() //vec3 생성자 아무것도 입력안할 시  x y z w 값은 0으로 초기화
	{
	}
	vec1x4(float x, float y, float z, float w) //vec3 생성자 x y z값을 입력하여 생성
	{
		num[0][0] = x;
		num[1][0] = y;
		num[2][0] = z;
		num[3][0] = w;
	}
};

class mat3 //3x3 행렬 클래스
{
public:
	float num[3][3] = {}; //생성할때 0으로 초기화

	mat3() //생성할때 0으로 초기화 함으로 내용 X
	{
	}

	mat3(float _00, float _01, float _02,
		float _10, float _11, float _12,
		float _20, float _21, float _22); //값을 입력하여 초기화 하는 생성자


	mat3 Identity(); //단위행렬 반환
	mat3 Transpose(); //전치행렬 반환

};

class mat4 //4x4 행렬 클래스
{
public:
	float num[4][4] = {}; //생성할때 0으로 초기화

	mat4() //생성할때 0으로 초기화 함으로 내용 X
	{}
	

	mat4(float _00, float _01, float _02, float _03,
		float _10, float _11, float _12, float _13,
		float _20, float _21, float _22, float _23,
		float _30, float _31, float _32, float _33); //값을 입력하여 초기화 하는 생성자
	

	mat4 Identity(); //단위행렬 반환
	mat4 Transpose(); //전치행렬 반환
	
};

const vec3 operator + (const vec3& vec, const vec3& ref); //vec3끼리의 덧셈
const vec3 operator - (const vec3& vec, const vec3& ref); //vec3끼리의 뺄셈
const vec3 operator * (const vec3& vec, const vec3& ref); //vec3와 3x3행렬의 곱을 구현
const vec3 operator * (const vec3& vec, const int& ref); //vec3와 상수의 곱
const vec3 operator / (const vec3& vec, const int& ref); //vec3와 상수의 나누셈을 구현
const vec3 operator * (const vec3& vec, const mat3& ref); //vec3와 3x3행렬의 곱을 구현
const vec3 operator * (const mat3& ref, const vec3& vec); //vec3와 3x3행렬의 곱을 구현
const vec4 operator + (const vec4& vec, const vec4& ref); //vec4끼리의 덧셈
const vec4 operator - (const vec4& vec, const vec4& ref); //vec4끼리의 뺄셈
const vec4 operator * (const vec4& vec, const int& ref); //vec4와 상수의 곱
const vec4 operator / (const vec4& vec, const int& ref); //vec4와 상수의 나누셈
const mat3 operator * (const mat3& mat, const mat3& ref); //3x3행렬 끼리의 곱을 구현
const mat3 operator + (const mat3& mat, const mat3& ref); //3x3행렬 끼리의 덧셈을 구현
const mat3 operator - (const mat3& mat, const mat3& ref); //3x3행렬 끼리의 뺄셈을 구현
const mat4 operator * (const mat4& mat, const mat4& ref); //4x4행렬 끼리의 곱을 구현
const mat4 operator + (const mat4& mat, const mat4& ref); //4x4행렬 끼리의 덧셈을 구현
const mat4 operator - (const mat4& mat, const mat4& ref); //4x4행렬 끼리의 뺄셈을 구현

double radians(double degree);
double degree(double radian);
