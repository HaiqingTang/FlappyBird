
// FlappyBirdDlg.h: 头文件
//

#pragma once
#include"CTestDlg.h"
static int score = 0;//得分
static int restart = 0;
static int best = 0;//最高分
static int score1 = 0;//得分传值
static int ScoreTemp = 0;
// CFlappyBirdDlg 对话框
class CFlappyBirdDlg : public CDialogEx
{
// 构造
public:
	CFlappyBirdDlg(CWnd* pParent = nullptr);	// 标准构造函数
	CTestDlg m_cTest;
	CTestDlg *m_Test;
	float Get_By();
	float m_By;//鸟儿的y坐标
	int m_Bx;//鸟儿的x坐标
	
// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_FLAPPYBIRD_DIALOG };
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
	afx_msg void OnBnClickedOk();
	void reset();

	void TransparentPNG(CImage* png);


	CImage m_bird[3];
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	void timer_1();
	void timer_2();
	void timer_3();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	CImage m_fly;
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
//	afx_msg void OnNcPaint();
	CImage m_fly1;
	afx_msg void OnBnClickedButton1();
	CImage m_UpColumn;
	CImage m_DownColumn;
	CImage m_background;
//	int score;
//	CEdit m_Score;
//	int m_score;
	int m_score;
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	CImage Num[10];
	CImage heart;
	int getScore();
	int getBest();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	CImage pause;
	CImage resume;
};
