
#include"fileOperate.h"
#include"main.h"

#include<fstream>
#include<iostream>

using namespace std;


void writeFile() {
	fstream file;
	file.open("info_merchandise.txt",ios::out|ios::trunc);

	if (!file) {
		printShortDash();
		cout << "打开文件失败，请确保文件路径正确！！";
		printShortDash();
		cout << endl;
	}

	Merchandise *ptr = NULL;
	ptr = ListOfGoods.getHeader();
	while (ptr->next!=NULL) {
		
		file << *(ptr->next);
		ptr = ptr->next;
	};
	file.close();
}


void readFile(){
	fstream file;
	file.open("info_merchandise.txt", ios_base::in);

	if (!file) {
		printShortDash();
		cout << "打开文件失败，请确保文件路径正确！！";
		printShortDash();
		cout << endl;
	}

	//Merchandise *ptr = NULL;
	//ptr = ListOfGoods.getHeader();
	Merchandise *backup=new Merchandise;

	while(!file.eof()){

		file >> *backup;
		if (file.fail())
			break;
		ListOfGoods.insertData(backup);
		backup->ModifyMERSTOCKS();
		backup = new Merchandise;

	};
	delete backup;
	file.close();
}