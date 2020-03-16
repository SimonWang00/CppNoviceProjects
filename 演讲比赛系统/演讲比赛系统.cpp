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
		cout << "请输入步骤：" ;
		cin >> select;
		switch (select)
		{
		case 0:	//退出系统
			sm.exitSystem();
			break;
		case 1:	//开始比赛
			sm.startSpeech();
			break;
		case 2:	//查看比赛记录
			sm.loadRecord();
			sm.showRecord();
			break;
		case 3:	//清空记录
			sm.clearRecord();
			break;
		default:
			break;
		}
	}
	system("pause");
	return 0;
}
