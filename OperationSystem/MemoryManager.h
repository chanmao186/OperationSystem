#pragma once
#include "Define.h"
class MemoryManager
{
public:
	// //将内存初始化	Mem RAM[128];
	int Initialize();
	MemoryManager();

	MemoryNode Memory[128];
	// 页表的头部
	Page Head;
	// 空闲程序的进程块
	//Page Idle;
	// 开辟地址
	Page Malloc(int size);
	void Free(Page _page);
	// 配置页块
	Page ConfigPage(Page p,int length,int start, Page front, Page next);
};

