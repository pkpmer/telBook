#include<iostream>
#include<string>
#include<fstream>
#define max 1000
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
	int gender = 3;//1--�У�2--Ů��3--δ֪�Ա�
	int age = 0;//0����δ֪����
	string tel;
	string addr;
};
//ͨѶ¼�ṹ��
struct telBook {
	struct person perArray[max];//��ϵ������
	int size;
};
//�����ϵ��
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
		//tB->size++;//��Ҫ�������
		//����Ա�
		int gender = 3;
		cout << '\n' << "*�������Ա�:" << endl
			<< "1--�У�2--Ů��3--δ֪�Ա� " << endl;
		cin >> gender;
		tB->perArray[tB->size].gender = gender;
		//�������
		int age = 0;
		cout << '\n' << "*����������(���δ֪���0��):" << endl;//�����޸�Ϊ��׽�س���
		if (cin >> age)
			tB->perArray[tB->size].age = age;
		else
			tB->perArray[tB->size].age = 0;
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
		//��׷�ӷ�ʽ���ļ�
		ofstream outFile("D:\\GitHub\\telBook\\ͨѶ¼ϵͳ\\ͨѶ��.txt", ios_base::app);
		if (!outFile)//�ж��ļ��Ƿ��
			cerr << "֮ǰ�����޷�д����ڣ�";
		else
			outFile << endl
			<< tB->perArray[tB->size].name << "  "
			<< tB->perArray[tB->size].gender << "  "
			<< tB->perArray[tB->size].age << "  "
			<< tB->perArray[tB->size].tel << "  "
			<< tB->perArray[tB->size].addr;
		tB->size++;
		cout << "-------- ������� --------" << endl;
		outFile.close();
	}
}
//��ʾ������ϵ��
void showAll(telBook* tB) {//Ӧ��Ҳ����ʹ�ô�ֵ�ķ�ʽ����Ϊֻ������һ����ʾ������
	ifstream infile("D:\\GitHub\\telBook\\ͨѶ¼ϵͳ\\ͨѶ��.txt");
	string name;
	int gender = 3;
	int age = 0;
	string tel;
	string addr;
	while (infile >> name) {
		infile >> gender >> age >> tel >> addr;
		cout << name << " " << gender << " " << age << " " << tel << " " << addr << endl << endl;
	}
	cout << "---------- ���� ----------" << endl;
	infile.close();
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
			cin >> slct;
			break;
		case 2:// 2.��ʾ��ϵ��
			showAll(&tB);
			cin >> slct;
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
			break;
		default:
			cout << "�밴��ʾ���룡giao��" << endl;
			cin >> slct;
		}
	}
}