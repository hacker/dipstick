// SelectURLsDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Dipstick.h"
#include "SelectURLsDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSelectURLsDlg dialog


CSelectURLsDlg::CSelectURLsDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSelectURLsDlg::IDD, pParent), m_minSize(0,0)
{
	//{{AFX_DATA_INIT(CSelectURLsDlg)
	m_bAdjustInnermost = FALSE;
	m_bAdjust = FALSE;
	//}}AFX_DATA_INIT
}


void CSelectURLsDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSelectURLsDlg)
	DDX_Control(pDX, IDC_DOADJUST, m_AdjustCtl);
	DDX_Control(pDX, IDC_ADJUSTINN, m_AdjustInnCtl);
	DDX_Control(pDX, IDOK, m_OkCtl);
	DDX_Control(pDX, IDCANCEL, m_CancelCtl);
	DDX_Control(pDX, IDC_URLS, m_URLsCtl);
	DDX_Check(pDX, IDC_ADJUSTINN, m_bAdjustInnermost);
	DDX_Check(pDX, IDC_DOADJUST, m_bAdjust);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSelectURLsDlg, CDialog)
	//{{AFX_MSG_MAP(CSelectURLsDlg)
	ON_WM_SIZE()
	ON_WM_GETMINMAXINFO()
	ON_LBN_SELCHANGE(IDC_URLS, OnSelchangeUrls)
	ON_WM_HELPINFO()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSelectURLsDlg message handlers

BOOL CSelectURLsDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
POSITION p = m_URLs.GetHeadPosition();
	while(p){
	CString url = m_URLs.GetNext(p);
		ASSERT(!url.IsEmpty());
		m_URLsCtl.AddString(url);
	}
CRect rc;
	GetWindowRect(rc);
	m_minSize.cx = rc.Width();
	m_minSize.cy = rc.Height();
	m_URLsCtl.GetWindowRect(rc);
	ScreenToClient(rc);
	m_Gap = CSize(rc.left,rc.top);
	m_minSize.cy -= rc.Height()-20;
	m_URLsCtl.SelItemRange(TRUE,0,m_URLsCtl.GetCount()-1);
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CSelectURLsDlg::OnSize(UINT nType, int cx, int cy) 
{
	CDialog::OnSize(nType, cx, cy);
	
	RecalcLayout(cx,cy);
	
}

void CSelectURLsDlg::OnGetMinMaxInfo(MINMAXINFO FAR* lpMMI) 
{
	CDialog::OnGetMinMaxInfo(lpMMI);
	if(m_minSize.cx && m_minSize.cy){
		lpMMI->ptMinTrackSize.x = m_minSize.cx;
		lpMMI->ptMinTrackSize.y = m_minSize.cy;
	}
}

void CSelectURLsDlg::RecalcLayout(int cx,int cy)
{
	if(!(m_minSize.cx&&m_minSize.cy))
		return;
CRect rcok, rccan, rcadj, rcadjin, rclist;
	m_OkCtl.GetWindowRect(rcok); ScreenToClient(rcok);
	m_CancelCtl.GetWindowRect(rccan); ScreenToClient(rccan);
	m_AdjustCtl.GetWindowRect(rcadj); ScreenToClient(rcadj);
	m_AdjustInnCtl.GetWindowRect(rcadjin); ScreenToClient(rcadjin);
	m_URLsCtl.GetWindowRect(rclist); ScreenToClient(rclist);
	m_CancelCtl.SetWindowPos(NULL,rccan.left,cy-m_Gap.cy-rccan.Height(),0,0,SWP_NOACTIVATE|SWP_NOSIZE|SWP_NOZORDER|SWP_NOCOPYBITS);
	m_OkCtl.SetWindowPos(NULL,rcok.left,cy-m_Gap.cy-rcok.Height()-rccan.bottom+rcok.bottom,0,0,SWP_NOACTIVATE|SWP_NOSIZE|SWP_NOZORDER|SWP_NOCOPYBITS);
	m_AdjustCtl.SetWindowPos(NULL,rcadj.left,cy-m_Gap.cy-rccan.bottom+rcadj.bottom-rcadj.Height(),0,0,SWP_NOACTIVATE|SWP_NOSIZE|SWP_NOZORDER|SWP_NOCOPYBITS);
	m_AdjustInnCtl.SetWindowPos(NULL,rcadjin.left,cy-m_Gap.cy-rccan.bottom+rcadjin.bottom-rcadjin.Height(),0,0,SWP_NOACTIVATE|SWP_NOSIZE|SWP_NOZORDER|SWP_NOCOPYBITS);
	m_URLsCtl.SetWindowPos(NULL,rclist.left,rclist.top,cx-m_Gap.cx*2,cy-m_Gap.cy*2-rccan.bottom+rclist.bottom,SWP_NOACTIVATE|SWP_NOZORDER|SWP_NOCOPYBITS);
}

void CSelectURLsDlg::OnSelchangeUrls() 
{
	UpdateData(TRUE);
	if(!m_bAdjust)
		return;
	if(m_URLsCtl.GetSelCount()!=1)
		return;
INT	selection;
	VERIFY(m_URLsCtl.GetSelItems(1,&selection)==1);
CCrackURL base;
CString selectedItem;
	m_URLsCtl.GetText(selection,selectedItem);
	VERIFY(base.Crack(selectedItem));
CCrackURL item;
int is = m_URLsCtl.GetCount();
	BeginWaitCursor();
	for(int i = 0;i<is;i++){
		if(i==selection)
			continue;
	CString it;
		m_URLsCtl.GetText(i,it);
		if(m_bAdjustInnermost)
			it = CCrackURL::InnermostURL(it);
		VERIFY(item.Crack(it));
		if(item.m_pathFile==base.m_pathFile)
			m_URLsCtl.SetSel(i);
	}
	EndWaitCursor();
}

void CSelectURLsDlg::OnOK() 
{
	m_URLs.RemoveAll();
int is = m_URLsCtl.GetSelCount();
	if(is){
	LPINT	items = new INT[is];
		VERIFY(m_URLsCtl.GetSelItems(is,items)==is);
		for(int i=0;i<is;i++){
		CString url;
			m_URLsCtl.GetText(items[i],url);
			m_URLs.AddTail(url);
		}
		delete items;
	}
	CDialog::OnOK();
}

BOOL CSelectURLsDlg::OnHelpInfo(HELPINFO* pHelpInfo) 
{
	WinHelp(IDD|0x20000l);
	return TRUE;
}
