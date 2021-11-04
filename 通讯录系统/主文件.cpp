#include<iostream>
#include<string>
#include<fstream>
#define max 1000
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
	int gender = 3;//1--男，2--女，3--未知性别
	int age = 0;//0代表未知年龄
	string tel;
	string addr;
};
//通讯录结构体
struct telBook {
	struct person perArray[max];//联系人数组
	int size;
};
//添加联系人
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
		//tB->size++;//需要放在最后
		//添加性别
		int gender = 3;
		cout << '\n' << "*请输入性别:" << endl
			<< "1--男，2--女，3--未知性别 " << endl;
		cin >> gender;
		tB->perArray[tB->size].gender = gender;
		//添加年龄
		int age = 0;
		cout << '\n' << "*请输入年龄(如果未知可填“0”):" << endl;//建议修改为捕捉回车键
		if (cin >> age)
			tB->perArray[tB->size].age = age;
		else
			tB->perArray[tB->size].age = 0;
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
		//以追加方式打开文件
		ofstream outFile("D:\\GitHub\\telBook\\通讯录系统\\通讯库.txt", ios_base::app);
		if (!outFile)//判断文件是否打开
			cerr << "之前操作无法写入库内！";
		else
			outFile << endl
			<< tB->perArray[tB->size].name << "  "
			<< tB->perArray[tB->size].gender << "  "
			<< tB->perArray[tB->size].age << "  "
			<< tB->perArray[tB->size].tel << "  "
			<< tB->perArray[tB->size].addr;
		tB->size++;
		cout << "-------- 输入完成 --------" << endl;
		outFile.close();
	}
}
//显示所有联系人
void showAll(telBook* tB) {//应该也可以使用传值的方式，因为只是起到了一个显示的作用
	ifstream infile("D:\\GitHub\\telBook\\通讯录系统\\通讯库.txt");
	string name;
	int gender = 3;
	int age = 0;
	string tel;
	string addr;
	while (infile >> name) {
		infile >> gender >> age >> tel >> addr;
		cout << name << " " << gender << " " << age << " " << tel << " " << addr << endl << endl;
	}
	cout << "---------- 以上 ----------" << endl;
	infile.close();
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
			cin >> slct;
			break;
		case 2:// 2.显示联系人
			showAll(&tB);
			cin >> slct;
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
			break;
		default:
			cout << "请按提示输入！giao！" << endl;
			cin >> slct;
		}
	}
}