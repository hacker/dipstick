// DipstickDlg.h : header file
//

class CDipstickDlg;
struct	CPingyHost	{
	CPingyHost(CDipstickDlg* daddy)	: m_IP(0), m_MinRTT(0), m_AvgRTT(0), m_MaxRTT(0), m_Pinged(FALSE), m_Pinging(FALSE), m_Packetloss(-1), m_bToPing(TRUE), m_Daddy(daddy)	{}
	CPingyHost(CDipstickDlg* daddy,LPTSTR hostname)	: m_HostName(hostname), m_IP(0), m_MinRTT(0), m_AvgRTT(0), m_MaxRTT(0), m_Pinged(FALSE), m_Pinging(FALSE), m_Packetloss(-1), m_bToPing(TRUE), m_Daddy(daddy)	{}
	CPingyHost(CDipstickDlg* daddy,LPTSTR hostname,DWORD ip)	: m_HostName(hostname), m_IP(ip), m_MinRTT(0), m_AvgRTT(0), m_MaxRTT(0), m_Pinged(FALSE), m_Pinging(FALSE), m_Packetloss(-1), m_bToPing(TRUE), m_Daddy(daddy)	{}
	CPingyHost(CDipstickDlg* daddy,DWORD ip)	: m_IP(ip), m_MinRTT(0), m_AvgRTT(0), m_MaxRTT(0), m_Pinged(FALSE), m_Pinging(FALSE), m_Packetloss(-1), m_bToPing(TRUE), m_Daddy(daddy)	{}
public:
	static UINT SuicideProc(LPVOID pParam);
	void Suicide();
	void Ping();
	UINT DoPing();
	static UINT PingProc(LPVOID);
	CDipstickDlg* m_Daddy;
	CMutex m_mutex;
	CString m_Descr;
	CString m_URL;
	BOOL m_bToPing;
	BOOL m_Pinging;
	CString	m_HostName;
	CString m_Status;
	DWORD m_IP;
	ULONG m_MinRTT;
	ULONG m_AvgRTT;
	ULONG m_MaxRTT;
	BOOL m_Pinged;
	int m_Packetloss;
};

typedef	CList<CPingyHost*,CPingyHost*>	CHostList;

/////////////////////////////////////////////////////////////////////////////
// CDipstickDlg dialog

class CDragPad;
class CDipstickDlg : public CDialog
{
// Construction
	struct	_xferHTML	{
		CString html;
		CCrackURL src;
	};
public:
	LRESULT OnURLSPing(WPARAM wP,LPARAM lP);
	CRegEx m_reURL;
	BOOL ExportLocations(LPCTSTR file);
	CString m_impexPath;
	BOOL ImportLocations(LPCTSTR file);
	BOOL m_bIgnorelative;
	CEvent m_eveStartup;
	UINT volatile m_ActiveThreads;
	BOOL m_bAdjustInnermost;
	BOOL m_bSmartAdjust;
	BOOL CollectURLs(COleDataObject* pDO,BOOL bTestOnly=FALSE);
	BOOL IsPasteableClipboard();
	void UpdateDragpadTitle();
	BOOL m_bAutoBest;
	void RecalcLayout(int cx,int cy);
	CSize m_MinSize;
	UINT m_GapY;
	UINT m_OverY;
	UINT m_OverX;
	BOOL m_bMSWorkAround;
	CRegEx m_reCrackHost;
	CRegEx m_reNestedURL;
	CRegEx m_reHTMLURL;		// 1 - URL
	CRegEx m_reCrackURL;	//	3 - schema, 4 - host, 5 - path, 7 - query string
	BITMAP m_bitmapBack;
	CBitmap m_bmpBack;
	int m_iUnreachable;
	int m_iCompleted;
	int m_iPinging;
	int m_iPending;
	CImageList m_Images;
	void UpdateControlButtons();
	BOOL m_bExiting;
	int CheckForPendingRequests();
	UINT m_MaxThreads;
	BOOL m_bShown;
	enum	{
		sortHost, sortIP, sortMin, sortAvg, sortMax, sortLoss
	};
	int m_SortCriteria;
	static int CALLBACK CompareItems(LPARAM lp1, LPARAM lp2, LPARAM lp);
	DWORD m_Interval;
	BOOL RemovePingyHost(CPingyHost *host,int index=-1);
	BOOL UpdatePingyHost(CPingyHost *host,int index=-1);
	BOOL AddPingyHost(CPingyHost *host);
	CHostList m_Hosts;
	enum	{
		subitemHost = 0, subitemIP, subitemMin,subitemAvg,subitemMax, subitemPacketloss
	};
	DWORD m_TimeOut;
	UINT m_PingSize;
	UINT m_PingsPerHost;
	CDragPad * m_DragPad;
	~CDipstickDlg();
	CDipstickDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CDipstickDlg)
	enum { IDD = IDD_DIPSTICK_DIALOG };
	CButton	m_AdvancedCtl;
	CButton	m_HelpCtl;
	CButton	m_ExitCtl;
	CButton	m_OptionsCtl;
	CButton	m_ManualPingCtl;
	CButton	m_RemoveCtl;
	CButton	m_RepingAllCtl;
	CButton	m_RepingCtl;
	CButton	m_ClearListCtl;
	CListCtrl	m_HostList;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDipstickDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CDipstickDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnDestroy();
	afx_msg void OnOptions();
	afx_msg LRESULT OnUrlPing(WPARAM,LPARAM);
	afx_msg LRESULT OnActivityCount(WPARAM,LPARAM);
	afx_msg LRESULT OnUpdateHostData(WPARAM,LPARAM);
	afx_msg LRESULT OnHTMLTransfer(WPARAM,LPARAM);
	afx_msg void OnColumnclickHostlist(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnWindowPosChanging(WINDOWPOS FAR* lpwndpos);
	afx_msg void OnDragpadOptions();
	afx_msg void OnDragpadShowmainwindow();
	afx_msg void OnDragpadHelp();
	afx_msg void OnDragpadAbout();
	afx_msg void OnDragpadExit();
	virtual void OnOK();
	virtual void OnCancel();
	afx_msg void OnManualping();
	afx_msg void OnDragpadManualping();
	afx_msg void OnDragpadRepingAll();
	afx_msg void OnDragpadRemoveAll();
	afx_msg void OnReping();
	afx_msg void OnRepingall();
	afx_msg void OnClear();
	afx_msg void OnInsertitemHostlist(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeleteitemHostlist(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeleteallitemsHostlist(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnExit();
	afx_msg void OnItemchangedHostlist(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnRemove();
	afx_msg void OnRclickHostlist(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnHostListReping();
	afx_msg void OnHostListRemove();
	afx_msg void OnHostListRepingAll();
	afx_msg void OnHostListRemoveAll();
	afx_msg void OnHostListOpenURL();
	afx_msg void OnHostListProperties();
	afx_msg void OnDblclkHostlist(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnClose();
	afx_msg void OnGetMinMaxInfo(MINMAXINFO FAR* lpMMI);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnHelp();
	afx_msg void OnBegindragHostlist(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnPasteurl();
	afx_msg void OnHostlistCopyurl();
	afx_msg BOOL OnHelpInfo(HELPINFO* pHelpInfo);
	afx_msg void OnDropFiles(HDROP hDropInfo);
	afx_msg void OnAdvanced();
	afx_msg void OnAdvancedExportlist();
	afx_msg void OnAdvancedImportlist();
	afx_msg void OnDragpadAdvancedExportlist();
	afx_msg void OnDragpadAdvancedImportlist();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
