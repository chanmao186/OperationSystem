#include "pch.h"
#include "CPU.h"
#include"Global.h"
void CPU::Deal() {
	
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
		theRegister.PSW = Blocked;
	}
	else if (theRegister.IR[0] == 'E') {

	}
}


// //进行程序调度
void CPU::Dispatch()
{
	// TODO: 在此处添加实现代码.
	//保持当前的程序的状态
	theRegister.SvaePCBState();
	//theRegister.
}
