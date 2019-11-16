//用来定义一下公有变量
#include "pch.h"
#include "Global.h"


PCB pcbArray[PNum];
//static PCB IdlePCB("Idle");
queue PCB_Ready;
queue PCB_Blocked;
MemoryManager TheMemory;
Process process;
Register theRegister;
//IO设备的寄存器
Register IORegister;

CString Result = "";
CPU cpu;

