#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include "student.h"
#include "Identity.h"
#include "globalFile.h"
using namespace std;

//教师类
class Teacher : public Identity
{
public:
	int m_EmpId;		//老师工号

	//默认构造
	Teacher();

	//析构函数
	~Teacher();

	//含参构造
	Teacher(int id, string name, string pwd);

	//菜单界面
	virtual void operMenu();

	//查看所有预约
	void showAllOrder();

	//审核预约
	void validOrder();

};

