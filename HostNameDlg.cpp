// HostNameDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Dipstick.h"
#include "HostNameDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CHostNameDlg dialog


CHostNameDlg::CHostNameDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CHostNameDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CHostNameDlg)
	m_Host = _T("");
	//}}AFX_DATA_INIT
}


void CHostNameDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CHostNameDlg)
	DDX_Text(pDX, IDC_HOST, m_Host);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CHostNameDlg, CDialog)
	//{{AFX_MSG_MAP(CHostNameDlg)
	ON_WM_HELPINFO()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CHostNameDlg message handlers

BOOL CHostNameDlg::OnHelpInfo(HELPINFO* pHelpInfo) 
{
	WinHelp(IDD|0x20000l);
	return TRUE;
}
