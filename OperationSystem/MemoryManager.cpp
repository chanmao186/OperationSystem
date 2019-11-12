#include "pch.h"
#include "MemoryManager.h"
#include "Define.h"

//将内存初始化
int MemoryManager::Initialize()
{
	// TODO: 在此处添加实现代码.
	for (int i = 0; i < 128; i++) {
		Memory[i].flag= false;
	}
	return 0;
}

MemoryManager::MemoryManager() {
	Initialize();
}
// 开辟地址
Page MemoryManager::malloc(int size)
{
	Page temp = Head;
	/**
	寻找下一个地址块
	要求
	地址块存在
	未被使用
	可以利用长度大于size
	*/
	while (temp && Memory[temp->Start].flag && temp->Length < size) {
		temp = temp->Next;
	}

	//判定找到的地址块是否为空
	if (!temp)return NULL;

	//若该地址块的过长，则进行分割
	if (temp->Length - size <= MinSize) {
		Page p = (Page)malloc(sizeof(PageNode));
		p->Start = temp->Start + size;
		p->Length = temp->Length - size;
		p->Next = temp->Next;
		temp->Next = p;
		temp->Length = size;
	}
	return temp;
};


