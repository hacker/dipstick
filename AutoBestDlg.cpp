// AutoBestDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Dipstick.h"
#include "AutoBestDlg.h"

#include "URLSource.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAutoBestDlg dialog


CAutoBestDlg::CAutoBestDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CAutoBestDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CAutoBestDlg)
	m_PktLoss = _T("");
	m_RTT = _T("");
	m_URL = _T("");
	//}}AFX_DATA_INIT
}


void CAutoBestDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAutoBestDlg)
	DDX_Control(pDX, IDC_DROPSOURCE, m_DropSourceCtl);
	DDX_Control(pDX, IDC_PREV, m_PrevCtl);
	DDX_Control(pDX, IDC_NEXT, m_NextCtl);
	DDX_Text(pDX, IDC_PKTLOSS, m_PktLoss);
	DDX_Text(pDX, IDC_RTT, m_RTT);
	DDX_Text(pDX, IDC_URL, m_URL);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CAutoBestDlg, CDialog)
	//{{AFX_MSG_MAP(CAutoBestDlg)
	ON_BN_CLICKED(IDC_NEXT, OnNext)
	ON_BN_CLICKED(IDC_PREV, OnPrev)
	ON_WM_LBUTTONDOWN()
	ON_BN_CLICKED(IDC_COPYURL, OnCopyurl)
	ON_WM_HELPINFO()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAutoBestDlg message handlers

void CAutoBestDlg::OnNext() 
{
	EndDialog(IDC_NEXT);
}

void CAutoBestDlg::OnPrev() 
{
	EndDialog(IDC_PREV);
}

BOOL CAutoBestDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	m_NextCtl.EnableWindow(m_bNext);
	m_PrevCtl.EnableWindow(m_bPrev);

	VERIFY(m_DropSourceCtl.Open(IDR_DRAGAVI));
	SetWindowPos(&CWnd::wndTopMost,0,0,0,0,SWP_NOMOVE|SWP_NOSIZE);

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

CAutoBestDlg::~CAutoBestDlg()
{
}

void CAutoBestDlg::OnLButtonDown(UINT nFlags, CPoint point) 
{
	if(ChildWindowFromPoint(point,CWP_ALL)==&m_DropSourceCtl){
		TRACE0("Dragging!\n");
	CURLSource us(m_URL);
		m_DropSourceCtl.Stop();
		us.DoDragDrop(DROPEFFECT_COPY|DROPEFFECT_LINK);
		m_DropSourceCtl.Play(0,-1,-1);
	}else
		CDialog::OnLButtonDown(nFlags, point);
}

void CAutoBestDlg::OnCopyurl() 
{
CURLSource *us = new CURLSource(m_URL);
	us->SetClipboard();
	us->FlushClipboard();
}

BOOL CAutoBestDlg::OnHelpInfo(HELPINFO* pHelpInfo) 
{
	WinHelp(IDD|0x20000l);
	return TRUE;
}
