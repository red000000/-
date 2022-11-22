#include<iostream>
#include<time.h>
#include"mgwt.h"
using namespace mg;
int main()
{
	int x, y;//迷宫行列数存放点
	char dt[hang][lie];//迷宫存放点
	int R[hang0][lie0];//迷宫入口存放点
	int C[hang1][lie1];//迷宫入口存放点
	std::string file;//文件名
	std::stack<std::pair<int, int>> s;//创建栈
	std::cout << "请输入文件名" << std::endl;
	std::cin >> file;
	std::memset(dt, 35, 2550);//迷宫初始化'#'	
	getfile(dt, x, y, file);
	getf(dt, R, C, x, y);
	s.push({ R[0][0],R[0][1] });
	stlzou(s, dt, x, y, C[0][0], C[0][1]);
	slt(dt, x, y);

}
