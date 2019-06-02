
// Minecraft AFKDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "Minecraft AFK.h"
#include "Minecraft AFKDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框
HWND hwnd;

CMinecraftAFKDlg::CMinecraftAFKDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MINECRAFTAFK_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMinecraftAFKDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_SHOW_CAP, CE_ShowCap);
	DDX_Control(pDX, IDC_SHOW_HWND, ShowHandle);
	DDX_Control(pDX, IDC_MESSAGE_TYPE, m_messageType);
}

BEGIN_MESSAGE_MAP(CMinecraftAFKDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_START, &CMinecraftAFKDlg::OnBnClickedStart)
	ON_CBN_SELCHANGE(IDC_MESSAGE_TYPE, &CMinecraftAFKDlg::OnCbnSelchangeMessageType)
END_MESSAGE_MAP()


// CMinecraftAFKDlg 消息处理程序

BOOL CMinecraftAFKDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	my_icon.SubclassDlgItem(IDC_CUR_ICON,this);
	m_messageType.SetCurSel(3);
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CMinecraftAFKDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
		CDialogEx::OnSysCommand(nID, lParam);
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMinecraftAFKDlg::OnPaint()
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
HCURSOR CMinecraftAFKDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CMinecraftAFKDlg::OnBnClickedStart()
{
	// TODO: 在此添加控件通知处理程序代码
	if (hwnd)
		switch (m_messageType.GetCurSel())
		{
		case 0://处理鼠标左键按下事件
			::PostMessage(hwnd, WM_LBUTTONDOWN, MK_LBUTTON, MAKELPARAM(0, 0));
			break;
		case 1://处理鼠标左键抬起事件
			::PostMessage(hwnd, WM_LBUTTONUP, MK_LBUTTON, MAKELPARAM(0, 0));
			break;
		case 2://处理鼠标左键双击事件
			::PostMessage(hwnd, WM_LBUTTONDBLCLK, 0, MAKELPARAM(0, 0));
			break;
		case 3://处理鼠标右键按下事件
			::PostMessage(hwnd, WM_RBUTTONDOWN, MK_RBUTTON, MAKELPARAM(0, 0));
			break;
		case 4://处理鼠标右键抬起事件
			::PostMessage(hwnd, WM_RBUTTONUP, MK_RBUTTON, MAKELPARAM(0, 0));
			break;
		case 5://处理鼠标右键双击事件
			::PostMessage(hwnd, WM_RBUTTONDBLCLK, 0, MAKELPARAM(0, 0));
			break;
		case 6://处理鼠标中键按下事件
			::PostMessage(hwnd, WM_MBUTTONDOWN, MK_MBUTTON, MAKELPARAM(0, 0));
			break;
		case 7://处理鼠标中键抬起事件
			::PostMessage(hwnd, WM_MBUTTONUP, MK_MBUTTON, MAKELPARAM(0, 0));
			break;
		case 8://处理鼠标中键双击事件
			::PostMessage(hwnd, WM_MBUTTONDBLCLK, 0, MAKELPARAM(0, 0));
			break;
		case 9://处理滚轮向前滚动事件
			::PostMessage(hwnd, WM_MOUSEWHEEL, MAKEWPARAM(0, 120), MAKELPARAM(0, 0));
			break;
		case 10://处理滚轮向后滚动事件
			::PostMessage(hwnd, WM_MOUSEWHEEL, MAKEWPARAM(0, -120), MAKELPARAM(0, 0));
			break;
		default:
			break;
		}
	else
		MessageBox("请先将光标移至游戏窗口获取窗口句柄！");
}


void CMinecraftAFKDlg::OnCbnSelchangeMessageType()
{
	// TODO: 在此添加控件通知处理程序代码

}
