#pragma once


/**
*�����溯������
**/

void sale(chartMerchan &ListOfGoods);
void retrunSale(chartMerchan &ListOfGoods);
void analyseData(chartMerchan &ListOfGoods);
void exitSystem();




/**
*�ӽ��溯������
**/


void selectAdd(chartMerchan &ListOfGood);
void selectDelete();
void returnLast();


/**
*���Һ���
*/
void SelectByName(chartMerchan &ListOfGoods);
void SelectByMfr(chartMerchan &ListOfGoods);
void SelectByClass(chartMerchan &ListOfGoods);
void returnChildLast();

void selectModify(Merchandise *backup);



