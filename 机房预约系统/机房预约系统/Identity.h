#pragma once
#include<iostream>
#include<string>
using namespace std;

//��ݵĳ������
class Identity
{
public:
	string m_Name;	//����
	string m_Pwd;	//����

	//�����˵��������麯��
	virtual void operMenu() = 0;	
};