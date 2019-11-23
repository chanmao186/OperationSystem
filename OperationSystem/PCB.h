
#pragma once

#include "Define.h"
#include <string>

using namespace std;
class PCB
{
public:
	// 程序当前的状态
	PStates PState;
	// 程序当前执行的地址
	int PC;
	// 程序的ID编号，内部名字
	int ID;
	// 运行中程序的下一个指针
	PPCB Next;
	// 程序的结果
	int Date;
	// 程序所在页表
	Page page;
	int Initialize();
	// 该进程块是否正在被使用，true是在被使用，false代表空闲
	bool flag;
	// 要加载的文件名字,外部名字
	string Name;
	void Config(Page _page,string name);
	// 改变进程块的状态，并加入到相关队列
	void TranformStates(PStates state);
	PCB();
	PCB(string name);
	// 该进程要阻塞的时间
	int BlockedTime;
	// 阻塞时间

};

