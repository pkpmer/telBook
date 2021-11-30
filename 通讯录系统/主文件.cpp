#include<iostream>
#include<string>
#include<fstream>
#include "getIO.h"
using namespace std;
//显示菜单
void showMenu() {
	cout << "*********菜单界面*********" << endl
		<< "------ 1.添加联系人 ------" << endl
		<< "------ 2.显示联系人 ------" << endl
		<< "------ 3.删除联系人 ------" << endl
		<< "------ 4.查找联系人 ------" << endl
		<< "------ 5.修改联系人 ------" << endl
		<< "------ 6.清空联系人 ------" << endl
		<< "------ 0.退出通讯录 ------" << endl
		<< "**************************" << endl;
}
//1.添加联系人
void addPerson(){
	telBook* tB = NULL;
	tB = new telBook;
	getItIn(tB);
	if (tB->size == 3000) { //"->"是指针的指向运算符，常与数据体联用，表示取值
		cout << "通讯录已满!";
		return;
	}
	else {
		string name, gender, age, tel, addr;
		cout << "*请输入名字:" << endl;cin >> name;
		tB->perArray[tB->size].name = name;
		cout << '\n' << "*请输入性别:" << endl;cin >> gender;
		tB->perArray[tB->size].gender = gender;
		cout << '\n' << "*请输入年龄:" << endl;cin >> age;
		tB->perArray[tB->size].age = age;
		cout << '\n' << "*请输入电话:" << endl;cin >> tel;
		tB->perArray[tB->size].tel = tel;
		cout << '\n' << "*请输入住址:" << endl;cin >> addr;
		tB->perArray[tB->size].addr = addr;
		++tB->size;//不加这个最后一行显示不了
		getItOut(tB);
		cout << "-------- 输入完成 --------" << endl;
	}
	delete tB;
	tB = NULL;
	system("pause");
	system("cls");//清除屏幕
}
//2.显示所有联系人
void showAll() {
	telBook* tB = NULL;//动态分配内存，new；
	//可以认为telBook* tB = new telBook是在telBook* tB后面加了个注释，
	//或者是你的这个指针是指想哪一块儿区域
	tB = new telBook;
	getItIn(tB);
	for (int i = 0; i < tB->size; i++) {
		cout << tB->perArray[i].name << "\t"
			<< tB->perArray[i].gender << "\t"
			<< tB->perArray[i].age << "\t"
			<< tB->perArray[i].tel << "\t"
			<< tB->perArray[i].addr << "\t"
			<< endl << endl;
	}
	cout << "---------- 以上 ----------" << endl;
	delete tB;
	tB = NULL;
	system("pause");
	system("cls");//函数退出后结构体会被直接释放
}
//3.删除联系人
void deleteIndvl(string individual) {
	telBook* tB = NULL;
	tB = new telBook;
	getItIn(tB);
	int i; bool check = false;
	for (i = 0; i < tB->size; i++) {
		if (tB->perArray[i].name == individual) {
			for (int j = i; j < tB->size; j++)
				tB->perArray[j] = tB->perArray[j + 1];
			//tB.perArray[tB.size-1] = "";//清空最后一行
			check = true;
			break;//终止上一级的《循环》，而不是跳出if语句，否则写在这里多余
		}
	}
	if (!check)
		cout << endl << "*联系人不存在" << endl << endl;
	getItOut(tB);//没有在该函数里为tB再分配内存，因为前面已经分配过了
	cout << "-------- 删除完成 --------" << endl;
	delete tB;	tB = NULL;
	system("pause");
	system("cls");
}
//4.查找联系人
void search(string individual) {
	telBook* tB = NULL;
	tB = new telBook;
	getItIn(tB);
	int i; bool check = false;
	for (i = 0; i < tB->size; i++) {
		if (tB->perArray[i].name == individual) {
			cout << endl << tB->perArray[i].name << "\t" << endl
				<< tB->perArray[i].gender << "\t" << endl
				<< tB->perArray[i].age << "\t" << endl
				<< tB->perArray[i].tel << "\t" << endl
				<< tB->perArray[i].addr << endl << endl;
			check = true;//用来判断列表中有无此人
			break;
		}
	}
	if(!check)
		cout << endl << "*查无此人" << endl << endl;
	cout << "-------- 查询完成 --------" << endl;
	delete tB;	tB = NULL;
	system("pause");
	system("cls");
}
//5.修改联系人
void modify(string individual) {
	telBook* tB = NULL; tB = new telBook;
	getItIn(tB);
	string name, gender, age, tel, addr;
	cout << "*请输入名字:" << endl;cin >> name;
	cout << '\n' << "*请输入性别:" << endl; cin >> gender;
	cout << '\n' << "*请输入年龄:" << endl; cin >> age;
	cout << '\n' << "*请输入电话:" << endl; cin >> tel;
	cout << '\n' << "*请输入住址:" << endl; cin >> addr;
	int i; bool check = false;
	for (i = 0; i < tB->size; i++) {
		if (tB->perArray[i].name == individual) {
			tB->perArray[i].name = name;
			tB->perArray[i].gender = gender;
			tB->perArray[i].age = age;
			tB->perArray[i].tel = tel;
			tB->perArray[i].addr = addr;
			check = true;//用来判断列表中有无此人
			break;
		}
	}
	if (!check)
		cout << endl << "*联系人不存在" << endl << endl;
	cout << "-------- 修改完成 --------" << endl;
	getItOut(tB);
	delete tB;	tB = NULL;
	system("pause");
	system("cls");
}
//6.清空联系人
void clearAll() {
	telBook* tB = new telBook;//需要在该函数里为tB分配内存，因为getItOut不会分配
	tB->size = 0;//直接修改结构体大小！！
	getItOut(tB);
	cout << "-------- 清空完成 --------" << endl;
	delete tB; tB = NULL;
	system("pause");
	system("cls");
}
//主函数
int main() {
	showMenu();
	//telBook tB; //创建结构体变量，可以认为telBook和int、double一个意思，只过是自己定义的
	int slct = 0;//输入的数字
	cin >> slct;
	bool flag = true;
	while (flag) {
		switch (slct) {
		case 1: // 1.添加联系人
			addPerson();
			break;
		case 2:// 2.显示联系人
			showAll();
			break;
		case 3: {// 3.删除联系人
			cout << endl << "请输入需要删除的联系人姓名：" << endl;
			string individual;
			cin >> individual;
			deleteIndvl(individual);
			break;
		}
		case 4: {// 4.查找联系人
			cout << endl << "请输入需要查询的联系人姓名：" << endl;
			string individual;
			cin >> individual;
			search(individual);
			break; 
		}
		case 5: {// 5.修改联系人
			cout << endl << "请输入需要修改的联系人姓名：" << endl;
			string individual;
			cin >> individual;
			modify(individual);
			break; 
		}
		case 6: {// 6.清空联系人
			cout << endl << "确认删除[y/n]:";
			char cmd;//字符串必须定义大小
			cin >> cmd;
			if ((cmd == 'y') || (cmd == 'Y'))
				clearAll();
			else {
				system("pause");
				system("cls");
			}
			break;
		}
		case 0:// 0.退出通讯录
			cout << "-------- 系统关闭 --------" << endl;
			flag = false;
			system("pause");
			return 0;
		default:
			cout << "请按提示输入！giao！" << endl;
		}
		showMenu();
		cin >> slct;
	}
}