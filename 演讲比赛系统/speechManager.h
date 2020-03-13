#pragma once
#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<algorithm>
#include<numeric>
#include<deque>
#include<fstream>
#include "speaker.h"
using namespace std;

//设计演讲管理类
class SpeechManager
{
public:
	////构造函数////
	SpeechManager();
	////析构函数////
	~SpeechManager();
	////显示菜单////
	void show_menu();
	////退出系统////
	void exitSystem();

	////成员属性////
	vector<int> v1;		//第一轮比赛选手容器
	vector<int> v2;		//第一轮晋级选手容器
	vector<int> vVictory;	//前三名选手容器

	////存放编号以及对应选手的容器////
	map<int, Speaker> m_Speaker;

	////存放比赛轮数////
	int m_Index;
	////初始化////
	void initSpeech();
	////创建选手////
	//初始化创建12名选手
	void createSpeaker();
	////开始比赛////
	void startSpeech();
	////抽签////
	void speechDraw();
	////比赛////
	void speechContest();
	////显示比赛结果////
	void showScore();
	////保存记录////
	void saveRecord();

	////读取记录////
	void loadRecord();

	////文件为空的标志////
	bool fileIsEmpty;

	////往届记录////
	map<int, vector<string>> m_Record;
	
	////显示往届得分////
	void showRecord();

	////清空记录////
	void clearRecord();
};