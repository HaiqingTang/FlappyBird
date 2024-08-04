// CRank.cpp: 实现文件
//

#include "pch.h"
#include "FlappyBird.h"
#include "CRank.h"
#include "afxdialogex.h"
#include "FlappyBirdDlg.h"


// CRank 对话框

IMPLEMENT_DYNAMIC(CRank, CDialogEx)

CRank::CRank(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1, pParent)
{

}

CRank::~CRank()
{
}

void CRank::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CRank, CDialogEx)
	ON_WM_PAINT()
END_MESSAGE_MAP()


// CRank 消息处理程序
int temp3;
int best1=0;//NO1
int best2 = 0;//NO2
int best3 = 0;//NO3
void CRank::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: 在此处添加消息处理程序代码
					   // 不为绘图消息调用 CDialogEx::OnPaint()

	CBitmap   bitmap;                            //定义位图
	bitmap.LoadBitmap(IDB_BITMAP12);    //这个IDB_BITMAP1要自己添加
	CBrush   brush;
	brush.CreatePatternBrush(&bitmap);
	CBrush*   pOldBrush = dc.SelectObject(&brush);
	dc.Rectangle(0, 0, 664, 487);                  //前两个为图片起始位置，后两个为图片终点位置，实际为图片的像素大小
	dc.SelectObject(pOldBrush);

	CFlappyBirdDlg a;
	int s = a.getScore();
	
	if (s > best3)
		 best3=s;
	if (best3 > best2)
	{
		temp3 = best3;
		best3 = best2;
		best2 = temp3;
	}
	if (best2 > best1)
	{
		temp3 = best2;
		best2 = best1;
		best1 = temp3;
	}
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
	int number = best1 % 10;//score Yushu
	int number1 = (best1 - number) / 10;//score zhengshu
	int number2 = best2% 10;//best Yushu
	int number3 = (best2 - number) / 10;//best zhengshu
	int number4 = best3 % 10;//score Yushu
	int number5 = (best3 - number) / 10;//score zhengshu
	num[number1].Draw(dc, 220, 240, 21, 40);
	num[number].Draw(dc, 240, 240, 21, 40);
	num[number2].Draw(dc, 240,280, 21, 40);
	num[number3].Draw(dc, 220, 280, 21, 40);
	num[number4].Draw(dc, 240,320, 21, 40);
	num[number5].Draw(dc, 220, 320, 21, 40);
	
}
