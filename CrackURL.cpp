#include "stdafx.h"
#include "CrackURL.h"

CCrackURL::CCrackURL()
{
	VERIFY(m_reSchema.Compile("([[:alpha:]]+):",CRegEx::regExtended|CRegEx::regIgnoreCase));
	VERIFY(m_reUPHP.Compile("(([^:]+)?(:([^@]*))?@)?([^:/]+)(:([[:digit:]]+))?",CRegEx::regExtended|CRegEx::regIgnoreCase));
	VERIFY(m_reHTTPReq.Compile("(.*/)?([^#\\?]*)(#[^\\?]*)?(\\?.*)?",CRegEx::regExtended|CRegEx::regIgnoreCase));
}

BOOL CCrackURL::Crack(LPCTSTR url)
{
	m_URL = url;
CString rest;
	if(m_reSchema.Match(url)){
		m_Schema = m_reSchema.GetMatch(1);
		rest = m_reSchema.GetMatch(CRegEx::matchPostMatch);
	}else{
		m_Schema.Empty();
		rest = url;
	}
	if(rest.Left(2)=="//"){
		// URL conforms to common syntax
		rest=rest.Mid(2);
		ParseUPHP(rest);
	}else if(!m_Schema.CompareNoCase("mailto")){
		ParseUPHP(rest);
	}else{
		m_User.Empty(); m_Password.Empty(); m_Host.Empty(); m_Port.Empty();
	}
	if((!rest.IsEmpty()) && m_reHTTPReq.Match(rest)){
		m_pathPath = m_reHTTPReq.GetMatch(1);
		m_pathFile = m_reHTTPReq.GetMatch(2);
		m_pathAnchor = m_reHTTPReq.GetMatch(3);
		m_pathQuery = m_reHTTPReq.GetMatch(4);
		m_URLPath = m_reHTTPReq.GetMatch(CRegEx::matchMatch);
		rest = m_reHTTPReq.GetMatch(CRegEx::matchPostMatch);
	}else{
		m_URLPath.Empty();
		m_pathPath.Empty();
		m_pathFile.Empty();
		m_pathAnchor.Empty();
		m_pathQuery.Empty();
	}
	m_urlRest = rest;
	return TRUE;
}

void CCrackURL::ParseUPHP(CString& rest)
{
	if(m_reUPHP.Match(rest)){
		m_User = m_reUPHP.GetMatch(2);
		m_Password = m_reUPHP.GetMatch(4);
		m_Host = m_reUPHP.GetMatch(5);
		m_Port = m_reUPHP.GetMatch(7);
		if(!m_Port.IsEmpty())
			m_nPort = atoi(m_Port);
		rest = m_reUPHP.GetMatch(CRegEx::matchPostMatch);
	}else{
		m_User.Empty();
		m_Password.Empty();
		m_Host.Empty();
		m_Port.Empty();
	}
}

BOOL CCrackURL::Adjust(LPCTSTR srcURL)
{
CCrackURL cracked;
	VERIFY(cracked.Crack(srcURL));
	return Adjust(cracked);
}

BOOL CCrackURL::Adjust(CCrackURL& srcURL)
{
	if(m_Schema.IsEmpty()) m_Schema = srcURL.m_Schema;
	if(m_Host.IsEmpty()){
		m_Host = srcURL.m_Host;
		if(m_User.IsEmpty()) m_User = srcURL.m_User;
		if(m_Password.IsEmpty()) m_Password = srcURL.m_Password;
		if(m_Port.IsEmpty()) m_Port = srcURL.m_Port, m_nPort = srcURL.m_nPort;
	}
	if(m_pathPath.Find('/')==0)
		return TRUE;
	m_pathPath = srcURL.m_pathPath+m_pathPath;
	m_URLPath.Empty();
	return TRUE;
}

CString CCrackURL::Build()
{
CString rv;
	if(!m_Schema.IsEmpty())
		rv+=m_Schema+':';
	if(!m_Schema.CompareNoCase("mailto")){
		rv+=m_User+'@'+m_Host;
	}else{
		rv+="//";
		if(!m_User.IsEmpty()){
			rv+=m_User;
			if(!m_Password.IsEmpty())
				rv+=':'+m_Password;
			rv+='@';
		}
		rv+=m_Host;
		if(!m_Port.IsEmpty())
			rv+=':'+m_Port;
		if(!m_URLPath.IsEmpty()){
			rv+=m_URLPath;
		}else{
			rv+=m_pathPath+m_pathFile+m_pathAnchor+m_pathQuery;
		}
	}
	return rv;
}

CString CCrackURL::InnermostURL(LPCTSTR url)
{
static CRegEx reInnerURL;
	if(!reInnerURL.m_bCompiled)
		VERIFY(reInnerURL.Compile(".+[^[:alpha:]]([[:alpha:]]+://[^&]+)",CRegEx::regExtended|CRegEx::regIgnoreCase));
CString rv = url;
	while(reInnerURL.Match(rv))
			rv=reInnerURL.GetMatch(1);
	return rv;
}

CString CCrackURL::GetHostName(LPCTSTR url)
{
static CRegEx reHost;
	if(!reHost.m_bCompiled)
		VERIFY(reHost.Compile("^[[:alpha:]]+://([^/:]+)",CRegEx::regExtended|CRegEx::regIgnoreCase));
CString rv;
	if(reHost.Match(url))
		rv = reHost.GetMatch(1);
	else
		rv = url;
	return rv;
}
