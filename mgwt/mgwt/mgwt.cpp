#include<iostream>
#include<fstream>
#include<stack>
#include<vector>
#include"值.h"
namespace mg
{
	int d = 1;//方向,1234,上下左右
	int h = 0, l = 0;//算法内的行列数
	void getfile(char(&a)[hang][lie], int& x, int& y, std::string file)
	{
		int i = 0, j = 0;
		std::fstream F(file, std::ios::in);
		if (F.is_open())
		{
			while (F.peek() != EOF)
			{
				F.getline(a[i], 50);
				++i;
			}
			F.close();
			std::cout << "读取成功" << std::endl;
			while (a[0][j] != 0 && j < 51)
			{
				++j;
			}
			std::cout << "迷宫一共有" << i << "行" << j << "列" << std::endl;
			x = i, y = j;
		}
		else
		{
			std::cout << "文件打开失败" << std::endl;
		}
	}
	void slt(char(&a)[hang][lie], int& i, int& k)
	{
		for (int i0 = 0; i0 < i; ++i0)
		{
			for (int k0 = 0; k0 < k; ++k0)
			{
				std::cout << a[i0][k0];
			}
			std::cout << std::endl;
		}
	}
	bool getf(char(&a)[hang][lie], int(&b)[hang0][lie0], int(&c)[hang1][lie1], int x, int y)
	{		//遍历迷宫找开头s和结尾e
		bool R = false, C = false;
		int k = 0, l = 0;
		if (x < 1 || y < 1)
		{
			std::cout << "起始位置错误" << std::endl;
			return false;
		}
		for (int i = 0; i < x; ++i)
		{
			for (int j = 0; j < y; ++j)
			{
				if (a[i][j] == 's')
				{
					b[k][0] = i;
					b[k][1] = j;
					++k;
					R = true;
				}
				if (a[i][j] == 'e')
				{
					c[l][0] = i;
					c[l][1] = j;
					++l;
					C = true;
				}
			}
		}
		if (R == false)
		{
			std::cout << "入口没有找到" << std::endl;
			return false;
		}
		if (C == false)
		{
			std::cout << "出口没有找到" << std::endl;
			return false;
		}
		if (R == true && C == true)
		{
			std::cout << "出入口搜索成功" << std::endl;
			std::cout << b[0][0] << "," << b[0][1] << std::endl;//测试
			std::cout << c[0][0] << "," << c[0][1] << std::endl;//测试
		}
	}
	bool stlzou(std::stack<std::pair<int, int>> s, char(&a)[hang][lie], int x0, int y0, int x1, int y1)//x0 y0为最大行数,x1 y1为终点处
	{
		int h = s.top().first, l = s.top().second, o = -1;//行 列 计数器
		std::vector<std::pair<int, int>> top;
		bool find;//是否找到可走的路，需要每次判断
		a[s.top().first][s.top().second] = '*';//入口标记
		while (!s.empty())
		{
			if (s.top().first == x1 && s.top().second == y1)//是否到出口
			{
				while (!s.empty())
				{
					top.push_back(s.top());
					++o;
					s.pop();
				}
				for (o; o >= 0; --o)
				{
					std::cout << "[" << top[o].first << "," << top[o].second << "]" << std::endl;
				}
				return true;
			}
			find = false;
			while (d <= 4)
			{
				h = s.top().first, l = s.top().second;
				switch (d)
				{
				case 1://上
				{
					if (h > 0)
						h = s.top().first - 1;
					break;
				}
				case 2://下
				{
					if (h < x0 - 1)
						h = s.top().first + 1;
					break;
				}
				case 3://左
				{
					if (l > 0)
						l = s.top().second - 1;
					break;
				}
				case 4://右
				{
					if (l < y0 - 1)
						l = s.top().second + 1;
					break;
				}
				}
				if (a[h][l] == '0' || a[h][l] == 'e')
				{
					s.push({ h,l });
					a[h][l] = '*';//标记路线
					find = true;
					d = 0;//下面会先+
					//slt(a, x0, y0);//检验
				}
				++d;
			}
			if (find == false && d == 5)//无路可走
			{
				a[s.top().first][s.top().second] = 'x';
				s.pop();
				d = 1;
			}
		}
		return false;
	}
}
