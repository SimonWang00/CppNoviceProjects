#include<iostream>
#include "speechManager.h"
using namespace std;

int main()
{
	SpeechManager sm;
	while (true)
	{
		sm.show_menu();
		int select = -1;
		cout << "�����벽�裺" ;
		cin >> select;
		switch (select)
		{
		case 0:	//�˳�ϵͳ
			sm.exitSystem();
			break;
		case 1:	//��ʼ����
			sm.startSpeech();
			break;
		case 2:	//�鿴������¼
			sm.loadRecord();
			break;
		case 3:	//��ռ�¼
			sm.clearRecord();
			break;
		default:
			break;
		}
	}
	system("pause");
	return 0;
}