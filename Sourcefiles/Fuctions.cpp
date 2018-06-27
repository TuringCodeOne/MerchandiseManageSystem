#pragma once

#include"main.h"
#include"Fuction.h"
#include"fileOperate.h"

#include<iostream>
//主界面
void sale(chartMerchan &ListOfGoods) {
	string id;
	cout << endl;
	printLongDash();
	cout << endl;
	cout << "卖货了！！那就请输入商品编号吧：";
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
		if (ListOfGoods.modifyStatus(id)->getStatus() == 0) {
			cout << endl;
			printShortDash();
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
			cout << "出售失败！！！该商品已售出";
			printShortDash();
			cout << endl;
		}
		else {
			ListOfGoods.modifyStatus(id)->modifyOut();
			cout << endl;
			printShortDash();
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
			cout << "成功售出！！！";
			printShortDash();
			cout << endl;
		}
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

void retrunSale(chartMerchan &ListOfGoods) {
	string id;
	cout << endl;
	printLongDash();
	cout << endl;
	cout << "退货？那就请输入商品编号吧：";
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
		if (ListOfGoods.modifyStatus(id)->getStatus() != 0) {
			cout << endl;
			printShortDash();
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
			cout << "退货失败！！！该商品未售出";
			printShortDash();
			cout << endl;
		}
		else {
			ListOfGoods.modifyStatus(id)->modifyIn();
			cout << endl;
			printShortDash();
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
			cout << "退货成功！！！";
			printShortDash();
			cout << endl;
		}

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

/**
void analyseData(chartMerchan &ListOfGoods) {
	
	int sum= ListOfGoods.selectData();
	cout << "\n\t";
	printLongerDash();
	cout << "商品总数："<<sum;
	printLongerDash();
	cout << "\n\n";
	
	const string MERCLASS[4] = { "食品","化妆品","日用品","饮料" };
}
*/

void analyseData(chartMerchan &ListOfGoods) {
		
	int sum = ListOfGoods.selectData();

	cout << "\n";
	printLongDash();
	printShortDash();
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE);
	cout << "\t\t\t商品总数：" <<sum<< "\t\t\t";
	printShortDash();
	cout << endl;
	printLongDash();
	cout << "\n\n";

	//printLongerDash();
	//printLongerDash();
	//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_RED);
	//cout << "食品类" << "\t\t\t";
	//printLongerDash();
	//printLongerDash();
	//printShortDash();
	//cout << "\n\n";

	printHeaderLine();

//ListOfGoods.makeListByClass(1);
	
	//if (p1!= NULL) {
	//	if (p1->next != NULL) {
	//		p1 = p1->next;
	//		while (p1) {

	//			p1->displayLine();
	//			p1 = p1->next;
	//		};
	//	}
	//}

		
	


	//printLongerDash();
	//printLongerDash();
	//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_RED);
	//cout << "化妆品" ;
	//printLongerDash();
	//printLongerDash();
	//printShortDash();
	//cout << "\n\n";

	//printHeaderLine();

 Merchandise *p2=ListOfGoods.makeListByClass(2);
	if (p2 != NULL) {
		if (p2->next!=NULL) {
			p2 = p2->next;
			while (p2) {

				p2->displayLine();
				p2 = p2->next;
			};
		}
	}

	cout << endl;
	printDividerStarPurple();


	//printLongerDash();
	//printLongerDash();
	//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_RED);
	//cout << "日用品类" ;
	//printLongerDash();
	//printLongerDash();
	//printShortDash();
	//cout << "\n\n";

	//printHeaderLine();

	//ListOfGoods.makeListByClass(3);
	/*if (p3 != NULL) {
		if (p3->next!=NULL) {
			p3 = p3->next;
			while (p3) {

				p3->displayLine();
				p3 = p3->next;
			};
		}
	}
*/
//
//	printLongerDash();
//	printLongerDash();
//	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_RED);
//	cout << "饮料类" ;
//	printLongerDash();
//	printLongerDash();
//		printShortDash();
//	cout << "\n\n";
//
//	printHeaderLine();
//
//ListOfGoods.makeListByClass(4);
	//if (p4->next!=NULL ) {
	//	p4 = p4->next;
	//	while (p4) {
	//		
	//		p4->displayLine();
	//		p4 = p4->next;
	//	};
	//}
	//Merchandise *p8 = ListOfGoods.makeListByClass(4);
	//delete p8;

}

void exitSystem() {
	cout << endl;
	cout << endl;
	writeFile();
	printShortStar();
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
	cout << "您已成功退出系统，欢迎下次使用！";
	printSystemTime();
	printShortStar();
	cout << endl;
	exit(0);
}

//子界面


void selectAdd(chartMerchan &ListOfGoods) {
	Merchandise *p = new Merchandise;
	if (p != NULL) {
		p->initGood(ListOfGoods);
	}
	ListOfGoods.insertData(p);
	cout << endl;
	printDividerStar();
	printBlank();
	printShortDash();
	cout << "创建成功！信息如下:";
	printShortDash();
	cout << endl;
	p->display();
	
	manageFunction();
}




void selectDelete() {
		string id;
		cout << endl;
		printLongDash();
		cout << endl;
		cout << "想删除？那就请输入商品编号吧：";
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
			manageFunction();
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


void returnLast() {
	cout << endl;
	cout << endl;

	printShortStar();
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
	cout << "您已离开商品管理，成功返回主界面！";
	printShortStar();
	cout << endl;

	switchFunction();

}



void selectModify(Merchandise *backup) {
	cout << endl;
	printLongDash();
	printModifyMenu();
	string mark;
	cout << '\n' << '\n';
	printDividerStar();
	cout << "\t";
	cout << "动动手，选择你想要修改的商品项吧：";
	cin >> mark;


	if (mark.size() > 1) {
		cout << endl;
		cout << endl;
		printShortStar();
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
		cout << "选项不合法！！！请重试";
		printShortStar();

		manageFunction();
	}
	else {
		char i_chooseId = mark[0];
		switch (i_chooseId) {
		case '1': {
			string element;
			bool i = true;
			do {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE);
				cout << "\n\n";
				cout << "*请输入新的商品ID编号:";
				cin >> element;
				
				if (ListOfGoods.checkDataId(element)) {
					cin.sync();
					printShortDash();
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
					cout << "数据库中已经存在此编号，请重新输入商品编号！";
					printShortDash();
				}
				else if (element.size() != 6) {
					printShortDash();
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
					cout << "注意！！！商品编号需6位";
					printShortDash();
				}
				else i = false;
			} while (i);


			backup->modifyId(element);
			printShortDash();
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
			cout << "修改成功！！";
			printShortDash();
			cout << endl;
			selectModify(backup);
			break;		}
		case '2': {
			string element;

			bool i = true;

			do {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE);
				cout << "\n";
				cout << "*请输入新的生产厂家：";
				cin >> element;
				if (element.size() > 0 && element.size() < 100) {
					i = false;
				}
				else {
					printShortDash();
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
					cout << "那个生产厂家名字会这么长！！！请重新输入";
					printShortDash();
				}
			} while (i);

			
			backup->modifyMfr(element);
			printShortDash();
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
			cout << "修改成功！！";
			printShortDash();
			cout << endl;
			selectModify(backup);

			break;		}
		case '3': {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE);
			cout << endl;
			printShortDash();
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
			cout << "当前食品类型为:";
			printShortDash();
			cout << "\n\n";
			unsigned short int element;

			bool i = true;


			do {
				cout << "\n类型：[1]食品\t[2]化妆品\t[3]日用品\t[4]饮料\n";
				printLongDash();
				cout << "\n*请选择新类型：";
				cin >> element;
				if (cin.fail()) {
					printShortDash();
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
					cout << "无效字符串，请重试！！！";
					printShortDash();
					cin.clear();
					cin.ignore(1024, '\n');
				}
				else {
					if (element == 1 || element == 2 || element == 3 || element == 4) {
						if (backup->getClass() != element) {
							i = false;
							backup->ModifyMERSTOCKS(true, backup->getClass());
							backup->modifyClass(element);
							backup->ModifyMERSTOCKS(false, backup->getClass());
							printShortDash();
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
							cout << "修改成功！！";
							printShortDash();
							cout << endl;
						}
						else {
							printShortDash();
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
							cout << "当前此商品已是此类型！！！";
							printShortDash();
							cout << endl;
						}
					}else {
						printShortDash();
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
						cout << "选项不存在！！！无此类商品!请重试";
						printShortDash();
					}
				}
			} while (i);
			selectModify(backup);
			break;	
		}
		case '4': {
			
			string element;

			bool i = true;

			do {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE);
				cout << "\n\n";
				cout << "*请输入新的商品名称：";
				cin >> element;
				if (element.size() > 0 && element.size() < 20) {
					i = false;
				}
				else {
					printShortDash();
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
					cout << "商品名过长不合法！！！请重试";
					printShortDash();
				}
			} while (i);

			backup->modifyName(element); 
			printShortDash();
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
			cout << "修改成功！！";
			printShortDash();
			cout << endl;
			selectModify(backup);
			break;	}
		case '5': {
			
			double element;
			bool i = true;

			do {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE);
				cout << "\n\n";
				cout << "*请输入定义新价格:";
				cin >> element;
				if (cin.fail()) {
					printShortDash();
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
					cout << "您输入的不是数字！！！请重新输入";
					printShortDash();
					cin.clear();
					cin.ignore(1024, '\n');
				}
				else if (element < 0 || element>100000) {
					printShortDash();
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
					cout << "您输入的价钱不符合常理！！！请重试";
					printShortDash();
				}
				else i = false;

			} while (i);

			backup->modifyPrice(element); 
			printShortDash();
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
			cout << "修改成功！！";
			printShortDash();
			cout << endl;
			selectModify(backup);
			break; }
		case '6': {
			
			string element;

			bool i = true;

			do {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE);
				cout << "\n\n";
				cout << "*请输入新的商品品牌：";
				cin >> element;
				if (element.size() > 0 && element.size() < 20) {
					i = false;
				}
				else {
					printShortDash();
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
					cout << "有这么长的品牌吗？？？请重新输入";
					printShortDash();
				}
			} while (i);

			backup->modifyBrand(element);
			printShortDash();
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
			cout << "修改成功！！";
			printShortDash();
			cout << endl;
			selectModify(backup);
			break; }
		case '0':returnChildLast(); break;		
		default:
			cout << endl;
			cout << endl;
			printShortStar();
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
			cout << "!!!未找到您的选项呢,要不再试试?";
			printShortStar();
			manageFunction();
		}
	}
}








//选择界面

void SelectByName(chartMerchan &ListOfGoods) {
	string name;
	cout << endl;
	printLongDash();
	cout << endl;
	cout << "\n请输入商品名称：";
	cin >> name;
	while (name.size() < 0 || name.size() > 20) {		
				printShortDash();
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
				cout << "商品名过长不合法！！！请重试";
				printShortDash();
				cout << "\n请输入商品名称：";
				cin >> name;
	};
	ListOfGoods.selectByName(name);
	selectFunction();
}
void SelectByMfr(chartMerchan &ListOfGoods) {
	string mfr;
	cout << endl;
	printLongDash();
	cout << endl;
	cout << "\n请输入生产厂家：";
	cin >> mfr;
	while (mfr.size() < 0 || mfr.size() > 50) {
		cout << endl;
		printShortDash();
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
		cout << "生产厂家名称过长！！！请重新输入";
		printShortDash();
		cout << endl;
		cout << "\n请输入生产厂家：";
		cin >> mfr;

	};
	ListOfGoods.selectByMfr(mfr);
	selectFunction();
}
void SelectByClass(chartMerchan &ListOfGoods) {
	int kindOf;
	cout << endl;
	printLongDash();
	cout << endl;

	cout << "\n\n类型：[1]食品\t[2]化妆品\t[3]日用品\t[4]饮料\n";
	printLongDash();
	cout << "\n请选择：";
	cin >> kindOf;
	while (true) {
		if (cin.fail() || (kindOf != 1 && kindOf != 2 && kindOf != 3 && kindOf != 4)) {
			printShortDash();
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
			cout << "无此选项，请重试！！！";
			printShortDash();
			cin.clear();
			cin.ignore(1024, '\n');
		}else if(kindOf == 1 || kindOf == 2 || kindOf == 3 || kindOf == 4) {
			ListOfGoods.selectByClass(kindOf,true);
			break;
		}

		cout << "\n请选择：";
		cin >> kindOf;
	};
		selectFunction();

}


void returnChildLast() {
	cout << endl;
	cout << endl;

	printShortStar();
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
	cout << "\t您已离开查询系统，成功返回商品管理界面！\t";
	printShortStar();
	cout << endl;

	manageFunction();

}


void manageFunction() {
	printChildMenu();


	string chooseId;
	cout << '\n' << '\n';
	printDividerStar();
	printDividerStar();
	cout << "\t";
	cout << "您想做些什么呢？动动手，做个简单的选择吧:";
	cin >> chooseId;


	if (chooseId.size() > 1) {
		cout << endl;
		cout << endl;
		printShortStar();
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
		cout << "选项不合法！！！请重试";
		printShortStar();

		manageFunction();
	}
	else {
		char i_chooseId = chooseId[0];
		switch (i_chooseId) {
		case '1':selectAdd(ListOfGoods); break;		//添加
		case '2':selectFunction(); break;		//条件查询
		case '3':modifyFunction(ListOfGoods); break;		//修改
		case '4':selectDelete(); break;		//删除
		case '0':returnLast(); break;		//返回上一层
		default:
			cout << endl;
			cout << endl;
			printShortStar();
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
			cout << "!!!未找到您的选项呢,要不再试试?";
			printShortStar();
			manageFunction();
		}
	}
}











