#include "getIO.h"
#include<fstream>
//��ȡtxt�ļ��������ݵ��ṹ��������
void getItIn(telBook*& tB) {
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
		(tB->size)++;//��ʱ���������С���ᳬ��3000������û��������
	}
	infile.close();
}