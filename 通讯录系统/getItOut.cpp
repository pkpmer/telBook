#include "getIO.h"
#include<iostream>
#include<fstream>
using namespace std;
//��ȡ�ṹ�������������ݵ�txt�ļ��У���Ҫ��getItIn���ʹ��
void getItOut(telBook*& tB) {//һ���getItIn���ʹ�ã�getItIn���Ѿ���ָ�������ڴ��ˣ��ʲ����ٷ���
	ofstream outFile("D:\\GitHub\\telBook\\ͨѶ¼ϵͳ\\ͨѶ��.txt");
	if (!outFile)//�ж��ļ��Ƿ��
		cerr << "֮ǰ�����޷�д����ڣ�";//�˴��õ���iostream.h,�Ѿ���ͷ�ļ��а���֮
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