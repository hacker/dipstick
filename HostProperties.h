// HostProperties.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CHostProperties dialog

struct CPingyHost;
class CHostProperties : public CDialog
{
// Construction
public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	void SetHost(CPingyHost *host);
	CPingyHost * host;
	CHostProperties(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CHostProperties)
	enum { IDD = IDD_PROPS };
	CStatic	m_StateCtl;
	CStatic	m_URLCaptionCtl;
	CStatic	m_URLCtl;
	CStatic	m_TimesCaptionCtl;
	CStatic	m_TimesCtl;
	CStatic	m_StatusCaptionCtl;
	CStatic	m_StatusCtl;
	CButton	m_OpenURLCtl;
	CStatic	m_LossCaptionCtl;
	CStatic	m_LossCtl;
	CStatic	m_IPCaptionCtl;
	CStatic	m_IPCtl;
	CStatic	m_HostCaptionCtl;
	CStatic	m_HostCtl;
	CString	m_Host;
	CString	m_IP;
	CString	m_Loss;
	CString	m_Status;
	CString	m_Times;
	CString	m_URL;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CHostProperties)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	CToolTipCtrl m_tooltip;

	// Generated message map functions
	//{{AFX_MSG(CHostProperties)
	virtual BOOL OnInitDialog();
	afx_msg void OnOpenurl();
	afx_msg BOOL OnHelpInfo(HELPINFO* pHelpInfo);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
