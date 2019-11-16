//用来定义一下公有变量
#include "pch.h"
#include "PCB.h"
#include "Define.h"
#include "queue.h"
#include "Process.h"
#include <iostream>
#include "MemoryManager.h"
#include "Register.h"
#include "CPU.h"

#ifndef _GLOBAL_H_
#define _GLOBAL_H_
#define TheID 10;
//进程的总数，一共9个一个空闲进程
#define PNum 9
extern PCB pcbArray[PNum];
//static PCB IdlePCB("Idle");
extern queue PCB_Ready;
extern queue PCB_Blocked;
extern MemoryManager TheMemory;
static string path = "res\\process_code\\";
extern Process process;
extern Register theRegister;
//IO设备的寄存器
extern Register IORegister;

extern CString Result;
extern CPU cpu;

#endif // !_Global_
