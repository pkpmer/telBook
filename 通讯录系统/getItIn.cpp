#include "getIO.h"
#include<fstream>
//读取txt文件所有内容到结构体数组中
void getItIn(telBook*& tB) {
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
		(tB->size)++;//暂时假设数组大小不会超过3000，所以没有做检验
	}
	infile.close();
}