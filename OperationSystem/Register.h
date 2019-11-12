#pragma once
#include "Define.cpp"

class Register
{
public:
	// 程序状态寄存器
	PStates PSW;
	//	指令寄存器	
	COMMAND IR;
	// //地址寄存器
	int PC;
	// 正在执行的指令控制块
	PCB pcb;
	// 保持当前程序的状态
	void SvaePCBState();
	int DR;
	Register();
	// 获取当前寄存器的状态
	void GetPcbState(PCB curPCB);
};

