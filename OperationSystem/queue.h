#pragma once
#include "Define.cpp"
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


