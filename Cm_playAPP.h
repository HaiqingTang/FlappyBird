#pragma once


// Cm_playAPP 对话框

class Cm_playAPP : public CDialogEx
{
	DECLARE_DYNAMIC(Cm_playAPP)

public:
	Cm_playAPP(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~Cm_playAPP();
	BOOL OnInitDialog();
	HICON m_hIcon;
// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG4 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedfilechoice();
	afx_msg void OnBnClickedplay();
	afx_msg void OnBnClickedpause();
	afx_msg void OnBnClickedstop();
	afx_msg void OnNMCustomdrawSlider1(NMHDR *pNMHDR, LRESULT *pResult);
	CSliderCtrl m_slider1;
	CString m_int;
	
	int m_slider;
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
};
