// stdafx.h : include file for standard system include files,
//  or project specific include files that are used frequently, but
//      are changed infrequently
//

#define VC_EXTRALEAN		// Exclude rarely-used stuff from Windows headers

#include <afxwin.h>         // MFC core and standard components
#include <afxext.h>         // MFC extensions
#ifndef _AFX_NO_AFXCMN_SUPPORT
#include <afxcmn.h>			// MFC support for Windows 95 Common Controls
#endif // _AFX_NO_AFXCMN_SUPPORT

#include <afxsock.h>		// MFC socket extensions

#include <afxole.h>
#include <afxtempl.h>
#include <afxmt.h>

#include <winsock.h>
#include "shared-code/ms_icmp.h"
#include "shared-code/ip_icmp.h"

#include "shared-code/kICMP.h"
#include "shared-code/RegEx.h"
#include "CrackURL.h"

enum	{
	WM_DNP_ACTIVITYCOUNT = WM_USER+16,
	WM_DNP_URLPING,
	WM_DNP_UPDATEHOSTDATA,
	WM_DNP_HTML
};
#include <MMSystem.h>
// CG: The following line was added by the Windows Multimedia component.
#pragma comment(lib, "winmm.lib")
