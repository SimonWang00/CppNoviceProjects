#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include<algorithm>
#include "student.h"
#include "globalFile.h"
#include "Identity.h"
#include "teacher.h"
#include "computerRoom.h"
using namespace std;

class Manager : public Identity
{
public:
	//无参构造
	Manager();

	//有参构造
	Manager(string name, string pwd);

	//析构函数
	~Manager();

	//菜单栏
	virtual void operMenu();

	//添加账号
	void addPerson();

	//查看账号
	void showPerson();

	//查看机房信息
	void showComputer();

	//清空信息
	void clearFile();

	//初始化容器
	void initVector();

	//学生容器
	vector<Student> vStu;

	//教师容器
	vector<Teacher> vTea;

	//机房容器
	vector<ComputerRoom> vCom;

	//检测去重
	bool checkRepeat(int id, int type);
};

