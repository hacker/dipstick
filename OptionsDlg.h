// OptionsDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// COptionsDlg dialog

class COptionsDlg : public CDialog
{
// Construction
public:
	COptionsDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(COptionsDlg)
	enum { IDD = IDD_OPTIONS };
	CSpinButtonCtrl	m_SpinTimeOutCtl;
	CSpinButtonCtrl	m_SpinIntervalCtl;
	CSpinButtonCtrl	m_SpinPingSizeCtl;
	CSpinButtonCtrl	m_SpinPingsCtl;
	CSpinButtonCtrl	m_SpinMaxThreadsCtl;
	UINT	m_Pings;
	UINT	m_PingSize;
	DWORD	m_TimeOut;
	DWORD	m_Interval;
	UINT	m_MaxThreads;
	BOOL	m_bMSWorkAround;
	BOOL	m_bAutoBest;
	BOOL	m_bAdjustInn;
	BOOL	m_bIgnorelative;
	BOOL	m_bAdjust;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(COptionsDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	CToolTipCtrl m_tooltip;
	virtual BOOL OnInitDialog();

	// Generated message map functions
	//{{AFX_MSG(COptionsDlg)
	afx_msg BOOL OnHelpInfo(HELPINFO* pHelpInfo);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
