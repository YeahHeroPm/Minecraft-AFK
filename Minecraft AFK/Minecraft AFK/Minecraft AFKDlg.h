
// Minecraft AFKDlg.h: 头文件
//

#pragma once
#include "CMy_Icon.h"

// CMinecraftAFKDlg 对话框
class CMinecraftAFKDlg : public CDialogEx
{
// 构造
public:
	CMinecraftAFKDlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MINECRAFTAFK_DIALOG };
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
	CMy_Icon my_icon;
	afx_msg void OnBnClickedStart();
	CEdit CE_ShowCap;
	CEdit ShowHandle;
	afx_msg void OnCbnSelchangeMessageType();
	CComboBox m_messageType;
};
