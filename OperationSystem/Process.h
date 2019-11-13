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
};

