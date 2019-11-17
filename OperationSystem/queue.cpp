#include "pch.h"
#include "queue.h"
void queue::Push(PPCB pcb)
{
	Nail->Next = pcb;
	Nail = pcb;
	pcb->Next = NULL;
	// TODO: 在此处添加实现代码.
}
queue::queue() {
	Head = (PPCB)malloc(sizeof(PCB));
	//Nail = Head;
	Head->Next =NULL;
	Nail = Head;
}

PPCB queue::Pop()
{
	if (Empty()) {
		return NULL;
	}
	// TODO: 在此处添加实现代码.
	PPCB temp = Head->Next;
	if (!temp->Next) {
		Nail = Head;
	}
	Head->Next = temp->Next;
	return temp;
}


bool queue::Empty()
{
	// TODO: 在此处添加实现代码.
	return !Head->Next;
}


// 获取头节点
PPCB queue::GetHead()
{
	// TODO: 在此处添加实现代码.
	return Head->Next;
}
