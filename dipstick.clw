; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CDipstickDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "Dipstick.h"

ClassCount=10
Class1=CDipstickApp
Class2=CDipstickDlg
Class3=CAboutDlg

ResourceCount=10
Resource1=IDD_PROPS
Resource2=IDR_MAINFRAME
Class4=CDropURL
Resource3=IDD_MANUALHOST
Class5=CDragPad
Resource4=IDD_ABOUTBOX
Class6=COptionsDlg
Resource5=IDD_OPTIONS
Resource6=IDD_AUTOBEST
Class7=CHostNameDlg
Resource7=IDD_DRAGPAD
Class8=CHostProperties
Resource8=IDR_MENU
Class9=CAutoBestDlg
Resource9=IDD_DIPSTICK_DIALOG
Class10=CSelectURLsDlg
Resource10=IDD_URLS

[CLS:CDipstickApp]
Type=0
HeaderFile=Dipstick.h
ImplementationFile=Dipstick.cpp
Filter=N
LastObject=CDipstickApp
BaseClass=CWinApp
VirtualFilter=AC

[CLS:CDipstickDlg]
Type=0
HeaderFile=DipstickDlg.h
ImplementationFile=DipstickDlg.cpp
Filter=W
BaseClass=CDialog
VirtualFilter=dWC
LastObject=CDipstickDlg

[CLS:CAboutDlg]
Type=0
HeaderFile=DipstickDlg.h
ImplementationFile=DipstickDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=IDC_KLEVERNET

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=5
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889
Control5=IDC_KLEVERNET,button,1342242816

[DLG:IDD_DIPSTICK_DIALOG]
Type=1
Class=CDipstickDlg
ControlCount=11
Control1=IDC_HOSTLIST,SysListView32,1350631697
Control2=IDC_MANUALPING,button,1342242816
Control3=IDC_REPING,button,1476460544
Control4=IDC_REPINGALL,button,1476460544
Control5=IDC_REMOVE,button,1476460544
Control6=IDC_CLEAR,button,1476460544
Control7=ID_HELP,button,1342242816
Control8=IDC_OPTIONS,button,1342242816
Control9=IDC_EXIT,button,1342242816
Control10=IDCANCEL,button,1208025088
Control11=IDC_ADVANCED,button,1342242816

[CLS:CDropURL]
Type=0
HeaderFile=DropURL.h
ImplementationFile=DropURL.cpp
BaseClass=CCmdTarget
Filter=N
LastObject=CDropURL
VirtualFilter=C

[DLG:IDD_DRAGPAD]
Type=1
Class=CDragPad
ControlCount=3
Control1=IDC_DNDTARGET,SysAnimate32,1342242816
Control2=IDCANCEL,button,1208025088
Control3=IDOK,button,1208025089

[CLS:CDragPad]
Type=0
HeaderFile=DragPad.h
ImplementationFile=DragPad.cpp
BaseClass=CDialog
Filter=W
VirtualFilter=dWC
LastObject=CDragPad

[DLG:IDD_OPTIONS]
Type=1
Class=COptionsDlg
ControlCount=22
Control1=IDC_STATIC,static,1342308352
Control2=IDC_NPINGS,edit,1350631552
Control3=IDC_SPINPINGS,msctls_updown32,1342177463
Control4=IDC_STATIC,static,1342308352
Control5=IDC_MAXPINGS,edit,1350631552
Control6=IDC_SPINMAXPINGS,msctls_updown32,1342177463
Control7=IDC_STATIC,static,1342308352
Control8=IDC_TIMEOUT,edit,1350631552
Control9=IDC_SPINTIMEOUT,msctls_updown32,1342177463
Control10=IDC_STATIC,static,1342308352
Control11=IDC_INTERVAL,edit,1350631552
Control12=IDC_SPINTERVAL,msctls_updown32,1342177463
Control13=IDC_STATIC,static,1342308352
Control14=IDC_PACKETSIZE,edit,1350631552
Control15=IDC_SPINSIZE,msctls_updown32,1342177463
Control16=IDC_MSWORKAROUND,button,1342259203
Control17=IDOK,button,1342242817
Control18=IDCANCEL,button,1342242816
Control19=IDC_AUTOBEST,button,1342259203
Control20=IDC_SMARTADJUST,button,1342259203
Control21=IDC_ADJUSTINN,button,1342259203
Control22=IDC_IGNORELA,button,1342259203

[CLS:COptionsDlg]
Type=0
HeaderFile=OptionsDlg.h
ImplementationFile=OptionsDlg.cpp
BaseClass=CDialog
Filter=W
VirtualFilter=dWC
LastObject=COptionsDlg

[MNU:IDR_MENU]
Type=1
Class=CDipstickDlg
Command1=ID_DRAGPAD_MANUALPING
Command2=ID_DRAGPAD_PASTEURL
Command3=ID_DRAGPAD_REPINGALL
Command4=ID_DRAGPAD_REMOVEALL
Command5=ID_DRAGPAD_OPTIONS
Command6=ID_DRAGPAD_SHOWMAINWINDOW
Command7=ID_DRAGPAD_ADVANCED_EXPORTLIST
Command8=ID_DRAGPAD_ADVANCED_IMPORTLIST
Command9=ID_DRAGPAD_HELP
Command10=ID_DRAGPAD_ABOUT
Command11=ID_DRAGPAD_EXIT
Command12=ID_HOSTLIST_REPING
Command13=ID_HOSTLIST_REMOVE
Command14=ID_HOSTLIST_OPENURL
Command15=ID_HOSTLIST_COPYURL
Command16=ID_HOSTLIST_REPINGALL
Command17=ID_HOSTLIST_REMOVEALL
Command18=ID_HOSTLIST_PASTEURL
Command19=ID_HOSTLIST_PROPERTIES
Command20=ID_ADVANCED_EXPORTLIST
Command21=ID_ADVANCED_IMPORTLIST
CommandCount=21

[DLG:IDD_MANUALHOST]
Type=1
Class=CHostNameDlg
ControlCount=4
Control1=IDC_STATIC,static,1342308352
Control2=IDC_HOST,edit,1350631568
Control3=IDOK,button,1342242817
Control4=IDCANCEL,button,1342242816

[CLS:CHostNameDlg]
Type=0
HeaderFile=HostNameDlg.h
ImplementationFile=HostNameDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=CHostNameDlg
VirtualFilter=dWC

[DLG:IDD_PROPS]
Type=1
Class=CHostProperties
ControlCount=16
Control1=IDOK,button,1342242817
Control2=IDC_URLCAPTION,static,1342308608
Control3=IDC_URL,static,1342308736
Control4=IDC_HOSTCAPTION,static,1342308608
Control5=IDC_HOST,static,1342308736
Control6=IDC_IPCAPTION,static,1342308608
Control7=IDC_IP,static,1342308608
Control8=IDC_TIMESCAPTION,static,1342308608
Control9=IDC_TIMES,static,1342308608
Control10=IDC_LOSSCAPTION,static,1342308608
Control11=IDC_LOSS,static,1342308736
Control12=IDC_STATUSCAPTION,static,1342308608
Control13=IDC_STATUS,static,1342308736
Control14=IDC_OPENURL,button,1342242816
Control15=IDC_STATE,static,1342180099
Control16=IDC_COPYURL,button,1342242816

[CLS:CHostProperties]
Type=0
HeaderFile=HostProperties.h
ImplementationFile=HostProperties.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CHostProperties

[DLG:IDD_AUTOBEST]
Type=1
Class=CAutoBestDlg
ControlCount=11
Control1=IDOK,button,1342242817
Control2=IDC_NEXT,button,1342242816
Control3=IDC_PREV,button,1342242816
Control4=IDC_URL,static,1342308481
Control5=IDC_STATIC,static,1342308352
Control6=IDC_RTT,static,1342308352
Control7=IDC_STATIC,static,1342308352
Control8=IDC_PKTLOSS,static,1342308352
Control9=IDCANCEL,button,1342242816
Control10=IDC_DROPSOURCE,SysAnimate32,1342177285
Control11=IDC_COPYURL,button,1342254848

[CLS:CAutoBestDlg]
Type=0
HeaderFile=AutoBestDlg.h
ImplementationFile=AutoBestDlg.cpp
BaseClass=CDialog
Filter=W
LastObject=CAutoBestDlg
VirtualFilter=dWC

[DLG:IDD_URLS]
Type=1
Class=CSelectURLsDlg
ControlCount=5
Control1=IDC_URLS,listbox,1345390851
Control2=IDOK,button,1342242817
Control3=IDCANCEL,button,1342242816
Control4=IDC_DOADJUST,button,1342243843
Control5=IDC_ADJUSTINN,button,1342252035

[CLS:CSelectURLsDlg]
Type=0
HeaderFile=SelectURLsDlg.h
ImplementationFile=SelectURLsDlg.cpp
BaseClass=CDialog
Filter=W
LastObject=CSelectURLsDlg
VirtualFilter=dWC

