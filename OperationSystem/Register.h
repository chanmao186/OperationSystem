#pragma once
#include "Define.h"

class Register
{
public:
	// 程序状态寄存器
	PStates PSW;
	//	指令寄存器	
	string IR;
	// //地址寄存器
	int PC;
	// 正在执行的指令控制块指针
	PPCB pcb;
	string Name;
	// 保持当前程序的状态
	void SvaePCBState();
	int DR;
	Register();
	
	int BlockedTime;
	// 获取当前寄存器的状态
	void GetPcbState(PPCB curPCB);
	void LoadPCB(PPCB _pcb);

};

