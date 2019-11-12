
// OperationSystemDlg.h: 头文件
//

#pragma once
#include "Global.h"
typedef BOOL* CheckState;
// COperationSystemDlg 对话框
class COperationSystemDlg : public CDialogEx
{
	// 构造
public:
	COperationSystemDlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_OPERATIONSYSTEM_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedLoadp0();
	// 当前正在运行的进程控制块
	CString Edit_CurPCB;
	BOOL check10;
	BOOL check2;

	CString CurResult;
	CEdit CurTimeSlice;
	CString CurCommand;
	BOOL check3;
	BOOL check1;
	BOOL check4;;
	BOOL check5;
	BOOL check6;
	BOOL check7;
	BOOL check8;
	BOOL check9;
	CheckState check[10] = {
		&check1,&check2,&check3,
		&check4,&check5,&check6,
		&check7,&check8,&check9,
		&check10
	};
};
