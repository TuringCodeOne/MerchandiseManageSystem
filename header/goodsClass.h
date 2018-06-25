#pragma once

/***************************************
** ��Ʒ�ඨ��                       
**             *ʳƷ
**             *��ױƷ
**             *����Ʒ
**             *����
**
** ��Ʒ�����ඨ��
***************************************/


#include<string>
#include<iostream>
using namespace std;

const string STATUS[2] = { "���۳�","����" };
const string MERCLASS[4] = { "ʳƷ","��ױƷ","����Ʒ","����" };

class chartMerchan;//��������charMerchan��

class Merchandise
{
protected:
	string merName;     //��Ʒ��
	string merId;       //���
	double merPrice;    //�۸�
	unsigned short int merStatus;     //�Ƿ�����
	string merMfr;      //��������
	string merBrand;    //Ʒ��
	unsigned short int merClass;       //��Ʒ����
	static int MERSTOCKS[4];//�ֱ����4����Ʒ���Կ��
	
public:
	Merchandise *next;

	bool getStatus() { return merStatus; }
	void initGood(chartMerchan &ListOfGoods);
	void display();
	void modifyData();
	void modifyIn();
	void modifyOut();
	
	string getMerId();
	string getMerClass();
	unsigned short int getClass();
	string getMerMfr();
	string getMerName();

	void modifyClass(unsigned short int backup);    //������
	void modifyMfr(string backup);					//����������
	void modifyName(string backup);					//����Ʒ��  
	void modifyId(string backup);					//����Ʒ���  
	void modifyPrice(double backup);				//����Ʒ�۸�
	void modifyBrand(string backup);				//����ƷƷ��

	void ModifyMERSTOCKS(bool element,unsigned short int merclass);		//�޸Ŀ��

};







class chartMerchan
{
private:
	Merchandise *header;
	Merchandise *move;
	
public:
	Merchandise *front;

	chartMerchan();
	void insertData(Merchandise *newData);
	int selectData();
	Merchandise* modifyStatus(string id);



	bool checkDataId(string id);
	void selectByName(string merName);
	void selectByClass(int merclass);
	void selectByMfr(string mermfr);
	

};
//ȫ������ListOfGoods
extern chartMerchan ListOfGoods;