#pragma once

/***************************************
** 商品类定义                       
**             *食品
**             *化妆品
**             *日用品
**             *饮料
**
** 商品链表类定义
***************************************/


#include<string>
#include<iostream>
using namespace std;

const string STATUS[2] = { "已售出","在售" };
const string MERCLASS[4] = { "食品","化妆品","日用品","饮料" };

class chartMerchan;//先行声明charMerchan类

class Merchandise
{
protected:
	string merName;     //商品名
	string merId;       //编号
	double merPrice;    //价格
	unsigned short int merStatus;     //是否在售
	string merMfr;      //生产厂家
	string merBrand;    //品牌
	unsigned short int merClass;       //商品类型
	static int MERSTOCKS[4];//分别代表4种商品各自库存
	
public:
	Merchandise *next;


	Merchandise();
	bool getStatus() { return merStatus; }
	
	
	void initGood(chartMerchan &ListOfGoods);
	void display();
	void displayLine();

	void modifyData();
	void modifyIn();
	void modifyOut();
	
	string getMerId();
	string getMerClass();
	unsigned short int getClass();
	string getMerMfr();
	string getMerName();
	unsigned short int getMerStatus();
	double getMerPrice();
	string getMerBrand();
	int gerMerRespo();


	void modifyClass(unsigned short int backup);    //改类型
	void modifyMfr(string backup);					//改生产厂家
	void modifyName(string backup);					//改商品名  
	void modifyId(string backup);					//改商品编号  
	void modifyPrice(double backup);				//改商品价格
	void modifyBrand(string backup);				//改商品品牌

	void ModifyMERSTOCKS();
	void ModifyMERSTOCKS(bool element,unsigned short int merclass);		//修改库存


	friend ostream &operator << (ostream &out,  Merchandise &merchandise);
	friend istream &operator >>(istream &in, Merchandise &merchandise);
};







class chartMerchan
{
private:
	Merchandise *header;
	Merchandise *move;
	
public:
	Merchandise *front;
	chartMerchan();
	Merchandise *getHeader();


	void insertData(Merchandise *newData);
	int selectData();

	Merchandise* modifyStatus(string id);



	bool checkDataId(string id);


	void selectByName(string merName);
	int selectByClass(int merclass, bool isnt);
	void selectByMfr(string mermfr);

	Merchandise *makeListByClass(int merclass);
	

	//friend ostream &operator << (ostream &out, chartMerchan &charmerchan);

};
//全局声明ListOfGoods
extern chartMerchan ListOfGoods;
