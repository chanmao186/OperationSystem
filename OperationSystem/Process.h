#pragma once
#include "pch.h"
#include "Define.h"

class Process
{
public:
	int ID = 0;
	// 创建进程
	void Create(string FileName);
	// 寻找空白进程块
	PPCB SeekBlankPCB();
	// 阻塞函数
	int Block();
	// 进行进程唤醒
	int WeakUp();
	// 销毁进程的函数
	void Destery();
	void Initialize();
};

