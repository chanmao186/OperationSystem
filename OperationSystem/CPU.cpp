#include "pch.h"
#include "CPU.h"
#include"Global.h"
#include "Define.h"
void CPU::Deal() {
	//若进程中断进行调度，时间片用完也要进行调度
	if (theRegister.PSW > 1 || TimeSlice == 4 || theRegister.pcb->ID == 0) {
		Dispatch();
		if (theRegister.pcb->ID || TimeSlice == 4) {
			TimeSlice = 0;
		}
	}
	//更新阻塞的进程
	UpdateBlockedProcess();
	CheckProcessStates();
	UpdateIR();
	DealIR();
	theRegister.PC++;
	TimeSlice++;
}

// 处理IR中的指令
void CPU::DealIR()
{
	// TODO: 在此处添加实现代码.
	if (theRegister.IR[1] == '=') {
		theRegister.DR = theRegister.IR[2] - '0';
	}
	else if (theRegister.IR[1] == '+') {
		theRegister.DR++;
	}
	else if (theRegister.IR[1] == '-') {
		theRegister.DR--;
	}
	else if (theRegister.IR[0] == '!') {
		theRegister.PSW = Blocked_IO;
		//获取阻塞时间
		theRegister.BlockedTime = theRegister.IR[2] - '0';
	}
	else if (theRegister.IR[0] == 'e') {
		theRegister.PSW = Blocked_Destroy;
	}
	else if (theRegister.IR[0] == 'g') {
		theRegister.PC -= 2;
	}
}

// //进行程序调度
void CPU::Dispatch()
{
	//保存上一个程序的状态
	//theRegister.SvaePCBState();
	//加载新的进程，若就绪队列为空，则加载idle进程
	if (theRegister.pcb->ID) {
		theRegister.SvaePCBState();
		if (theRegister.PSW ==Blocked_IO) {
			process.Block();
		}
		else if(theRegister.PSW == Ready){
			PCB_Ready.Push(theRegister.pcb);
		}
		else if (theRegister.PSW == Blocked_Destroy) {
			process.Destery();
		}
	}
	if (!PCB_Ready.Empty()) {
		theRegister.LoadPCB(PCB_Ready.Pop());
	}
	else {
		//检查当前运行的是否为idle进程
		if (theRegister.pcb->ID)
			theRegister.LoadPCB(&pcbArray[0]);
	}
}

// 更新IR中的指令
void CPU::UpdateIR()
{
	// TODO: 在此处添加实现代码.
	theRegister.IR = TheMemory.Memory[theRegister.PC].command;
}

// 处理中断
void CPU::DealInterrupt()
{
	// TODO: 在此处添加实现代码.
	theRegister.SvaePCBState();
}

// 进行时间片的更新
void CPU::UpdateTime()
{
	// TODO: 在此处添加实现代码.
	TimeSlice++;
}


// 更新阻塞队列中的进程
void CPU::UpdateBlockedProcess()
{
	// TODO: 在此处添加实现代码.
	PPCB p = PCB_Blocked.GetHead();
	while (p) {
		p->BlockedTime--;
		p = p->Next;
	}
}


void CPU::CheckProcessStates()
{
 	PPCB p = PCB_Blocked.GetHead();

	if (p && !p->BlockedTime) {
		process.WeakUp();
	}
}
