// DropURL.cpp : implementation file
//

#include "stdafx.h"
#include "Dipstick.h"
#include "DropURL.h"
#include "DragPad.h"
#include "Dipstick.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDropURL

IMPLEMENT_DYNCREATE(CDropURL, CCmdTarget)

CDropURL::CDropURL()
	: m_Pad(NULL)
{
}

CDropURL::~CDropURL()
{
}


BEGIN_MESSAGE_MAP(CDropURL, CCmdTarget)
	//{{AFX_MSG_MAP(CDropURL)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BEGIN_INTERFACE_MAP(CDropURL, CCmdTarget)
	INTERFACE_PART(CDropURL, IID_IDropTarget, DDropTarget)
END_INTERFACE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDropURL message handlers

STDMETHODIMP_(ULONG) CDropURL::XDDropTarget::AddRef()
{
	METHOD_PROLOGUE(CDropURL, DDropTarget)
	return pThis->ExternalAddRef();
}
STDMETHODIMP_(ULONG) CDropURL::XDDropTarget::Release()
{
	METHOD_PROLOGUE(CDropURL, DDropTarget)
	return pThis->ExternalRelease();
}
STDMETHODIMP_(HRESULT) CDropURL::XDDropTarget::QueryInterface(REFIID iid,void FAR* FAR * ppvObj)
{
	METHOD_PROLOGUE(CDropURL, DDropTarget)
	return pThis->ExternalQueryInterface(&iid,ppvObj);
}

STDMETHODIMP_(HRESULT) CDropURL::XDDropTarget::DragEnter(IDataObject *pDataObject,DWORD grfKeyState,POINTL pt,DWORD *pdwEffect)
{
	METHOD_PROLOGUE(CDropURL, DDropTarget)
	TRACE0("DragEnter\n");
	return pThis->DragEnter(pDataObject,grfKeyState,pt,pdwEffect);
}
STDMETHODIMP_(HRESULT) CDropURL::XDDropTarget::DragOver(DWORD grfKeyState,POINTL pt,DWORD *pdwEffect)
{
	METHOD_PROLOGUE(CDropURL, DDropTarget)
	return S_OK;
}
STDMETHODIMP_(HRESULT) CDropURL::XDDropTarget::DragLeave(void)
{
	METHOD_PROLOGUE(CDropURL, DDropTarget)
	TRACE0("DragLeave\n");
	return S_OK;
}
STDMETHODIMP_(HRESULT) CDropURL::XDDropTarget::Drop(IDataObject *pDataObject,DWORD grfKeyState,POINTL pt,DWORD *pdwEffect)
{
	METHOD_PROLOGUE(CDropURL, DDropTarget)
	TRACE0("Drop\n");
	return pThis->Drop(pDataObject,grfKeyState,pt,pdwEffect);
}


HRESULT CDropURL::DragEnter(IDataObject *pDataObject,DWORD grfKeyState,POINTL pt,DWORD *pdwEffect)
{
CString host = GetHostName(pDataObject);
	if(host.IsEmpty()){
		(*pdwEffect)=DROPEFFECT_NONE;
		return S_FALSE;
	}else{
		(*pdwEffect)=DROPEFFECT_LINK;
		return S_OK;
	}
}

CString CDropURL::GetHostName(IDataObject *pDataObject,CString *_url)
{
FORMATETC fetc;
	fetc.cfFormat=CF_TEXT;
	fetc.ptd=NULL;
	fetc.dwAspect=DVASPECT_CONTENT;
	fetc.lindex=-1;
	fetc.tymed=TYMED_HGLOBAL;
STGMEDIUM stgm;
LPVOID	globe = NULL;
CString	url;
CString rv;
	stgm.pUnkForRelease=NULL;
	do{
		if(pDataObject->GetData(&fetc,&stgm)!=S_OK)
			break;
		ASSERT(stgm.tymed==TYMED_HGLOBAL);
		if(GlobalSize(stgm.hGlobal)>=1024)
			break;
		VERIFY(globe=GlobalLock(stgm.hGlobal));
		url=(LPTSTR)globe;
		TRACE0("["+url+"]\n");
		if(_url)
			(*_url) = url;
		rv = m_Pad->m_Daddy->GetHostName(url);
	}while(FALSE);
	if(globe)
		GlobalUnlock(stgm.hGlobal);
	if(stgm.pUnkForRelease)
		stgm.pUnkForRelease->Release();
	return rv;
}

HRESULT CDropURL::Drop(IDataObject *pDataObject,DWORD grfKeyState,POINTL pt,DWORD *pwdEffect)
{
CString url;
CString host = GetHostName(pDataObject,&url);
	if(host.IsEmpty())
		return S_FALSE;
#ifdef	TRUE
	// URL Mode
CString *u = new CString(url);
	m_Pad->m_Daddy->PostMessage(WM_DNP_URLPING,0,(LPARAM)u);
#else
CString *hn = new CString(host);
	m_Pad->m_Daddy->PostMessage(WM_DNP_HOSTPING,0,(LPARAM)hn);
#endif
	return S_OK;
}
void CDropURL::OnFinalRelease() 
{
	TRACE0("Final Release\n");
	CCmdTarget::OnFinalRelease();
}
