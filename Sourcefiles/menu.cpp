#pragma once

/**************************

*��������

****************************/
#include"main.h"
#include"Fuction.h"
#include"goodsClass.h"

#define TITLE "��Ʒ����"
#pragma warning(disable:4996)

void systemStart() {
	SetConsoleTitle(TITLE);
	printDividerStar();
	cout << "*****\t\t\t\t\t\t\t*****";
	cout << '\n';
	printShortStar();
	cout << "\t\t";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
	cout << "��ӭ������Ʒ��̨����ϵͳ";
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
	cout << "���ǹ���Ա���Ǿ����¼��......";
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
	cout << "��ǰϵͳʱ�䣺"
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
	cout << "���������룺";
	cin >> password;
	if (isLogin(password)) {
		cout << endl;
		printShortStar();
		cout << "��¼�ɹ���";
		printSystemTime();
		
		printShortStar();
		cout << "\n\n";
		printDividerStar();

	}
	else{
		cout << endl;
		printShortStar();
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED);
		cout << "��¼ʧ�ܣ�";
		cout << "û��ϵ������һ�ΰɣ�";
		printShortStar();
		cout << endl;

		Sleep(1000);
		
		cout << endl;
		cout << "���������룺";
		cin >> password;
		if (isLogin(password)) {
			cout << endl;
			printShortStar();
			cout << "��¼�ɹ���";
			printSystemTime();
			printShortStar();
			cout << endl;
		}
		else {
			cout << endl;
			printShortStar();
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
			cout << "��¼ʧ�ܣ�";
			cout << "��һ�����ǹ���Ա���ټ���";
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
	cout << "\t�����ڴ�����Ʒ������棡\t";
	printLongStar();
	cout << endl;


	cout << endl;	   
	printShortWhiteStar();  
	cout << "\t\t[1] �����Ʒ\t\t";
	printShortWhiteStar();

	cout << endl;
	printShortWhiteStar();
	cout << "\t\t[2] ��Ʒ��ѯ\t\t";
	printShortWhiteStar();

	cout << endl;
	printShortWhiteStar();
	cout << "\t\t[3] �޸���Ʒ��Ϣ\t";
	printShortWhiteStar();

	cout << endl;
	printShortWhiteStar();
	cout << "\t\t[4] ɾ����Ʒ\t\t";
	printShortWhiteStar();


	cout << endl;
	printShortWhiteStar();
	cout << "\t\t[0] ������һ��\t\t";
	printShortWhiteStar();

}

void printMainMenu() {

	cout << endl;
	printShortWhiteStar();
	cout << "\t\t[1] ��Ʒ����\t\t";
	printShortWhiteStar();

	cout << endl;
	printShortWhiteStar();
	cout << "\t\t[2] �˻�\t\t";
	printShortWhiteStar();

	cout << endl;
	printShortWhiteStar();
	cout << "\t\t[3] ��Ʒͳ��\t\t";
	printShortWhiteStar();

	cout << endl;
	printShortWhiteStar();
	cout << "\t\t[4] ��Ʒ����ϵͳ\t";
	printShortWhiteStar();

	cout << endl;
	printShortWhiteStar();
	cout << "\t\t[0] �뿪\t\t";
	printShortWhiteStar();

}

void printModifyMenu() {


	cout << endl;
	printShortWhiteStar();
	cout << "\t\t[1] ��Ʒ���\t\t";
	printShortWhiteStar();

	cout << endl;
	printShortWhiteStar();
	cout << "\t\t[2] ��������\t\t";
	printShortWhiteStar();

	cout << endl;
	printShortWhiteStar();
	cout << "\t\t[3] ��Ʒ����\t\t";
	printShortWhiteStar();

	cout << endl;
	printShortWhiteStar();
	cout << "\t\t[4] ��Ʒ��\t\t";
	printShortWhiteStar();

	cout << endl;
	printShortWhiteStar();
	cout << "\t\t[5] �۸�\t\t";
	printShortWhiteStar();
		
	cout << endl;			
	printShortWhiteStar();	
	cout << "\t\t[6] ��ƷƷ��\t\t";
	printShortWhiteStar();



	cout << endl;
	printShortWhiteStar();
	cout << "\t\t[0] ������һ��\t\t";
	printShortWhiteStar();
}

void printSelectMenu() {
	cout << endl;
	cout << endl;
	printLongStar();
	cout << "�������ڷ�����ҽ��棡�����������������²������ݣ���";
	printLongStar();
	cout << endl;


	cout << endl;
	printShortWhiteStar();
	cout << "\t\t[1] ��Ʒ����\t\t";
	printShortWhiteStar();

	cout << endl;
	printShortWhiteStar();
	cout << "\t\t[2] ��������\t\t";
	printShortWhiteStar();

	cout << endl;
	printShortWhiteStar();
	cout << "\t\t[3] ��Ʒ���\t\t";
	printShortWhiteStar();

	cout << endl;
	printShortWhiteStar();
	cout << "\t\t[0] ������һ��\t\t";
	printShortWhiteStar();

}

void selectFunction() {
	printSelectMenu();
	string chooseId;
	cout << '\n' << '\n';
	printDividerStar();
	printDividerStar();
	cout << '\t';
	cout << "��������������أ������򵥵�ѡ���:";
	cin >> chooseId;


	if (chooseId.size() > 1) {
		cout << endl;
		cout << endl;
		printShortStar();
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
		cout << "ѡ��Ϸ�������������";
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
			cout << "!!!δ�ҵ�����ѡ����,Ҫ��������?";
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
	cout << "������Щʲô�أ������֣������򵥵�ѡ���:";
	cin >> chooseId;
	
	
	if (chooseId.size() > 1) {
		cout << endl;
		cout << endl;
		printShortStar();
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
		cout << "ѡ��Ϸ�������������";
		printShortStar();
		cout << endl;
		
		switchFunction();
	}
	else {
		char i_chooseId = chooseId[0];
		switch (i_chooseId) {
		case '1':sale(ListOfGoods); break;		//���۹���
		case '2':retrunSale(ListOfGoods); break;		//�˻�����
		case '3':analyseData(ListOfGoods); break;		//ͳ�ƹ���
		case '4':manageFunction(); break;		//��Ʒ������
		case '0':exitSystem(); break;		//�˳�ϵͳ
		default:
			cout << endl;
			cout << endl;
			printShortStar();
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
			cout << "!!!δ�ҵ�����ѡ����,Ҫ��������?";
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
	cout << "׼����Ҫ�޸���Ʒ����Ϣ�����Ǿ���������Ʒ��Űɣ�";
	cin >> id;
	while (id.size() != 6) {
		cout << endl;
		printShortDash();
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
		cout << "ע�⣡������Ʒ�����6λ";
		printShortDash();
		cout << endl;
		cout << "���ٴ�������Ʒ�ţ�";
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
		cout << "���ݿ��������Ʒ�����Ϣ";
		printShortDash();
		cout << "\n\n";
		manageFunction();
	}
}




void printHeaderLine() {
	cout << "*��Ʒ���*"
		<< "\t*��Ʒ��*"
		<< "\t*�۸�*"
		<< "\t\t*��������*"
		<< "\t*Ʒ��*\t" 
		<<"\t*״̬*"<< "\n\n";
}















/**
void modifyFunction(chartMerchan &ListOfGoods) {
	string id;
	cout << endl;
	printLongDash();
	cout << endl;
	cout << "��������Ҫ�޸ĵ���Ʒ��ID��Ʒ�ţ�";
	cin >> id;
	while (id.size() != 6) {
		cout << endl;
		printShortDash();
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
		cout << "ע�⣡������Ʒ�����6λ";
		printShortDash();
		cout << endl;
		cout << "���ٴ�������Ʒ�ţ�";
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
		cout << "���ݿ��������Ʒ�����Ϣ";
		printShortDash();
		cout << "\n\n";
		manageFunction();
	}
}
*/



