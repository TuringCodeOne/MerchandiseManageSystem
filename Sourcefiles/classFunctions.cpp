#pragma once

#include"goodsClass.h"
#include"main.h"
#include<iomanip>


//静态成员初始化
int Merchandise::MERSTOCKS[] = { 0,0,0,0 };

Merchandise::Merchandise() {
	merName = "";
	merId = "";
	merPrice = 0;
	merMfr = "";
	merBrand = "";
	merStatus = 0;
	merClass = 0;
	next = NULL;
	MERSTOCKS[merClass - 1]++;


}

void Merchandise::initGood(chartMerchan &ListOfGoods) {


	cout << endl;
	printLongDash();
	printShortDash();
	cout << "\t\t\t*商品信息录入*\t\t\t";
	printShortDash();
	cout << endl;
	printLongDash();

	bool i = true;
	

	do{
		cout << "\n\n类型：[1]食品\t[2]化妆品\t[3]日用品\t[4]饮料\n";
		printLongDash();
		cout << "\n请选择：";
		cin >>merClass;
		if(cin.fail()) {
			printShortDash();
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
			cout << "无效字符串，请重试！！！";
			printShortDash();
			cin.clear();
			cin.ignore(1024, '\n');
		}
		else {
			if (merClass == 1 || merClass == 2 || merClass == 3 || merClass == 4) {
				i = false;
				MERSTOCKS[merClass - 1]++;//对应商品库存+1
			}
			else {
				printShortDash();
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
				cout << "选项不存在！！！无此类商品!请重试";
				printShortDash();
			}
		}
	} while (i);

	i = true;

	do {
		cout << "\n请输入商品名称：";
		cin >> merName;
		if (merName.size() > 0 && merName.size() < 20) {
			i = false;
		}
		else {
			printShortDash();
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
			cout << "商品名过长不合法！！！请重试";
			printShortDash();
		}
	} while (i);

	i = true;

	do {
		cout << "\n请输入商品编号：";
		cin >> merId;
		if (ListOfGoods.checkDataId(merId)) {
			cin.sync();
			printShortDash();
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
			cout << "数据库中已经存在此编号，请重新输入商品编号！";
			printShortDash();
		}
		else if(merId.size() != 6) {
				printShortDash();
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
				cout << "注意！！！商品编号需6位";
				printShortDash();
		}else i = false;
	} while (i);

	i = true;

	do {
		cout << "\n请输入商品价格：";
		cin >> merPrice;
		if (cin.fail()) {
			printShortDash();
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
			cout << "您输入的不是数字！！！请重新输入";
			printShortDash();
			cin.clear();
			cin.ignore(1024, '\n');
		}
		else if (merPrice < 0 || merPrice>100000) {
			printShortDash();
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
			cout << "您输入的价钱不符合常理！！！请重试";
			printShortDash();
		}
		else i = false;

	} while (i);

	
	i = true;

	do {
		cout << "\n请输入生产厂家：";
		cin >> merMfr;
		if (merMfr.size() > 0 && merMfr.size() < 100) {
			i = false;
		}
		else {
			printShortDash();
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
			cout << "那个生产厂家名字会这么长！！！请重新输入";
			printShortDash();
		}
	} while (i);

	i = true;

	do {
		cout << "\n请输入商品品牌：";
		cin >> merBrand;
		if (merBrand.size() > 0 && merBrand.size() < 20) {
			i = false;
		}
		else {
			printShortDash();
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
			cout << "有这么长的品牌吗？？？请重新输入";
			printShortDash();
		}
	} while (i);


	merStatus = 1;
}

void Merchandise::display() {
	cout << "\n\t\t*商品名:" << merName
		<< "\n\t\t*商品类别:" << MERCLASS[merClass - 1]
		<< "\n\t\t*商品编号:" << merId
		<< "\n\t\t*商品价格:" << merPrice
		<< "\n\t\t*生产厂家:" << merMfr
		<< "\n\t\t*商品品牌:" << merBrand;
	cout << "\n\t\t*状态:";
	if(merStatus==1){
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);
	cout<< STATUS[merStatus];
	}
	else {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
		cout << STATUS[merStatus];
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE);
	cout<< "\n\t\t*库存:"<<MERSTOCKS[merClass-1];
}

void Merchandise::displayLine() {
	cout << setw(8)<< merId
		<< setw(14)<<merName
		<< setw(13) << merPrice
		<< setw(21) << merMfr
		<< setw(13) << merBrand;
	cout << setw(16) ;
	if (merStatus == 1) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);
		cout << STATUS[merStatus];
	}
	else {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
		cout << STATUS[merStatus];
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE);
	cout << endl;
}





string Merchandise::getMerId() {
	return merId;
}

string Merchandise::getMerClass() {
	return MERCLASS[merClass-1];
}

unsigned short int Merchandise::getClass() {
	return merClass;
}

string Merchandise::getMerMfr() {
	return merMfr;
}

string Merchandise::getMerName() {
	return merName;
}
unsigned short int Merchandise::getMerStatus() {
	return merStatus;
}


double Merchandise::getMerPrice() {
	return merPrice;
}
string Merchandise::getMerBrand() {
	return merBrand;
}
int Merchandise::gerMerRespo() {
	return merClass;
}


void Merchandise::modifyIn() {
	merStatus = 1;
	MERSTOCKS[merClass - 1]++;
}
void Merchandise::modifyOut() {
	merStatus = 0;
	MERSTOCKS[merClass - 1]--;
}

void Merchandise::modifyData() {
	string id;
	cout << endl;
	printLongDash();
	cout << endl;
	cout << "想修改信息？那就请输入商品编号吧：";
	cin >> id;
	while (id.size() != 6) {
		cout << endl;
		printShortDash();
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
		cout << "注意！！！商品编号需6位";
		printShortDash();
		cout << endl;
		cout << "请再次输入商品号：";
		cin.clear();
		cin.ignore(1024, '\n');
		cin >> id;
	};

	if (ListOfGoods.checkDataId(id)) {
		Merchandise *ptr = ListOfGoods.modifyStatus(id);
		ListOfGoods.front->next = ptr->next;
		delete ptr;
		cout << endl;
		printShortDash();
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
		cout << "删除成功！！！";
		printShortDash();
		cout << endl;
	}
	else {
		cout << endl;
		printShortDash();
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
		cout << "数据库无与此商品相关信息";
		printShortDash();
		cout << "\n\n";

	}
}

void Merchandise::modifyClass(unsigned short int backup) {
	merClass = backup;						   
}											   
void Merchandise::modifyMfr(string backup) {
	merMfr = backup;
}
void Merchandise::modifyName(string backup) {
	merName = backup;
}
void Merchandise::modifyId(string backup) {
	merId = backup;
}
void Merchandise::modifyPrice(double backup) {
	merPrice = backup;
}
void Merchandise::modifyBrand(string backup) {
	merBrand = backup;
}

void Merchandise::ModifyMERSTOCKS() {
	MERSTOCKS[merClass - 1]++;
}

void Merchandise::ModifyMERSTOCKS(bool element,unsigned short int merclass) {
	if (element) {
		MERSTOCKS[merclass - 1]--;
	}
	if (!element) {
		MERSTOCKS[merclass - 1]++;
	}
}


ostream &operator << (ostream &out, Merchandise &merchandise) {
	out << "  " << merchandise.getMerId()
		<< "  " << merchandise.getMerName()
		<< "  " << merchandise.getClass()
		<< "  " << merchandise.getMerBrand()
		<< "  " << merchandise.getMerPrice()
		<< "  " << merchandise.getMerStatus()
		<< "  " << merchandise.getMerMfr()
		//<< "  " << merchandise.gerMerRespo()
		<< endl;
	return out;
}

istream &operator >> (istream &in, Merchandise &merchandise) {
	in >> merchandise.merId
		>> merchandise.merName
		>> merchandise.merClass
		>> merchandise.merBrand
		>> merchandise.merPrice
		>> merchandise.merStatus
		>> merchandise.merMfr;
		//>> merchandise.MERSTOCKS[merClass - 1];
	return in;
}

/**
string merName;     //商品名
string merId;       //编号
double merPrice;    //价格
unsigned short int merStatus;     //是否在售
string merMfr;      //生产厂家
string merBrand;    //品牌
unsigned short int merClass;       //商品类型
static int MERSTOCKS[4];//分别代表4种商品各自库存
*/











//表
chartMerchan::chartMerchan() {
	header = new Merchandise;
	move= header;
	front = header;
}

void chartMerchan::insertData(Merchandise *ptr) {
	move->next = ptr;
	move = ptr;
	ptr->next = NULL;
}

int chartMerchan::selectData() {
	Merchandise *p=header->next;
	int sum=0;
	cout << "\n\t";

	while (p) {	
		p = p->next;
		sum++;
	}
	return sum;
}

Merchandise *chartMerchan::getHeader() {
	return header;
}



Merchandise* chartMerchan::modifyStatus(string id) {
	Merchandise *p = front->next;
	while (p) {
		
		if (p->getMerId() == id)
			return p;
		front = front->next;
		p = front->next;
	};
	return NULL;
}



bool chartMerchan::checkDataId(string id) {
	Merchandise *p = header->next;
	while (p) {
		if (p->getMerId() == id)
			return true;
		p = p->next;
	}
	return false;
}

int chartMerchan::selectByClass(int merclass, bool isnt) {
	bool comby=isnt;
	int sum = 0;
	Merchandise *p = header->next;
	while (p) {
		if (p->getMerClass() == MERCLASS[merclass-1]) {
			comby = false;
			cout << endl;
			printBlank();
			printLongerDash();
			p->display();
			cout << "\n\t\t";
			printLongerDash();
			cout << endl;
			sum++;
		}
		p = p->next;
	};
	if(comby){
		cout << endl;
		printShortDash();
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
		cout << "库存中没有此类商品！！！";
		printShortDash();
		cout << "\n\n";
	}
	return sum;
}

void chartMerchan::selectByMfr(string mermfr) {
	bool comby = true;
	Merchandise *p = header->next;
	while (p) {
		if (p->getMerMfr() == mermfr) {
			comby = false;
			cout << endl;
			printBlank();
			printLongerDash();
			p->display();
			cout << "\n\t\t";
			printLongerDash();
			cout << endl;
		}
		p = p->next;
	};
	if (comby) {
		cout << endl;
		printShortDash();
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
		cout << "库存中没有此生产厂家的商品！！！";
		printShortDash();
		cout << "\n\n";
	}
}

void chartMerchan::selectByName(string mername) {
	bool comby = true;

	Merchandise *p = header->next;
	while (p) {
		if (p->getMerName() == mername) {
			comby = false;
			cout << endl;
			printBlank();
			printLongerDash();
			p->display();
			cout << "\n\t\t";
			printLongerDash();
			cout << endl;
		}
		p = p->next;
	};
	if (comby) {
		cout << endl;
		printShortDash();
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
		cout << "库存中没有此名称的商品！！！";
		printShortDash();
		cout << "\n\n";
	}
}

Merchandise* chartMerchan::makeListByClass(int merclass) {
	
	Merchandise *head = new Merchandise;
	Merchandise *pCompare;
	pCompare = head;
	Merchandise *insert;
	Merchandise *MOVE;
	MOVE = header;

	if (header->next == NULL) {
		return NULL;
	}


	*head = *header;
	head->next = NULL;
	MOVE = MOVE->next;
	insert = new Merchandise;
	*insert = *MOVE;
	insert->next = NULL;
	pCompare->next = insert;
	MOVE = MOVE->next;
	while (MOVE) {	
			pCompare = head;
			if (MOVE->getMerId().compare(pCompare->next->getMerId()) < 0) {
				insert = new Merchandise;
				*insert = *MOVE;
				insert->next = pCompare->next;
				pCompare->next = insert;
				MOVE = MOVE->next;
			}
			else {
				while (MOVE->getMerId().compare(pCompare->next->getMerId()) > 0) {

					pCompare = pCompare->next;
					if (pCompare->next == NULL) {
						break;
					}
				};

				if (pCompare->next == NULL) {
					insert = new Merchandise;
					*insert = *MOVE;
					pCompare->next = insert;
					insert->next = NULL;
					pCompare = head;
					MOVE = MOVE->next;
					
				}
				else {
					insert = new Merchandise;
					*insert = *MOVE;
					insert->next = pCompare->next;
					pCompare->next = insert;
					pCompare = head;
					MOVE = MOVE->next;	
				}
			}
	};
	return head;
}


//ostream &operator << (ostream &out, chartMerchan &chartmerchan) {
//	
//}

