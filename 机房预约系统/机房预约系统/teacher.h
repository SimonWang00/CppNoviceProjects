#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include "student.h"
#include "Identity.h"
#include "globalFile.h"
using namespace std;

//��ʦ��
class Teacher : public Identity
{
public:
	int m_EmpId;		//��ʦ����

	//Ĭ�Ϲ���
	Teacher();

	//��������
	~Teacher();

	//���ι���
	Teacher(int id, string name, string pwd);

	//�˵�����
	virtual void operMenu();

	//�鿴����ԤԼ
	void showAllOrder();

	//���ԤԼ
	void validOrder();

};

