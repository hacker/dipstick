// OptionsDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Dipstick.h"
#include "OptionsDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// COptionsDlg dialog


COptionsDlg::COptionsDlg(CWnd* pParent /*=NULL*/)
	: CDialog(COptionsDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(COptionsDlg)
	m_Pings = 0;
	m_PingSize = 0;
	m_TimeOut = 0;
	m_Interval = 0;
	m_MaxThreads = 0;
	m_bMSWorkAround = FALSE;
	m_bAutoBest = FALSE;
	m_bAdjustInn = FALSE;
	m_bIgnorelative = FALSE;
	m_bAdjust = FALSE;
	//}}AFX_DATA_INIT
}


void COptionsDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(COptionsDlg)
	DDX_Control(pDX, IDC_SPINTIMEOUT, m_SpinTimeOutCtl);
	DDX_Control(pDX, IDC_SPINTERVAL, m_SpinIntervalCtl);
	DDX_Control(pDX, IDC_SPINSIZE, m_SpinPingSizeCtl);
	DDX_Control(pDX, IDC_SPINPINGS, m_SpinPingsCtl);
	DDX_Control(pDX, IDC_SPINMAXPINGS, m_SpinMaxThreadsCtl);
	DDX_Text(pDX, IDC_NPINGS, m_Pings);
	DDX_Text(pDX, IDC_PACKETSIZE, m_PingSize);
	DDX_Text(pDX, IDC_TIMEOUT, m_TimeOut);
	DDX_Text(pDX, IDC_INTERVAL, m_Interval);
	DDX_Text(pDX, IDC_MAXPINGS, m_MaxThreads);
	DDV_MinMaxUInt(pDX, m_MaxThreads, 1, 100);
	DDX_Check(pDX, IDC_MSWORKAROUND, m_bMSWorkAround);
	DDX_Check(pDX, IDC_AUTOBEST, m_bAutoBest);
	DDX_Check(pDX, IDC_ADJUSTINN, m_bAdjustInn);
	DDX_Check(pDX, IDC_IGNORELA, m_bIgnorelative);
	DDX_Check(pDX, IDC_SMARTADJUST, m_bAdjust);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(COptionsDlg, CDialog)
	//{{AFX_MSG_MAP(COptionsDlg)
	ON_WM_HELPINFO()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// COptionsDlg message handlers

BOOL COptionsDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	m_SpinIntervalCtl.SetRange(0,60);
	m_SpinMaxThreadsCtl.SetRange(1,50);
	m_SpinPingsCtl.SetRange(1,100);
	m_SpinPingSizeCtl.SetRange(0,32767);
	m_SpinTimeOutCtl.SetRange(1,60);

	return TRUE;
}

BOOL COptionsDlg::OnHelpInfo(HELPINFO* pHelpInfo) 
{
	WinHelp(IDD|0x20000l);
	return TRUE;
}
