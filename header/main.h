#pragma once
/********************************
	
	*主要完成控制台窗口格式定义
	   1.系统管理员登录
	   2.获取当前系统时间
	   3.系统功能菜单选项布局

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
*菜单布局
**/

void printDividerStar();
void printDividerStarPurple();
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

void printHeaderLine();



void modifyFunction(chartMerchan &ListOfGoods);

/**
*系统时间
**/
void printSystemTime();

/**
*管理员登录
**/
void administratorLigin();
bool isLogin(string password);


