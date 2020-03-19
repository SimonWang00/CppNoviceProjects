#pragma once
#include<string>
#include<iostream>
#include<vector>
#include<fstream>
#include<map>
#include "computerRoom.h"
#include "Identity.h"
#include "globalFile.h"
#include "orderFile.h"
using namespace std;

// 学生类
class Student : public Identity
{
public:
	int m_Id;	//学生学号

	//无参构造
	Student();

	//有参构造，学号，姓名，密码
	Student(int id, string name, string pwd);

	//菜单显示栏
	virtual void operMenu();

	//申请预约
	void applyOrder();

	//查看我的预约
	void showMyOrder();

	//查看所有预约
	void showAllOrder();

	//取消预约
	void cancelOrder();

	//机房容器
	vector<ComputerRoom> vCom;

	//析构函数
	~Student();
};

