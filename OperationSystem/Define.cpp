//������������ļ�������Ҫ����ͽṹ��
#include "pch.h"
#include "PCB.h"
//������̵��ڴ�鳤��
#define MinSize 2

//��ֹ�����ر���
#ifndef _Define_
#define _Define_

//��������ֻ���״̬
enum PStates
{
	Ready,Running,Blocked
};

typedef class PCB *PPCB;
//�ڴ���ָ��
typedef struct PageNode* Page;

typedef string COMMAND;
struct PageNode {
	//�ڴ��Ŀ�ʼ��ַ
	int Start;
	//�ڴ��ĳ���
	int Length;
	//��һ����ַ��λ��
	Page Next;
};
/*
�ڴ��
*/
struct MemoryNode
{
	//�õ�ַ���������ָ��
	COMMAND command;
	//��ַ�Ƿ�ռ��
	bool flag;
};
#endif // !_Global_
