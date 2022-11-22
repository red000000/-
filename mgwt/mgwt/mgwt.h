#pragma once
#include"值.h"
#include<stack>
namespace mg//函数命名存放
{
	void getfile(char(&a)[hang][lie], int& x, int& y,std::string file);//读取文件信息
	bool getf(char(&a)[hang][lie], int(&b)[hang0][lie0], int(&c)[hang1][lie1], int x, int y);//拿到开始和终点位置
	void slt(char(&a)[hang][lie],int &i,int& k);//地图整体缩略图打印(忽略#)
	bool stlzou(std::stack<std::pair<int, int>> s, char(&a)[hang][lie], int x0, int y0, int x1, int y1);//深度优先算法,栈内1234对应上下左右
}