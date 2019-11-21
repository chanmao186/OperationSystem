#include "pch.h"
#include "MemoryManager.h"
#include "Define.h"
#include <iostream>

//将内存初始化
int MemoryManager::Initialize()
{

	for (int i = 0; i < 128; i++) {
		Memory[i].flag = 0;
	}
	Head = ConfigPage(NULL, 128, 0, NULL, NULL);
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
	while (temp) {
		if (!Memory[temp->Start].flag || temp->Length > size) {
			break;
		}
		temp = temp->Next;
	}

	//判定找到的地址块是否为空
	if (!temp)return NULL;

	//若该地址块的过长，则进行分割
	if (temp->Length - size >= MinSize) {
		Page p = ConfigPage(NULL, temp->Length - size,
			temp->Start + size, temp, temp->Next);
		temp->Next = p;
		temp->Length = size;
	}
	for (int i = temp->Start, j = i + temp->Length; i < j; i++) {
		Memory[i].flag = 1;
	}
	return temp;
};

void MemoryManager::Free(Page _page)
{
	Page temp;
	for (int i = _page->Start, j = i + _page->Length; i < j; i++) {
		Memory[i].flag = 0;
	}
	//进行可变内存块的合并
	temp = _page->Front;
	//先向前进行合并
	if (temp && !Memory[temp->Start].flag) {
		temp->Length += _page->Length;
		temp->Next = _page->Next;
		if (_page->Next) {
			_page->Next->Front = temp;
		}
		free(_page);
		_page = temp;
	}

	//向后进行合并
	temp = _page->Next;
	if (temp && !Memory[temp->Start].flag) {
		_page->Length += temp->Length;
		_page->Next = temp->Next;
		if (temp->Next) {
			temp->Next->Front = _page;
		}
		free(temp);
	}
}


// 配置页块
Page MemoryManager::ConfigPage(Page p, int length, int start, Page front, Page next)
{
	// TODO: 在此处添加实现代码.
	if (p == NULL) {
		p = (Page)malloc(sizeof(PageNode));
	}

	p->Next = next;
	p->Front = front;
	p->Start = start;
	p->Length = length;
	return p;
}
