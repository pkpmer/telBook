#include<iostream>
#include<string>
#include<fstream>
#define max 100//！！数字过大会超过16k
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
	string name, gender, age, tel, addr;
};
//通讯录结构体
struct telBook {
	struct person perArray[max];//联系人数组
	int size = 0;
};
//读取txt文件所有内容到结构体数组中
void getItIn(telBook* tB) {
	ifstream infile("D:\\GitHub\\telBook\\通讯录系统\\通讯库.txt");
	string name, gender, age, tel, addr;
	tB->size = 0;
	while (infile >> name) {
		infile >> gender >> age >> tel >> addr;
		tB->perArray[tB->size].name = name;
		tB->perArray[tB->size].gender = gender;
		tB->perArray[tB->size].age = age;
		tB->perArray[tB->size].tel = tel;
		tB->perArray[tB->size].addr = addr;
		(tB->size)++;//暂时假设数组大小不会超过150，所以没有做检验
	}
	infile.close();
}
//读取结构体数组所有内容到txt文件中，需要与getItIn配合使用
void getItOut(telBook* tB) {
	ofstream outFile("D:\\GitHub\\telBook\\通讯录系统\\通讯库.txt");
	if (!outFile)//判断文件是否打开
		cerr << "之前操作无法写入库内！";
	else {
		outFile << tB->perArray[0].name << "\t"
			<< tB->perArray[0].gender << "\t"
			<< tB->perArray[0].age << "\t"
			<< tB->perArray[0].tel << "\t"
			<< tB->perArray[0].addr;
		for (int i = 1; i < tB->size; i++)
			outFile << endl << tB->perArray[i].name << "\t"
			<< tB->perArray[i].gender << "\t"
			<< tB->perArray[i].age << "\t"
			<< tB->perArray[i].tel << "\t"
			<< tB->perArray[i].addr;
	}
	outFile.close();
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
		string name, gender, age, tel, addr;
		cout << "*请输入名字:" << endl;
		cin >> name;
		tB->perArray[tB->size].name = name;
		cout << '\n' << "*请输入性别:" << endl;
		cin >> gender;
		tB->perArray[tB->size].gender = gender;
		cout << '\n' << "*请输入年龄:" << endl;
		cin >> age;
		tB->perArray[tB->size].age = age;
		cout << '\n' << "*请输入电话:" << endl;
		cin >> tel;
		tB->perArray[tB->size].tel = tel;
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
	//函数退出后结构体会被直接释放
}
//3.删除联系人
void deleteIndvl(string individual) {
	telBook tB;
	getItIn(&tB);
	int i; bool check = false;
	for (i = 0; i < tB.size; i++) {
		if (tB.perArray[i].name == individual) {
			for (int j = i; j < tB.size; j++) {
				tB.perArray[j].name = tB.perArray[j + 1].name;
				tB.perArray[j].gender = tB.perArray[j + 1].gender;
				tB.perArray[j].age = tB.perArray[j + 1].age;
				tB.perArray[j].tel = tB.perArray[j + 1].tel;
				tB.perArray[j].addr = tB.perArray[j + 1].addr;
			}
			tB.perArray[tB.size].name = '\0';//清空最后一行
			tB.perArray[tB.size].gender = '\0';
			tB.perArray[tB.size].age = '\0';
			tB.perArray[tB.size].tel = '\0';
			tB.perArray[tB.size].addr = '\0';
			check = false;
			break;
		}
	}
	getItOut(&tB);
	if (!check)
		cout << endl << "*联系人不存在" << endl << endl;
	cout << "-------- 删除完成 --------" << endl;
	system("pause");
	system("cls");
}
//4.查找联系人
void search(string individual) {
	telBook tB;
	getItIn(&tB);
	int i; bool check = false;
	for (i = 0; i < tB.size; i++) {
		if (tB.perArray[i].name == individual) {
			cout <<endl << tB.perArray[i].name << "\t"
				<< tB.perArray[i].gender << "\t"
				<< tB.perArray[i].age << "\t"
				<< tB.perArray[i].tel << "\t"
				<< tB.perArray[i].addr << endl <<endl;
			check = true;//用来判断列表中有无此人
			break;
		}
	}
	if(!check)
		cout << endl << "*查无此人" << endl << endl;
	cout << "-------- 查询完成 --------" << endl;
	system("pause");
	system("cls");
}
//5.修改联系人
void modify(string individual) {
	telBook tB;
	getItIn(&tB);
	string name, gender, age, tel, addr;
	cout << "*请输入名字:" << endl;cin >> name;
	cout << '\n' << "*请输入性别:" << endl; cin >> gender;
	cout << '\n' << "*请输入年龄:" << endl; cin >> age;
	cout << '\n' << "*请输入电话:" << endl; cin >> tel;
	cout << '\n' << "*请输入住址:" << endl; cin >> addr;
	int i; bool check = false;
	for (i = 0; i < tB.size; i++) {
		if (tB.perArray[i].name == individual) {
			tB.perArray[i].name = name;
			tB.perArray[i].gender = gender;
			tB.perArray[i].age = age;
			tB.perArray[i].tel = tel;
			tB.perArray[i].addr = addr;
			check = true;//用来判断列表中有无此人
			break;
		}
	}
	if (!check)
		cout << endl << "*联系人不存在" << endl << endl;
	cout << "-------- 查询完成 --------" << endl;
	getItOut(&tB);
	system("pause");
	system("cls");
}
//6.清空联系人
void clearAll() {
	telBook tB;
	getItIn(&tB);
	for (int i = 0; i < tB.size; i++) {
			tB.perArray[i].name = '\0';
			tB.perArray[i].gender = '\0';
			tB.perArray[i].age = '\0';
			tB.perArray[i].tel = '\0';
			tB.perArray[i].addr = '\0';
	}
	getItOut(&tB);
	cout << "-------- 清空完成 --------" << endl;
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