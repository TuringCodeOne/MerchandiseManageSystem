#include"main.h"
#include"goodsClass.h"
#include"fileOperate.h"


#include<iostream>
using namespace std;



chartMerchan ListOfGoods;
int main() {
	readFile();
	systemStart();
	while (true) {
		switchFunction();
	}
	return 0;
}