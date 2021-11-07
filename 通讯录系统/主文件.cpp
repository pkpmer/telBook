#include<iostream>
#include<string>
#include<fstream>
#define max 100
using namespace std;
//��ʾ�˵�
void showMenu() {
	cout << "*********�˵�����*********" << endl
		<< "------ 1.�����ϵ�� ------" << endl
		<< "------ 2.��ʾ��ϵ�� ------" << endl
		<< "------ 3.ɾ����ϵ�� ------" << endl
		<< "------ 4.������ϵ�� ------" << endl
		<< "------ 5.�޸���ϵ�� ------" << endl
		<< "------ 6.�����ϵ�� ------" << endl
		<< "------ 0.�˳�ͨѶ¼ ------" << endl
		<< "**************************" << endl;
}
//��ϵ�˽ṹ��
struct person {
	string name;
	int gender;//1--�У�2--Ů
	int age;
	string tel;
	string addr;
};
//ͨѶ¼�ṹ��
struct telBook {
	struct person perArray[max];//��ϵ������
	int size;
};
//��ȡtxt�ļ����ṹ��������
void getItIn(telBook* tB) {
	ifstream infile("D:\\GitHub\\telBook\\ͨѶ¼ϵͳ\\ͨѶ��.txt");
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
		(tB->size)++;//��ʱ���������С���ᳬ��1000������û��������
	}
	infile.close();
}
//��ȡ�ṹ�����鵽txt�ļ���
void getItOut(telBook* tB) {
	ifstream inFile("D:\\GitHub\\telBook\\ͨѶ¼ϵͳ\\ͨѶ��.txt");
	if (!inFile)//�ж��ļ��Ƿ��
		cerr << "�޷����ļ���" << endl;
	ofstream outFile("D:\\GitHub\\telBook\\ͨѶ¼ϵͳ\\ͨѶ��.txt", ios_base::app);
	char checkEmpty;
	inFile >> checkEmpty;
	if (inFile.eof()) {
		if (!outFile)//�ж��ļ��Ƿ��
			cerr << "֮ǰ�����޷�д����ڣ�";
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
		if (!outFile)//�ж��ļ��Ƿ��
			cerr << "֮ǰ�����޷�д����ڣ�";
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
//1.�����ϵ��
void addPerson(telBook* tB){
	//�ж�ͨѶ¼�Ƿ�����
	if (tB->size == max) { //"->"��ָ���ָ����������������������ã���ʾȡֵ
		cout << "ͨѶ¼����!";
		return;
	}
	else {
		//�������
		string name;
		cout << "*����������:" << endl;
		cin >> name;
		tB->perArray[tB->size].name = name;
		//����Ա�
		int gender = 3;
		cout << '\n' << "*�������Ա�:" << endl
			<< "1--�У�2--Ů " << endl;
		cin >> gender;
		tB->perArray[tB->size].gender = gender;
		//�������
		int age = 0;
		cout << '\n' << "*����������(���δ֪���0��):" << endl;//�����޸�Ϊ��׽�س���
		if (cin >> age)
			tB->perArray[tB->size].age = age;
		//��ӵ绰
		string tel;
		cout << '\n' << "*������绰:" << endl;
		cin >> tel;
		tB->perArray[tB->size].tel = tel;
		//���סַ
		string addr;
		cout << '\n' << "*������סַ:" << endl;
		cin >> addr;
		tB->perArray[tB->size].addr = addr;
		ifstream inFile("D:\\GitHub\\telBook\\ͨѶ¼ϵͳ\\ͨѶ��.txt");
		if (!inFile)//�ж��ļ��Ƿ��
			cerr << "�޷����ļ���" << endl;
		ofstream outFile("D:\\GitHub\\telBook\\ͨѶ¼ϵͳ\\ͨѶ��.txt", ios_base::app);
		char checkEmpty;
		inFile >> checkEmpty;
		if (inFile.eof()) {
			if (!outFile)//�ж��ļ��Ƿ��
				cerr << "֮ǰ�����޷�д����ڣ�";
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
			if (!outFile)//�ж��ļ��Ƿ��
				cerr << "֮ǰ�����޷�д����ڣ�";
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
		cout << "-------- ������� --------" << endl;
	}
	system("pause");
	system("cls");//�����Ļ
}
//2.��ʾ������ϵ��
void showAll() {//Ӧ��Ҳ����ʹ�ô�ֵ�ķ�ʽ����Ϊֻ������һ����ʾ������
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
	cout << "---------- ���� ----------" << endl;
	system("pause");
	system("cls");
}
//������
int main() {
	showMenu();
	telBook tB; //�����ṹ�������������ΪtelBook��int��doubleһ����˼��ֻ�����Լ������
	tB.size = 0;
	int slct = 0;//���������
	cin >> slct;
	bool flag = true;
	while (flag) {
		switch (slct) {
		case 1:// 1.�����ϵ��
			addPerson(&tB);
			break;
		case 2:// 2.��ʾ��ϵ��
			showAll();
			break;
		case 3:// 3.ɾ����ϵ��
			break;
		case 4:// 4.������ϵ��
			break;
		case 5:// 5.�޸���ϵ��
			break;
		case 6:// 6.�����ϵ��
			break;
		case 0:// 0.�˳�ͨѶ¼
			cout << "-------- ϵͳ�ر� --------" << endl;
			flag = false;
			system("pause");
			return 0;
		default:
			cout << "�밴��ʾ���룡giao��" << endl;
		}
		showMenu();
		cin >> slct;
	}
}