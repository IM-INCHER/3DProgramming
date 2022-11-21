#include "MuSoenMath.h"

const vec3 operator + (const vec3& vec, const vec3& ref) //vec3³¢¸®ÀÇ µ¡¼À
{
	vec3 result;

	result.x = vec.x + ref.x;
	result.y = vec.y + ref.y;
	result.z = vec.z + ref.z;

	return result;
}

const vec3 operator - (const vec3& vec, const vec3& ref) //vec3³¢¸®ÀÇ »¬¼À
{
	vec3 result;

	result.x = vec.x - ref.x;
	result.y = vec.y - ref.y;
	result.z = vec.z - ref.z;

	return result;
}

const vec3 operator * (const vec3& vec, const vec3& ref) //vec3¿Í 3x3Çà·ÄÀÇ °öÀ» ±¸Çö
{
	vec3 result;

	result.x = vec.x * ref.x;
	result.y = vec.y * ref.y;
	result.z = vec.z * ref.z;

	return result;
}

const vec3 operator * (const vec3& vec, const int& ref) //vec3¿Í »ó¼öÀÇ °ö
{
	vec3 result;

	result.x = vec.x * ref;
	result.y = vec.y * ref;
	result.z = vec.z * ref;

	return result;
}

const vec3 operator / (const vec3& vec, const int& ref) //vec3¿Í »ó¼öÀÇ ³ª´©¼ÀÀ» ±¸Çö
{
	vec3 result;

	result.x = vec.x / ref;
	result.y = vec.y / ref;
	result.z = vec.z / ref;

	return result;
}

const vec3 operator * (const vec3& vec, const mat3& ref) //vec3¿Í 3x3Çà·ÄÀÇ °öÀ» ±¸Çö
{
	vec3 result;

	result.x = ref.num[0][0] * vec.x + ref.num[0][1] * vec.y + ref.num[0][2] * vec.z;
	result.y = ref.num[1][0] * vec.x + ref.num[1][1] * vec.y + ref.num[1][2] * vec.z;
	result.z = ref.num[2][0] * vec.x + ref.num[2][1] * vec.y + ref.num[2][2] * vec.z;

	return result;
}

const vec3 operator * (const mat3& ref, const vec3& vec) //vec3¿Í 3x3Çà·ÄÀÇ °öÀ» ±¸Çö
{
	vec3 result;
	mat3 mat = ref;
	mat = mat.Transpose(); //Çà·Ä¿Í ¹éÅÍÀÇ °öÀÌ±â¿¡ ÀüÄ¡Çà·Ä·Î º¯È¯ ÇÏ¿© °è»êÇØÁİ´Ï´Ù.

	result.x = mat.num[0][0] * vec.x + mat.num[0][1] * vec.y + mat.num[0][2] * vec.z;
	result.y = mat.num[1][0] * vec.x + mat.num[1][1] * vec.y + mat.num[1][2] * vec.z;
	result.z = mat.num[2][0] * vec.x + mat.num[2][1] * vec.y + mat.num[2][2] * vec.z;

	return result;
}

const vec4 operator + (const vec4& vec, const vec4& ref) //vec4³¢¸®ÀÇ µ¡¼À
{
	vec4 result;

	result.x = vec.x + ref.x;
	result.y = vec.y + ref.y;
	result.z = vec.z + ref.z;
	result.w = vec.w + ref.w;

	return result;
}

const vec4 operator - (const vec4& vec, const vec4& ref) //vec4³¢¸®ÀÇ »¬¼À
{
	vec4 result;

	result.x = vec.x - ref.x;
	result.y = vec.y - ref.y;
	result.z = vec.z - ref.z;
	result.w = vec.w - ref.w;

	return result;
}

const vec4 operator * (const vec4& vec, const int& ref) //vec4¿Í »ó¼öÀÇ °ö
{
	vec4 result;

	result.x = vec.x * ref;
	result.y = vec.y * ref;
	result.z = vec.z * ref;
	result.w = vec.w * ref;

	return result;
}

const vec4 operator / (const vec4& vec, const int& ref) //vec4¿Í »ó¼öÀÇ ³ª´©¼À
{
	vec4 result;

	result.x = vec.x / ref;
	result.y = vec.y / ref;
	result.z = vec.z / ref;
	result.w = vec.w / ref;

	return result;
}

const mat3 operator * (const mat3& mat, const mat3& ref) //3x3Çà·Ä ³¢¸®ÀÇ °öÀ» ±¸Çö
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

const mat3 operator + (const mat3& mat, const mat3& ref) //3x3Çà·Ä ³¢¸®ÀÇ µ¡¼ÀÀ» ±¸Çö
{
	mat3 result;

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			result.num[i][j] = mat.num[i][j] + ref.num[i][j];
		}
	}

	return result;
}

const mat3 operator - (const mat3& mat, const mat3& ref) //3x3Çà·Ä ³¢¸®ÀÇ »¬¼ÀÀ» ±¸Çö
{
	mat3 result;

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			result.num[i][j] = mat.num[i][j] - ref.num[i][j];
		}
	}

	return result;
}

const mat4 operator * (const mat4& mat, const mat4& ref) //4x4Çà·Ä ³¢¸®ÀÇ °öÀ» ±¸Çö
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

const mat4 operator + (const mat4& mat, const mat4& ref) //4x4Çà·Ä ³¢¸®ÀÇ µ¡¼ÀÀ» ±¸Çö
{
	mat4 result;

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			result.num[i][j] = mat.num[i][j] + ref.num[i][j];
		}
	}

	return result;
}

const mat4 operator - (const mat4& mat, const mat4& ref) //4x4Çà·Ä ³¢¸®ÀÇ »¬¼ÀÀ» ±¸Çö
{
	mat4 result;

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			result.num[i][j] = mat.num[i][j] - ref.num[i][j];
		}
	}

	return result;
}

double radians(double degree)
{
	return degree * PI / 180;
}

double degree(double radian)
{
	return radian * 180 / PI;
}

mat4::mat4(float _00, float _01, float _02, float _03, float _10, float _11, float _12, float _13, float _20, float _21, float _22, float _23, float _30, float _31, float _32, float _33)
{
	num[0][0] = _00; num[0][1] = _01; num[0][2] = _02; num[0][3] = _03;
	num[1][0] = _10; num[1][1] = _11; num[1][2] = _12; num[1][3] = _13;
	num[2][0] = _20; num[2][1] = _21; num[2][2] = _22; num[2][3] = _23;
	num[3][0] = _30; num[3][1] = _31; num[3][2] = _32; num[3][3] = _33;
}

mat4 mat4::Identity()
{
	return mat4(1, 0, 0, 0,
				0, 1, 0, 0,
				0, 0, 1, 0,
				0, 0, 0, 1);
}

mat4 mat4::Transpose()
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

mat3::mat3(float _00, float _01, float _02, float _10, float _11, float _12, float _20, float _21, float _22)
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

mat3 mat3::Identity()
{
	return mat3(1, 0, 0,
				0, 1, 0,
				0, 0, 1);
}

mat3 mat3::Transpose()
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
