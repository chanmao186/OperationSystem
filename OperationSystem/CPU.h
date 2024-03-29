#pragma once
class CPU
{
public:
	// 处理器运行指令
	void Deal();
	// 处理IR中的指令
	void DealIR();
	bool Power = false;
	// //进行程序调度
	void Dispatch();
	// 更新IR中的指令
	void UpdateIR();
	// 处理中断
	void DealInterrupt();
	int TimeSlice = 0;
	// 进行时间片的更新
	void UpdateTime();
	// 更新阻塞队列中的进程
	void UpdateBlockedProcess();
	void CheckProcessStates();
	void Initialize();
};

