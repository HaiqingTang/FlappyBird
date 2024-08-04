#pragma once


// COver1 对话框

class COver1 : public CDialogEx
{
	DECLARE_DYNAMIC(COver1)

public:
	COver1(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~COver1();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG3 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
	afx_msg void OnBnClickedOk();
//	CButtom m_Btn;
	CImage num[10];
	CButton m_Btn;
	CImage medal[3];
	afx_msg void OnBnClickedButton1();
	CImage rank;
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
};
