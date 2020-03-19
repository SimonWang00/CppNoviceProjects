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
	//�޲ι���
	Manager();

	//�вι���
	Manager(string name, string pwd);

	//��������
	~Manager();

	//�˵���
	virtual void operMenu();

	//����˺�
	void addPerson();

	//�鿴�˺�
	void showPerson();

	//�鿴������Ϣ
	void showComputer();

	//�����Ϣ
	void clearFile();

	//��ʼ������
	void initVector();

	//ѧ������
	vector<Student> vStu;

	//��ʦ����
	vector<Teacher> vTea;

	//��������
	vector<ComputerRoom> vCom;

	//���ȥ��
	bool checkRepeat(int id, int type);
};

