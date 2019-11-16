#include "pch.h"
#include "IODevice.h"
#include "Global.h"

// 正常工作处理程序
void IODevice::Deal()
{
	// TODO: 在此处添加实现代码.
	if (!IORegister.pcb||IORegister.BlockedTime == 0) {
		GetNextPCB();
	}
	//确保成功获得下一地址
	if (IORegister.pcb) {
		if (--IORegister.BlockedTime == 0) {
			PrintResult();
			IORegister.PSW = Ready;
			process.WeakUp();
		}
	}
}


// 获取下一个要进行打印的进程
void IODevice::GetNextPCB()
{
	// TODO: 在此处添加实现代码.
	if (!PCB_Blocked.Empty()) {
		IORegister.LoadPCB(PCB_Blocked.Pop());
	}
	else {
		IORegister.pcb = NULL;      
	}
}


// 打印结果
void IODevice::PrintResult()
{
	CString temp;
	//将该结果显示在对话框中
	
}
