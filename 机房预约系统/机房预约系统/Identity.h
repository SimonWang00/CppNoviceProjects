#pragma once
#include<iostream>
#include<string>
using namespace std;

//身份的抽象基类
class Identity
{
public:
	string m_Name;	//姓名
	string m_Pwd;	//密码

	//操作菜单栏，纯虚函数
	virtual void operMenu() = 0;	
};