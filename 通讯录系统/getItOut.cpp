#include "getIO.h"
#include<iostream>
#include<fstream>
using namespace std;
//读取结构体数组所有内容到txt文件中，需要与getItIn配合使用
void getItOut(telBook*& tB) {//一般和getItIn配合使用，getItIn中已经给指针分配过内存了，故不用再分配
	ofstream outFile("D:\\GitHub\\telBook\\通讯录系统\\通讯库.txt");
	if (!outFile)//判断文件是否打开
		cerr << "之前操作无法写入库内！";//此处用到了iostream.h,已经在头文件中包含之
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