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

// ѧ����
class Student : public Identity
{
public:
	int m_Id;	//ѧ��ѧ��

	//�޲ι���
	Student();

	//�вι��죬ѧ�ţ�����������
	Student(int id, string name, string pwd);

	//�˵���ʾ��
	virtual void operMenu();

	//����ԤԼ
	void applyOrder();

	//�鿴�ҵ�ԤԼ
	void showMyOrder();

	//�鿴����ԤԼ
	void showAllOrder();

	//ȡ��ԤԼ
	void cancelOrder();

	//��������
	vector<ComputerRoom> vCom;

	//��������
	~Student();
};

