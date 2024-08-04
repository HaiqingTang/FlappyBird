#pragma once


// COver 对话框

class COver : public CDialogEx
{
	DECLARE_DYNAMIC(COver)

public:
	COver(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~COver();
	afx_msg void OnPaint();
// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	CImage m_over;
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnBnClickedButton1();
//	int score;
//	CEdit best;
	afx_msg void OnBnClickedrestart();
	afx_msg void OnBnClickedBotton1();
	afx_msg void OnBnClickedButton2();
	CButton m_Btn;
	afx_msg void OnEnChangeEdit2();
	int m_score;
	CImage num[10];
};
