#pragma once

/**************************

*函数定义

****************************/
#include"main.h"
#include"Fuction.h"
#include"goodsClass.h"

#define TITLE "商品管理"
#pragma warning(disable:4996)

void systemStart() {
	SetConsoleTitle(TITLE);
	printDividerStar();
	cout << "*****\t\t\t\t\t\t\t*****";
	cout << '\n';
	printShortStar();
	cout << "\t\t";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
	cout << "欢迎来到商品后台管理系统";
	cout << "\t\t";
	printShortStar();
	cout << "\n";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);
	cout << "*****\t\t\t\t\t\t\t*****";
	cout << "\n";
	printDividerStar();
	Sleep(2000);
	
	cout << endl;
	printShortStar();
	cout << "你是管理员吗？那就请登录吧......";
	printShortStar();
	cout << endl;
	Sleep(1000);
	

	administratorLigin();


}
void printDividerStar() {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),  FOREGROUND_GREEN);
	cout << "*************************************************************"<<endl;
}

void printDividerStarPurple() {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE| FOREGROUND_RED);
	cout << "**************************************************************************************";
	cout << endl;
	cout << endl;
}
void printShortStar() {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_RED);
	cout << "*****";
}

void printShortWhiteStar() {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE);
	cout << "*****";
}
void printLongStar() {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_RED);
	
	cout <<"********";
}
void printLongDash() {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE);
	cout << "-------------------------------------------------------------" << endl;
}

void printShortDash() {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE);
	cout << "-----";
}

void printLongerDash() {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE);
	cout << "---------------";
}

void printBlank() {
	cout << "\t\t";
}



void printSystemTime() {
	time_t rawtime;
	struct tm *ptminfo;
	time(&rawtime);
	ptminfo = localtime(&rawtime);
	cout << "当前系统时间："
		<< ptminfo->tm_year + 1900 << "-"
		<< ptminfo->tm_mon + 1 << "-"
		<< ptminfo->tm_mday << " "
		<< ptminfo->tm_hour << ":"
		<< ptminfo->tm_min << ":"
		<< ptminfo->tm_sec;
}

bool isLogin(string password) {
	if (password == PASSWORD)
		return true;
	else return false;
}

void administratorLigin() {
	string password;
	int tryInputPassword=0;
	cout << endl;
	cout << "请输入密码：";
	cin >> password;
	if (isLogin(password)) {
		cout << endl;
		printShortStar();
		cout << "登录成功！";
		printSystemTime();
		
		printShortStar();
		cout << "\n\n";
		printDividerStar();

	}
	else{
		cout << endl;
		printShortStar();
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED);
		cout << "登录失败！";
		cout << "没关系，再试一次吧！";
		printShortStar();
		cout << endl;

		Sleep(1000);
		
		cout << endl;
		cout << "请输入密码：";
		cin >> password;
		if (isLogin(password)) {
			cout << endl;
			printShortStar();
			cout << "登录成功！";
			printSystemTime();
			printShortStar();
			cout << endl;
		}
		else {
			cout << endl;
			printShortStar();
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
			cout << "登录失败！";
			cout << "你一定不是管理员，再见！";
			printShortStar();
			cout << endl;
			exit(0);
		}
	}
}

void printChildMenu() {


	cout << endl;
	cout << endl;
	printLongStar();
	cout << "\t你现在处于商品管理界面！\t";
	printLongStar();
	cout << endl;


	cout << endl;	   
	printShortWhiteStar();  
	cout << "\t\t[1] 添加商品\t\t";
	printShortWhiteStar();

	cout << endl;
	printShortWhiteStar();
	cout << "\t\t[2] 商品查询\t\t";
	printShortWhiteStar();

	cout << endl;
	printShortWhiteStar();
	cout << "\t\t[3] 修改商品信息\t";
	printShortWhiteStar();

	cout << endl;
	printShortWhiteStar();
	cout << "\t\t[4] 删除商品\t\t";
	printShortWhiteStar();


	cout << endl;
	printShortWhiteStar();
	cout << "\t\t[0] 返回上一层\t\t";
	printShortWhiteStar();

}

void printMainMenu() {

	cout << endl;
	printShortWhiteStar();
	cout << "\t\t[1] 商品出售\t\t";
	printShortWhiteStar();

	cout << endl;
	printShortWhiteStar();
	cout << "\t\t[2] 退货\t\t";
	printShortWhiteStar();

	cout << endl;
	printShortWhiteStar();
	cout << "\t\t[3] 商品统计\t\t";
	printShortWhiteStar();

	cout << endl;
	printShortWhiteStar();
	cout << "\t\t[4] 商品管理系统\t";
	printShortWhiteStar();

	cout << endl;
	printShortWhiteStar();
	cout << "\t\t[0] 离开\t\t";
	printShortWhiteStar();

}

void printModifyMenu() {


	cout << endl;
	printShortWhiteStar();
	cout << "\t\t[1] 商品编号\t\t";
	printShortWhiteStar();

	cout << endl;
	printShortWhiteStar();
	cout << "\t\t[2] 生产厂家\t\t";
	printShortWhiteStar();

	cout << endl;
	printShortWhiteStar();
	cout << "\t\t[3] 商品类型\t\t";
	printShortWhiteStar();

	cout << endl;
	printShortWhiteStar();
	cout << "\t\t[4] 商品名\t\t";
	printShortWhiteStar();

	cout << endl;
	printShortWhiteStar();
	cout << "\t\t[5] 价格\t\t";
	printShortWhiteStar();
		
	cout << endl;			
	printShortWhiteStar();	
	cout << "\t\t[6] 商品品牌\t\t";
	printShortWhiteStar();



	cout << endl;
	printShortWhiteStar();
	cout << "\t\t[0] 返回上一层\t\t";
	printShortWhiteStar();
}

void printSelectMenu() {
	cout << endl;
	cout << endl;
	printLongStar();
	cout << "您正处于分类查找界面！正如你所见，有以下查找依据！！";
	printLongStar();
	cout << endl;


	cout << endl;
	printShortWhiteStar();
	cout << "\t\t[1] 商品名称\t\t";
	printShortWhiteStar();

	cout << endl;
	printShortWhiteStar();
	cout << "\t\t[2] 生产厂家\t\t";
	printShortWhiteStar();

	cout << endl;
	printShortWhiteStar();
	cout << "\t\t[3] 商品类别\t\t";
	printShortWhiteStar();

	cout << endl;
	printShortWhiteStar();
	cout << "\t\t[0] 返回上一层\t\t";
	printShortWhiteStar();

}

void selectFunction() {
	printSelectMenu();
	string chooseId;
	cout << '\n' << '\n';
	printDividerStar();
	printDividerStar();
	cout << '\t';
	cout << "你打算怎样查找呢？做个简单的选择吧:";
	cin >> chooseId;


	if (chooseId.size() > 1) {
		cout << endl;
		cout << endl;
		printShortStar();
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
		cout << "选项不合法！！！请重试";
		printShortStar();
		cout << endl;
		selectFunction();
	}
	else {
		char i_chooseId = chooseId[0];
		switch (i_chooseId) {
		case '1':SelectByName(ListOfGoods); break;
		case '2':SelectByMfr(ListOfGoods); break;
		case '3':SelectByClass(ListOfGoods); break;
		case '0':returnChildLast(); break;
		default:
			cout << endl;
			cout << endl;
			printShortStar();
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
			cout << "!!!未找到您的选项呢,要不再试试?";
			printShortStar();
			cout << endl;
			selectFunction();
		}
	}
}

void switchFunction() {
	
	printMainMenu();
	string chooseId;
	cout << '\n' << '\n';
	printDividerStar();
	printDividerStar();
	cout << '\t';
	cout << "您想做些什么呢？动动手，做个简单的选择吧:";
	cin >> chooseId;
	
	
	if (chooseId.size() > 1) {
		cout << endl;
		cout << endl;
		printShortStar();
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
		cout << "选项不合法！！！请重试";
		printShortStar();
		cout << endl;
		
		switchFunction();
	}
	else {
		char i_chooseId = chooseId[0];
		switch (i_chooseId) {
		case '1':sale(ListOfGoods); break;		//销售功能
		case '2':retrunSale(ListOfGoods); break;		//退货功能
		case '3':analyseData(ListOfGoods); break;		//统计功能
		case '4':manageFunction(); break;		//商品管理功能
		case '0':exitSystem(); break;		//退出系统
		default:
			cout << endl;
			cout << endl;
			printShortStar();
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
			cout << "!!!未找到您的选项呢,要不再试试?";
			printShortStar();
			cout << endl;
		}
	}
	}

void modifyFunction(chartMerchan &ListOfGoods) {
	string id;
	cout << endl;
	printLongDash();
	cout << endl;
	cout << "准备好要修改商品的信息了吗？那就请输入商品编号吧：";
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
		selectModify(ListOfGoods.modifyStatus(id));
	}
	else {
		cout << endl;
		printShortDash();
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
		cout << "数据库无与此商品相关信息";
		printShortDash();
		cout << "\n\n";
		manageFunction();
	}
}




void printHeaderLine() {
	cout << "*商品编号*"
		<< "\t*商品名*"
		<< "\t*价格*"
		<< "\t\t*生产厂商*"
		<< "\t*品牌*\t" 
		<<"\t*状态*"<< "\n\n";
}















/**
void modifyFunction(chartMerchan &ListOfGoods) {
	string id;
	cout << endl;
	printLongDash();
	cout << endl;
	cout << "请输入您要修改的商品的ID商品号：";
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
		ListOfGoods.modifyStatus(id)->display();
		selectModify(ListOfGoods.modifyStatus(id));
	}else{
		cout << endl;
		printShortDash();
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
		cout << "数据库无与此商品相关信息";
		printShortDash();
		cout << "\n\n";
		manageFunction();
	}
}
*/



