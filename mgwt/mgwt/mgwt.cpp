#include<iostream>
#include<fstream>
#include"hong.h"
namespace mg
{
	void getfile(char(&a)[hang][lie])
	{
		int i = 0;
		std::string file;
		std::cout << "�������ļ���" << std::endl;
		std::cin >> file;
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
		}
		else
		{
			std::cout << "�ļ���ʧ��" << std::endl;
		}
	}
	void slt(char(&a)[50][51])
	{
		for (int i = 0; i < 50; ++i)
		{
			for (int j = 0; j < 50; ++j)
			{
				std::cout << a[i][j];
			}
			std::cout << std::endl;
		}
	}
}
