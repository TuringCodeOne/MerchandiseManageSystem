#pragma once


/**
*主界面函数定义
**/

void sale(chartMerchan &ListOfGoods);
void retrunSale(chartMerchan &ListOfGoods);
void analyseData(chartMerchan &ListOfGoods);
void exitSystem();




/**
*子界面函数定义
**/


void selectAdd(chartMerchan &ListOfGood);
void selectDelete();
void returnLast();


/**
*查找函数
*/
void SelectByName(chartMerchan &ListOfGoods);
void SelectByMfr(chartMerchan &ListOfGoods);
void SelectByClass(chartMerchan &ListOfGoods);
void returnChildLast();

void selectModify(Merchandise *backup);



