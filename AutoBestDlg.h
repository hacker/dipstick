// AutoBestDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CAutoBestDlg dialog

class CAutoBestDlg : public CDialog
{
// Construction
public:
	~CAutoBestDlg();
	BOOL m_bPrev;
	BOOL m_bNext;
	CAutoBestDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CAutoBestDlg)
	enum { IDD = IDD_AUTOBEST };
	CAnimateCtrl	m_DropSourceCtl;
	CButton	m_PrevCtl;
	CButton	m_NextCtl;
	CString	m_PktLoss;
	CString	m_RTT;
	CString	m_URL;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAutoBestDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CAutoBestDlg)
	afx_msg void OnNext();
	afx_msg void OnPrev();
	virtual BOOL OnInitDialog();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnCopyurl();
	afx_msg BOOL OnHelpInfo(HELPINFO* pHelpInfo);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
