#include<iostream>
#include<fstream>
#include<string>
using namespace std;

#include "Identity.h"
#include "globalFile.h"
#include "student.h"
#include "teacher.h"
#include "Manager.h"

//����ѧ���Ӳ˵�
void studentMenu(Identity * &student)
{
	while (true)
	{
		//ѧ����˵�
		student->operMenu();
		//ָ������ǿת,��Ȼ����ָ��û�����������еķ���
		Student* stu = (Student*) student;
		int select = 0;

		cin >> select;
		if (select == 1)  //����ԤԼ
		{
			stu->applyOrder();
		}
		else if (select == 2) //�鿴����ԤԼ
		{
			stu->showMyOrder();
		}
		else if (select == 3) //�鿴������ԤԼ
		{
			stu->showAllOrder();
		}
		else if (select == 4) //ȡ��ԤԼ
		{
			stu->cancelOrder();
		}
		else
		{
			delete stu;
			cout << "ע���ɹ�" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

//�����ʦ�Ӳ˵�
void teacherMenu(Identity * &teacher)
{
	while (true)
	{
		//��ʦ��˵�
		teacher->operMenu();
		//ָ������ǿת,��Ȼ����ָ��û�����������еķ���
		Teacher* tea = (Teacher*)teacher;
		int select = 0;

		cin >> select;
		if (select == 1)  //�鿴����ԤԼ
		{
			tea->showAllOrder();
		}
		else if (select == 2) //���ԤԼ
		{
			tea->validOrder();
		}
		else
		{
			delete tea;
			cout << "ע���ɹ�" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

//�������Ա�Ӳ˵�
void managerMenu(Identity * &manager)
{
	while (true)
	{
		//����Ա�˵�
		manager->operMenu();
		//ָ������ǿת,��Ȼ����ָ��û�����������еķ���
		Manager* man = (Manager*)manager;
		int select = 0;

		cin >> select;
		if (select == 1)  //����˺�
		{
			//cout << "����˺�" << endl;
			man->addPerson();
		}
		else if (select == 2) //�鿴�˺�
		{
			//cout << "�鿴�˺�" << endl;
			man->showPerson();
		}
		else if (select == 3) //�鿴����
		{
			//cout << "�鿴����" << endl;
			man->showComputer();
		}
		else if (select == 4) //���ԤԼ
		{
			//cout << "���ԤԼ" << endl;
			man->clearFile();
		}
		else
		{
			delete manager;
			cout << "ע���ɹ�" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

//��¼��֤
void LoginIn(string fileName, int type)
{
	//����ָ������ָ�����࣬��̬
	Identity *person = NULL;
	ifstream ifs;
	ifs.open(fileName, ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ������ڣ�" << endl;
		ifs.close();
		return;
	}
	//׼��������Ϣ
	int id;
	string name, pwd;
	//�ж����
	if (type == 1)		//ѧ��
	{
		cout << "���������ѧ�ţ�" << endl;
		cin >> id;
	}
	else if (type == 2)		//��ʦ
	{
		cout << "���������ְ���ţ�" << endl;
		cin >> id;
	}
	cout << "�������û�����" << endl;
	cin >> name;

	cout << "���������룺 " << endl;
	cin >> pwd;

	if (type == 1)
	{
		//ѧ����¼��֤
		int fId;	//�ļ��е�id
		string fName;	//�ļ��е�����
		string fPwd;	//�ļ��е�����

		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
		{
			//cout << fId << " " << fName << " " << fPwd << endl;
			if (fId == id && fName ==name && fPwd == pwd)
			{
				cout << "ѧ����֤��¼�ɹ���" << endl;
				system("pause");
				system("cls");
				person = new Student(id, name, pwd);
				//����ѧ���˵�����
				studentMenu(person);
				return;
			}
		}
	}
	else if (type == 2)
	{
		//��ʦ��¼��֤
		int fId;	//�ļ��е�id
		string fName;	//�ļ��е�����
		string fPwd;	//�ļ��е�����

		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
		{
			//cout << fId << " " << fName << " " << fPwd << endl;
			if (fId == id && fName == name && fPwd == pwd)
			{
				cout << "��ʦ��֤��¼�ɹ���" << endl;
				system("pause");
				system("cls");
				person = new Teacher(id, name, pwd);
				//�����ʦ�˵�����
				teacherMenu(person);
				return;
			}
		}
	}
	else if (type == 3)
	{
		//����Ա��¼��֤
		string fName;
		string fPwd;
		while (ifs >> fName && ifs >> fPwd)
		{
			if (name == fName && pwd == fPwd)
			{
				cout << "��֤��¼�ɹ�!" << endl;
				//��¼�ɹ��󣬰�������������Ա����
				system("pause");
				system("cls");
				//��������Ա����
				person = new Manager(name, pwd);
				managerMenu(person);
				return;
			}
		}
	}

	cout << "��֤��¼ʧ��!" << endl;
	system("pause");
	system("cls");
	return;
}

int main() 
{
	int select;	//�û�ѡ��
	while (true)
	{
		cout << "======================  ��ӭ��������ԤԼϵͳ  ====================="
			<< endl;
		cout << endl << "�������������" << endl;
		cout << "\t\t -------------------------------\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          1.ѧ    ��           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          2.��    ʦ           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          3.�� �� Ա           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          0.��    ��           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t -------------------------------\n";
		cout << "��������ѡ��: ";
		cin >> select;

		switch (select)
		{
		case 1:		//ѧ��
			LoginIn(STUDENT_FILE, 1);
			break;
		case 2:		//��ʦ
			LoginIn(TEACHER_FILE, 2);
			break;
		case 3:
			LoginIn(ADMIN_FILE, 3);
			break;	//����Ա
		case 0:		//�˳�
			cout << "��ӭ�´�ʹ�ã�" << endl;
			system("pause");
			return 0;
			break;
		default:
			cout << "��������������ѡ��" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
	system("pause");
	return 0;
}