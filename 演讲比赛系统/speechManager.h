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

//����ݽ�������
class SpeechManager
{
public:
	////���캯��////
	SpeechManager();
	////��������////
	~SpeechManager();
	////��ʾ�˵�////
	void show_menu();
	////�˳�ϵͳ////
	void exitSystem();

	////��Ա����////
	vector<int> v1;		//��һ�ֱ���ѡ������
	vector<int> v2;		//��һ�ֽ���ѡ������
	vector<int> vVictory;	//ǰ����ѡ������

	////��ű���Լ���Ӧѡ�ֵ�����////
	map<int, Speaker> m_Speaker;

	////��ű�������////
	int m_Index;
	////��ʼ��////
	void initSpeech();
	////����ѡ��////
	//��ʼ������12��ѡ��
	void createSpeaker();
	////��ʼ����////
	void startSpeech();
	////��ǩ////
	void speechDraw();
	////����////
	void speechContest();
	////��ʾ�������////
	void showScore();
	////�����¼////
	void saveRecord();

	////��ȡ��¼////
	void loadRecord();

	////�ļ�Ϊ�յı�־////
	bool fileIsEmpty;

	////�����¼////
	map<int, vector<string>> m_Record;
	
	////��ʾ����÷�////
	void showRecord();

	////��ռ�¼////
	void clearRecord();
};