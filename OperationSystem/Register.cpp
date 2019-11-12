#include "pch.h"
#include "Register.h"


// 保持当前程序的状态
void Register::SvaePCBState()
{
	// TODO: 在此处添加实现代码.
	pcb.PC = PC;
	pcb.Date = DR;
	pcb.PState = PSW;
}
Register::Register() {

}

// 获取当前寄存器的状态
void Register::GetPcbState(PCB curPCB)
{
	// TODO: 在此处添加实现代码.
	pcb = curPCB;
	PC = curPCB.PC;
	PSW = curPCB.PState = Running;
}
