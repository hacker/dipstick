// HostProperties.cpp : implementation file
//

#include "stdafx.h"
#include "Dipstick.h"
#include "HostProperties.h"
#include "DipstickDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CHostProperties dialog


CHostProperties::CHostProperties(CWnd* pParent /*=NULL*/)
	: CDialog(CHostProperties::IDD, pParent)
{
	//{{AFX_DATA_INIT(CHostProperties)
	m_Host = _T("");
	m_IP = _T("");
	m_Loss = _T("");
	m_Status = _T("");
	m_Times = _T("");
	m_URL = _T("");
	//}}AFX_DATA_INIT
}


void CHostProperties::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CHostProperties)
	DDX_Control(pDX, IDC_STATE, m_StateCtl);
	DDX_Control(pDX, IDC_URLCAPTION, m_URLCaptionCtl);
	DDX_Control(pDX, IDC_URL, m_URLCtl);
	DDX_Control(pDX, IDC_TIMESCAPTION, m_TimesCaptionCtl);
	DDX_Control(pDX, IDC_TIMES, m_TimesCtl);
	DDX_Control(pDX, IDC_STATUSCAPTION, m_StatusCaptionCtl);
	DDX_Control(pDX, IDC_STATUS, m_StatusCtl);
	DDX_Control(pDX, IDC_OPENURL, m_OpenURLCtl);
	DDX_Control(pDX, IDC_LOSSCAPTION, m_LossCaptionCtl);
	DDX_Control(pDX, IDC_LOSS, m_LossCtl);
	DDX_Control(pDX, IDC_IPCAPTION, m_IPCaptionCtl);
	DDX_Control(pDX, IDC_IP, m_IPCtl);
	DDX_Control(pDX, IDC_HOSTCAPTION, m_HostCaptionCtl);
	DDX_Control(pDX, IDC_HOST, m_HostCtl);
	DDX_Text(pDX, IDC_HOST, m_Host);
	DDX_Text(pDX, IDC_IP, m_IP);
	DDX_Text(pDX, IDC_LOSS, m_Loss);
	DDX_Text(pDX, IDC_STATUS, m_Status);
	DDX_Text(pDX, IDC_TIMES, m_Times);
	DDX_Text(pDX, IDC_URL, m_URL);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CHostProperties, CDialog)
	//{{AFX_MSG_MAP(CHostProperties)
	ON_BN_CLICKED(IDC_OPENURL, OnOpenurl)
	ON_WM_HELPINFO()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CHostProperties message handlers

BOOL CHostProperties::OnInitDialog() 
{
	CDialog::OnInitDialog();

	ASSERT(host);
	if(host->m_HostName.IsEmpty()){
		m_HostCtl.ShowWindow(SW_HIDE);
		m_HostCaptionCtl.ShowWindow(SW_HIDE);
	}else
		m_Host = host->m_HostName;
	if(host->m_IP)
		m_IP = inet_ntoa(*(in_addr*)&host->m_IP);
	else{
		m_IPCtl.ShowWindow(SW_HIDE);
		m_IPCaptionCtl.ShowWindow(SW_HIDE);
	}
	if(host->m_Pinged){
		m_Loss.Format(IDS_FMT_LOSS,host->m_Packetloss);
		m_Times.Format(IDS_FMT_TIMES,host->m_MinRTT,host->m_AvgRTT,host->m_MaxRTT);
	}else{
		m_LossCtl.ShowWindow(SW_HIDE);
		m_LossCaptionCtl.ShowWindow(SW_HIDE);
		m_TimesCtl.ShowWindow(SW_HIDE);
		m_TimesCaptionCtl.ShowWindow(SW_HIDE);
	}
	if(host->m_URL.IsEmpty()){
		m_URLCtl.ShowWindow(SW_HIDE);
		m_URLCaptionCtl.ShowWindow(SW_HIDE);
		m_OpenURLCtl.ShowWindow(SW_HIDE);
	}else
		m_URL = host->m_URL;
	if(host->m_Status.IsEmpty()){
		m_StatusCtl.ShowWindow(SW_HIDE);
		m_StatusCaptionCtl.ShowWindow(SW_HIDE);
	}else
		m_Status = host->m_Status;
	
	// CG: The following block was added by the ToolTips component.
	{
		// Create the ToolTip control.
		m_tooltip.Create(this);
		m_tooltip.Activate(TRUE);

		m_tooltip.AddTool(&m_HostCaptionCtl,IDC_HOSTCAPTION);
		m_tooltip.AddTool(&m_HostCtl,IDC_HOST);
		m_tooltip.AddTool(&m_IPCaptionCtl,IDC_IPCAPTION);
		m_tooltip.AddTool(&m_IPCtl,IDC_IPCAPTION);
		m_tooltip.AddTool(&m_LossCaptionCtl,IDC_LOSSCAPTION);
		m_tooltip.AddTool(&m_LossCtl,IDC_LOSS);
		m_tooltip.AddTool(&m_OpenURLCtl,IDC_OPENURL);
		m_tooltip.AddTool(&m_StatusCaptionCtl,IDC_STATUSCAPTION);
		m_tooltip.AddTool(&m_StatusCtl,IDC_STATUS);
		m_tooltip.AddTool(&m_TimesCaptionCtl,IDC_TIMESCAPTION);
		m_tooltip.AddTool(&m_TimesCtl,IDC_TIMES);
		m_tooltip.AddTool(&m_URLCaptionCtl,IDC_URLCAPTION);
		m_tooltip.AddTool(&m_URLCtl,IDC_URL);
		m_tooltip.AddTool(GetDlgItem(IDOK),IDS_TIP_PROPSOK);

		if(host->m_Pinging){
			m_StateCtl.SetIcon(AfxGetApp()->LoadIcon(IDI_PINGING));
			m_tooltip.AddTool(&m_StateCtl,IDS_TIP_PINGING);
		}else{
			if(host->m_bToPing){
				m_StateCtl.SetIcon(AfxGetApp()->LoadIcon(IDI_PENDING));
				m_tooltip.AddTool(&m_StateCtl,IDS_TIP_PENDING);
			}else{
				if(host->m_Pinged){
					if(host->m_Packetloss==100){
						m_StateCtl.SetIcon(AfxGetApp()->LoadIcon(IDI_UNREACHABLE));
						m_tooltip.AddTool(&m_StateCtl,IDS_TIP_UNREACHABLE);
					}else{
						m_StateCtl.SetIcon(AfxGetApp()->LoadIcon(IDI_COMPLETED));
						m_tooltip.AddTool(&m_StateCtl,IDS_TIP_COMPLETE);
					}
				}else{
					m_StateCtl.SetIcon(AfxGetApp()->LoadIcon(IDI_PENDING));
					m_tooltip.AddTool(&m_StateCtl,IDS_TIP_PENDING);
				}
			}
	}

	UpdateData(FALSE);

	}
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CHostProperties::SetHost(CPingyHost *host)
{
	CHostProperties::host = host;
}

void CHostProperties::OnOpenurl() 
{
	ASSERT(!m_URL.IsEmpty());
	ShellExecute(::GetDesktopWindow(),"open",m_URL,NULL,NULL,SW_SHOWMAXIMIZED);
}

BOOL CHostProperties::PreTranslateMessage(MSG* pMsg)
{
	// CG: The following block was added by the ToolTips component.
	{
		// Let the ToolTip process this message.
		m_tooltip.RelayEvent(pMsg);

		return CDialog::PreTranslateMessage(pMsg);
	}
}

BOOL CHostProperties::OnHelpInfo(HELPINFO* pHelpInfo) 
{
	WinHelp(IDD|0x20000l);
	return TRUE;
}
