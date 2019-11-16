#pragma once
#include "Define.h"
class queue
{
private:
	PPCB Head;
	PPCB Nail;
public:
	queue();
	
	void Push(PPCB pcb);
	PPCB Pop();
	bool Empty();
	// 获取头节点
	PPCB GetHead();
};


