#include<iostream>
#include<fstream>
#include<stack>
#include<vector>
#include"ֵ.h"
namespace mg
{
	int d = 1;//����,1234,��������
	int h = 0, l = 0;//�㷨�ڵ�������
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
			std::cout << "��ȡ�ɹ�" << std::endl;
			while (a[0][j] != 0 && j < 51)
			{
				++j;
			}
			std::cout << "�Թ�һ����" << i << "��" << j << "��" << std::endl;
			x = i, y = j;
		}
		else
		{
			std::cout << "�ļ���ʧ��" << std::endl;
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
	{		//�����Թ��ҿ�ͷs�ͽ�βe
		bool R = false, C = false;
		int k = 0, l = 0;
		if (x < 1 || y < 1)
		{
			std::cout << "��ʼλ�ô���" << std::endl;
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
			std::cout << "���û���ҵ�" << std::endl;
			return false;
		}
		if (C == false)
		{
			std::cout << "����û���ҵ�" << std::endl;
			return false;
		}
		if (R == true && C == true)
		{
			std::cout << "����������ɹ�" << std::endl;
			std::cout << b[0][0] << "," << b[0][1] << std::endl;//����
			std::cout << c[0][0] << "," << c[0][1] << std::endl;//����
		}
	}
	bool stlzou(std::stack<std::pair<int, int>> s, char(&a)[hang][lie], int x0, int y0, int x1, int y1)//x0 y0Ϊ�������,x1 y1Ϊ�յ㴦
	{
		int h = s.top().first, l = s.top().second, o = -1;//�� �� ������
		std::vector<std::pair<int, int>> top;
		bool find;//�Ƿ��ҵ����ߵ�·����Ҫÿ���ж�
		a[s.top().first][s.top().second] = '*';//��ڱ��
		while (!s.empty())
		{
			if (s.top().first == x1 && s.top().second == y1)//�Ƿ񵽳���
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
				case 1://��
				{
					if (h > 0)
						h = s.top().first - 1;
					break;
				}
				case 2://��
				{
					if (h < x0 - 1)
						h = s.top().first + 1;
					break;
				}
				case 3://��
				{
					if (l > 0)
						l = s.top().second - 1;
					break;
				}
				case 4://��
				{
					if (l < y0 - 1)
						l = s.top().second + 1;
					break;
				}
				}
				if (a[h][l] == '0' || a[h][l] == 'e')
				{
					s.push({ h,l });
					a[h][l] = '*';//���·��
					find = true;
					d = 0;//�������+
					//slt(a, x0, y0);//����
				}
				++d;
			}
			if (find == false && d == 5)//��·����
			{
				a[s.top().first][s.top().second] = 'x';
				s.pop();
				d = 1;
			}
		}
		return false;
	}
}
