// COver.cpp: 实现文件
//

#include "pch.h"
#include "FlappyBird.h"
#include "COver.h"
#include "afxdialogex.h"
#include"CTestDlg.h"
#include "FlappyBirdDlg.h"
// COver 对话框

IMPLEMENT_DYNAMIC(COver, CDialogEx)
BEGIN_MESSAGE_MAP(COver, CDialogEx)
	ON_BN_CLICKED(IDOK, &COver::OnBnClickedOk)
//	ON_EN_CHANGE(IDC_EDIT1, &COver::OnEnChangeEdit1)
	//ON_BN_CLICKED(IDC_BUTTON1, &COver::OnBnClickedButton1)
	//ON_BN_CLICKED(IDC_restart, &COver::OnBnClickedrestart)
//	ON_BN_CLICKED(IDC_BOTTON1, &COver::OnBnClickedBotton1)
	ON_BN_CLICKED(IDC_BUTTON1, &COver::OnBnClickedButton1)
//	ON_EN_CHANGE(IDC_EDIT2, &COver::OnEnChangeEdit2)
END_MESSAGE_MAP()
COver::COver(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1, pParent)
	
	, m_score(0)
{

}

COver::~COver()
{
}

void COver::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	
	DDX_Control(pDX, IDC_BUTTON1, m_Btn);
	
	HBITMAP   hBitmap;
	hBitmap = LoadBitmap(AfxGetInstanceHandle(),
		MAKEINTRESOURCE(IDB_BITMAP10));
	((CButton *)GetDlgItem(IDC_BUTTON1))->SetBitmap(hBitmap);
	
	
	CClientDC dc1(this);
	num[0].Load(TEXT("res//font_048.png"));//数字
	num[0].Draw(dc1, 200, 200, 24, 44);//数字


	
	
}
void COver::OnPaint()
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
}



// COver 消息处理程序


void COver::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK();
}


void COver::OnEnChangeEdit1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}






void COver::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	CTestDlg dlg;
	this->OnOK();
	dlg.DoModal();
	

}


void COver::OnEnChangeEdit2()
{
	UpdateData(FALSE);
	m_score = score;
	UpdateData(TRUE);

}
