#include "Manager.h"

//�޲�������
Manager::Manager()
{
}

//�вι���
Manager::Manager(string name, string pwd)
{
	this->m_Name = name;
	this->m_Pwd = pwd;
	//��ʼ����������ȡ�ļ��е�����
	this->initVector();

	//��ʼ����������Ϣ
	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);
	if (ifs.is_open())
	{
		ComputerRoom cr;
		while (ifs >> cr.m_ComId && ifs >> cr.m_MaxNum)
		{
			vCom.push_back(cr);
		}
	}
	ifs.close();
}

//��������
Manager::~Manager()
{

}

//�˵���Ŀ
void Manager::operMenu()
{
	cout << "��ӭ����Ա��" << this->m_Name << "��¼��" << endl;
	cout << "\t\t ---------------------------------\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          1.����˺�            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          2.�鿴�˺�            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          3.�鿴����            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          4.���ԤԼ            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          0.ע����¼            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t ---------------------------------\n";
	cout << "��ѡ�����Ĳ����� " << endl;
}

//����˺�
void Manager::addPerson()
{

	cout << "����������˺ŵ�����" << endl;
	cout << "1�����ѧ��" << endl;
	cout << "2�������ʦ" << endl;

	string fileName;
	string tip;
	string errorTip;		//������ʾ
	ofstream ofs;

	int select = 0;
	cin >> select;

	if (select == 1)
	{
		fileName = STUDENT_FILE;
		tip = "������ѧ�ţ� ";
		errorTip = "ѧ���ظ������������룡";
	}
	else
	{
		fileName = TEACHER_FILE;
		tip = "������ְ����ţ�";
		errorTip = "ְ�����ظ������������룡";
	}

	ofs.open(fileName, ios::out | ios::app);
	int id;
	string name;
	string pwd;

	while (true)
	{
		cout << tip << endl;
		cin >> id;
		bool ret = this->checkRepeat(id, select);
		if (ret)
		{
			cout << errorTip << endl;
		}
		else
		{
			break;
		}
	}
	cout << "������������ " << endl;
	cin >> name;

	cout << "���������룺 " << endl;
	cin >> pwd;

	ofs << id << " " << name << " " << pwd << " " << endl;
	cout << "��ӳɹ�" << endl;

	system("pause");
	system("cls");

	ofs.close();
	//ˢ����������֤����ӵ��ܽ���������
	this->initVector();
}

//��ʾѧ����
void printStu(Student &s)
{
	cout << "ѧ�ţ�" << s.m_Id << " ������" << s.m_Name << " ���룺" << s.m_Pwd << endl;
}

//��ʾ��ʦ��
void printTea(Teacher &t)
{
	cout << "���ţ�" << t.m_EmpId << " ������" << t.m_Name << " ���룺" << t.m_Pwd << endl;
}

//�鿴�˺�
void Manager::showPerson()
{
	cout << "��ѡ��鿴���ݣ�" << endl;
	cout << "1���鿴����ѧ��" << endl;
	cout << "2���鿴������ʦ" << endl;

	int select = 0;		//�����û���ѡ��
	cin >> select;
	if (select == 1)
	{
		//�鿴ѧ��
		for_each(vStu.begin(), vStu.end(), printStu);
	}
	else
	{
		//�鿴��ʦ
		for_each(vTea.begin(), vTea.end(), printTea);
	}
	system("pause");
	system("cls");
}

//�����Ϣ
void Manager::clearFile()
{
	ofstream ofs;
	ofs.open(ORDER_FILE, ios::trunc);
	ofs.close();
	cout << "��ճɹ���" << endl;
	system("pause");
	system("cls");
}

//��ʼ������
void Manager::initVector()
{
	//ȷ���������״̬
	vStu.clear();
	vTea.clear();

	//��ȡѧ����Ϣ
	ifstream ifs;
	ifs.open(STUDENT_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ���ʧ�ܣ�" << endl;
		return;
	}
	Student s;
	while (ifs >> s.m_Id && ifs >> s.m_Name && ifs >> s.m_Pwd)
	{
		vStu.push_back(s);
	}
	cout << "��ǰѧ������Ϊ��" << vStu.size() << endl;
	ifs.close();

	ifs.open(TEACHER_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ���ʧ�ܣ�" << endl;
		return;
	}
	Teacher t;
	while (ifs >> t.m_EmpId && ifs >> t.m_Name &&  ifs >> t.m_Pwd)
	{
		vTea.push_back(t);
	}
	cout << "��ǰ��ʦ����Ϊ��" << vTea.size() << endl;
	ifs.close();
}

bool Manager::checkRepeat(int id, int type)
{
	if (type == 1)
	{
		for (vector<Student>::iterator it = vStu.begin(); it < vStu.end(); it++)
		{
			if (it->m_Id == id)
			{
				return true;
			}
		}
	}
	else
	{
		for (vector<Teacher>::iterator it = vTea.begin(); it < vTea.end(); it++)
		{
			if (it->m_EmpId == id)
			{
				return true;
			}
		}
	}
	return false;
}

//��ʾ������Ϣ
void Manager::showComputer()
{
	cout << "������Ϣ���£�" << endl;
	for (vector<ComputerRoom>::iterator it = vCom.begin(); it < vCom.end(); it++)
	{
		cout << "������ţ�" << it->m_ComId << " �����������" << it->m_MaxNum << endl;
	}
	system("pause");
	system("cls");
}