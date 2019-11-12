#pragma once
#include "Define.h"
class queue
{
public:
	queue();
private:
	PPCB Head;
	PPCB Nail;
public:
	void Push(PPCB pcb);
	PPCB Pop();
	bool Empty();
};


