#include "MuSoenMath.h"

using namespace std;

void main() 
{
	vec3 v = vec3(0,0,1); //0,0 의 벡터 초기화

	mat3 Translate = mat3(1,0,0, //이동행렬 입력
						  0,1,0,
						  3,5,1);
	

	mat3 Rotate = mat3(cos(30 * PI / 180), -sin(30 * PI / 180), 0, //회전행렬 입력
						sin(30 * PI / 180), cos(30 * PI / 180), 0,
						0, 0, 1);

	mat3 Scale = mat3(2, 0, 0,		//크기조절 행렬 입력
						0, 2, 0,
						0, 0, 1);

	vec3 p = v * Translate * Rotate * Scale;   // 3,5 이동 | 30도 회전 | 2배 확대

	cout << "X = " << p.x << " Y = " << p.y << " Z = " << p.z << endl; //결과값 출력

	p = v * Scale * Rotate * Translate;   // SRT 순으로 계산

	cout << "SRT순서로 계산시" << endl; //결과값 출력
	cout << "X = " << p.x << " Y = " << p.y << " Z = " << p.z << endl; //결과값 출력
}
