#pragma once
#include<string>
using namespace std;
struct person {
	string name, gender, age, tel, addr;
};
struct telBook {
	struct person perArray[3000];//��ϵ������
	int size = 0;
};
//telBook tB;
void getItIn(telBook*& tBk);
void getItOut(telBook*& tBk);