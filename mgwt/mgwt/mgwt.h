#pragma once
#include"ֵ.h"
#include<stack>
namespace mg//�����������
{
	void getfile(char(&a)[hang][lie], int& x, int& y,std::string file);//��ȡ�ļ���Ϣ
	bool getf(char(&a)[hang][lie], int(&b)[hang0][lie0], int(&c)[hang1][lie1], int x, int y);//�õ���ʼ���յ�λ��
	void slt(char(&a)[hang][lie],int &i,int& k);//��ͼ��������ͼ��ӡ(����#)
	bool stlzou(std::stack<std::pair<int, int>> s, char(&a)[hang][lie], int x0, int y0, int x1, int y1);//��������㷨,ջ��1234��Ӧ��������
}