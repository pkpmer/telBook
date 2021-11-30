#include<iostream>
#include<string>
#include<fstream>
#include "getIO.h"
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
//1.�����ϵ��
void addPerson(){
	telBook* tB = NULL;
	tB = new telBook;
	getItIn(tB);
	if (tB->size == 3000) { //"->"��ָ���ָ����������������������ã���ʾȡֵ
		cout << "ͨѶ¼����!";
		return;
	}
	else {
		string name, gender, age, tel, addr;
		cout << "*����������:" << endl;cin >> name;
		tB->perArray[tB->size].name = name;
		cout << '\n' << "*�������Ա�:" << endl;cin >> gender;
		tB->perArray[tB->size].gender = gender;
		cout << '\n' << "*����������:" << endl;cin >> age;
		tB->perArray[tB->size].age = age;
		cout << '\n' << "*������绰:" << endl;cin >> tel;
		tB->perArray[tB->size].tel = tel;
		cout << '\n' << "*������סַ:" << endl;cin >> addr;
		tB->perArray[tB->size].addr = addr;
		++tB->size;//����������һ����ʾ����
		getItOut(tB);
		cout << "-------- ������� --------" << endl;
	}
	delete tB;
	tB = NULL;
	system("pause");
	system("cls");//�����Ļ
}
//2.��ʾ������ϵ��
void showAll() {
	telBook* tB = NULL;//��̬�����ڴ棬new��
	//������ΪtelBook* tB = new telBook����telBook* tB������˸�ע�ͣ�
	//������������ָ����ָ����һ�������
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
	cout << "---------- ���� ----------" << endl;
	delete tB;
	tB = NULL;
	system("pause");
	system("cls");//�����˳���ṹ��ᱻֱ���ͷ�
}
//3.ɾ����ϵ��
void deleteIndvl(string individual) {
	telBook* tB = NULL;
	tB = new telBook;
	getItIn(tB);
	int i; bool check = false;
	for (i = 0; i < tB->size; i++) {
		if (tB->perArray[i].name == individual) {
			for (int j = i; j < tB->size; j++)
				tB->perArray[j] = tB->perArray[j + 1];
			//tB.perArray[tB.size-1] = "";//������һ��
			check = true;
			break;//��ֹ��һ���ġ�ѭ����������������if��䣬����д���������
		}
	}
	if (!check)
		cout << endl << "*��ϵ�˲�����" << endl << endl;
	getItOut(tB);//û���ڸú�����ΪtB�ٷ����ڴ棬��Ϊǰ���Ѿ��������
	cout << "-------- ɾ����� --------" << endl;
	delete tB;	tB = NULL;
	system("pause");
	system("cls");
}
//4.������ϵ��
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
			check = true;//�����ж��б������޴���
			break;
		}
	}
	if(!check)
		cout << endl << "*���޴���" << endl << endl;
	cout << "-------- ��ѯ��� --------" << endl;
	delete tB;	tB = NULL;
	system("pause");
	system("cls");
}
//5.�޸���ϵ��
void modify(string individual) {
	telBook* tB = NULL; tB = new telBook;
	getItIn(tB);
	string name, gender, age, tel, addr;
	cout << "*����������:" << endl;cin >> name;
	cout << '\n' << "*�������Ա�:" << endl; cin >> gender;
	cout << '\n' << "*����������:" << endl; cin >> age;
	cout << '\n' << "*������绰:" << endl; cin >> tel;
	cout << '\n' << "*������סַ:" << endl; cin >> addr;
	int i; bool check = false;
	for (i = 0; i < tB->size; i++) {
		if (tB->perArray[i].name == individual) {
			tB->perArray[i].name = name;
			tB->perArray[i].gender = gender;
			tB->perArray[i].age = age;
			tB->perArray[i].tel = tel;
			tB->perArray[i].addr = addr;
			check = true;//�����ж��б������޴���
			break;
		}
	}
	if (!check)
		cout << endl << "*��ϵ�˲�����" << endl << endl;
	cout << "-------- �޸���� --------" << endl;
	getItOut(tB);
	delete tB;	tB = NULL;
	system("pause");
	system("cls");
}
//6.�����ϵ��
void clearAll() {
	telBook* tB = new telBook;//��Ҫ�ڸú�����ΪtB�����ڴ棬��ΪgetItOut�������
	tB->size = 0;//ֱ���޸Ľṹ���С����
	getItOut(tB);
	cout << "-------- ������ --------" << endl;
	delete tB; tB = NULL;
	system("pause");
	system("cls");
}
//������
int main() {
	showMenu();
	//telBook tB; //�����ṹ�������������ΪtelBook��int��doubleһ����˼��ֻ�����Լ������
	int slct = 0;//���������
	cin >> slct;
	bool flag = true;
	while (flag) {
		switch (slct) {
		case 1: // 1.�����ϵ��
			addPerson();
			break;
		case 2:// 2.��ʾ��ϵ��
			showAll();
			break;
		case 3: {// 3.ɾ����ϵ��
			cout << endl << "��������Ҫɾ������ϵ��������" << endl;
			string individual;
			cin >> individual;
			deleteIndvl(individual);
			break;
		}
		case 4: {// 4.������ϵ��
			cout << endl << "��������Ҫ��ѯ����ϵ��������" << endl;
			string individual;
			cin >> individual;
			search(individual);
			break; 
		}
		case 5: {// 5.�޸���ϵ��
			cout << endl << "��������Ҫ�޸ĵ���ϵ��������" << endl;
			string individual;
			cin >> individual;
			modify(individual);
			break; 
		}
		case 6: {// 6.�����ϵ��
			cout << endl << "ȷ��ɾ��[y/n]:";
			char cmd;//�ַ������붨���С
			cin >> cmd;
			if ((cmd == 'y') || (cmd == 'Y'))
				clearAll();
			else {
				system("pause");
				system("cls");
			}
			break;
		}
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