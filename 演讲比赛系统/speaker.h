#pragma once
#include<string>
using namespace std;

class Speaker
{
public:
	////构造函数////
	Speaker();
	////析构函数////
	~Speaker();

	string m_Name;  //姓名
	double m_Score[2]; //分数  最多有两轮得分
};