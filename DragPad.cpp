// DragPad.cpp : implementation file
//

#include "stdafx.h"
#include "Dipstick.h"
#include "DragPad.h"
#include "DipstickDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDragPad dialog


CDragPad::CDragPad(CWnd* pParent /*=NULL*/)
	: CDialog(CDragPad::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDragPad)
	//}}AFX_DATA_INIT
	m_DropTarget.m_Pad = this;
}

CDragPad::~CDragPad()
{
}

void CDragPad::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDragPad)
	DDX_Control(pDX, IDC_DNDTARGET, m_DragNDropTarget);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDragPad, CDialog)
	//{{AFX_MSG_MAP(CDragPad)
	ON_WM_WINDOWPOSCHANGED()
	ON_WM_NCACTIVATE()
	ON_WM_DESTROY()
	ON_WM_CREATE()
	ON_WM_LBUTTONDBLCLK()
	ON_WM_RBUTTONDOWN()
	ON_WM_LBUTTONDOWN()
	ON_WM_HELPINFO()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDragPad message handlers

BOOL CDragPad::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	m_DropTarget.Register(&m_DragNDropTarget);
	m_DragNDropTarget.Open(IDR_DNDAVI);
CRect rc;
	m_DragNDropTarget.GetClientRect(rc);
	m_DragNDropTarget.MoveWindow(rc,FALSE);
CRect wrc,crc,drc, nrc;
	GetWindowRect(wrc);
	GetClientRect(crc);
	GetDesktopWindow()->GetClientRect(drc);
	nrc.left = drc.right-(rc.Width()+(wrc.Width()-crc.Width())) - 5;
	nrc.top = drc.bottom-(rc.Height()+(wrc.Height()-crc.Height())) - 5;
CWinApp *app = AfxGetApp();
	ASSERT(app);
	ScreenToClient(nrc);
	nrc.top=app->GetProfileInt("Windows","DragPadTop",nrc.top);
	nrc.left=app->GetProfileInt("Windows","DragPadLeft",nrc.left);
	nrc.right = nrc.left+(rc.Width()+(wrc.Width()-crc.Width()));
	nrc.bottom = nrc.top+(rc.Height()+(wrc.Height()-crc.Height()));
	MoveWindow(nrc,FALSE);

	// CG: The following block was added by the ToolTips component.
	{
		// Create the ToolTip control.
		m_tooltip.Create(this);
		m_tooltip.Activate(TRUE);
 	}

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CDragPad::OnWindowPosChanged(WINDOWPOS FAR* lpwndpos) 
{
	CDialog::OnWindowPosChanged(lpwndpos);
	if(lpwndpos->hwnd!=m_hWnd)
		SetWindowPos(&wndTopMost,0,0,0,0,SWP_NOACTIVATE|SWP_NOMOVE|SWP_NOSIZE);
}

BOOL CDragPad::PreCreateWindow(CREATESTRUCT& cs) 
{
	cs.dwExStyle|=WS_EX_TOPMOST;
	return CDialog::PreCreateWindow(cs);
}

BOOL CDragPad::OnNcActivate(BOOL bActive) 
{
	if(!bActive)
		SetWindowPos(&wndTopMost,0,0,0,0,SWP_NOACTIVATE|SWP_NOMOVE|SWP_NOSIZE);
	return CDialog::OnNcActivate(bActive);
}

void CDragPad::OnDestroy() 
{
	CDialog::OnDestroy();
	TRACE0("DestroyPad\n");
	RevokeDragDrop(m_DragNDropTarget.m_hWnd);
}

int CDragPad::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CDialog::OnCreate(lpCreateStruct) == -1)
		return -1;
CRect rc,drc, nrc;
CWinApp *app = AfxGetApp();
	ASSERT(app);
	GetWindowRect(rc);
	GetDesktopWindow()->GetClientRect(drc);
	nrc.left = drc.right-rc.Width() - 5;
	nrc.top = drc.bottom-rc.Height() - 5;
	ScreenToClient(nrc);
	nrc.top=app->GetProfileInt("Windows","DragPadTop",nrc.top);
	nrc.left=app->GetProfileInt("Windows","DragPadLeft",nrc.left);
	nrc.right = nrc.left+rc.Width();
	nrc.bottom = nrc.top+rc.Height();
	MoveWindow(nrc);
	return 0;
}

void CDragPad::OnLButtonDblClk(UINT nFlags, CPoint point) 
{
	ToggleMainWindowDisplay();
	CDialog::OnLButtonDblClk(nFlags, point);
}

void CDragPad::OnRButtonDown(UINT nFlags, CPoint point) 
{
CMenu menus;
	VERIFY(menus.LoadMenu(IDR_MENU));
CMenu *dpm = menus.GetSubMenu(0);	// *** Position?
	ASSERT(dpm);
CPoint pt = point;
	ClientToScreen(&pt);
	m_Daddy->UpdateControlButtons();
	dpm->CheckMenuItem(ID_DRAGPAD_SHOWMAINWINDOW,MF_BYCOMMAND|(m_Daddy->m_bShown?MF_CHECKED:MF_UNCHECKED));
	dpm->EnableMenuItem(ID_DRAGPAD_REPINGALL,MF_BYCOMMAND|(m_Daddy->m_RepingAllCtl.IsWindowEnabled()?MF_ENABLED:MF_GRAYED));
	dpm->EnableMenuItem(ID_DRAGPAD_REMOVEALL,MF_BYCOMMAND|(m_Daddy->m_ClearListCtl.IsWindowEnabled()?MF_ENABLED:MF_GRAYED));
	dpm->EnableMenuItem(ID_DRAGPAD_PASTEURL,MF_BYCOMMAND|(m_Daddy->IsPasteableClipboard()?MF_ENABLED:MF_GRAYED));
	dpm->EnableMenuItem(ID_DRAGPAD_ADVANCED_EXPORTLIST,MF_BYCOMMAND|(m_Daddy->m_HostList.GetItemCount()?MF_ENABLED:MF_GRAYED));
	dpm->TrackPopupMenu(TPM_RIGHTALIGN|TPM_LEFTBUTTON|TPM_RIGHTBUTTON,pt.x,pt.y,m_Daddy,NULL);
	CDialog::OnRButtonDown(nFlags, point);
}

void CDragPad::OnLButtonDown(UINT nFlags, CPoint point) 
{
	ToggleMainWindowDisplay();
	CDialog::OnLButtonDown(nFlags, point);
}

void CDragPad::ToggleMainWindowDisplay()
{
	if(m_Daddy->IsWindowVisible()){
		m_Daddy->m_bShown=FALSE;
		m_Daddy->ShowWindow(SW_HIDE);
	}else{
		m_Daddy->m_bShown=TRUE;
		m_Daddy->ShowWindow(SW_SHOW);
	}
}

BOOL CDragPad::PreTranslateMessage(MSG* pMsg)
{
	// CG: The following block was added by the ToolTips component.
	{
		// Let the ToolTip process this message.
		m_tooltip.RelayEvent(pMsg);

		return CDialog::PreTranslateMessage(pMsg);
	}
}

DROPEFFECT CDUTarget::OnDragEnter(CWnd* pWnd,COleDataObject* pDO,DWORD dwKeyState,CPoint pt)
{
	if(m_Pad->m_Daddy->CollectURLs(pDO,TRUE))
		return m_dropAsEntered=DROPEFFECT_LINK|DROPEFFECT_COPY|DROPEFFECT_MOVE;
	else
		return m_dropAsEntered=DROPEFFECT_NONE;
}
DROPEFFECT CDUTarget::OnDragOver(CWnd* pWnd,COleDataObject* pDO,DWORD dwKeyState,CPoint pt)
{
	return m_dropAsEntered;
}
DROPEFFECT CDUTarget::OnDropEx(CWnd* pWnd,COleDataObject* pDO,DROPEFFECT dropDefault,DROPEFFECT dropList,CPoint pt)
{
	if(m_Pad->m_Daddy->CollectURLs(pDO,FALSE))
		return DROPEFFECT_LINK|DROPEFFECT_COPY|DROPEFFECT_MOVE;
	else
		return DROPEFFECT_NONE;
}

BOOL CDragPad::OnHelpInfo(HELPINFO* pHelpInfo) 
{
	WinHelp(IDD|0x20000l);
	return TRUE;
}
