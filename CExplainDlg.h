#pragma once


// CExplainDlg 对话框

class CExplainDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CExplainDlg)

public:
	CExplainDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CExplainDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
