// CMplayerDlg.cpp: 实现文件
//

#include "pch.h"
#include "FlappyBird.h"
#include "CMplayerDlg.h"
#include "afxdialogex.h"


// CMplayerDlg 对话框

IMPLEMENT_DYNAMIC(CMplayerDlg, CDialogEx)

CMplayerDlg::CMplayerDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG4, pParent)
{

}

CMplayerDlg::~CMplayerDlg()
{
}

void CMplayerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CMplayerDlg, CDialogEx)
END_MESSAGE_MAP()


// CMplayerDlg 消息处理程序
