#pragma once
class IODevice
{
public:
	// 正常工作处理程序
	void Deal();
	// 获取下一个要进行打印的进程
	void GetNextPCB();
	// 打印结果
	void PrintResult();
};

