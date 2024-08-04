
// FlappyBirdDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "FlappyBird.h"
#include "FlappyBirdDlg.h"
#include "afxdialogex.h"
#include"CTestDlg.h"
#include"CExplainDlg.h"
#include"COver1.h"
#include <mmsystem.h>
#pragma comment(lib, "WINMM.LIB")
#include <Vfw.H>
#include <cstdlib>
#include <ctime>
#include   <mmsystem.h>  
#pragma   comment(lib,   "winmm.lib")  



#define random(x) rand()%(x)


#ifdef _DEBUG
#define new DEBUG_NEW
#endif
#define TIMER3 3
#define TIMER4 4
#define TIMER5 5
// 用于应用程序“关于”菜单项的 CAboutDlg 对话框
//************************************************************************************************
int i = 5;//横坐标
int j = 0;//纵坐标
int n = 0;//掉落
int m = 700;//背景偏移量
int m2 = 0;
int m1 = -656.8;//拼接背景偏移量
int m3 = -420;//第二组柱子偏移量
int temp = 0;
int temp1 = 50;
//int m_BirdX= 60+i;//鸟横坐标1
int m_BirdX1 = 60 + i;//鸟横坐标2
int m_BirdY= 60 - j + n;//鸟纵坐标
int m_BirdY1= -230 - temp;//上1柱子高度
int m_BirdY2 = -230 - temp;//下1柱子高度
int m_BirdY3 = -230 - temp;//上2柱子高度
int m_BirdY4 = -230 - temp;//下2柱子高度
int number=0;//Yushu
int number1=0;//zhengshu
int fast = 0;//管道1移动
int fast1 = 0;//管道2移动
int times = 0;//得分循环
int times1 = 0;//得分循环
int life=1;//生命值
int once = 0;
int lifeStep = 0;//生命值辅助参数
int judge = 0;//判断
int pause1 = 0;

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
public:
	afx_msg void OnPaint();
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedDialog();
};
float CFlappyBirdDlg::Get_By()
{
	return m_By;
}
CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{


	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
	ON_WM_PAINT()
	ON_BN_CLICKED(IDOK, &CAboutDlg::OnBnClickedOk)
  ON_BN_CLICKED(IDC_BUTTON1, &CAboutDlg::OnBnClickedButton1)
//  ON_BN_CLICKED(IDD_DIALOG1, &CAboutDlg::OnBnClickedDialog)
END_MESSAGE_MAP()


// CFlappyBirdDlg 对话框



CFlappyBirdDlg::CFlappyBirdDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_FLAPPYBIRD_DIALOG,pParent)
	, m_score(0)
	
{
	//	m_cTest = new CTestDlg(this);//IDD_DIALOG1为子窗口ID;
	m_Test = new CTestDlg(this);
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	//  score = 0;
}

void CFlappyBirdDlg::DoDataExchange(CDataExchange* pDX)
{
	
	//  DDX_Control(pDX, IDC_EDIT1, m_score);
	//DDX_Text(pDX, IDC_EDIT1, m_score);
	CDialogEx::DoDataExchange(pDX);
	HBITMAP   hBitmap;
	hBitmap = LoadBitmap(AfxGetInstanceHandle(),
		MAKEINTRESOURCE(IDB_BITMAP3));
	((CButton *)GetDlgItem(IDC_BUTTON2))->SetBitmap(hBitmap);


	CDialogEx::DoDataExchange(pDX);
//	HBITMAP   hBitmap;
	hBitmap = LoadBitmap(AfxGetInstanceHandle(),
		MAKEINTRESOURCE(IDB_BITMAP2));
	((CButton *)GetDlgItem(IDC_BUTTON3))->SetBitmap(hBitmap);
	//CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CFlappyBirdDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CFlappyBirdDlg::OnBnClickedOk)
	ON_WM_TIMER()
	ON_WM_LBUTTONDOWN()
//	ON_WM_NCPAINT()
ON_BN_CLICKED(IDC_BUTTON1, &CFlappyBirdDlg::OnBnClickedButton1)
ON_WM_ERASEBKGND()
ON_BN_CLICKED(IDC_BUTTON2, &CFlappyBirdDlg::OnBnClickedButton2)
ON_BN_CLICKED(IDC_BUTTON3, &CFlappyBirdDlg::OnBnClickedButton3)
END_MESSAGE_MAP()


// CFlappyBirdDlg 消息处理程序
BOOL PreCreateWindow(CREATESTRUCT& m_cTest)
{
	return 0;
}
BOOL CFlappyBirdDlg::OnInitDialog()
{
	
	CDialogEx::OnInitDialog();

	
	//IDB_BITMAP1为位图资源ID ，IDC_BT_BYTE为按钮ID


	//m_cTest.Create(IDD_ABOUTBOX, this);
	//m_cTest.ShowWindow(SW_SHOW);
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

	SetWindowPos(NULL, 0, 0, 664,487, SWP_NOMOVE);//把窗口放到左下端
	m_fly.Load(TEXT("res//beijing1.bmp"));//背景
	m_fly1.Load(TEXT("res//beijing1.bmp"));//背景
	m_UpColumn.Load(TEXT("res//up.bmp"));//背景
	m_DownColumn.Load(TEXT("res//down.bmp"));//背景
	m_background.Load(TEXT("res//over.bmp"));
	m_bird[0].Load(TEXT("res//a.png"));//鸟
	m_bird[1].Load(TEXT("res//b.png"));
	m_bird[2].Load(TEXT("res//c.png"));
	heart.Load(TEXT("res//heart.png"));
	SetTimer(1, 100, NULL);//定时器1
	//SetTimer(9, 1, NULL);//定时器1
	Num[0].Load(TEXT("res//font_048.png"));//0
	Num[1].Load(TEXT("res//font_049.png"));//1
	Num[2].Load(TEXT("res//font_050.png"));//2
	Num[3].Load(TEXT("res//font_051.png"));//3
	Num[4].Load(TEXT("res//font_052.png"));//4
	Num[5].Load(TEXT("res//font_053.png"));//5
	Num[6].Load(TEXT("res//font_054.png"));//6
	Num[7].Load(TEXT("res//font_055.png"));//7
	Num[8].Load(TEXT("res//font_056.png"));//8
	Num[9].Load(TEXT("res//font_057.png"));//9
	pause.Load(TEXT("res//pause.png"));//暂停
	resume.Load(TEXT("res//resume.png"));//继续









	// TODO: 在此添加额外的初始化代码
	
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CFlappyBirdDlg::OnSysCommand(UINT nID, LPARAM lParam)
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



void CAboutDlg::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: 在此处添加消息处理程序代码
					   // 不为绘图消息调用 CDialogEx::OnPaint()
	CBitmap   bitmap;                            //定义位图
	bitmap.LoadBitmap(IDB_BITMAP7);    //这个IDB_BITMAP1要自己添加
	CBrush   brush;
	brush.CreatePatternBrush(&bitmap);
	CBrush*   pOldBrush = dc.SelectObject(&brush);
	dc.Rectangle(0, 0, 664, 487);                  //前两个为图片起始位置，后两个为图片终点位置，实际为图片的像素大小
	dc.SelectObject(pOldBrush);

	
	/*HBITMAP   hBitmap;
	hBitmap = LoadBitmap(AfxGetInstanceHandle(),
		MAKEINTRESOURCE(IDB_BITMAP10));
	((CButton *)GetDlgItem(IDC_restart)->SetBitmap(hBitmap);*/


}
void CFlappyBirdDlg::OnPaint()
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
		
	
		CPaintDC dc(this);
		m_fly.Draw(dc, 0, 0, 664,487);//显示背景
		m_bird->Draw(dc, 60, 60, 45, 34);//显示鸟

	

		CDialogEx::OnPaint();

	
		
}
	}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CFlappyBirdDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CFlappyBirdDlg::OnBnClickedOk()
{
	
	CAboutDlg dlg;
	this->OnOK();
	dlg.DoModal();
	
}






void CAboutDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码

	CFlappyBirdDlg dlg;
	this->OnOK();
	dlg.DoModal();
}

//*******************************************************************************************************
void CFlappyBirdDlg::OnTimer(UINT_PTR nIDEvent)
{
	CPaintDC dc(this);
	// TODO: 在此添加消息处理程序代码和/或调用默认值
int t = 0;
	int m_BirdY = 60 - j + n;
	int m_Birdx = 60 - j + n;
	
	//若鸟未碰撞，t=0;
	/*m_UpColumn.Draw(dc, 664 - m, -230 - temp+fast, 55, 388);//上柱子
		m_DownColumn.Draw(dc, 664 - m, 300 - temp + fast, 55, 389);//下柱子
	
	    m_UpColumn.Draw(dc, 664 - m3, -230 - temp1 + fast1, 55, 388);//上柱子2
		m_DownColumn.Draw(dc, 664 - m3, 300 - temp1 + fast1, 55, 389);//下柱子2
		TransparentPNG(&m_bird[1]);
		m_bird[1].Draw(dc, 60 + i, 60 - j + n, 45, 34);*/
	
//	if (m_Birdx >= 400 || m_Birdx <= -23||((560- m3 <=i)&& i <= 610 - m3&&((m_BirdY < (140 - temp1+fast1)) ||m_BirdY>(295 - temp1+fast1)))||( 560 - m2 <= i
	//	&& i <= 610 - m2 && (m_BirdY < ((140 - temp + fast)) || m_BirdY >(295 - temp + fast))))
	if (m_Birdx >= 400 || m_Birdx <= -23 || ((560 - m3 <= i) && i <= 610 - m3 && ((m_BirdY < (140 - temp1 + fast1)) || m_BirdY > (295 - temp1 + fast1))) || (560 - m2 <= i
		&& i <= 610 - m2 && (m_BirdY < ((140 - temp + fast)) || m_BirdY >(295 - temp + fast))))
	{
		if (life <1)
		{
			t = 1;
			once = once + 1;
			if (score > best)
			{
				best = score;
			}
		}
		else {
			if (judge == 0)
			{
				life = life - 1;
				judge = 1;
			}
		}

	}
		if (nIDEvent == 1  && t ==0 && pause1!=1)
	{
		timer_1();
	}
		
	
	
	
	if (once==1)
	{
		COver1 dlg;
		//this->OnOK();
		dlg.DoModal();
		once++;
		//重置
		//if (restart != 0)
	//	{
		ScoreTemp = score;
			i = 5;//横坐标
			j = 0;//纵坐标
			n = 0;//掉落
			m = 700;//背景偏移量
			m2 = 0;
			m1 = -656.8;//拼接背景偏移量
			m3 = -420;//第二组柱子偏移量
			temp = 0;
			temp1 = 50;
			//int m_BirdX= 60+i;//鸟横坐标1
			m_BirdX1 = 60 + i;//鸟横坐标2
			m_BirdY = 60 - j + n;//鸟纵坐标

		//	m_Score = 0;//得分
			once = 0;
			m_Birdx = 60 - j + n;
			t = 0;
			restart = 0;
			
			score = 0;
	//	}
	// score.SetDlgItemText(IDC_EDIT1,m_Score);
	}
	
}

void CFlappyBirdDlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	
	CDialogEx::OnLButtonDown(nFlags, point);
    j = j + 60;

	
	PlaySound((LPCTSTR)IDR_WAVE2, AfxGetInstanceHandle(), SND_RESOURCE | SND_ASYNC);
}
//*****************************************************************************************************************
void CFlappyBirdDlg::timer_1()
{
	// TODO: 在此处添加实现代码.
	CClientDC dc(this);
	
	
	m_fly.Draw(dc, 0, 0, 664, 487);

	n = n + 8;
	m = m + 10;
	m2 = m2 + 10;
	m1 = m1 + 10;
	m3 = m3 + 10;
	//int fast = 0;//管道移动

	if (i <= 250)
	{
		i = i + 1.5;
	}
		static int position = 0;
		switch (position)
		{
		case 0://状态1

		{
			m_fly.Draw(dc, 0 - m, 0, 664, 487);//显示背景
		m_fly1.Draw(dc, 8 - m1, 0, 664, 487);//显示背景
		if (m >= 664)
		{
			m = 0;
			m2 = 0;
			m1 = -656.8;
			temp = random(200);//管道偏移量
			times = 0;
			fast = 0;
		}
		if (m3 >= 664)
		{
			m3 = 0;
			temp1 = random(200);//管道偏移量
			times1 = 0;
			fast1 = 0;
		}
	if (score >= 2)
			{
			fast = fast + 2;
			fast1 = fast1 + 2;
			if (score >= 4)
		{

			m = m + 6;
			m1 = m1 + 6;
			m3 = m3 + 6;
			
		}}
	
		m_UpColumn.Draw(dc, 664 - m, -230 - temp + fast, 55, 388);//上柱子1
		m_DownColumn.Draw(dc, 664 - m, 300 - temp + fast, 55, 389);//下柱子1
		
		m_UpColumn.Draw(dc, 664 - m3, -230 - temp1 + fast1, 55, 388);//上柱子2
		m_DownColumn.Draw(dc, 664 - m3, 300 - temp1 + fast1, 55, 389);//下柱子2
		TransparentPNG(&m_bird[0]);
		m_bird[0].Draw(dc, 60 + i, 60 - j + n, 45, 34);
		pause.Draw(dc, 23, 24, 26, 28);
		resume.Draw(dc, 75, 24, 26, 28);
		//////////////////////////////////////////////
		TransparentPNG(&heart);
		heart.Draw(dc, 530, 30, 35, 32);//显示生命值
		m_BirdY = 60 - j + n;
		if (60 + i >= 664 - m && times == 0)
		{
			lifeStep++;
			score++;
			times++;
		}
		if (60 + i >= 664 - m3 && times1 == 0)
		{
			lifeStep++;
			score++;
			times1++;
		}
     if (lifeStep>4)
	{
		life ++;
		lifeStep =0;

	}
	
		number = score % 10;//Yushu
		number1 = (score - number) /10;//zhengshu
		Num[number1].Draw(dc, 300, 50,24, 44);
		Num[number].Draw(dc, 326, 50, 24, 44);
		Num[life].Draw(dc, 580, 25, 24, 44);
		if (i > 610 - m3 || i > 610 - m2)
			judge = 0;
		position++;
		break;
		}
		case 1://状态2

		{	m_fly.Draw(dc, 0 - m, 0, 664, 487);//显示背景
		m_fly1.Draw(dc, 8 - m1, 0, 664, 487);//显示背景
		if (m >= 664)
		{
			m = 0;
			m2 = 0;
			m1 = -656.8;
			temp = random(200);//管道偏移量
			times = 0;
			fast = 0;
		}
		if (m3 >= 664)
		{
			m3 = 0;
			temp1 = random(200);//管道偏移量
			times1 = 0;
			
			fast1 = 0;

		}
		if (score >= 2)
		{
			fast = fast + 2;
			fast1 = fast1 + 2;
			if (score >= 4)
			{

				m = m + 6;
				m1 = m1 + 6;
				m3 = m3 + 6;

			}
		}
		m_UpColumn.Draw(dc, 664 - m, -230 - temp+fast, 55, 388);//上柱子
		m_DownColumn.Draw(dc, 664 - m, 300 - temp + fast, 55, 389);//下柱子
	
	    m_UpColumn.Draw(dc, 664 - m3, -230 - temp1 + fast1, 55, 388);//上柱子2
		m_DownColumn.Draw(dc, 664 - m3, 300 - temp1 + fast1, 55, 389);//下柱子2
		TransparentPNG(&m_bird[1]);
		m_bird[1].Draw(dc, 60 + i, 60 - j + n, 45, 34);
		pause.Draw(dc, 23, 24, 26, 28);
		resume.Draw(dc, 75, 24, 26, 28);

		////////////////////////////////////////////
		TransparentPNG(&heart);
		heart.Draw(dc,530, 30, 35,32);//显示生命值
		if (60 + i >= 664 - m && times == 0)
		{
			score++;
			times++;
			lifeStep++;
		}
		if (60 + i >= 664 - m3 && times1 == 0)
		{
			score++;
			times1++;
			lifeStep++;

		}
		if (lifeStep >4)
		{
			life = life + 1;
			lifeStep =0;

		}

		number = score % 10;//Yushu
		number1 = (score - number) / 10;//zhengshu
		Num[number1].Draw(dc, 300, 50, 24, 44);
		Num[number].Draw(dc, 326, 50, 24, 44);
		Num[life].Draw(dc, 580, 25, 24, 44);
		if (i >610 - m3 || i >610 - m2)
			judge = 0;
		position++;
		break;
		}
		//*********************************************************************
		case 2://状态3

		{m_fly.Draw(dc, 0 - m, 0, 664, 487);//显示背景
		m_fly1.Draw(dc, 8 - m1, 0, 664, 487);//显示背景
		if (m >= 664)
		{
			m = 0;
			m2 = 0;
			m1 = -656.8;
			temp = random(200);//管道偏移量
			times = 0;
			fast = 0;
			
		}
		if (m3 >= 664)
		{
			m3 = 0;
			temp1 = random(200);//管道偏移量
			times1 = 0;
			
			fast1 = 0;
		}
		if (score >= 2)
		{
			fast = fast + 2;
			fast1 = fast1 + 2;
			if (score >= 4)
			{

				m = m + 6;
				m1 = m1 + 6;
				m3 = m3 + 6;

			}
		}
		m_UpColumn.Draw(dc, 664 - m, -230 - temp+fast, 55, 388);//上柱子
		m_DownColumn.Draw(dc, 664 - m, 300 - temp + fast, 55, 389);//下柱子

		m_UpColumn.Draw(dc, 664-m3, -230 - temp1 + fast1, 55, 388);//上柱子2
		
		m_DownColumn.Draw(dc, 664 - m3, 300 - temp1 + fast1, 55, 389);//下柱子2

		TransparentPNG(&m_bird[2]);
		m_bird[2].Draw(dc, 60 + i, 60 - j + n, 45, 34);//鸟
		pause.Draw(dc, 23, 24, 26, 28);
		resume.Draw(dc, 75, 24, 26, 28);
		//////////////////////////////////////////////////////
		TransparentPNG(&heart);
		heart.Draw(dc, 530, 30,35, 32);//显示生命值
		if (60 + i >= 664 - m && times == 0)
		{
			lifeStep++;
			score++;
			times++;
		}
		if (60 + i >= 664 - m3 && times1 == 0)
		{
			lifeStep++;
			score++;
			times1++;
		}if (lifeStep>4)
		{
			life++;
			lifeStep =0;

		}
	
		number = score %10;//Yushu
		number1 = (score - number) /10;//zhengshu
		Num[number1].Draw(dc, 300, 50, 24, 44);
		Num[number].Draw(dc, 326, 50, 24, 44);
		Num[life].Draw(dc, 580, 25, 24, 44);
		if (i > 610 - m3 || i >610 - m2)
			judge = 0;
		position=0;
		break;
		}
		}
}


BOOL CFlappyBirdDlg::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 在此添加专用代码和/或调用基类
	
	
	
	return CDialogEx::PreTranslateMessage(pMsg);
}


void CAboutDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	CExplainDlg dlg;

	dlg.DoModal();
}





void CFlappyBirdDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	CTestDlg dlg;
	this->OnOK();
	dlg.DoModal();
}

BOOL CFlappyBirdDlg::OnEraseBkgnd(CDC* pDC)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	return FALSE;
}
void CFlappyBirdDlg::TransparentPNG(CImage* png)
{
	for (int i = 0; i < png->GetWidth(); i++)
	{
		for (int j = 0; j < png->GetHeight(); j++)
		{
			unsigned char* pucColor = reinterpret_cast<unsigned char*>(png->GetPixelAddress(i, j));
			pucColor[0] = pucColor[0] * pucColor[3] / 255;
			pucColor[1] = pucColor[1] * pucColor[3] / 255;
			pucColor[2] = pucColor[2] * pucColor[3] / 255;
		}
	}
}
int CFlappyBirdDlg:: getScore() {
	return score;
}
int CFlappyBirdDlg::getBest() {
	return best;
}


void CFlappyBirdDlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	pause1 = 1;
}


void CFlappyBirdDlg::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	pause1 = 0;
}
