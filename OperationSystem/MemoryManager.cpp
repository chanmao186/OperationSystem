#include "pch.h"
#include "MemoryManager.h"
#include "Define.h"
#include <iostream>

//将内存初始化
int MemoryManager::Initialize()
{
	Memory[0].command = "x=0;";
	Memory[1].command = "god;";
	Memory[0].flag = true;
	Memory[1].flag = true;
	// TODO: 在此处添加实现代码.
	for (int i = 2; i < 128; i++) {
		Memory[i].flag= false;
	}
	Head = (Page)malloc(sizeof(PageNode));
	ConfigPage(Idle, 2,0, NULL, Head);
	ConfigPage(Head, 126,2, Idle, NULL);
	return 0;
}

MemoryManager::MemoryManager() {
	Initialize();
}
// 开辟地址
Page MemoryManager::Malloc(int size)
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
		Page p = ConfigPage(NULL, temp->Length - size,
			temp->Start + size, temp, temp->Next);
		temp->Next = p;
		temp->Length = size;
	}
	for (int i = temp->Start,j= i + temp->Length; i < j; i++) {
		Memory[i].flag = true;
	}
	return temp;
};

void MemoryManager::Free(Page _page)
{
	Page temp;
	for (int i = _page->Start, j = i + _page->Length; i < j; i++) {
		Memory[i].flag = false;
	}
	//进行可变内存块的合并
	temp = _page->Front;
	//先向前进行合并
	if (temp && !Memory[temp->Start].flag) {
		temp->Length += _page->Length;
		free(_page);
		_page = temp;
	}
	//向后进行合并
	temp = _page->Next;
	if (temp && !Memory[temp->Start].flag) {
		_page->Length += temp->Length;
		free(temp);
	}
}


// 配置页块
Page MemoryManager::ConfigPage(Page p,int length,int start, Page front, Page next)
{
	// TODO: 在此处添加实现代码.
	if (p == NULL) {
		p = (Page)malloc(sizeof(PageNode));
	}
	p->Length = length;
	p->Next = next;
	p->Front = front;
	p->Start = start;
	return p;
}
