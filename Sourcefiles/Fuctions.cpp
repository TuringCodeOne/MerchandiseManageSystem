#pragma once

#include"main.h"
#include"Fuction.h"

#include<iostream>
//������
void sale(chartMerchan &ListOfGoods) {
	string id;
	cout << endl;
	printLongDash();
	cout << endl;
	cout << "�����ˣ����Ǿ���������Ʒ��Űɣ�";
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
		if (ListOfGoods.modifyStatus(id)->getStatus() == 0) {
			cout << endl;
			printShortDash();
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
			cout << "����ʧ�ܣ���������Ʒ���۳�";
			printShortDash();
			cout << endl;
		}
		else {
			ListOfGoods.modifyStatus(id)->modifyOut();
			cout << endl;
			printShortDash();
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
			cout << "�ɹ��۳�������";
			printShortDash();
			cout << endl;
		}
	}
	else {
		cout << endl;
		printShortDash();
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
		cout << "���ݿ��������Ʒ�����Ϣ";
		printShortDash();
		cout << "\n\n";

	}
}

void retrunSale(chartMerchan &ListOfGoods) {
	string id;
	cout << endl;
	printLongDash();
	cout << endl;
	cout << "�˻����Ǿ���������Ʒ��Űɣ�";
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
		if (ListOfGoods.modifyStatus(id)->getStatus() != 0) {
			cout << endl;
			printShortDash();
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
			cout << "�˻�ʧ�ܣ���������Ʒδ�۳�";
			printShortDash();
			cout << endl;
		}
		else {
			ListOfGoods.modifyStatus(id)->modifyIn();
			cout << endl;
			printShortDash();
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
			cout << "�˻��ɹ�������";
			printShortDash();
			cout << endl;
		}

	}
	else {
		cout << endl;
		printShortDash();
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
		cout << "���ݿ��������Ʒ�����Ϣ";
		printShortDash();
		cout << "\n\n";
	}
}

void analyseData(chartMerchan &ListOfGoods) {
	
	int sum= ListOfGoods.selectData();
	cout << "\n\t";
	printLongerDash();
	cout << "��Ʒ������"<<sum;
	printLongerDash();
	cout << "\n\n";
	

}

void exitSystem() {
	cout << endl;
	cout << endl;

	printShortStar();
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
	cout << "���ѳɹ��˳�ϵͳ����ӭ�´�ʹ�ã�";
	printSystemTime();
	printShortStar();
	cout << endl;
	exit(0);
}

//�ӽ���


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
	cout << "�����ɹ�����Ϣ����:";
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
		cout << "��ɾ�����Ǿ���������Ʒ��Űɣ�";
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
			Merchandise *ptr = ListOfGoods.modifyStatus(id);
			ListOfGoods.front->next = ptr->next;
			delete ptr;
			cout << endl;
			printShortDash();
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
			cout << "ɾ���ɹ�������";
			printShortDash();
			cout << endl;
		}
		else {
			cout << endl;
			printShortDash();
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
			cout << "���ݿ��������Ʒ�����Ϣ";
			printShortDash();
			cout << "\n\n";
		}
	}


void returnLast() {
	cout << endl;
	cout << endl;

	printShortStar();
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
	cout << "�����뿪��Ʒ�����ɹ����������棡";
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
	cout << "�����֣�ѡ������Ҫ�޸ĵ���Ʒ��ɣ�";
	cin >> mark;


	if (mark.size() > 1) {
		cout << endl;
		cout << endl;
		printShortStar();
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
		cout << "ѡ��Ϸ�������������";
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
				cout << "*�������µ���ƷID���:";
				cin >> element;
				
				if (ListOfGoods.checkDataId(element)) {
					cin.sync();
					printShortDash();
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
					cout << "���ݿ����Ѿ����ڴ˱�ţ�������������Ʒ��ţ�";
					printShortDash();
				}
				else if (element.size() != 6) {
					printShortDash();
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
					cout << "ע�⣡������Ʒ�����6λ";
					printShortDash();
				}
				else i = false;
			} while (i);


			backup->modifyId(element);
			printShortDash();
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
			cout << "�޸ĳɹ�����";
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
				cout << "*�������µ��������ң�";
				cin >> element;
				if (element.size() > 0 && element.size() < 100) {
					i = false;
				}
				else {
					printShortDash();
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
					cout << "�Ǹ������������ֻ���ô������������������";
					printShortDash();
				}
			} while (i);

			
			backup->modifyMfr(element);
			printShortDash();
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
			cout << "�޸ĳɹ�����";
			printShortDash();
			cout << endl;
			selectModify(backup);

			break;		}
		case '3': {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE);
			cout << endl;
			printShortDash();
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
			cout << "��ǰʳƷ����Ϊ:";
			printShortDash();
			cout << "\n\n";
			unsigned short int element;

			bool i = true;


			do {
				cout << "\n���ͣ�[1]ʳƷ\t[2]��ױƷ\t[3]����Ʒ\t[4]����\n";
				printLongDash();
				cout << "\n*��ѡ�������ͣ�";
				cin >> element;
				if (cin.fail()) {
					printShortDash();
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
					cout << "��Ч�ַ����������ԣ�����";
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
							cout << "�޸ĳɹ�����";
							printShortDash();
							cout << endl;
						}
						else {
							printShortDash();
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
							cout << "��ǰ����Ʒ���Ǵ����ͣ�����";
							printShortDash();
							cout << endl;
						}
					}else {
						printShortDash();
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
						cout << "ѡ����ڣ������޴�����Ʒ!������";
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
				cout << "*�������µ���Ʒ���ƣ�";
				cin >> element;
				if (element.size() > 0 && element.size() < 20) {
					i = false;
				}
				else {
					printShortDash();
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
					cout << "��Ʒ���������Ϸ�������������";
					printShortDash();
				}
			} while (i);

			backup->modifyName(element); 
			printShortDash();
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
			cout << "�޸ĳɹ�����";
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
				cout << "*�����붨���¼۸�:";
				cin >> element;
				if (cin.fail()) {
					printShortDash();
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
					cout << "������Ĳ������֣���������������";
					printShortDash();
					cin.clear();
					cin.ignore(1024, '\n');
				}
				else if (element < 0 || element>100000) {
					printShortDash();
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
					cout << "������ļ�Ǯ�����ϳ�������������";
					printShortDash();
				}
				else i = false;

			} while (i);

			backup->modifyPrice(element); 
			printShortDash();
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
			cout << "�޸ĳɹ�����";
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
				cout << "*�������µ���ƷƷ�ƣ�";
				cin >> element;
				if (element.size() > 0 && element.size() < 20) {
					i = false;
				}
				else {
					printShortDash();
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
					cout << "����ô����Ʒ���𣿣�������������";
					printShortDash();
				}
			} while (i);

			backup->modifyBrand(element);
			printShortDash();
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
			cout << "�޸ĳɹ�����";
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
			cout << "!!!δ�ҵ�����ѡ����,Ҫ��������?";
			printShortStar();
			manageFunction();
		}
	}
}








//ѡ�����

void SelectByName(chartMerchan &ListOfGoods) {
	string name;
	cout << endl;
	printLongDash();
	cout << endl;
	cout << "\n��������Ʒ���ƣ�";
	cin >> name;
	while (name.size() < 0 || name.size() > 20) {		
				printShortDash();
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
				cout << "��Ʒ���������Ϸ�������������";
				printShortDash();
				cout << "\n��������Ʒ���ƣ�";
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
	cout << "\n�������������ң�";
	cin >> mfr;
	while (mfr.size() < 0 || mfr.size() > 50) {
		cout << endl;
		printShortDash();
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
		cout << "�����������ƹ�������������������";
		printShortDash();
		cout << endl;
		cout << "\n�������������ң�";
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

	cout << "\n\n���ͣ�[1]ʳƷ\t[2]��ױƷ\t[3]����Ʒ\t[4]����\n";
	printLongDash();
	cout << "\n��ѡ��";
	cin >> kindOf;
	while (true) {
		if (cin.fail() || (kindOf != 1 && kindOf != 2 && kindOf != 3 && kindOf != 4)) {
			printShortDash();
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
			cout << "�޴�ѡ������ԣ�����";
			printShortDash();
			cin.clear();
			cin.ignore(1024, '\n');
		}else if(kindOf == 1 || kindOf == 2 || kindOf == 3 || kindOf == 4) {
			ListOfGoods.selectByClass(kindOf);
			break;
		}

		cout << "\n��ѡ��";
		cin >> kindOf;
	};
		selectFunction();

}


void returnChildLast() {
	cout << endl;
	cout << endl;

	printShortStar();
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
	cout << "\t�����뿪��ѯϵͳ���ɹ�������Ʒ������棡\t";
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
	cout << "������Щʲô�أ������֣������򵥵�ѡ���:";
	cin >> chooseId;


	if (chooseId.size() > 1) {
		cout << endl;
		cout << endl;
		printShortStar();
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
		cout << "ѡ��Ϸ�������������";
		printShortStar();

		manageFunction();
	}
	else {
		char i_chooseId = chooseId[0];
		switch (i_chooseId) {
		case '1':selectAdd(ListOfGoods); break;		//���
		case '2':selectFunction(); break;		//������ѯ
		case '3':modifyFunction(ListOfGoods); break;		//�޸�
		case '4':selectDelete(); break;		//ɾ��
		case '0':returnLast(); break;		//������һ��
		default:
			cout << endl;
			cout << endl;
			printShortStar();
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
			cout << "!!!δ�ҵ�����ѡ����,Ҫ��������?";
			printShortStar();
			manageFunction();
		}
	}
}











