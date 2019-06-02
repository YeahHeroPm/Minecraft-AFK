#include "pch.h"
#include "CMy_Icon.h"
#include "resource.h"
#include "Minecraft AFKDlg.h"
#include "Minecraft AFK.h"

BEGIN_MESSAGE_MAP(CMy_Icon, CStatic)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()


void CMy_Icon::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	SetCapture();
	HCURSOR hc = LoadCursor(AfxGetApp()->m_hInstance, MAKEINTRESOURCE(IDC_CURSOR1));
	::SetCursor(hc);
	HICON hicon2 = LoadIcon(AfxGetApp()->m_hInstance, MAKEINTRESOURCE(IDI_ICON2)); 
	this->SetIcon(hicon2);
	CStatic::OnLButtonDown(nFlags, point);
}


void CMy_Icon::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	ReleaseCapture();
	HICON hicon1 = LoadIcon(AfxGetApp()->m_hInstance, MAKEINTRESOURCE(IDI_ICON1)); 
	this->SetIcon(hicon1);
	POINT pnt;
	CHAR wc_TargtWndTittle[200];
	::GetCursorPos(&pnt);
	extern HWND hwnd;
	hwnd = ::WindowFromPoint(pnt);
	::GetWindowText(hwnd, wc_TargtWndTittle, 200);
	extern CMinecraftAFKDlg* p_dlg;
	CString str;
	str.Format("%p", hwnd);
	p_dlg->CE_ShowCap.SetWindowText(wc_TargtWndTittle);
	p_dlg->ShowHandle.SetWindowText(str);
	CStatic::OnLButtonUp(nFlags, point);
}
