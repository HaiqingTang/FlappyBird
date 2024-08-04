// COver1.cpp: 实现文件
//

#include "pch.h"
#include "FlappyBird.h"
#include "COver1.h"
#include "afxdialogex.h"
#include"CTestDlg.h"
#include "FlappyBirdDlg.h"
#include "CRank.h"

// COver1 对话框
int m_rank = 0;
IMPLEMENT_DYNAMIC(COver1, CDialogEx)

COver1::COver1(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG3, pParent)
{

}

COver1::~COver1()
{
}

void COver1::DoDataExchange(CDataExchange* pDX)
{

	CDialogEx::DoDataExchange(pDX);
	HBITMAP   hBitmap;
	hBitmap = LoadBitmap(AfxGetInstanceHandle(),
		MAKEINTRESOURCE(IDB_BITMAP10));
	((CButton *)GetDlgItem(IDOK))->SetBitmap(hBitmap);

	HBITMAP   hBitmap1;
	hBitmap1 = LoadBitmap(AfxGetInstanceHandle(),
		MAKEINTRESOURCE(IDB_BITMAP11));
	((CButton *)GetDlgItem(IDC_BUTTON1))->SetBitmap(hBitmap1);
}


BEGIN_MESSAGE_MAP(COver1, CDialogEx)
	ON_WM_PAINT()
	ON_BN_CLICKED(IDOK, &COver1::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON1, &COver1::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &COver1::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &COver1::OnBnClickedButton3)
END_MESSAGE_MAP()


// COver1 消息处理程序


void COver1::OnPaint()
{
	CPaintDC dc(this); // device context for painting
						   // TODO: 在此处添加消息处理程序代码
						   // 不为绘图消息调用 CDialogEx::OnPaint()
	CFlappyBirdDlg a;
	int s = a.getScore();
	CFlappyBirdDlg ba;
	int b = a.getBest();
	num[0].Load(TEXT("res//font_048.png"));//0
	num[1].Load(TEXT("res//font_049.png"));//1
	num[2].Load(TEXT("res//font_050.png"));//2
	num[3].Load(TEXT("res//font_051.png"));//3
	num[4].Load(TEXT("res//font_052.png"));//4
	num[5].Load(TEXT("res//font_053.png"));//5
	num[6].Load(TEXT("res//font_054.png"));//6
	num[7].Load(TEXT("res//font_055.png"));//7
	num[8].Load(TEXT("res//font_056.png"));//8
	num[9].Load(TEXT("res//font_057.png"));//9
	medal[0].Load(TEXT("res//tong.png"));//0
	medal[1].Load(TEXT("res//yin.png"));//0
	medal[2].Load(TEXT("res//jin.png"));//0
	rank.Load(TEXT("res//rank.png"));//0
	int number = s % 10;//score Yushu
	int number1 = (s - number) / 10;//score zhengshu
	int number2 = b% 10;//best Yushu
	int number3 = (b- number) / 10;//best zhengshu
	
	CBitmap   bitmap;                            //定义位图
	bitmap.LoadBitmap(IDB_BITMAP9);    //这个IDB_BITMAP1要自己添加
	CBrush   brush;
	brush.CreatePatternBrush(&bitmap);
	CBrush*   pOldBrush = dc.SelectObject(&brush);
	dc.Rectangle(0, 0, 664, 487);                  //前两个为图片起始位置，后两个为图片终点位置，实际为图片的像素大小
	dc.SelectObject(pOldBrush);
    num[number1].Draw(dc, 440, 230, 24, 44);
	num[number].Draw(dc, 466,230, 24, 44);
	num[number2].Draw(dc, 466, 310, 24, 44);
	num[number3].Draw(dc, 440, 310, 24, 44);
	if (3> s &&s >= 2)
	{
		medal[0].Draw(dc, 140, 240, 120, 100);
	}
	if (5 > s&& s  >= 3)
	{
		medal[1].Draw(dc, 140, 240, 120, 100);
	}
	if (s >= 5)
	{
		medal[2].Draw(dc, 140, 240, 120, 100);
	}
	
	
	
}


void COver1::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	//CFlappyBirdDlg dlg;
	
	this->OnOK();
	restart++;
	//dlg.DoModal();
}


void COver1::OnBnClickedButton1()
{
	CRank dlg;
	//this->OnOK();
	//COver1 dlg;
	dlg.DoModal();

}


void COver1::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
}


void COver1::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
}
