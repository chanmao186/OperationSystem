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
};

