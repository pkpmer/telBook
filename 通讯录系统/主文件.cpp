#include<iostream>
#include<string>
#include<fstream>
#define max 100//�������ֹ���ᳬ��16k
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
	string name, gender, age, tel, addr;
};
//ͨѶ¼�ṹ��
struct telBook {
	struct person perArray[max];//��ϵ������
	int size = 0;
};
//��ȡtxt�ļ��������ݵ��ṹ��������
void getItIn(telBook* tB) {
	ifstream infile("D:\\GitHub\\telBook\\ͨѶ¼ϵͳ\\ͨѶ��.txt");
	string name, gender, age, tel, addr;
	tB->size = 0;
	while (infile >> name) {
		infile >> gender >> age >> tel >> addr;
		tB->perArray[tB->size].name = name;
		tB->perArray[tB->size].gender = gender;
		tB->perArray[tB->size].age = age;
		tB->perArray[tB->size].tel = tel;
		tB->perArray[tB->size].addr = addr;
		(tB->size)++;//��ʱ���������С���ᳬ��150������û��������
	}
	infile.close();
}
//��ȡ�ṹ�������������ݵ�txt�ļ��У���Ҫ��getItIn���ʹ��
void getItOut(telBook* tB) {
	ofstream outFile("D:\\GitHub\\telBook\\ͨѶ¼ϵͳ\\ͨѶ��.txt");
	if (!outFile)//�ж��ļ��Ƿ��
		cerr << "֮ǰ�����޷�д����ڣ�";
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
//1.�����ϵ��
void addPerson(telBook* tB){
	//�ж�ͨѶ¼�Ƿ�����
	if (tB->size == max) { //"->"��ָ���ָ����������������������ã���ʾȡֵ
		cout << "ͨѶ¼����!";
		return;
	}
	else {
		//�������
		string name, gender, age, tel, addr;
		cout << "*����������:" << endl;
		cin >> name;
		tB->perArray[tB->size].name = name;
		cout << '\n' << "*�������Ա�:" << endl;
		cin >> gender;
		tB->perArray[tB->size].gender = gender;
		cout << '\n' << "*����������:" << endl;
		cin >> age;
		tB->perArray[tB->size].age = age;
		cout << '\n' << "*������绰:" << endl;
		cin >> tel;
		tB->perArray[tB->size].tel = tel;
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
	//�����˳���ṹ��ᱻֱ���ͷ�
}
//3.ɾ����ϵ��
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
			tB.perArray[tB.size].name = '\0';//������һ��
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
		cout << endl << "*��ϵ�˲�����" << endl << endl;
	cout << "-------- ɾ����� --------" << endl;
	system("pause");
	system("cls");
}
//4.������ϵ��
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
			check = true;//�����ж��б������޴���
			break;
		}
	}
	if(!check)
		cout << endl << "*���޴���" << endl << endl;
	cout << "-------- ��ѯ��� --------" << endl;
	system("pause");
	system("cls");
}
//5.�޸���ϵ��
void modify(string individual) {
	telBook tB;
	getItIn(&tB);
	string name, gender, age, tel, addr;
	cout << "*����������:" << endl;cin >> name;
	cout << '\n' << "*�������Ա�:" << endl; cin >> gender;
	cout << '\n' << "*����������:" << endl; cin >> age;
	cout << '\n' << "*������绰:" << endl; cin >> tel;
	cout << '\n' << "*������סַ:" << endl; cin >> addr;
	int i; bool check = false;
	for (i = 0; i < tB.size; i++) {
		if (tB.perArray[i].name == individual) {
			tB.perArray[i].name = name;
			tB.perArray[i].gender = gender;
			tB.perArray[i].age = age;
			tB.perArray[i].tel = tel;
			tB.perArray[i].addr = addr;
			check = true;//�����ж��б������޴���
			break;
		}
	}
	if (!check)
		cout << endl << "*��ϵ�˲�����" << endl << endl;
	cout << "-------- ��ѯ��� --------" << endl;
	getItOut(&tB);
	system("pause");
	system("cls");
}
//6.�����ϵ��
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
	cout << "-------- ������ --------" << endl;
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