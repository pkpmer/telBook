#include<iostream>
#include<string>
#include<fstream>
#define max 100
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
//联系人结构体
struct person {
	string name;
	int gender;//1--男，2--女
	int age;
	string tel;
	string addr;
};
//通讯录结构体
struct telBook {
	struct person perArray[max];//联系人数组
	int size;
};
//读取txt文件到结构体数组中
void getItIn(telBook* tB) {
	ifstream infile("D:\\GitHub\\telBook\\通讯录系统\\通讯库.txt");
	string name;
	int gender;
	int age;
	string tel;
	string addr;
	tB->size = 0;
	while (infile >> name) {
		infile >> gender >> age >> tel >> addr;
		tB->perArray[tB->size].name = name;
		tB->perArray[tB->size].gender = gender;
		tB->perArray[tB->size].age = age;
		tB->perArray[tB->size].tel = tel;
		tB->perArray[tB->size].addr = addr;
		(tB->size)++;//暂时假设数组大小不会超过1000，所以没有做检验
	}
	infile.close();
}
//读取结构体数组到txt文件中
void getItOut(telBook* tB) {
	ifstream inFile("D:\\GitHub\\telBook\\通讯录系统\\通讯库.txt");
	if (!inFile)//判断文件是否打开
		cerr << "无法打开文件！" << endl;
	ofstream outFile("D:\\GitHub\\telBook\\通讯录系统\\通讯库.txt", ios_base::app);
	char checkEmpty;
	inFile >> checkEmpty;
	if (inFile.eof()) {
		if (!outFile)//判断文件是否打开
			cerr << "之前操作无法写入库内！";
		else {
			outFile << tB->perArray[tB->size].name << "\t"
				<< tB->perArray[tB->size].gender << "\t"
				<< tB->perArray[tB->size].age << "\t"
				<< tB->perArray[tB->size].tel << "\t"
				<< tB->perArray[tB->size].addr;
			outFile.close();
		}
	}
	else {
		if (!outFile)//判断文件是否打开
			cerr << "之前操作无法写入库内！";
		else {
			outFile << endl << tB->perArray[tB->size].name << "\t"
				<< tB->perArray[tB->size].gender << "\t"
				<< tB->perArray[tB->size].age << "\t"
				<< tB->perArray[tB->size].tel << "\t"
				<< tB->perArray[tB->size].addr;
			outFile.close();
		}
	}
}
//1.添加联系人
void addPerson(telBook* tB){
	//判断通讯录是否已满
	if (tB->size == max) { //"->"是指针的指向运算符，常与数据体联用，表示取值
		cout << "通讯录已满!";
		return;
	}
	else {
		//添加姓名
		string name;
		cout << "*请输入名字:" << endl;
		cin >> name;
		tB->perArray[tB->size].name = name;
		//添加性别
		int gender = 3;
		cout << '\n' << "*请输入性别:" << endl
			<< "1--男，2--女 " << endl;
		cin >> gender;
		tB->perArray[tB->size].gender = gender;
		//添加年龄
		int age = 0;
		cout << '\n' << "*请输入年龄(如果未知可填“0”):" << endl;//建议修改为捕捉回车键
		if (cin >> age)
			tB->perArray[tB->size].age = age;
		//添加电话
		string tel;
		cout << '\n' << "*请输入电话:" << endl;
		cin >> tel;
		tB->perArray[tB->size].tel = tel;
		//添加住址
		string addr;
		cout << '\n' << "*请输入住址:" << endl;
		cin >> addr;
		tB->perArray[tB->size].addr = addr;
		ifstream inFile("D:\\GitHub\\telBook\\通讯录系统\\通讯库.txt");
		if (!inFile)//判断文件是否打开
			cerr << "无法打开文件！" << endl;
		ofstream outFile("D:\\GitHub\\telBook\\通讯录系统\\通讯库.txt", ios_base::app);
		char checkEmpty;
		inFile >> checkEmpty;
		if (inFile.eof()) {
			if (!outFile)//判断文件是否打开
				cerr << "之前操作无法写入库内！";
			else {
				outFile << tB->perArray[tB->size].name << "\t"
					<< tB->perArray[tB->size].gender << "\t"
					<< tB->perArray[tB->size].age << "\t"
					<< tB->perArray[tB->size].tel << "\t"
					<< tB->perArray[tB->size].addr;
				outFile.close();
			}
		}
		else {
			if (!outFile)//判断文件是否打开
				cerr << "之前操作无法写入库内！";
			else {
				outFile << endl << tB->perArray[tB->size].name << "\t"
					<< tB->perArray[tB->size].gender << "\t"
					<< tB->perArray[tB->size].age << "\t"
					<< tB->perArray[tB->size].tel << "\t"
					<< tB->perArray[tB->size].addr;
				outFile.close();
			}
		}
		tB->size++;
		cout << "-------- 输入完成 --------" << endl;
	}
	system("pause");
	system("cls");//清除屏幕
}
//2.显示所有联系人
void showAll() {//应该也可以使用传值的方式，因为只是起到了一个显示的作用
	telBook tB;
	getItIn(&tB);
	for (int i = 0; i < tB.size; i++) {
		cout << tB.perArray[i].name << "\t"
			<< tB.perArray[i].gender << "\t"
			<< tB.perArray[i].age << "\t"
			<< tB.perArray[i].tel << "\t"
			<< tB.perArray[i].addr << "\t"
			<< endl << endl;
	}
	cout << "---------- 以上 ----------" << endl;
	system("pause");
	system("cls");
}
//主函数
int main() {
	showMenu();
	telBook tB; //创建结构体变量，可以认为telBook和int、double一个意思，只过是自己定义的
	tB.size = 0;
	int slct = 0;//输入的数字
	cin >> slct;
	bool flag = true;
	while (flag) {
		switch (slct) {
		case 1:// 1.添加联系人
			addPerson(&tB);
			break;
		case 2:// 2.显示联系人
			showAll();
			break;
		case 3:// 3.删除联系人
			break;
		case 4:// 4.查找联系人
			break;
		case 5:// 5.修改联系人
			break;
		case 6:// 6.清空联系人
			break;
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