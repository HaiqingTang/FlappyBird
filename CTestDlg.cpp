// CTestDlg.cpp: 实现文件
//

#include "pch.h"
#include "FlappyBird.h"
#include "FlappyBirdDlg.h"
#include "CTestDlg.h"
#include "afxdialogex.h"
#include <cstdlib>
#include <ctime>
#include   <mmsystem.h>  
#include "CExplainDlg.h"
#pragma   comment(lib,   "winmm.lib")  
#include "COver1.h"
#include "CRank.h"
#include"Cm_playAPP.h"
// CTestDlg 对话框

IMPLEMENT_DYNAMIC(CTestDlg, CDialogEx)

CTestDlg::CTestDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_ABOUTBOX, pParent)
{

}

CTestDlg::~CTestDlg()
{
}

void CTestDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CTestDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &CTestDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON1, &CTestDlg::OnBnClickedButton1)
	ON_WM_PAINT()
END_MESSAGE_MAP()


// CTestDlg 消息处理程序


void CTestDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	
	

	CFlappyBirdDlg dlg;
	this->OnOK();
	dlg.DoModal();
	
	//CDialogEx::OnOK();
}


void CTestDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
//	CExplainDlg dlg;
	//this->OnOK();
	//CRank dlg;
	Cm_playAPP dlg;
	dlg.DoModal();
}

void CTestDlg::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: 在此处添加消息处理程序代码
					   // 不为绘图消息调用 CDialogEx::OnPaint()
	CBitmap   bitmap;                            //定义位图
	bitmap.LoadBitmap(IDB_BITMAP5);    //这个IDB_BITMAP1要自己添加
	CBrush   brush;
	brush.CreatePatternBrush(&bitmap);
	CBrush*   pOldBrush = dc.SelectObject(&brush);
	dc.Rectangle(0, 0, 664, 487);                  //前两个为图片起始位置，后两个为图片终点位置，实际为图片的像素大小
	dc.SelectObject(pOldBrush);

	HBITMAP   hBitmap;
hBitmap = LoadBitmap(AfxGetInstanceHandle(),
	MAKEINTRESOURCE(IDB_BITMAP8));
((CButton *)GetDlgItem(IDOK))->SetBitmap(hBitmap);


hBitmap = LoadBitmap(AfxGetInstanceHandle(),
	MAKEINTRESOURCE(IDB_BITMAP6));
((CButton *)GetDlgItem(IDC_BUTTON1))->SetBitmap(hBitmap);

}
