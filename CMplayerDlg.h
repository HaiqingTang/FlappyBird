#pragma once


// CMplayerDlg 对话框

class CMplayerDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CMplayerDlg)

public:
	CMplayerDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CMplayerDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG4 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
