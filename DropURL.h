// DropURL.h : header file
//



/////////////////////////////////////////////////////////////////////////////
// CDropURL command target

class CDragPad;
class CDropURL : public CCmdTarget
{
	DECLARE_DYNCREATE(CDropURL)

	CDropURL();           // protected constructor used by dynamic creation

// Attributes
public:
	CDragPad* m_Pad;
	HRESULT Drop(IDataObject *pDataObject,DWORD grfKeyState,POINTL pt,DWORD *pwdEffect);
	CString GetHostName(IDataObject *pDataObject,CString *url =  NULL);
	HRESULT DragEnter(IDataObject *pDataObject,DWORD grfKeyState,POINTL pt,DWORD *pdwEffect);

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDropURL)
	public:
	virtual void OnFinalRelease();
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CDropURL();

	// Generated message map functions
	//{{AFX_MSG(CDropURL)
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()

	DECLARE_INTERFACE_MAP()

	BEGIN_INTERFACE_PART(DDropTarget, IDropTarget)
		STDMETHOD_(HRESULT, DragEnter)(IDataObject *pDataObject,DWORD grfKeyState,POINTL pt,DWORD *pdwEffect);
		STDMETHOD_(HRESULT, DragOver)(DWORD grfKeyState,POINTL pt,DWORD *pdwEffect);
		STDMETHOD_(HRESULT, DragLeave)(void);
		STDMETHOD_(HRESULT, Drop)(IDataObject *pDataObject,DWORD grfKeyState,POINTL pt,DWORD *pdwEffect);
	END_INTERFACE_PART(DDropTarget);

};

/////////////////////////////////////////////////////////////////////////////
