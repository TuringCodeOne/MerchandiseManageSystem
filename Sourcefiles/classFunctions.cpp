#pragma once

#include"goodsClass.h"
#include"main.h"


//��̬��Ա��ʼ��
int Merchandise::MERSTOCKS[] = { 0,0,0,0 };



void Merchandise::initGood(chartMerchan &ListOfGoods) {


	cout << endl;
	printLongDash();
	printShortDash();
	cout << "\t\t\t*��Ʒ��Ϣ¼��*\t\t\t";
	printShortDash();
	cout << endl;
	printLongDash();

	bool i = true;
	

	do{
		cout << "\n\n���ͣ�[1]ʳƷ\t[2]��ױƷ\t[3]����Ʒ\t[4]����\n";
		printLongDash();
		cout << "\n��ѡ��";
		cin >>merClass;
		if(cin.fail()) {
			printShortDash();
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
			cout << "��Ч�ַ����������ԣ�����";
			printShortDash();
			cin.clear();
			cin.ignore(1024, '\n');
		}
		else {
			if (merClass == 1 || merClass == 2 || merClass == 3 || merClass == 4) {
				i = false;
				MERSTOCKS[merClass - 1]++;//��Ӧ��Ʒ���+1
			}
			else {
				printShortDash();
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
				cout << "ѡ����ڣ������޴�����Ʒ!������";
				printShortDash();
			}
		}
	} while (i);

	i = true;

	do {
		cout << "\n��������Ʒ���ƣ�";
		cin >> merName;
		if (merName.size() > 0 && merName.size() < 20) {
			i = false;
		}
		else {
			printShortDash();
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
			cout << "��Ʒ���������Ϸ�������������";
			printShortDash();
		}
	} while (i);

	i = true;

	do {
		cout << "\n��������Ʒ��ţ�";
		cin >> merId;
		if (ListOfGoods.checkDataId(merId)) {
			cin.sync();
			printShortDash();
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
			cout << "���ݿ����Ѿ����ڴ˱�ţ�������������Ʒ��ţ�";
			printShortDash();
		}
		else if(merId.size() != 6) {
				printShortDash();
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
				cout << "ע�⣡������Ʒ�����6λ";
				printShortDash();
		}else i = false;
	} while (i);

	i = true;

	do {
		cout << "\n��������Ʒ�۸�";
		cin >> merPrice;
		if (cin.fail()) {
			printShortDash();
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
			cout << "������Ĳ������֣���������������";
			printShortDash();
			cin.clear();
			cin.ignore(1024, '\n');
		}
		else if (merPrice < 0 || merPrice>100000) {
			printShortDash();
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
			cout << "������ļ�Ǯ�����ϳ�������������";
			printShortDash();
		}
		else i = false;

	} while (i);

	
	i = true;

	do {
		cout << "\n�������������ң�";
		cin >> merMfr;
		if (merMfr.size() > 0 && merMfr.size() < 100) {
			i = false;
		}
		else {
			printShortDash();
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
			cout << "�Ǹ������������ֻ���ô������������������";
			printShortDash();
		}
	} while (i);

	i = true;

	do {
		cout << "\n��������ƷƷ�ƣ�";
		cin >> merBrand;
		if (merBrand.size() > 0 && merBrand.size() < 20) {
			i = false;
		}
		else {
			printShortDash();
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
			cout << "����ô����Ʒ���𣿣�������������";
			printShortDash();
		}
	} while (i);


	merStatus = 1;
}

void Merchandise::display() {
	cout << "\n\t\t*��Ʒ��:" << merName
		<< "\n\t\t*��Ʒ���:" << MERCLASS[merClass - 1]
		<< "\n\t\t*��Ʒ���:" << merId
		<< "\n\t\t*��Ʒ�۸�:" << merPrice
		<< "\n\t\t*��������:" << merMfr
		<< "\n\t\t*��ƷƷ��:" << merBrand;
	cout << "\n\t\t*״̬:";
	if(merStatus==1){
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);
	cout<< STATUS[merStatus];
	}
	else {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
		cout << STATUS[merStatus];
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE);
	cout<< "\n\t\t*���:"<<MERSTOCKS[merClass-1];
}





string Merchandise::getMerId() {
	return merId;
}

string Merchandise::getMerClass() {
	return MERCLASS[merClass - 1];
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
	cout << "���޸���Ϣ���Ǿ���������Ʒ��Űɣ�";
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

void Merchandise::ModifyMERSTOCKS(bool element,unsigned short int merclass) {
	if (element) {
		MERSTOCKS[merclass - 1]--;
	}
	if (!element) {
		MERSTOCKS[merclass - 1]++;
	}
}











//��
chartMerchan::chartMerchan() {
	header = new Merchandise;
	move= header;
	front = header;
	move->next = NULL;
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
	printLongerDash();
	cout << "��ѯ���";
	printLongerDash();
	cout <<"\n\n";
	while (p) {
		cout << endl;
		printBlank();
		printLongerDash();
		p->display();
		p = p->next;
		sum++;
		cout << "\n\t\t";
		printLongerDash();
		cout << endl;
	}
	return sum;
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

void chartMerchan::selectByClass(int merclass) {
	bool comby=true;
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
		}
		p = p->next;
	};
	if(comby){
		cout << endl;
		printShortDash();
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
		cout << "�����û�д�����Ʒ������";
		printShortDash();
		cout << "\n\n";
	}
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
		cout << "�����û�д��������ҵ���Ʒ������";
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
		cout << "�����û�д����Ƶ���Ʒ������";
		printShortDash();
		cout << "\n\n";
	}
}

