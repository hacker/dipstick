#include "stdafx.h"
#include "URLSource.h"

#include <intshcut.h>
#include <initguid.h>
#include <isguids.h>

CURLSource::CURLSource(LPCTSTR strURL)
{
IUniformResourceLocator *lpURL;
	if(CoCreateInstance(CLSID_InternetShortcut,NULL,CLSCTX_INPROC_SERVER,IID_IUniformResourceLocator,(LPVOID*)&lpURL)==S_OK){
		ASSERT(lpURL);
		lpURL->SetURL(strURL,IURL_SETURL_FL_GUESS_PROTOCOL);
	LPDATAOBJECT lpDO = NULL;
		VERIFY(lpURL->QueryInterface(IID_IDataObject,(LPVOID*)&lpDO)==S_OK);
	COleDataObject odo;
		odo.Attach(lpDO,TRUE);
		odo.BeginEnumFormats();
	FORMATETC fe;
		while(odo.GetNextFormat(&fe)){
		HGLOBAL hg = odo.GetGlobalData(fe.cfFormat,NULL);
			if(hg)
				CacheGlobalData(fe.cfFormat,hg,NULL);
		}
		lpURL->Release();
	}
HGLOBAL hg = GlobalAlloc(GHND,strlen(strURL)+1);
LPVOID lpv = GlobalLock(hg);
	memmove(lpv,strURL,strlen(strURL)+1);
	GlobalUnlock(hg);
	CacheGlobalData(CF_TEXT,hg,NULL);
}
