// DipstickDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Dipstick.h"
#include "DipstickDlg.h"
#include "DragPad.h"
#include "OptionsDlg.h"
#include "HostNameDlg.h"
#include "HostProperties.h"
#include "AutoBestDlg.h"
#include "ddeml.h"

#include "URLSource.h"
#include "SelectURLsDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual BOOL OnInitDialog();
	//{{AFX_MSG(CAboutDlg)
	afx_msg void OnKlevernet();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
	ON_BN_CLICKED(IDC_KLEVERNET, OnKlevernet)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDipstickDlg dialog

CDipstickDlg::CDipstickDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CDipstickDlg::IDD, pParent),
	  m_DragPad(NULL), m_PingsPerHost(10), m_PingSize(32), m_TimeOut(5000), m_Interval(500),
	  m_SortCriteria(sortAvg), m_bShown(FALSE), m_MaxThreads(10), m_bExiting(FALSE),
	  m_bMSWorkAround(TRUE), m_MinSize(-1,-1), m_bAutoBest(TRUE), m_bSmartAdjust(TRUE),
	  m_bAdjustInnermost(TRUE), m_ActiveThreads(0), m_bIgnorelative(TRUE)
{
CWinApp *app = AfxGetApp();
	ASSERT(app);
WORD hi,lo;
	hi=app->GetProfileInt("Options","IntervalHi",HIWORD(m_Interval));
	lo=app->GetProfileInt("Options","IntervalLo",LOWORD(m_Interval));
	m_Interval=MAKELONG(lo,hi);
	m_MaxThreads=app->GetProfileInt("Options","MaxThreads",m_MaxThreads);
	m_PingSize=app->GetProfileInt("Options","PingSize",m_PingSize);
	m_PingsPerHost=app->GetProfileInt("Options","PingsPerHost",m_PingsPerHost);
	m_SortCriteria=app->GetProfileInt("Options","SortBy",m_SortCriteria);
	hi=app->GetProfileInt("Options","TimeOutHi",HIWORD(m_TimeOut));
	lo=app->GetProfileInt("Options","TimeOutLo",LOWORD(m_TimeOut));
	m_TimeOut=MAKELONG(lo,hi);
	m_bMSWorkAround = app->GetProfileInt("Options","InnermostURL",m_bMSWorkAround);
	m_bAutoBest = app->GetProfileInt("Options","AutoBest",m_bAutoBest);
	m_bSmartAdjust = app->GetProfileInt("Options","SmartAdjust",m_bSmartAdjust);
	m_bAdjustInnermost = app->GetProfileInt("Options","AdjustInnermost",m_bAdjustInnermost);
	m_bIgnorelative = app->GetProfileInt("Options","IgnoreRelative",m_bIgnorelative);
	m_impexPath = app->GetProfileString("Options","ImportExportPath",m_impexPath);
	//{{AFX_DATA_INIT(CDipstickDlg)
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_bmpBack.LoadBitmap(IDB_DIABACK);
	m_bmpBack.GetBitmap(&m_bitmapBack);
CString tmp;
	VERIFY(tmp.LoadString(IDS_REGEX_HTMLURL));
	VERIFY(m_reHTMLURL.Compile(tmp,CRegEx::regExtended|CRegEx::regIgnoreCase));
}

CDipstickDlg::~CDipstickDlg()
{
}

void CDipstickDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDipstickDlg)
	DDX_Control(pDX, IDC_ADVANCED, m_AdvancedCtl);
	DDX_Control(pDX, ID_HELP, m_HelpCtl);
	DDX_Control(pDX, IDC_EXIT, m_ExitCtl);
	DDX_Control(pDX, IDC_OPTIONS, m_OptionsCtl);
	DDX_Control(pDX, IDC_MANUALPING, m_ManualPingCtl);
	DDX_Control(pDX, IDC_REMOVE, m_RemoveCtl);
	DDX_Control(pDX, IDC_REPINGALL, m_RepingAllCtl);
	DDX_Control(pDX, IDC_REPING, m_RepingCtl);
	DDX_Control(pDX, IDC_CLEAR, m_ClearListCtl);
	DDX_Control(pDX, IDC_HOSTLIST, m_HostList);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CDipstickDlg, CDialog)
	//{{AFX_MSG_MAP(CDipstickDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_DESTROY()
	ON_BN_CLICKED(IDC_OPTIONS, OnOptions)
	ON_MESSAGE(WM_DNP_URLPING, OnUrlPing)
	ON_MESSAGE(WM_DNP_ACTIVITYCOUNT, OnActivityCount)
	ON_MESSAGE(WM_DNP_UPDATEHOSTDATA, OnUpdateHostData)
	ON_MESSAGE(WM_DNP_HTML, OnHTMLTransfer)
	ON_NOTIFY(LVN_COLUMNCLICK, IDC_HOSTLIST, OnColumnclickHostlist)
	ON_WM_WINDOWPOSCHANGING()
	ON_COMMAND(ID_DRAGPAD_OPTIONS, OnDragpadOptions)
	ON_COMMAND(ID_DRAGPAD_SHOWMAINWINDOW, OnDragpadShowmainwindow)
	ON_COMMAND(ID_DRAGPAD_HELP, OnDragpadHelp)
	ON_COMMAND(ID_DRAGPAD_ABOUT, OnDragpadAbout)
	ON_COMMAND(ID_DRAGPAD_EXIT, OnDragpadExit)
	ON_BN_CLICKED(IDC_MANUALPING, OnManualping)
	ON_COMMAND(ID_DRAGPAD_MANUALPING, OnDragpadManualping)
	ON_COMMAND(ID_DRAGPAD_REPINGALL, OnDragpadRepingAll)
	ON_COMMAND(ID_DRAGPAD_REMOVEALL, OnDragpadRemoveAll)
	ON_BN_CLICKED(IDC_REPING, OnReping)
	ON_BN_CLICKED(IDC_REPINGALL, OnRepingall)
	ON_BN_CLICKED(IDC_CLEAR, OnClear)
	ON_NOTIFY(LVN_INSERTITEM, IDC_HOSTLIST, OnInsertitemHostlist)
	ON_NOTIFY(LVN_DELETEITEM, IDC_HOSTLIST, OnDeleteitemHostlist)
	ON_NOTIFY(LVN_DELETEALLITEMS, IDC_HOSTLIST, OnDeleteallitemsHostlist)
	ON_BN_CLICKED(IDC_EXIT, OnExit)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_HOSTLIST, OnItemchangedHostlist)
	ON_BN_CLICKED(IDC_REMOVE, OnRemove)
	ON_NOTIFY(NM_RCLICK, IDC_HOSTLIST, OnRclickHostlist)
	ON_COMMAND(ID_HOSTLIST_REPING, OnHostListReping)
	ON_COMMAND(ID_HOSTLIST_REMOVE, OnHostListRemove)
	ON_COMMAND(ID_HOSTLIST_REPINGALL, OnHostListRepingAll)
	ON_COMMAND(ID_HOSTLIST_REMOVEALL, OnHostListRemoveAll)
	ON_COMMAND(ID_HOSTLIST_OPENURL, OnHostListOpenURL)
	ON_COMMAND(ID_HOSTLIST_PROPERTIES, OnHostListProperties)
	ON_NOTIFY(NM_DBLCLK, IDC_HOSTLIST, OnDblclkHostlist)
	ON_WM_CLOSE()
	ON_WM_GETMINMAXINFO()
	ON_WM_SIZE()
	ON_BN_CLICKED(ID_HELP, OnHelp)
	ON_NOTIFY(LVN_BEGINDRAG, IDC_HOSTLIST, OnBegindragHostlist)
	ON_COMMAND(ID_HOSTLIST_PASTEURL, OnPasteurl)
	ON_COMMAND(ID_HOSTLIST_COPYURL, OnHostlistCopyurl)
	ON_WM_HELPINFO()
	ON_WM_DROPFILES()
	ON_BN_CLICKED(IDC_ADVANCED, OnAdvanced)
	ON_COMMAND(ID_ADVANCED_EXPORTLIST, OnAdvancedExportlist)
	ON_COMMAND(ID_ADVANCED_IMPORTLIST, OnAdvancedImportlist)
	ON_COMMAND(ID_DRAGPAD_PASTEURL, OnPasteurl)
	ON_COMMAND(ID_DRAGPAD_ADVANCED_EXPORTLIST, OnDragpadAdvancedExportlist)
	ON_COMMAND(ID_DRAGPAD_ADVANCED_IMPORTLIST, OnDragpadAdvancedImportlist)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDipstickDlg message handlers

BOOL CDipstickDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	CString strAboutMenu;
	strAboutMenu.LoadString(IDS_ABOUTBOX);
	if (!strAboutMenu.IsEmpty())
	{
		pSysMenu->AppendMenu(MF_SEPARATOR);
		pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

CRect wrci, wrco;
	GetWindowRect(&wrco);
	GetClientRect(&wrci);
CRect brc1, brc2, lrc;
	m_HostList.GetWindowRect(&lrc);
	ScreenToClient(&lrc);
	m_ManualPingCtl.GetWindowRect(&brc1);
	ScreenToClient(brc1);
	m_RepingCtl.GetWindowRect(&brc2);
	ScreenToClient(&brc2);
	m_OverX = lrc.left;
	m_OverY = lrc.top;
	m_GapY = brc2.top - brc1.bottom;
	m_MinSize.cx = m_OverX+m_OverX+m_OverX+brc1.Width()+m_OverX;
	m_MinSize.cy = m_OverY+(brc1.Height()+m_GapY)*6+(brc1.Height()+m_GapY)*3+m_OverY;
	m_MinSize.cx+=wrco.Width()-wrci.Width();
	m_MinSize.cy+=wrco.Height()-wrci.Height();

CWinApp *app = AfxGetApp();
	ASSERT(app);
CRect wrc;
	wrc.top=app->GetProfileInt("Windows","DlgTop",-1);
	wrc.bottom=app->GetProfileInt("Windows","DlgBottom",-1);
	wrc.left=app->GetProfileInt("Windows","DlgLeft",-1);
	wrc.right=app->GetProfileInt("Windows","DlgRight",-1);
	if((wrc.top!=-1|| wrc.bottom!=-1) && wrc.left!=-1&&  wrc.right!=-1)
		MoveWindow(&wrc);

	RecalcLayout(-1,-1);
	
	m_DragPad = new CDragPad();
	m_DragPad->m_Daddy=this;
	m_DragPad->Create(CDragPad::IDD);
	m_Images.Create(16,16,TRUE,4,1);
	m_iPending=m_Images.Add(app->LoadIcon(IDI_PENDING));
	m_iPinging=m_Images.Add(app->LoadIcon(IDI_PINGING));
	m_iCompleted=m_Images.Add(app->LoadIcon(IDI_COMPLETED));
	m_iUnreachable=m_Images.Add(app->LoadIcon(IDI_UNREACHABLE));
	ASSERT(!(m_iPending<0 ||  m_iPinging<0 || m_iCompleted<0 || m_iUnreachable<0));
	m_HostList.SetImageList(&m_Images,LVSIL_NORMAL);
	m_HostList.SetImageList(&m_Images,LVSIL_SMALL);
	m_HostList.SetImageList(&m_Images,LVSIL_STATE);
	m_HostList.SetTextColor(RGB(255,255,0));	// Yellow
	m_HostList.SetTextBkColor(RGB(12,167,0));	// Green
	m_HostList.SetBkColor(RGB(12,167,0));		// Green
CRect listrc;
	m_HostList.GetClientRect(&listrc);
	m_HostList.InsertColumn(0,"Host Name",LVCFMT_LEFT,app->GetProfileInt("Columns","HostName",listrc.Width()-(listrc.Width()*2/16)*4-(listrc.Width()*3/16)),subitemHost);
	m_HostList.InsertColumn(1,"Host IP",LVCFMT_LEFT,app->GetProfileInt("Columns","HostIP",listrc.Width()*3/16),subitemIP);
	m_HostList.InsertColumn(2,"Min RTT",LVCFMT_RIGHT,app->GetProfileInt("Columns","MinRTT",listrc.Width()*2/16),subitemMin);
	m_HostList.InsertColumn(3,"Avg RTT",LVCFMT_RIGHT,app->GetProfileInt("Columns","AvgRTT",listrc.Width()*2/16),subitemAvg);
	m_HostList.InsertColumn(4,"Max RTT",LVCFMT_RIGHT,app->GetProfileInt("Columns","MaxRTT",listrc.Width()*2/16),subitemMax);
	m_HostList.InsertColumn(5,"Pktloss", LVCFMT_RIGHT,app->GetProfileInt("Columns","PktLoss",listrc.Width()*2/16),subitemPacketloss);

	DragAcceptFiles(TRUE);
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CDipstickDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CDipstickDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
	CPaintDC pDC(this);
	CDC bmpDC;
		bmpDC.CreateCompatibleDC(&pDC);
		bmpDC.SelectObject(&m_bmpBack);
	CRect rc;
		GetClientRect(&rc);
		for(int x=-m_bitmapBack.bmWidth*2/4;x<rc.Width();x+=m_bitmapBack.bmWidth)
			for(int y=-m_bitmapBack.bmHeight*2/4;y<rc.Height();y+=m_bitmapBack.bmHeight)
				pDC.BitBlt(x,y,m_bitmapBack.bmWidth,m_bitmapBack.bmHeight,&bmpDC,0,0,SRCCOPY);
		bmpDC.DeleteDC();
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CDipstickDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

//////////////////////////

void CDipstickDlg::OnDestroy() 
{
	CDialog::OnDestroy();
	TRACE0("DestroyMain\n");
	m_DragPad->DestroyWindow();
	delete m_DragPad;
	m_DragPad=NULL;
	// *** Eventually move the following code to separate function
POSITION p = m_Hosts.GetHeadPosition();
	while(p){
	POSITION pp = p;
	CPingyHost *host = m_Hosts.GetNext(p);
		ASSERT(host);
		m_Hosts.RemoveAt(pp);
		host->Suicide();
	}
	ASSERT(m_Hosts.IsEmpty());
}

void CDipstickDlg::OnOptions() 
{
COptionsDlg o(this);
	o.m_Pings = m_PingsPerHost;
	o.m_PingSize = m_PingSize;
	o.m_TimeOut = max(1,m_TimeOut/1000);
	o.m_Interval = max(1,m_Interval/1000);
	o.m_MaxThreads = m_MaxThreads;
	o.m_bMSWorkAround = m_bMSWorkAround;
	o.m_bAutoBest = m_bAutoBest;
	o.m_bAdjust = m_bSmartAdjust;
	o.m_bAdjustInn = m_bAdjustInnermost;
	o.m_bIgnorelative = m_bIgnorelative;
	if(o.DoModal()==IDOK){
		m_PingsPerHost = o.m_Pings;
		m_PingSize = o.m_PingSize;
		m_TimeOut = o.m_TimeOut*1000;
		m_Interval = o.m_Interval*1000;
		m_MaxThreads = o.m_MaxThreads;
		m_bMSWorkAround = o.m_bMSWorkAround;
		m_bAutoBest = o.m_bAutoBest;
		m_bSmartAdjust = o.m_bAdjust;
		m_bAdjustInnermost = o.m_bAdjustInn;
		m_bIgnorelative = o.m_bIgnorelative;
	}
}

BOOL CDipstickDlg::AddPingyHost(CPingyHost *host)
{
	m_Hosts.AddTail(host);
int i = m_HostList.InsertItem(0,host->m_HostName);
	m_HostList.SetItemData(i,(DWORD)host);
	UpdateDragpadTitle();
	return UpdatePingyHost(host,i);	// *** Do someting if failed.
}

BOOL CDipstickDlg::UpdatePingyHost(CPingyHost *host,int index)
{
	UpdateDragpadTitle();
int i = index;
	if(i<0){
	int is = m_HostList.GetItemCount();
		for(i=0;i<is;i++)
			if(m_HostList.GetItemData(i)==(DWORD)host)
				break;
		if(!(i<is))
			return FALSE;
	}
	ASSERT(m_HostList.GetItemData(i)==(DWORD)host);
	m_HostList.SetItemText(i,subitemHost,host->m_HostName.IsEmpty()?"...":host->m_HostName);
	m_HostList.SetItemText(i,subitemIP,host->m_IP?inet_ntoa(*(in_addr*)&host->m_IP):"...");
	if(host->m_Pinged && host->m_Packetloss>=0){
	CString tmp;
		if(host->m_Packetloss==100){
			m_HostList.SetItemText(i,subitemMin,"-");
			m_HostList.SetItemText(i,subitemAvg,"-");
			m_HostList.SetItemText(i,subitemMax,"-");
		}else{
			tmp.Format("%lu",host->m_MinRTT);
			m_HostList.SetItemText(i,subitemMin,tmp);
			tmp.Format("%lu",host->m_AvgRTT);
			m_HostList.SetItemText(i,subitemAvg,tmp);
			tmp.Format("%lu",host->m_MaxRTT);
			m_HostList.SetItemText(i,subitemMax,tmp);
		}
		tmp.Format("%d%%",host->m_Packetloss);
		m_HostList.SetItemText(i,subitemPacketloss,tmp);
	}else{
		m_HostList.SetItemText(i,subitemMin,"...");
		m_HostList.SetItemText(i,subitemAvg,"...");
		m_HostList.SetItemText(i,subitemMax,"...");
		m_HostList.SetItemText(i,subitemPacketloss,"...");
	}
	if(host->m_Pinging)
		m_HostList.SetItem(i,subitemHost,LVIF_IMAGE,NULL,m_iPinging,0,0,0);
	else{
		if(host->m_bToPing)
			m_HostList.SetItem(i,subitemHost,LVIF_IMAGE,NULL,m_iPending,0,0,0);
		else{
			if(host->m_Pinged){
				if(host->m_Packetloss==100)
					m_HostList.SetItem(i,subitemHost,LVIF_IMAGE,NULL,m_iUnreachable,0,0,0);
				else
					m_HostList.SetItem(i,subitemHost,LVIF_IMAGE,NULL,m_iCompleted,0,0,0);
			}else
				m_HostList.SetItem(i,subitemHost,LVIF_IMAGE,NULL,m_iPending,0,0,0);
		}
	}
	m_HostList.SortItems(CompareItems,(DWORD)this);
	UpdateControlButtons();
	return TRUE;
}

BOOL CDipstickDlg::RemovePingyHost(CPingyHost *host,int index)
{
	if(host->m_Pinging)
		return FALSE;
int i = index;
	if(i<0){
	int is = m_HostList.GetItemCount();
		for(i=0;i<is;i++)
			if(m_HostList.GetItemData(i)==(DWORD)host)
				break;
		if(!(i<is))
			return FALSE;
	}
	ASSERT(m_HostList.GetItemData(i)==(DWORD)host);
POSITION p = m_Hosts.Find(host,NULL);
	if(!p)
		return FALSE;
	m_HostList.DeleteItem(i);
	m_Hosts.RemoveAt(p);
	host->Suicide();
	UpdateControlButtons();
	UpdateDragpadTitle();
	return TRUE;
}

LRESULT CDipstickDlg::OnUrlPing(WPARAM wP, LPARAM lP)
{
	ASSERT(lP);
CString *u = (CString*)lP;
CString hn;
CPingyHost *host;
	if(m_bMSWorkAround)
		hn = CCrackURL::InnermostURL(*u);
	else
		hn = *u;
	hn = CCrackURL::GetHostName(hn);
DWORD ip = inet_addr(hn);
	if(ip==INADDR_NONE)
		host = new CPingyHost(this,(char*)(LPCTSTR)hn);
	else
		host = new CPingyHost(this,ip);
	host->m_URL=*u;
	delete u;
	AddPingyHost(host);
	CheckForPendingRequests();
	return 0;
}

LRESULT CDipstickDlg::OnActivityCount(WPARAM wP,LPARAM)
{
	if(!wP)
		return 0;
int	crement = (int)wP;
	m_ActiveThreads+=crement;
	if(m_ActiveThreads<0){
		TRACE0("C'est n'est pas possible!\n");
		m_ActiveThreads=0;
	}
	TRACE1("AC: %d\n",m_ActiveThreads);
	if(m_ActiveThreads){
		m_DragPad->m_DragNDropTarget.Play(0,(UINT)-1,(UINT)-1);
		m_ClearListCtl.EnableWindow(FALSE);
	}else{
		m_DragPad->m_DragNDropTarget.Stop();
		m_DragPad->m_DragNDropTarget.Seek(0);
		if(m_HostList.GetItemCount())
			m_ClearListCtl.EnableWindow(TRUE);
	}
	if(crement>0)
		return 0;
	UpdateDragpadTitle();
int items = m_HostList.GetItemCount();
	if((!CheckForPendingRequests()) && m_bAutoBest && items && !m_ActiveThreads){
		// Come up with the best URL..
		m_SortCriteria=sortAvg;
		m_HostList.SortItems(CompareItems,(DWORD)this);
	CPtrArray hs;
		for(int tmp=0;tmp<items;tmp++){
		CPingyHost *host = (CPingyHost*)m_HostList.GetItemData(tmp);
			ASSERT(!host->m_Pinging);
			ASSERT(host->m_Pinged);
			if(host->m_Packetloss==100 || host->m_URL.IsEmpty())
				continue;
			hs.Add(host);
		}
		if(hs.GetSize()){
		int item = 0;
			if(!::PlaySound((LPCTSTR)IDW_BESTURL,AfxGetApp()->m_hInstance,SND_ASYNC|SND_NODEFAULT|SND_NOSTOP|SND_NOWAIT|SND_RESOURCE))
				MessageBeep(0xFFFFFFFF);
			for(;;){
			CPingyHost *host = (CPingyHost*)hs[item];
			CAutoBestDlg abd;
				abd.m_bPrev = (item>0);
				abd.m_bNext = (item<hs.GetUpperBound());
				abd.m_PktLoss.Format("%d%%",host->m_Packetloss);
				abd.m_RTT.Format("%lu",host->m_AvgRTT);
				abd.m_URL=host->m_URL;
			int rv = abd.DoModal();
				if(rv==IDOK){
					ShellExecute(::GetDesktopWindow(),"open",host->m_URL,NULL,NULL,SW_SHOWMAXIMIZED);
				CString title, text;
					VERIFY(title.LoadString(IDS_ABEST_TITLE));
					VERIFY(text.LoadString(IDS_ABEST_CLEANUP));
					if(MessageBox(text,title,MB_YESNO|MB_ICONQUESTION|MB_APPLMODAL)==IDYES)
						OnClear();
					break;
				}else if(rv==IDCANCEL){
					break;
				}else if(rv==IDC_PREV){
					item--;
					ASSERT(item>=0);
				}else if(rv==IDC_NEXT){
					item++;
					ASSERT(item<hs.GetSize());
				}else
					break;
			}
		}else{
		CString title, text;
			VERIFY(title.LoadString(IDS_ABEST_TITLE));
			VERIFY(text.LoadString(IDS_ABEST_NONEFOUND));
			MessageBox(text,title,MB_OK|MB_ICONEXCLAMATION|MB_APPLMODAL);
		}
	}
	return 0;
}

LRESULT CDipstickDlg::OnUpdateHostData(WPARAM,LPARAM lP)
{
	TRACE0("UpdateHostData\n");
CPingyHost *host = (CPingyHost*)lP;
	ASSERT(host);
	UpdatePingyHost(host);
	UpdateDragpadTitle();
	return 0;
}

int CALLBACK CDipstickDlg::CompareItems(LPARAM lp1, LPARAM lp2, LPARAM lp)
{
CDipstickDlg *dlg = (CDipstickDlg*)lp;
CPingyHost *h1 = (CPingyHost*)lp1;
CPingyHost *h2 = (CPingyHost*)lp2;
	ASSERT(dlg);
	ASSERT(h1);
	ASSERT(h2);
int criteria = dlg->m_SortCriteria;
	switch(criteria){
	case sortHost:
		return h1->m_HostName.CompareNoCase(h2->m_HostName);
	case sortIP:
		return htonl(h1->m_IP)-htonl(h2->m_IP);
	default:
		if(h1->m_Pinged){
			if(!h2->m_Pinged)
				return -1;
			if(h1->m_Packetloss==100){
				if(h2->m_Packetloss!=100)
					return 1;
				return 0;
			}else{
				if(h2->m_Packetloss==100)
					return -1;
			}
		}else{
			if(h2->m_Pinged)
				return 1;
			break;
		}
		switch(criteria){
		case sortMin:
			return h1->m_MinRTT-h2->m_MinRTT;
		case sortAvg:
			return h1->m_AvgRTT-h2->m_AvgRTT;
		case sortMax:
			return h1->m_MaxRTT-h2->m_MaxRTT;
		case sortLoss:
			return h1->m_Packetloss-h2->m_Packetloss;
		}
	}
	return 0;
}

void CDipstickDlg::OnColumnclickHostlist(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_LISTVIEW* pNMListView = (NM_LISTVIEW*)pNMHDR;
	switch(pNMListView->iSubItem){
	case subitemHost: m_SortCriteria=sortHost; break;
	case subitemIP: m_SortCriteria=sortIP; break;
	case subitemMin: m_SortCriteria=sortMin; break;
	case subitemAvg: m_SortCriteria=sortAvg; break;
	case subitemMax: m_SortCriteria=sortMax; break;
	case subitemPacketloss: m_SortCriteria=sortLoss; break;
	}
	m_HostList.SortItems(CompareItems,(DWORD)this);
	*pResult = 0;
}

BOOL CDipstickDlg::PreCreateWindow(CREATESTRUCT& cs) 
{
	cs.style&=~WS_VISIBLE;
	return CDialog::PreCreateWindow(cs);
}

void CDipstickDlg::OnWindowPosChanging(WINDOWPOS FAR* lpwndpos) 
{
	CDialog::OnWindowPosChanging(lpwndpos);
	if(!m_bExiting){
		if(m_bShown){
			lpwndpos->flags&=~SWP_HIDEWINDOW;
			lpwndpos->flags|=SWP_SHOWWINDOW;
		}else{
			lpwndpos->flags&=~SWP_SHOWWINDOW;
			lpwndpos->flags|=SWP_HIDEWINDOW;
		}
	}
}

void CDipstickDlg::OnDragpadOptions()
{
	OnOptions();
}
void CDipstickDlg::OnDragpadShowmainwindow()
{
	m_DragPad->ToggleMainWindowDisplay();
}
void CDipstickDlg::OnDragpadHelp()
{
	OnHelp();
}
void CDipstickDlg::OnDragpadAbout()
{
CAboutDlg dlgAbout;
	dlgAbout.DoModal();
}
void CDipstickDlg::OnDragpadExit()
{
	// *** More threading-aware
	OnOK();
}

int CDipstickDlg::CheckForPendingRequests()
{
static BOOL bChecking = FALSE;
	if(bChecking)
		return -1;
	bChecking = TRUE;
	TRACE1("CFPR: AC: %d\n",m_ActiveThreads);
int newRequests = m_MaxThreads-m_ActiveThreads;
POSITION p = m_Hosts.GetHeadPosition();
int rv = 0;
	while(newRequests>0 && p){
	CPingyHost *host = m_Hosts.GetNext(p);
		ASSERT(host);
		if(host->m_Pinging)
			continue;
		if(!host->m_bToPing)
			continue;
		TRACE0("!");
		host->Ping();
		newRequests--;
		rv++;
	}
	TRACE0("/CFPR\n");
	bChecking = FALSE;
	return rv;
}

void CAboutDlg::OnKlevernet() 
{
CString url;
	url.LoadString(IDS_KLEVERNET_URL);
	ShellExecute(::GetDesktopWindow(),"open",url,NULL,NULL,SW_SHOWMAXIMIZED);
}

void CDipstickDlg::OnOK() 
{
CWinApp *app = AfxGetApp();
	ASSERT(app);
	app->WriteProfileInt("Options","IntervalHi",HIWORD(m_Interval));
	app->WriteProfileInt("Options","IntervalLo",LOWORD(m_Interval));
	app->WriteProfileInt("Options","MaxThreads",m_MaxThreads);
	app->WriteProfileInt("Options","PingSize",m_PingSize);
	app->WriteProfileInt("Options","PingsPerHost",m_PingsPerHost);
	app->WriteProfileInt("Options","SortBy",m_SortCriteria);
	app->WriteProfileInt("Options","TimeOutHi",HIWORD(m_TimeOut));
	app->WriteProfileInt("Options","TimeOutLo",LOWORD(m_TimeOut));
	app->WriteProfileInt("Options","InnermostURL",m_bMSWorkAround);
	app->WriteProfileInt("Options","AutoBest",m_bAutoBest);
	app->WriteProfileInt("Options","SmartAdjust",m_bSmartAdjust);
	app->WriteProfileInt("Options","AdjustInnermost",m_bAdjustInnermost);
	app->WriteProfileInt("Options","IgnoreRelative",m_bIgnorelative);
	app->WriteProfileString("Options","ImportExportPath",m_impexPath);
CRect rc;
	GetWindowRect(&rc);
	app->WriteProfileInt("Windows","DlgTop",rc.top);
	app->WriteProfileInt("Windows","DlgBottom",rc.bottom);
	app->WriteProfileInt("Windows","DlgLeft",rc.left);
	app->WriteProfileInt("Windows","DlgRight",rc.right);
	m_DragPad->GetWindowRect(&rc);
	app->WriteProfileInt("Windows","DragPadTop",rc.top);
	app->WriteProfileInt("Windows","DragPadLeft",rc.left);
	// Columns
	app->WriteProfileInt("Columns","HostName",m_HostList.GetColumnWidth(0));
	app->WriteProfileInt("Columns","HostIP",m_HostList.GetColumnWidth(1));
	app->WriteProfileInt("Columns","MinRTT",m_HostList.GetColumnWidth(2));
	app->WriteProfileInt("Columns","AvgRTT",m_HostList.GetColumnWidth(3));
	app->WriteProfileInt("Columns","MaxRTT",m_HostList.GetColumnWidth(4));
	app->WriteProfileInt("Columns","PktLoss",m_HostList.GetColumnWidth(5));
	m_bExiting=TRUE;
	CDialog::OnOK();
}

void CDipstickDlg::OnCancel() 
{
}

void CDipstickDlg::OnManualping() 
{
CHostNameDlg hnd(this);
	if(hnd.DoModal()==IDOK && !hnd.m_Host.IsEmpty()){
	CString *host = new CString(hnd.m_Host);
		ASSERT(host);
		PostMessage(WM_DNP_URLPING,0,(LPARAM)host);
	}
}

void CDipstickDlg::OnDragpadManualping()
{
	OnManualping();
}

void CDipstickDlg::OnDragpadRepingAll()
{
	OnRepingall();
}
void CDipstickDlg::OnDragpadRemoveAll()
{
	OnClear();
}

void CDipstickDlg::OnReping() 
{
	if(!m_HostList.GetSelectedCount())
		return;
int	items = m_HostList.GetItemCount();
	for(int tmp=0;tmp<items;tmp++){
		if(!(m_HostList.GetItemState(tmp,LVIS_SELECTED)&LVIS_SELECTED))
			continue;
	CPingyHost *host = (CPingyHost*) m_HostList.GetItemData(tmp);
		ASSERT(host);
		if(host->m_Pinged && !host->m_Pinging)
			host->m_bToPing=TRUE;
	}
	UpdateDragpadTitle();
	CheckForPendingRequests();
}

void CDipstickDlg::OnRepingall() 
{
POSITION p = m_Hosts.GetHeadPosition();
	while(p){
	CPingyHost *host = m_Hosts.GetNext(p);
		ASSERT(host);
		if(host->m_Pinged && !host->m_Pinging)
			host->m_bToPing=TRUE;
	}
	UpdateDragpadTitle();
	CheckForPendingRequests();
}

void CDipstickDlg::OnClear() 
{
	if(m_ActiveThreads)
		return;
	m_HostList.DeleteAllItems();
	// *** Eventually move the following code to separate function
POSITION p = m_Hosts.GetHeadPosition();
	while(p){
	POSITION pp = p;
	CPingyHost *host = (CPingyHost*)m_Hosts.GetNext(p);
		ASSERT(host);
		m_Hosts.RemoveAt(pp);
		host->Suicide();
	}
	ASSERT(m_Hosts.IsEmpty());
	UpdateDragpadTitle();
}

void CDipstickDlg::OnInsertitemHostlist(NMHDR* pNMHDR, LRESULT* pResult) 
{
NM_LISTVIEW* pNMListView = (NM_LISTVIEW*)pNMHDR;
	m_RepingCtl.EnableWindow(TRUE);
	m_RepingAllCtl.EnableWindow(TRUE);
	UpdateDragpadTitle();
	*pResult = 0;
}

void CDipstickDlg::OnDeleteitemHostlist(NMHDR* pNMHDR, LRESULT* pResult) 
{
NM_LISTVIEW* pNMListView = (NM_LISTVIEW*)pNMHDR;
	if(!m_HostList.GetItemCount()){
		m_RepingCtl.EnableWindow(FALSE);
		m_RepingAllCtl.EnableWindow(FALSE);
		m_ClearListCtl.EnableWindow(FALSE);
	}
	UpdateDragpadTitle();
	*pResult = 0;
}

void CDipstickDlg::OnDeleteallitemsHostlist(NMHDR* pNMHDR, LRESULT* pResult) 
{
NM_LISTVIEW* pNMListView = (NM_LISTVIEW*)pNMHDR;
	m_RepingCtl.EnableWindow(FALSE);
	m_RepingAllCtl.EnableWindow(FALSE);
	m_ClearListCtl.EnableWindow(FALSE);
	UpdateDragpadTitle();
	*pResult = 0;
}

void CDipstickDlg::OnExit() 
{
	OnOK();
}

void CDipstickDlg::OnItemchangedHostlist(NMHDR* pNMHDR, LRESULT* pResult) 
{
NM_LISTVIEW* pNMListView = (NM_LISTVIEW*)pNMHDR;
	if(pNMListView->uChanged&LVIF_STATE && (pNMListView->uOldState&LVIS_SELECTED)!=(pNMListView->uNewState&LVIS_SELECTED))
		UpdateControlButtons();
	UpdateDragpadTitle();
	*pResult = 0;
}

void CDipstickDlg::UpdateControlButtons()
{
int items = m_HostList.GetItemCount();
	if(!items){
		m_ClearListCtl.EnableWindow(FALSE);
		m_RemoveCtl.EnableWindow(FALSE);
		m_RepingAllCtl.EnableWindow(FALSE);
		m_RepingCtl.EnableWindow(FALSE);
		return;
	}
BOOL cl = m_ActiveThreads?FALSE:TRUE, rm = FALSE, ra = FALSE, rp = FALSE;
	for(int tmp=0;tmp<items;tmp++){
	CPingyHost *host = (CPingyHost*)m_HostList.GetItemData(tmp);
		if(!host->m_Pinging){
			ra=TRUE;
			if(m_HostList.GetItemState(tmp,LVIS_SELECTED)&LVIS_SELECTED){
				rp = TRUE;
				rm = TRUE;
				break;
			}
		}
	}
	m_ClearListCtl.EnableWindow(cl);
	m_RemoveCtl.EnableWindow(rm);
	m_RepingAllCtl.EnableWindow(ra);
	m_RepingCtl.EnableWindow(rp);
}

void CDipstickDlg::OnRemove() 
{
	if(!m_HostList.GetSelectedCount())
		return;
int	items = m_HostList.GetItemCount();
	for(int tmp=0;tmp<items;tmp++){
		if(!(m_HostList.GetItemState(tmp,LVIS_SELECTED)&LVIS_SELECTED))
			continue;
	CPingyHost *host = (CPingyHost*) m_HostList.GetItemData(tmp);
		ASSERT(host);
		if(!host->m_Pinging)
			RemovePingyHost(host,tmp);
	}
}

void CDipstickDlg::OnRclickHostlist(NMHDR* pNMHDR, LRESULT* pResult) 
{
	if(!m_HostList.GetSelectedCount())
		return;
int items = m_HostList.GetItemCount();
int item = -1;
	for(int tmp=0;tmp<items;tmp++){
	int	s = m_HostList.GetItemState(tmp,LVIS_SELECTED|LVIS_FOCUSED);
		if(s&LVIS_FOCUSED){
			item = tmp;
			break;
		}
		if(s&LVIS_SELECTED)
			item=tmp;
	}
	ASSERT(item>=0);
CPoint p;
	VERIFY(m_HostList.GetItemPosition(item,&p));
CPingyHost *host = (CPingyHost*)m_HostList.GetItemData(item);
	ASSERT(host);
	m_HostList.ClientToScreen(&p);
CMenu menus;
	VERIFY(menus.LoadMenu(IDR_MENU));
CMenu *popUp = menus.GetSubMenu(1);
	ASSERT(popUp);
	UpdateControlButtons();
	popUp->EnableMenuItem(ID_HOSTLIST_REPING,MF_BYCOMMAND|(m_RepingCtl.IsWindowEnabled()?MF_ENABLED:MF_GRAYED));
	popUp->EnableMenuItem(ID_HOSTLIST_REMOVE,MF_BYCOMMAND|(m_RemoveCtl.IsWindowEnabled()?MF_ENABLED:MF_GRAYED));
	popUp->EnableMenuItem(ID_HOSTLIST_REMOVEALL,MF_BYCOMMAND|(m_ClearListCtl.IsWindowEnabled()?MF_ENABLED:MF_GRAYED));
	popUp->EnableMenuItem(ID_HOSTLIST_REPINGALL,MF_BYCOMMAND|(m_RepingAllCtl.IsWindowEnabled()?MF_ENABLED:MF_GRAYED));
	popUp->EnableMenuItem(ID_HOSTLIST_OPENURL,MF_BYCOMMAND|((m_HostList.GetSelectedCount()==1 && !host->m_URL.IsEmpty())?MF_ENABLED:MF_GRAYED));
	popUp->EnableMenuItem(ID_HOSTLIST_COPYURL,MF_BYCOMMAND|((m_HostList.GetSelectedCount()==1 && !host->m_URL.IsEmpty())?MF_ENABLED:MF_GRAYED));
	popUp->EnableMenuItem(ID_HOSTLIST_PROPERTIES,MF_BYCOMMAND|((m_HostList.GetSelectedCount()==1)?MF_ENABLED:MF_GRAYED));
	popUp->EnableMenuItem(ID_HOSTLIST_PASTEURL,MF_BYCOMMAND|(IsPasteableClipboard()?MF_ENABLED:MF_GRAYED));
	popUp->TrackPopupMenu(TPM_LEFTALIGN|TPM_RIGHTBUTTON|TPM_LEFTBUTTON,p.x,p.y,this);
	*pResult = 0;
}

void CDipstickDlg::OnHostListReping()
{
	OnReping();
}
void CDipstickDlg::OnHostListRemove()
{
	OnRemove();
}
void CDipstickDlg::OnHostListRepingAll()
{
	OnRepingall();
}
void CDipstickDlg::OnHostListRemoveAll()
{
	OnClear();
}
void CDipstickDlg::OnHostListOpenURL()
{
	if(m_HostList.GetSelectedCount()!=1)
		return;
int items = m_HostList.GetItemCount();
	for(int tmp=0;tmp<items;tmp++){
		if((m_HostList.GetItemState(tmp,LVIS_SELECTED|LVIS_FOCUSED))&LVIS_SELECTED)
			break;
	}
	ASSERT(tmp<items);
CPingyHost *host = (CPingyHost*)m_HostList.GetItemData(tmp);
	ASSERT(host);
	if(!host->m_URL.IsEmpty())
		ShellExecute(::GetDesktopWindow(),NULL,host->m_URL,NULL,NULL,SW_SHOWMAXIMIZED);
}

void CDipstickDlg::OnHostListProperties()
{
	if(m_HostList.GetSelectedCount()!=1)
		return;
int items = m_HostList.GetItemCount();
	for(int tmp=0;tmp<items;tmp++){
		if((m_HostList.GetItemState(tmp,LVIS_SELECTED|LVIS_FOCUSED))&LVIS_SELECTED)
			break;
	}
	ASSERT(tmp<items);
CPingyHost *host = (CPingyHost*)m_HostList.GetItemData(tmp);
	ASSERT(host);
CHostProperties hp(this);
	hp.SetHost(host);
	hp.DoModal();
}

void CDipstickDlg::OnDblclkHostlist(NMHDR* pNMHDR, LRESULT* pResult) 
{
	OnHostListOpenURL();
	*pResult = 0;
}

void CDipstickDlg::OnClose() 
{
	m_bShown=FALSE;
	ShowWindow(SW_HIDE);
}

BOOL CAboutDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	return TRUE;
}

void CDipstickDlg::OnGetMinMaxInfo(MINMAXINFO FAR* lpMMI) 
{
	CDialog::OnGetMinMaxInfo(lpMMI);
	if(m_MinSize.cx>0 && m_MinSize.cy>0){
		lpMMI->ptMinTrackSize.x = m_MinSize.cx;
		lpMMI->ptMinTrackSize.y = m_MinSize.cy;
	}
}

void CDipstickDlg::OnSize(UINT nType, int cx, int cy) 
{
	CDialog::OnSize(nType, cx, cy);
	if(nType==SIZE_RESTORED)
		RecalcLayout(cx,cy);
}

void CDipstickDlg::RecalcLayout(int,int)
{
CRect wrc;
	GetClientRect(&wrc);
CRect brc;
	m_ManualPingCtl.GetWindowRect(&brc);
	m_HostList.SetWindowPos(NULL,m_OverX,m_OverY,wrc.Width()-m_OverX*3-brc.Width(),wrc.Height()-m_OverY*2,SWP_NOACTIVATE|SWP_NOOWNERZORDER|SWP_NOZORDER);
int xb = wrc.Width()-m_OverX-brc.Width();
int cyb = brc.Height()+m_GapY;
	m_ManualPingCtl.SetWindowPos(NULL,xb,m_OverY,0,0,SWP_NOACTIVATE|SWP_NOOWNERZORDER|SWP_NOSIZE|SWP_NOZORDER|SWP_NOCOPYBITS);
	m_RepingCtl.SetWindowPos(NULL,xb,m_OverY+cyb,0,0,SWP_NOACTIVATE|SWP_NOOWNERZORDER|SWP_NOSIZE|SWP_NOZORDER|SWP_NOCOPYBITS);
	m_RepingAllCtl.SetWindowPos(NULL,xb,m_OverY+cyb*2,0,0,SWP_NOACTIVATE|SWP_NOOWNERZORDER|SWP_NOSIZE|SWP_NOZORDER|SWP_NOCOPYBITS);
	m_RemoveCtl.SetWindowPos(NULL,xb,m_OverY+cyb*3,0,0,SWP_NOACTIVATE|SWP_NOOWNERZORDER|SWP_NOSIZE|SWP_NOZORDER|SWP_NOCOPYBITS);
	m_ClearListCtl.SetWindowPos(NULL,xb,m_OverY+cyb*4,0,0,SWP_NOACTIVATE|SWP_NOOWNERZORDER|SWP_NOSIZE|SWP_NOZORDER|SWP_NOCOPYBITS);
	m_AdvancedCtl.SetWindowPos(NULL,xb,m_OverY+cyb*5,0,0,SWP_NOACTIVATE|SWP_NOOWNERZORDER|SWP_NOSIZE|SWP_NOZORDER|SWP_NOCOPYBITS);
	m_ExitCtl.SetWindowPos(NULL,xb,wrc.Height()-m_OverY-brc.Height(),0,0,SWP_NOACTIVATE|SWP_NOOWNERZORDER|SWP_NOSIZE|SWP_NOZORDER|SWP_NOCOPYBITS);
	m_OptionsCtl.SetWindowPos(NULL,xb,wrc.Height()-m_OverY-cyb-brc.Height(),0,0,SWP_NOACTIVATE|SWP_NOOWNERZORDER|SWP_NOSIZE|SWP_NOZORDER|SWP_NOCOPYBITS);
	m_HelpCtl.SetWindowPos(NULL,xb,wrc.Height()-m_OverY-cyb*2-brc.Height(),0,0,SWP_NOACTIVATE|SWP_NOOWNERZORDER|SWP_NOSIZE|SWP_NOZORDER|SWP_NOCOPYBITS);
}

void CDipstickDlg::OnHelp() 
{
	WinHelp(0,HELP_FINDER);
}

void CDipstickDlg::UpdateDragpadTitle()
{
int ic = m_HostList.GetItemCount();
CString title;
	if(!ic){
		VERIFY(title.LoadString(IDS_DRAGPAD_TITLE));
	}else{
	int ip = 0;
	POSITION p = m_Hosts.GetHeadPosition();
		while(p){
		CPingyHost *host = m_Hosts.GetNext(p);
			ASSERT(host);
			if(!(host->m_Pinging || host->m_bToPing))
				ip++;
		}
		title.Format(IDS_DRAGPAD_URLS,ip,ic);
	}
	if(m_DragPad)
		m_DragPad->SetWindowText(title);
}

void CDipstickDlg::OnBegindragHostlist(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_LISTVIEW* pNMListView = (NM_LISTVIEW*)pNMHDR;

	if(pNMListView->iItem>=0){
	CPingyHost *host = (CPingyHost*) m_HostList.GetItemData(pNMListView->iItem);
		ASSERT(host);
		if(!host->m_URL.IsEmpty()){
		CURLSource us(host->m_URL);
			us.DoDragDrop(DROPEFFECT_COPY|DROPEFFECT_LINK);
		}
	}

	*pResult = 0;
}

void CDipstickDlg::OnPasteurl() 
{
COleDataObject odo;
	if(!odo.AttachClipboard())
		return;
	CollectURLs(&odo,FALSE);
}

BOOL CDipstickDlg::IsPasteableClipboard()
{
COleDataObject odo;
	if(!odo.AttachClipboard())
		return FALSE;
	if(CollectURLs(&odo,TRUE))
		return TRUE;
	return FALSE;
}

BOOL CDipstickDlg::CollectURLs(COleDataObject* pDO,BOOL bTestOnly)
{
UINT	cfURL = RegisterClipboardFormat("UniformResourceLocator");
UINT	cfHTML = RegisterClipboardFormat("HTML Format");
UINT	cfNIF = RegisterClipboardFormat("Netscape Image Format");
	if(pDO->IsDataAvailable(cfURL)){
		if(!bTestOnly){
		HGLOBAL hg = pDO->GetGlobalData(cfURL);
			ASSERT(hg);
		LPVOID lpv = GlobalLock(hg);
			ASSERT(lpv);
			PostMessage(WM_DNP_URLPING,0,(LPARAM)new CString((LPCTSTR)lpv));
			GlobalUnlock(hg);
			GlobalFree(hg);
		}
		return TRUE;
	}
	if(pDO->IsDataAvailable(cfHTML)){
	HGLOBAL hg = pDO->GetGlobalData(cfHTML);
		ASSERT(hg);
	LPCTSTR lps = (LPCTSTR)GlobalLock(hg);
		ASSERT(lps);
	BOOL rv = FALSE;
		do{
		static LPCTSTR v10 = "Version:1.0\r\n";
			if(memcmp(v10,lps,strlen(v10)))
				break;
		static LPCTSTR strStartSelection = "StartSelection:";
		static LPCTSTR strEndSelection = "EndSelection:";
		static LPCTSTR strSourceURL = "SourceURL:";
		LPTSTR subs = strstr(lps,strStartSelection);
			if(!subs)
				break;
		LONG startSelection = atol(&subs[strlen(strStartSelection)]);
			if(!startSelection)
				break;
			if(!(subs=strstr(lps,strEndSelection)))
				break;
		LONG endSelection = atol(&subs[strlen(strEndSelection)]);
			if(!endSelection)
				break;
			if(!(subs=strstr(lps,strSourceURL)))
				break;
			subs = &subs[strlen(strSourceURL)];
		LPTSTR eol = strchr(subs,'\r');
			if(!eol)
				break;
			(*eol)=0;
		CString sourceURL = subs;
			if(!sourceURL.GetLength())
				break;
			TRACE0("SourceURL = "+sourceURL+"\n");
		_xferHTML* xf = new _xferHTML;
			VERIFY(xf->src.Crack(sourceURL));
		LPTSTR htmlBuff = xf->html.GetBuffer(endSelection-startSelection+2);
			ASSERT(htmlBuff);
			memmove(htmlBuff,&lps[startSelection],endSelection-startSelection+1);
			htmlBuff[endSelection-startSelection+1]=0;
			xf->html.ReleaseBuffer();
			if(bTestOnly){
				rv = m_reHTMLURL.Match(xf->html);
				delete xf;
			}else{
				PostMessage(WM_DNP_HTML,0,(LPARAM)xf);
			}
		}while(FALSE);
		GlobalUnlock(hg);
		GlobalFree(hg);
		return rv;
	}
	if(pDO->IsDataAvailable(cfNIF)){
		if(!bTestOnly){
		HGLOBAL hg = pDO->GetGlobalData(cfNIF);
			ASSERT(hg);
		LPVOID lpv = GlobalLock(hg);
			ASSERT(lpv);
		struct	_nif	{
			BYTE data[0x20];
			DWORD m_offDescr;
			DWORD m_offURL;
			DWORD m_offToImage;
		} *nif = (_nif*)lpv;
			PostMessage(WM_DNP_URLPING,0,(LPARAM)new CString((LPCTSTR)&nif->data[nif->m_offURL]));
			GlobalUnlock(hg);
			GlobalFree(hg);
		}
		return TRUE;
	}
	if(pDO->IsDataAvailable(CF_TEXT)){
		if(!bTestOnly){
		HGLOBAL hg = pDO->GetGlobalData(CF_TEXT);
			ASSERT(hg);
		LPVOID lpv = GlobalLock(hg);
			ASSERT(lpv);
			PostMessage(WM_DNP_URLPING,0,(LPARAM)new CString((LPCTSTR)lpv));
			GlobalUnlock(hg);
			GlobalFree(hg);
		}
		return TRUE;
	}
	return FALSE;
}

LRESULT CDipstickDlg::OnHTMLTransfer(WPARAM wP, LPARAM lP)
{
_xferHTML* xf = (_xferHTML*)lP;
CSelectURLsDlg su;
	su.m_bAdjust = m_bSmartAdjust;
	su.m_bAdjustInnermost = m_bAdjustInnermost;
	BeginWaitCursor();
	while(m_reHTMLURL.Match(xf->html)){
	CString url = m_reHTMLURL.GetMatch(1);
		xf->html = m_reHTMLURL.GetMatch(CRegEx::matchPostMatch);
		if(CCrackURL::GetHostName(url)==url){
			if(m_bIgnorelative)
				continue;
		CCrackURL cracked;
			VERIFY(cracked.Crack(url));
			cracked.Adjust(xf->src);
			url = cracked.Build();
		}
		if(!su.m_URLs.Find(url))
			VERIFY(su.m_URLs.AddTail(url));
	}
	EndWaitCursor();
	delete xf;
	if(su.DoModal()==IDOK){
	POSITION p = su.m_URLs.GetHeadPosition();
		while(p){
		CString url = su.m_URLs.GetNext(p);
			PostMessage(WM_DNP_URLPING,0,(LPARAM)new CString(url));
		}
	}
	return 0;
}

UINT CPingyHost::PingProc(LPVOID pParam)
{
CPingyHost* pThis = (CPingyHost*)pParam;
	ASSERT(pThis->m_Daddy);
	return pThis->DoPing();
}

UINT CPingyHost::DoPing()
{
CSingleLock slock(&m_mutex);
	if(!slock.Lock(2000)){
		m_Status.LoadString(IDS_PS_FAILEDTOLOCK);
		return 1;
	}
	m_Pinging = TRUE;
	m_bToPing = FALSE;
	VERIFY(m_Daddy->m_eveStartup.SetEvent());
	m_Daddy->PostMessage(WM_DNP_UPDATEHOSTDATA,0,(LPARAM)this);
in_addr ip;
UINT packets, lost;
	packets=lost=0;
CICMP* pICMP = NULL;
UINT dataSize = m_Daddy->m_PingSize;
int	ploss = 100;
	do{
		if(m_HostName.IsEmpty()){
			ip.s_addr = m_IP;
		hostent *he = gethostbyaddr((char*)&ip,4,PF_INET);
			if(!he)
				m_HostName.Empty();
			else
				m_HostName = he->h_name;
		}else{
		hostent *he = gethostbyname(m_HostName);
			if(!he){
				m_Status.LoadString(IDS_PS_FAILEDTORESOLVE);
				m_IP = 0;
				break;
			}
			memmove(&ip.s_addr,he->h_addr,sizeof(ip.s_addr));
			m_IP = ip.s_addr;
		}
		pICMP = CICMP::CreateICMP();
		if(!(pICMP && pICMP->Initialize())){
			m_Status.LoadString(IDS_PS_UNABLETOICMP);
			break;
		}
		m_Daddy->PostMessage(WM_DNP_UPDATEHOSTDATA,0,(LPARAM)this);
	ULONG sum, num, pmin, pmax;
		sum = num = 0;
		pmin = 0xFFFFFFFF;
		pmax = 0;
	UINT seq;
		for(seq = 0;seq<m_Daddy->m_PingsPerHost;seq++){
		INT status;
		LONG rtt = pICMP->Ping(ip,dataSize,m_Daddy->m_TimeOut,&status);
		UINT stString = 0;
			switch(status){
			case CICMP::ipSuccess:
				sum+=rtt; num++;
				if(rtt<pmin)
					pmin=rtt;
				if(rtt>pmax)
					pmax=rtt;
				break;
			case CICMP::ipBuffTooSmall: stString = IDS_PS_INTERNALERROR;
				break;
			case CICMP::ipDestNetUnreachable: stString = IDS_PS_NETUNREACHABLE;
				break;
			case CICMP::ipDestHostUnreachable: stString = IDS_PS_HOSTUNREACHABLE;
				break;
			case CICMP::ipDestProtUnreachable: stString = IDS_PS_PROTUNREACHABLE;
				break;
			case CICMP::ipDestPortUnreachable: stString = IDS_PS_PORTUNREACHABLE;
				break;
			case CICMP::ipNoResources: stString = IDS_PS_NORESOURCES;
				break;
			case CICMP::ipBadOption: stString = IDS_PS_INTERNALERROR;
				break;
			case CICMP::ipHWError: stString = IDS_PS_HWERROR;
				break;
			case CICMP::ipPacketTooBig: stString = IDS_PS_BIGPACKET;
				break;
			case CICMP::ipTimeOut: stString = IDS_PS_TIMEOUT;
				break;
			case CICMP::ipBadRequest: stString = IDS_PS_INTERNALERROR;
				break;
			case CICMP::ipBadRoute: stString = IDS_PS_BADROUTE;
				break;
			case CICMP::ipTTLExpiredInTransit: stString = IDS_PS_TTLEXPTRANSIT;
				break;
			case CICMP::ipTTLExpiredInReasm: stString = IDS_PS_TTLEXPREASM;
				break;
			case CICMP::ipParamProblem: stString = IDS_PS_IPARAMP;
				break;
			case CICMP::ipSourceQuench: stString = IDS_PS_SOURCEQUENCH;
				break;
			case CICMP::ipOptionTooBig: stString = IDS_PS_BIGOPTION;
				break;
			case CICMP::ipBadDest: stString = IDS_PS_BADDEST;
				break;
			default:
				stString = IDS_PS_UNKNOWNERROR;
				break;
			}
			if(stString)
				m_Status.LoadString(stString);
			packets++;
			if(rtt<0)
				lost++;
			Sleep(m_Daddy->m_Interval);
		}
		if(packets==lost || !packets){
			ploss=100;
		}else{
			ploss = lost*100/packets;
			m_MinRTT = pmin;
			m_MaxRTT = pmax;
			if(sum){
				ASSERT(num);
				m_AvgRTT = sum/num;
			}else{
				m_AvgRTT = 0;
			}
		}
	}while(FALSE);
	m_Packetloss=ploss;
	m_Pinged=TRUE;
	m_Pinging=FALSE;
	if(pICMP){
		pICMP->Deinitialize();
		delete pICMP;
	}
	m_Daddy->PostMessage(WM_DNP_UPDATEHOSTDATA,0,(LPARAM)this);
	m_Daddy->PostMessage(WM_DNP_ACTIVITYCOUNT,(WPARAM)-1);
	return 0;
}

void CPingyHost::Ping()
{
	ASSERT(m_Daddy);
	m_Daddy->m_eveStartup.ResetEvent();
	if(!AfxBeginThread(CPingyHost::PingProc,this)){
		ASSERT(FALSE);
	}else{
	CSingleLock sl(&m_Daddy->m_eveStartup);
		sl.Lock();
		m_Daddy->SendMessage(WM_DNP_ACTIVITYCOUNT,(WPARAM)1);	// *** AWFUL! Shouldn't be here!
	}
}

void CDipstickDlg::OnHostlistCopyurl() 
{
	if(m_HostList.GetSelectedCount()!=1)
		return;
int items = m_HostList.GetItemCount();
	for(int tmp=0;tmp<items;tmp++){
		if((m_HostList.GetItemState(tmp,LVIS_SELECTED|LVIS_FOCUSED))&LVIS_SELECTED)
			break;
	}
	ASSERT(tmp<items);
CPingyHost *host = (CPingyHost*)m_HostList.GetItemData(tmp);
	ASSERT(host);
	if(!host->m_URL.IsEmpty()){
	CURLSource *us = new CURLSource(host->m_URL);
		us->SetClipboard();
		us->FlushClipboard();
	}
}

BOOL CDipstickDlg::OnHelpInfo(HELPINFO* pHelpInfo) 
{
	WinHelp(IDD|0x20000l);
	return TRUE;
}

void CDipstickDlg::OnDropFiles(HDROP hDropInfo) 
{
	// *** Import only 1st file, but maybe we should fall into prompt mode if multiple files are dropped.
CString fileName;
int bufferSize = DragQueryFile(hDropInfo,0,NULL,0);
	DragQueryFile(hDropInfo,0,fileName.GetBuffer(bufferSize+2),bufferSize+1);
	fileName.ReleaseBuffer();
	if(fileName.IsEmpty())
		CDialog::OnDropFiles(hDropInfo);
	else
		ImportLocations(fileName);
}

BOOL CDipstickDlg::ImportLocations(LPCTSTR file)
{
CString fileLine;
CString q;
	try{
	CStdioFile f(file,CFile::modeRead|CFile::typeText|CFile::shareDenyWrite);
		// *** Cleanup locations..
		while(f.ReadString(fileLine)){
			if(fileLine.IsEmpty())
				continue;
			if(fileLine[0]=='\"' || fileLine[0]=='\''){
			TCHAR q = fileLine[0];
				fileLine=fileLine.Mid(1);
				for(int tmp=0;tmp<fileLine.GetLength();tmp++){
					if(fileLine[tmp]!=q)
						continue;
					if(!tmp){
						fileLine.Empty();
						break;
					}
					fileLine=fileLine.Left(tmp);
					break;
				}
			}else{
			int co = fileLine.Find(',');
				if(co>=0)
					fileLine=fileLine.Left(co);
			}
			if(fileLine.IsEmpty())
				continue;
			if(!fileLine.CompareNoCase("url"))
				continue;
			PostMessage(WM_DNP_URLPING,0,(LPARAM)new CString(fileLine));
		}
	}catch(CException* e){
		e->Delete();
		TRACE0("Failed to import URLList file\n");
		return FALSE;
	}
	return TRUE;
}

void CDipstickDlg::OnAdvanced() 
{
CRect rc;
	m_AdvancedCtl.GetClientRect(rc);
	m_AdvancedCtl.ClientToScreen(rc);
CMenu menus;
	VERIFY(menus.LoadMenu(IDR_MENU));
CMenu *popUp = menus.GetSubMenu(2);
	ASSERT(popUp);
	popUp->EnableMenuItem(ID_ADVANCED_EXPORTLIST,MF_BYCOMMAND|(m_HostList.GetItemCount()?MF_ENABLED:MF_GRAYED));
	popUp->TrackPopupMenu(TPM_CENTERALIGN|TPM_RIGHTBUTTON|TPM_LEFTBUTTON,(rc.left+rc.right)/2,rc.top,this);
}

void CDipstickDlg::OnAdvancedExportlist() 
{
CString filter;
	filter.LoadString(IDS_CSVFILTER);
CFileDialog cfd(FALSE,".csv",NULL,OFN_EXPLORER|OFN_HIDEREADONLY|OFN_PATHMUSTEXIST,filter,this);
	if(!m_impexPath.IsEmpty())
		SetCurrentDirectory(m_impexPath);
	if(cfd.DoModal()==IDOK){
		GetCurrentDirectory(2048,m_impexPath.GetBuffer(2048));
		m_impexPath.ReleaseBuffer();
		ExportLocations(cfd.GetPathName());
	}
}

void CDipstickDlg::OnAdvancedImportlist() 
{
CString filter;
	filter.LoadString(IDS_CSVFILTER);
CFileDialog cfd(TRUE,".csv",NULL,OFN_EXPLORER|OFN_HIDEREADONLY|OFN_PATHMUSTEXIST|OFN_FILEMUSTEXIST,filter,this);
	if(!m_impexPath.IsEmpty())
		SetCurrentDirectory(m_impexPath);
	if(cfd.DoModal()==IDOK){
		GetCurrentDirectory(2048,m_impexPath.GetBuffer(2048));
		m_impexPath.ReleaseBuffer();
		ImportLocations(cfd.GetPathName());
	}
}

BOOL CDipstickDlg::ExportLocations(LPCTSTR file)
{
	try{
	CStdioFile f(file,CFile::modeCreate|CFile::modeWrite|CFile::typeText);
		f.WriteString("URL,Host Name,IP Address, Min RTT,Avg RTT,Max RTT,Pktloss\n");
	POSITION p = m_Hosts.GetHeadPosition();
		while(p){
		CPingyHost *host = m_Hosts.GetNext(p);
			ASSERT(host);
		CString ph;
			ph.Format("\"%s\",%s,%s,%lu,%lu,%lu,%d%%\n",host->m_URL,host->m_HostName,inet_ntoa(*(in_addr*)&host->m_IP),
				host->m_MinRTT,host->m_AvgRTT,host->m_MaxRTT,host->m_Packetloss
			);
			f.WriteString(ph);
		}
		f.Close();
	}catch(CException* e){
		TRACE0("Failed to export URLList\n");
		e->Delete();
		return FALSE;
	}
	return TRUE;
}

void CDipstickDlg::OnDragpadAdvancedExportlist() 
{
	OnAdvancedExportlist();
}

void CDipstickDlg::OnDragpadAdvancedImportlist() 
{
	OnAdvancedImportlist();
}

void CPingyHost::Suicide()
{
CSingleLock sl(&m_mutex);
	if(sl.Lock(10)){
		sl.Unlock();
		delete this;
	}else{
		if(!AfxBeginThread(CPingyHost::SuicideProc,this))
			ASSERT(FALSE);
	}
}

UINT CPingyHost::SuicideProc(LPVOID pParam)
{
CPingyHost* pThis = (CPingyHost*)pParam;
CSingleLock sl(&pThis->m_mutex);
	sl.Lock();
	VERIFY(sl.Unlock());
	delete pThis;
	return 0;
}
