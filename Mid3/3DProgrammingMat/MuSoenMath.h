#pragma once

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
		float _20, float _21, float _22); //���� �Է��Ͽ� �ʱ�ȭ �ϴ� ������


	mat3 Identity(); //������� ��ȯ
	mat3 Transpose(); //��ġ��� ��ȯ

};

class mat4 //4x4 ��� Ŭ����
{
public:
	float num[4][4] = {}; //�����Ҷ� 0���� �ʱ�ȭ

	mat4() //�����Ҷ� 0���� �ʱ�ȭ ������ ���� X
	{}
	

	mat4(float _00, float _01, float _02, float _03,
		float _10, float _11, float _12, float _13,
		float _20, float _21, float _22, float _23,
		float _30, float _31, float _32, float _33); //���� �Է��Ͽ� �ʱ�ȭ �ϴ� ������
	

	mat4 Identity(); //������� ��ȯ
	mat4 Transpose(); //��ġ��� ��ȯ
	
};

const vec3 operator + (const vec3& vec, const vec3& ref); //vec3������ ����
const vec3 operator - (const vec3& vec, const vec3& ref); //vec3������ ����
const vec3 operator * (const vec3& vec, const vec3& ref); //vec3�� 3x3����� ���� ����
const vec3 operator * (const vec3& vec, const int& ref); //vec3�� ����� ��
const vec3 operator / (const vec3& vec, const int& ref); //vec3�� ����� �������� ����
const vec3 operator * (const vec3& vec, const mat3& ref); //vec3�� 3x3����� ���� ����
const vec3 operator * (const mat3& ref, const vec3& vec); //vec3�� 3x3����� ���� ����
const vec4 operator + (const vec4& vec, const vec4& ref); //vec4������ ����
const vec4 operator - (const vec4& vec, const vec4& ref); //vec4������ ����
const vec4 operator * (const vec4& vec, const int& ref); //vec4�� ����� ��
const vec4 operator / (const vec4& vec, const int& ref); //vec4�� ����� ������
const mat3 operator * (const mat3& mat, const mat3& ref); //3x3��� ������ ���� ����
const mat3 operator + (const mat3& mat, const mat3& ref); //3x3��� ������ ������ ����
const mat3 operator - (const mat3& mat, const mat3& ref); //3x3��� ������ ������ ����
const mat4 operator * (const mat4& mat, const mat4& ref); //4x4��� ������ ���� ����
const mat4 operator + (const mat4& mat, const mat4& ref); //4x4��� ������ ������ ����
const mat4 operator - (const mat4& mat, const mat4& ref); //4x4��� ������ ������ ����

double radians(double degree);
double degree(double radian);
