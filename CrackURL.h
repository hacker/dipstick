#ifndef	__CRACKURL_H
#define	__CRACKURL_H

#include "shared-code/RegEx.h"

class CCrackURL	{
public:
	static CString GetHostName(LPCTSTR url);
	static CString InnermostURL(LPCTSTR url);
	CString Build();
	BOOL Adjust(CCrackURL& srcURL);
	CString m_pathPath;
	CString m_pathFile;
	CString m_pathAnchor;
	CString m_pathQuery;
	CString m_urlRest;
	BOOL Adjust(LPCTSTR srcURL);
	CRegEx m_reHTTPReq;
	CRegEx m_reUPHP;
	CString m_URLPath;
	UINT m_nPort;
	CString m_Port;
	CString m_Host;
	CString m_Password;
	CString m_User;
	void ParseUPHP(CString& rest);
	CString m_Schema;
	CString m_URL;
	BOOL Crack(LPCTSTR url);
	CCrackURL();
	CRegEx	m_reSchema;
};

#endif	// __CRACKURL_H
