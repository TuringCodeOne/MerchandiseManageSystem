#pragma once
/********************************
	
	*��Ҫ��ɿ���̨���ڸ�ʽ����
	   1.ϵͳ����Ա��¼
	   2.��ȡ��ǰϵͳʱ��
	   3.ϵͳ���ܲ˵�ѡ���

**********************************/

#include<iostream>
#include<ctime>
#include<string>
#include<Windows.h>
#include"goodsClass.h"

#define PASSWORD  "rootroot"
#define TRY_TIMES 2

using namespace std;


/**
*�˵�����
**/

void printDividerStar();
void printShortStar();
void printShortWhiteStar();
void printLongStar();
void printLongDash();
void printLongerDash();
void printShortDash();
void printBlank();


void printMainMenu();
void printChildMenu();

void printModifyMenu();
void printSelectMenu();

void switchFunction();
void manageFunction();
void selectFunction();
void systemStart();



void modifyFunction(chartMerchan &ListOfGoods);

/**
*ϵͳʱ��
**/
void printSystemTime();

/**
*����Ա��¼
**/
void administratorLigin();
bool isLogin(string password);


