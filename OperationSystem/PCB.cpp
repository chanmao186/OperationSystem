#include "pch.h"
#include "PCB.h"
#include "Global.h"

int PCB::Initialize()
{
	PC = 0;
	Date = 0;
	ID = 0;
	BlockedTime = 0;
	Next = NULL;
	page = NULL;
	PState = Ready;
	flag = false;
	Name = "";
	return 0;
}


void PCB::Config(Page _page,string name)
{
	// TODO: 在此处添加实现代码.
	Name = name;
	page = _page;
	PC = _page->Start;

	flag = true;
	//默认程序的状态为就绪
	//TranformStates(Ready);
}


// 改变进程块的状态，并加入到相关队列
void PCB::TranformStates(PStates state)
{
	// TODO: 在此处添加实现代码.
	PState = state;
	if (state == Ready) {
		PCB_Ready.Push(this);
	}
	else if(state == Blocked_IO){
		PCB_Blocked.Push(this);
	}
}
PCB::PCB() {
	Initialize();
}
PCB::PCB(string name) {
	Initialize();
	flag = true;
	this->Name = name;
}