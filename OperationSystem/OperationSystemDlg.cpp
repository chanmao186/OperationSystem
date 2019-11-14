﻿
// OperationSystemDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "OperationSystem.h"
#include "OperationSystemDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
#include <fstream>
#include <string>
#include <iostream>
using namespace std;


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// COperationSystemDlg 对话框



COperationSystemDlg::COperationSystemDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_OPERATIONSYSTEM_DIALOG, pParent)
	, Edit_CurPCB(_T(""))
	, check10(FALSE)
	, check2(FALSE)
	, CurResult(_T(""))
	, CurCommand(_T(""))
	, check3(FALSE)
	, check1(FALSE)
	, check4(FALSE)
	, check5(FALSE)
	, check6(FALSE)
	, check7(FALSE)
	, check8(FALSE)
	, check9(FALSE)
	, Edit_Ready(_T(""))
	, Edit_Blocked(_T(""))
	, Edit_Result(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void COperationSystemDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_CurPCB, Edit_CurPCB);
	DDX_Check(pDX, IDC_CHECK2, check2);
	DDX_Text(pDX, IDC_EDIT_CurResult, CurResult);
	DDX_Control(pDX, IDC_EDIT_CurTimeSlice, CurTimeSlice);
	DDX_Text(pDX, IDC_EDIT_CurCommand, CurCommand);
	DDX_Check(pDX, IDC_CHECK3, check3);
	DDX_Check(pDX, IDC_CHECK1, check1);
	DDX_Check(pDX, IDC_CHECK10, check10);
	DDX_Check(pDX, IDC_CHECK4, check4);
	DDX_Check(pDX, IDC_CHECK5, check5);
	DDX_Check(pDX, IDC_CHECK6, check6);
	DDX_Check(pDX, IDC_CHECK7, check7);
	DDX_Check(pDX, IDC_CHECK8, check8);
	DDX_Check(pDX, IDC_CHECK9, check9);
	DDX_Text(pDX, IDC_EDIT_Ready, Edit_Ready);
	DDX_Text(pDX, IDC_EDIT_Blocked, Edit_Blocked);
	DDX_Text(pDX, IDC_EDIT_Result, Edit_Result);
	DDX_Control(pDX, PowerButton, PowerBtn);
}

BEGIN_MESSAGE_MAP(COperationSystemDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_LoadP0, &COperationSystemDlg::OnBnClickedLoadp0)
	ON_BN_CLICKED(PowerButton, &COperationSystemDlg::OnBnClickedPowerbutton)
END_MESSAGE_MAP()


// COperationSystemDlg 消息处理程序

BOOL COperationSystemDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void COperationSystemDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void COperationSystemDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR COperationSystemDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void COperationSystemDlg::OnBnClickedLoadp0()
{

	if (!cpu.Power)return;
	//先获取列表框中的数据
	
	UpdateData(true);
	string file = "000.c";
	//根据文件明创建进程
	for (int i = 0; i < 10; i++) {
		if (*check[i]) {
			file[2] = i+'0';
			//process.Create(file);
			*check[i] = FALSE;
		}
	}
	//显示修改
	UpdateData(false);
}

void COperationSystemDlg::OnBnClickedPowerbutton()
{
	// TODO: 在此添加控件通知处理程序代码
	cpu.Power = !cpu.Power;
	if (cpu.Power) {
		PowerBtn.SetWindowTextA("关机");
	}
	else {
		PowerBtn.SetWindowTextA("开机");
	}
}
