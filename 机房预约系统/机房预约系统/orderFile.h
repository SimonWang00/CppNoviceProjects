#pragma once
#include<string>
#include<fstream>
#include<map>
#include<vector>
#include "globalFile.h"
using namespace std;

class OrderFile
{
public:
	//���캯��
	OrderFile();

	//����ԤԼ��¼
	void updateOrder();

	//��¼������  key --- ��¼������  value --- �����¼�ļ�ֵ����Ϣ
	map<int, map<string, string>> m_orderData;

	//ԤԼ��¼����
	int m_Size;
};

