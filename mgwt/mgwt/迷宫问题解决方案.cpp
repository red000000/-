#include<iostream>
#include<time.h>
#include"mgwt.h"
using namespace mg;
int main()
{
	int x, y;//�Թ���������ŵ�
	char dt[hang][lie];//�Թ���ŵ�
	int R[hang0][lie0];//�Թ���ڴ�ŵ�
	int C[hang1][lie1];//�Թ���ڴ�ŵ�
	std::string file;//�ļ���
	std::stack<std::pair<int, int>> s;//����ջ
	std::cout << "�������ļ���" << std::endl;
	std::cin >> file;
	std::memset(dt, 35, 2550);//�Թ���ʼ��'#'	
	getfile(dt, x, y, file);
	getf(dt, R, C, x, y);
	s.push({ R[0][0],R[0][1] });
	stlzou(s, dt, x, y, C[0][0], C[0][1]);
	slt(dt, x, y);

}
