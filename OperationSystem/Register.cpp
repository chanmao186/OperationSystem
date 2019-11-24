#include "pch.h"
#include "Register.h"
#include "Global.h"

// 保持当前程序的状态
void Register::SvaePCBState()
{
	// TODO: 在此处添加实现代码.
	pcb->PC = PC;
	pcb->Date = DR;
	pcb->PState = PSW;
	pcb->BlockedTime = BlockedTime;
}
Register::Register() {
	Initalize();
}

// 获取当前寄存器的状态
void Register::GetPcbState(PPCB curPCB)
{
	PC = curPCB->PC;
	PSW = curPCB->PState = Running;
}


void Register::LoadPCB(PPCB _pcb)
{
	// TODO: 在此处添加实现代码.
	PC = _pcb->PC;
	DR = _pcb->Date;
	pcb = _pcb;
	PSW = _pcb->PState;
	Name = _pcb->Name;
}



void Register::Initalize()
{
	// TODO: 在此处添加实现代码.
	DR = 0;
	PC = 0;
	PSW = Ready;
	pcb = &pcbArray[0];
	BlockedTime = 0;
	Name = "idle.c";
}
