// Cm_playAPP.cpp: 实现文件
//

#include "pch.h"
#include "FlappyBird.h"
#include "Cm_playAPP.h"
#include "afxdialogex.h"
#include <MMSystem.h>
#include <Digitalv.h>

#pragma comment(lib, "Winmm.lib")

//定义三个全局变量
HWND m_hWnd;
DWORD DeviceId;
MCI_OPEN_PARMS mciopenparms;

//加载


// Cm_playAPP 对话框

IMPLEMENT_DYNAMIC(Cm_playAPP, CDialogEx)

Cm_playAPP::Cm_playAPP(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG4, pParent)
	, m_int(_T(""))
	, m_slider(0)
{

}

Cm_playAPP::~Cm_playAPP()
{
}

void Cm_playAPP::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_SLIDER1, m_slider1);
	DDX_Text(pDX, IDC_volume, m_int);
	DDX_Slider(pDX, IDC_SLIDER1, m_slider);
}


BEGIN_MESSAGE_MAP(Cm_playAPP, CDialogEx)
	ON_BN_CLICKED(IDC_filechoice, &Cm_playAPP::OnBnClickedfilechoice)
	ON_BN_CLICKED(IDC_play, &Cm_playAPP::OnBnClickedplay)
	ON_BN_CLICKED(IDC_pause, &Cm_playAPP::OnBnClickedpause)
	ON_BN_CLICKED(IDC_stop, &Cm_playAPP::OnBnClickedstop)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER1, &Cm_playAPP::OnNMCustomdrawSlider1)
	ON_WM_HSCROLL()
END_MESSAGE_MAP()

void Load(HWND hWnd, CString strFilepath)
{
	m_hWnd = hWnd;
	mciSendCommand(DeviceId, MCI_CLOSE, 0, 0); //在加载文件前先清空上一次播放的设备
	mciopenparms.lpstrElementName = strFilepath; //将音乐文件路径传给设备
	DWORD dwReturn;
	if (dwReturn = mciSendCommand(NULL, MCI_OPEN, MCI_OPEN_ELEMENT | MCI_WAIT, (DWORD)(LPVOID)&mciopenparms))
	{
		//如果打开玩家失败,将出错信息储存在buffer,并显示出错警告
		char buffer[256];
		mciGetErrorString(dwReturn, buffer, 256); //获取错误码对应的错误信息
		MessageBox(hWnd, buffer, "出错警告！", MB_ICONHAND | MB_ICONERROR | MB_ICONSTOP); //弹出错误信息提示对话框
	}
	DeviceId = mciopenparms.wDeviceID;
	//打开文件成功就关联文件到设备
}
void play()
{
	MCI_PLAY_PARMS mciplayparms;
	mciplayparms.dwCallback = (DWORD)m_hWnd;
	mciplayparms.dwFrom = 0; //每次播放都是从0开始播放
	mciSendCommand(DeviceId, MCI_PLAY, MCI_FROM | MCI_NOTIFY, (DWORD)(LPVOID)&mciplayparms);
}
void pause()
{
	mciSendCommand(DeviceId, MCI_PAUSE, 0, 0);
}
void resume()
{
	mciSendCommand(DeviceId, MCI_RESUME, 0, 0);
}

void stop()
{
	mciSendCommand(DeviceId, MCI_STOP, 0, 0);
	mciSendCommand(DeviceId, MCI_CLOSE, 0, 0);
	//当点击停止按钮时,将所有的信息都清除掉
}

DWORD setVolume(DWORD vol)
{
	MCI_DGV_SETAUDIO_PARMS setvolume; //设置音量的参数结构体
	setvolume.dwCallback = NULL; //
	setvolume.dwItem = MCI_DGV_SETAUDIO_VOLUME; //动作是设置音量
	setvolume.dwValue = vol; //音量值是vol
	mciSendCommand(DeviceId, MCI_SETAUDIO, MCI_DGV_SETAUDIO_ITEM | MCI_DGV_SETAUDIO_VALUE, (DWORD)(LPVOID)&setvolume);
	return 0;
}


void Cm_playAPP::OnBnClickedfilechoice()
{
	// TODO: 在此添加控件通知处理程序代码
	char szFileFilter[] = "mp3文件(*.mp3)|*.mp3|"
		"wma文件(*.wma)|*.wma|"
		"wav文件(*.wav)|*.wav|"
		"所有文件(*.*)|*.*|";
	CFileDialog dlg (true, NULL, NULL, OFN_HIDEREADONLY, szFileFilter);
	if (dlg.DoModal() == IDOK)
	{
		CString strFilepath = dlg.GetPathName();
		CString strFilename = dlg.GetFileName();
		SetDlgItemText(IDC_filename, strFilename);
		Load(this->m_hWnd, strFilepath);
	}
	GetDlgItem(IDC_play)->EnableWindow(true); //文件读取成功时所有按钮变成可选
	GetDlgItem(IDC_pause)->EnableWindow(true);
	GetDlgItem(IDC_stop)->EnableWindow(true);

}


void Cm_playAPP::OnBnClickedplay()
{
	// TODO: 在此添加控件通知处理程序代码
	play();
	SetDlgItemText(IDC_pause, _T("暂停"));
}


void Cm_playAPP::OnBnClickedpause()
{
	// TODO: 在此添加控件通知处理程序代码
	CString strTemp;
	GetDlgItemText(IDC_pause, strTemp); //获取按钮的状态
	if (strTemp.Compare(_T("暂停")) == 0)
	{
		pause();
		SetDlgItemText(IDC_pause, _T("恢复"));
	}

	if (strTemp.Compare(_T("恢复")) == 0)
	{
		resume();
		SetDlgItemText(IDC_pause, _T("暂停"));
	}

}


void Cm_playAPP::OnBnClickedstop()
{
	// TODO: 在此添加控件通知处理程序代码
	stop();
	SetDlgItemText(IDC_pause,_T("暂停"));
	GetDlgItem(IDC_play)->EnableWindow(false); //当按下stop的时候,播放和暂停不可选
	GetDlgItem(IDC_pause)->EnableWindow(false);
}


void Cm_playAPP::OnNMCustomdrawSlider1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	m_int == m_slider1.GetPos() / 10;
	setVolume(m_slider1.GetPos());
	UpdateData(false);
	//*pResult = 0;

	*pResult = 0;
}


void Cm_playAPP::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	
	//int pos = m_slider1.GetScrollPos(0);    // 获取水平滚动条当前位置  
	int pos = m_slider1.GetScrollPos(nPos);
	switch (nSBCode)
	{
		// 如果向左滚动一列，则pos减1  
	case SB_LINELEFT:
		pos -= 1;
		break;
		// 如果向右滚动一列，则pos加1  
	case SB_LINERIGHT:
		pos += 1;
		break;
		// 如果向左滚动一页，则pos减10  
	case SB_PAGELEFT:
		pos -= 10;
		break;
		// 如果向右滚动一页，则pos加10  
	case SB_PAGERIGHT:
		pos += 10;
		break;
		// 如果滚动到最左端，则pos为1  
	case SB_LEFT:
		pos = 1;
		break;
		// 如果滚动到最右端，则pos为100  
	case SB_RIGHT:
		pos = 100;
		break;
		// 如果拖动滚动块滚动到指定位置，则pos赋值为nPos的值  
	case SB_THUMBPOSITION:
		pos = nPos;
		break;
		// 下面的m_horiScrollbar.SetScrollPos(pos);执行时会第二次进入此函数，最终确定滚动块位置，并且会直接到default分支，所以在此处设置编辑框中显示数值  
	default:
		SetDlgItemInt(IDC_volume, pos);
		return;
	}

	// 设置滚动块位置  
	//pos=slider1.SetScrollPos(Pos, BOOL bRedraw = TRUE);
	pos = m_slider1.GetScrollPos(pos);

	//setVolume(pos);

	CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
}
BOOL Cm_playAPP::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
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

	// TODO:  在此添加额外的初始化代码
	m_slider1.SetRange(0, 1000);
	// 设置水平滚动条的初始位置为200   
	m_slider1.SetPos(200);
	// 在编辑框中显示200  
	SetDlgItemInt(IDC_volume, 200);
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}
