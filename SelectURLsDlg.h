// SelectURLsDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSelectURLsDlg dialog

class CSelectURLsDlg : public CDialog
{
// Construction
public:
	void RecalcLayout(int cx,int cy);
	CSize m_Gap;
	CSize m_minSize;
	CStringList m_URLs;
	CSelectURLsDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CSelectURLsDlg)
	enum { IDD = IDD_URLS };
	CButton	m_AdjustCtl;
	CButton	m_AdjustInnCtl;
	CButton	m_OkCtl;
	CButton	m_CancelCtl;
	CListBox	m_URLsCtl;
	BOOL	m_bAdjustInnermost;
	BOOL	m_bAdjust;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSelectURLsDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CSelectURLsDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnGetMinMaxInfo(MINMAXINFO FAR* lpMMI);
	afx_msg void OnSelchangeUrls();
	virtual void OnOK();
	afx_msg BOOL OnHelpInfo(HELPINFO* pHelpInfo);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
