#pragma once
#include "Define.cpp"
#include "Global.h"
#include "pch.h"
class Process
{
public:
	// 创建进程
	void Create(string FileName);
	// 寻找空白进程块
	PPCB SeekBlankPCB();
};

