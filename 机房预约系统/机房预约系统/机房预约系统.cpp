#include<iostream>
#include<fstream>
#include<string>
using namespace std;

#include "Identity.h"
#include "globalFile.h"
#include "student.h"
#include "teacher.h"
#include "Manager.h"

//进入学生子菜单
void studentMenu(Identity * &student)
{
	while (true)
	{
		//学生类菜单
		student->operMenu();
		//指针类型强转,不然父类指针没法访问子类中的方法
		Student* stu = (Student*) student;
		int select = 0;

		cin >> select;
		if (select == 1)  //申请预约
		{
			stu->applyOrder();
		}
		else if (select == 2) //查看自身预约
		{
			stu->showMyOrder();
		}
		else if (select == 3) //查看所有人预约
		{
			stu->showAllOrder();
		}
		else if (select == 4) //取消预约
		{
			stu->cancelOrder();
		}
		else
		{
			delete stu;
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

//进入教师子菜单
void teacherMenu(Identity * &teacher)
{
	while (true)
	{
		//教师类菜单
		teacher->operMenu();
		//指针类型强转,不然父类指针没法访问子类中的方法
		Teacher* tea = (Teacher*)teacher;
		int select = 0;

		cin >> select;
		if (select == 1)  //查看所有预约
		{
			tea->showAllOrder();
		}
		else if (select == 2) //审核预约
		{
			tea->validOrder();
		}
		else
		{
			delete tea;
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

//进入管理员子菜单
void managerMenu(Identity * &manager)
{
	while (true)
	{
		//管理员菜单
		manager->operMenu();
		//指针类型强转,不然父类指针没法访问子类中的方法
		Manager* man = (Manager*)manager;
		int select = 0;

		cin >> select;
		if (select == 1)  //添加账号
		{
			//cout << "添加账号" << endl;
			man->addPerson();
		}
		else if (select == 2) //查看账号
		{
			//cout << "查看账号" << endl;
			man->showPerson();
		}
		else if (select == 3) //查看机房
		{
			//cout << "查看机房" << endl;
			man->showComputer();
		}
		else if (select == 4) //清空预约
		{
			//cout << "清空预约" << endl;
			man->clearFile();
		}
		else
		{
			delete manager;
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

//登录验证
void LoginIn(string fileName, int type)
{
	//父类指针用于指向子类，多态
	Identity *person = NULL;
	ifstream ifs;
	ifs.open(fileName, ios::in);
	if (!ifs.is_open())
	{
		cout << "文件不存在！" << endl;
		ifs.close();
		return;
	}
	//准备接收信息
	int id;
	string name, pwd;
	//判断身份
	if (type == 1)		//学生
	{
		cout << "请输入你的学号：" << endl;
		cin >> id;
	}
	else if (type == 2)		//老师
	{
		cout << "请输入你的职工号：" << endl;
		cin >> id;
	}
	cout << "请输入用户名：" << endl;
	cin >> name;

	cout << "请输入密码： " << endl;
	cin >> pwd;

	if (type == 1)
	{
		//学生登录验证
		int fId;	//文件中的id
		string fName;	//文件中的姓名
		string fPwd;	//文件中的密码

		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
		{
			//cout << fId << " " << fName << " " << fPwd << endl;
			if (fId == id && fName ==name && fPwd == pwd)
			{
				cout << "学生验证登录成功！" << endl;
				system("pause");
				system("cls");
				person = new Student(id, name, pwd);
				//进入学生菜单界面
				studentMenu(person);
				return;
			}
		}
	}
	else if (type == 2)
	{
		//教师登录验证
		int fId;	//文件中的id
		string fName;	//文件中的姓名
		string fPwd;	//文件中的密码

		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
		{
			//cout << fId << " " << fName << " " << fPwd << endl;
			if (fId == id && fName == name && fPwd == pwd)
			{
				cout << "教师验证登录成功！" << endl;
				system("pause");
				system("cls");
				person = new Teacher(id, name, pwd);
				//进入教师菜单界面
				teacherMenu(person);
				return;
			}
		}
	}
	else if (type == 3)
	{
		//管理员登录验证
		string fName;
		string fPwd;
		while (ifs >> fName && ifs >> fPwd)
		{
			if (name == fName && pwd == fPwd)
			{
				cout << "验证登录成功!" << endl;
				//登录成功后，按任意键进入管理员界面
				system("pause");
				system("cls");
				//创建管理员对象
				person = new Manager(name, pwd);
				managerMenu(person);
				return;
			}
		}
	}

	cout << "验证登录失败!" << endl;
	system("pause");
	system("cls");
	return;
}

int main() 
{
	int select;	//用户选择
	while (true)
	{
		cout << "======================  欢迎来到机房预约系统  ====================="
			<< endl;
		cout << endl << "请输入您的身份" << endl;
		cout << "\t\t -------------------------------\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          1.学    生           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          2.老    师           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          3.管 理 员           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          0.退    出           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t -------------------------------\n";
		cout << "输入您的选择: ";
		cin >> select;

		switch (select)
		{
		case 1:		//学生
			LoginIn(STUDENT_FILE, 1);
			break;
		case 2:		//老师
			LoginIn(TEACHER_FILE, 2);
			break;
		case 3:
			LoginIn(ADMIN_FILE, 3);
			break;	//管理员
		case 0:		//退出
			cout << "欢迎下次使用！" << endl;
			system("pause");
			return 0;
			break;
		default:
			cout << "输入有误，请重新选择！" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
	system("pause");
	return 0;
}