
// 懒汉式线程同步Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "懒汉式线程同步.h"
#include "懒汉式线程同步Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// C懒汉式线程同步Dlg 对话框




C懒汉式线程同步Dlg::C懒汉式线程同步Dlg(CWnd* pParent /*=NULL*/)
		: CDialogEx(C懒汉式线程同步Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void C懒汉式线程同步Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(C懒汉式线程同步Dlg, CDialogEx)
ON_WM_SYSCOMMAND()
ON_WM_PAINT()
ON_WM_QUERYDRAGICON()
ON_BN_CLICKED(IDC_BUTTON1, &C懒汉式线程同步Dlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// C懒汉式线程同步Dlg 消息处理程序

BOOL C懒汉式线程同步Dlg::OnInitDialog()
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

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void C懒汉式线程同步Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void C懒汉式线程同步Dlg::OnPaint()
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
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR C懒汉式线程同步Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


//////////////////////////////////////////////////////////////////////////

//临界区
static CCriticalSection cs;

class Singleton
{
private:
	Singleton()
	{
		m_count ++;
		TRACE("Singleton begin\n");
		Sleep(1000);
		TRACE("Singleton end\n");

	}
	Singleton(const Singleton &);
	Singleton& operator = (const Singleton &);

public:
	static void printV()
	{
		TRACE("printV..m_count:%d \n", m_count);
	}
	static Singleton *Instantialize()
	{
		if(pInstance == NULL)  //double check
		{
			//cs.Lock(); //只有当pInstance等于null时，才开始使用枷锁机制 二次检查
			if(pInstance == NULL)
			{
				pInstance = new Singleton();
			}
			//cs.Unlock();
		}
		return pInstance;
	}
	static Singleton *pInstance;
	static int m_count;

};

Singleton* Singleton::pInstance = 0;
int Singleton::m_count = 0;

//////////////////////////////////////////////////////////////////////////

void threadfunc(void *myIpAdd)
{
	Singleton::Instantialize()->printV();
}


void C懒汉式线程同步Dlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	//AfxMessageBox("hello....");

	int i = 0;
	DWORD dwThreadId[201], dwThrdParam = 1;
	HANDLE hThread[201];
	int threadnum = 3;

	for (i=0; i<threadnum; i++)
	{
		//hThread[i] = (HANDLE)_beginthreadex( NULL, 0, &threadfunc, NULL, 0,&dwThreadId[i] );
		hThread[i] = (HANDLE)_beginthread(&threadfunc, 0 , 0 );
		if (hThread[i] == NULL)
		{
			TRACE("begin thread %d error!!!\n", i);
			break;
		}
	}

	for (i=0; i<threadnum; i++)
	{
		WaitForSingleObject( hThread[i], INFINITE );
	}

}
