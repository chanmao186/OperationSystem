#include "pch.h"
#include <fstream>
#include "Process.h"
#include "Global.h"
void Process::Create(string FileName) {
	PPCB pcb = SeekBlankPCB();
	if (!pcb) {
		//进程块已经满了
		AfxMessageBox("进程块已满，创建失败", MB_OK | MB_ICONERROR);  return;
	}	
	string file = path + FileName;
	ifstream ifs(file);
	string temp;
	getline(ifs, temp);
	//获取此代码块的长度
	int length = atoi(temp.c_str()), addr;
	
	//获取开辟内存，并并使用该内存块配置PCB
	pcb->Config(TheMemory.Malloc(length), FileName);
	addr = pcb->page->Start;
	//给地址赋值
	for (int i = 0; i < length; i++) {
		getline(ifs, TheMemory.Memory[i].command);
	}
	
	ifs.close();
	pcb->ID = ID++;
	if (pcb->ID) {
		pcb->TranformStates(Ready);
	}
	//将新建的进程加入的就绪队列
	//int length = atoi();
}
PPCB Process::SeekBlankPCB()
{
	for (int i = 0; i < 9; i++) {
		if (pcbArray[i].flag)
			continue;
		return &pcbArray[i];
	}  return NULL;
}


// 阻塞函数
int Process::Block()
{
	//加入到阻塞队列
	PCB_Blocked.Push(theRegister.pcb);
	// TODO: 在此处添加实现代码.
	return 0;
}


// 进行进程唤醒
int Process::WeakUp()
{
	// TODO: 在此处添加实现代码.
	PPCB p = PCB_Blocked.Pop();

	//将数据显示在对话框内
	CString temp;
	temp.Format(_T("%s ->%d\n"), p->Name.c_str(), p->Date);
	Result += temp;

	p->PState = Ready;
	PCB_Ready.Push(p);
	return 0;
}


// 销毁进程的函数
void Process::Destery()
{
	// TODO: 在此处添加实现代码.
	PPCB temp= theRegister.pcb;
	//释放进程的所占的内存
	TheMemory.Free(temp->page);
	//初始化进程
	temp->Initialize();
}
