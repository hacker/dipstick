# Microsoft Developer Studio Generated NMAKE File, Format Version 4.20
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

!IF "$(CFG)" == ""
CFG=Install - Win32 Canned
!MESSAGE No configuration specified.  Defaulting to Install - Win32 Canned.
!ENDIF 

!IF "$(CFG)" != "Dipstick - Win32 Release" && "$(CFG)" !=\
 "Dipstick - Win32 Debug" && "$(CFG)" != "Dipstick - Win32 Release Static" &&\
 "$(CFG)" != "Install - Win32 Debug" && "$(CFG)" != "Install - Win32 Pure" &&\
 "$(CFG)" != "Install - Win32 Static" && "$(CFG)" != "Install - Win32 Canned"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE on this makefile
!MESSAGE by defining the macro CFG on the command line.  For example:
!MESSAGE 
!MESSAGE NMAKE /f "dipstick.mak" CFG="Install - Win32 Canned"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "Dipstick - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "Dipstick - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE "Dipstick - Win32 Release Static" (based on "Win32 (x86) Application")
!MESSAGE "Install - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE "Install - Win32 Pure" (based on "Win32 (x86) Application")
!MESSAGE "Install - Win32 Static" (based on "Win32 (x86) Application")
!MESSAGE "Install - Win32 Canned" (based on "Win32 (x86) Application")
!MESSAGE 
!ERROR An invalid configuration is specified.
!ENDIF 

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE 
NULL=nul
!ENDIF 
################################################################################
# Begin Project
# PROP Target_Last_Scanned "Dipstick - Win32 Release"
RSC=rc.exe
MTL=mktyplib.exe
CPP=cl.exe

!IF  "$(CFG)" == "Dipstick - Win32 Release"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Target_Dir ""
OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\Release
TargetName=dipstick
# End Custom Macros

ALL : "$(OUTDIR)\dipstick.exe" "$(OUTDIR)\dipstick.ex_"\
 "$(OUTDIR)\dipstick.hlp" "$(OUTDIR)\dipstick.cnt" "$(OUTDIR)\dipstick.hl_"\
 "$(OUTDIR)\dipstick.cn_"

CLEAN : 
	-@erase "$(INTDIR)\AutoBestDlg.obj"
	-@erase "$(INTDIR)\CrackURL.obj"
	-@erase "$(INTDIR)\dipstick.cn_"
	-@erase "$(INTDIR)\dipstick.cnt"
	-@erase "$(INTDIR)\dipstick.hl_"
	-@erase "$(INTDIR)\dipstick.hlp"
	-@erase "$(INTDIR)\Dipstick.obj"
	-@erase "$(INTDIR)\dipstick.pch"
	-@erase "$(INTDIR)\dipstick.res"
	-@erase "$(INTDIR)\DipstickDlg.obj"
	-@erase "$(INTDIR)\DragPad.obj"
	-@erase "$(INTDIR)\HostNameDlg.obj"
	-@erase "$(INTDIR)\HostProperties.obj"
	-@erase "$(INTDIR)\kICMP.obj"
	-@erase "$(INTDIR)\OptionsDlg.obj"
	-@erase "$(INTDIR)\RegEx.obj"
	-@erase "$(INTDIR)\SelectURLsDlg.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\URLSource.obj"
	-@erase "$(OUTDIR)\dipstick.ex_"
	-@erase "$(OUTDIR)\dipstick.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

# ADD BASE CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /c
# ADD CPP /nologo /MD /W3 /GX /O1 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /c
CPP_PROJ=/nologo /MD /W3 /GX /O1 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D\
 "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)/dipstick.pch" /Yu"stdafx.h" /Fo"$(INTDIR)/"\
 /c 
CPP_OBJS=.\Release/
CPP_SBRS=.\.
# ADD BASE MTL /nologo /D "NDEBUG" /win32
# ADD MTL /nologo /D "NDEBUG" /win32
MTL_PROJ=/nologo /D "NDEBUG" /win32 
# ADD BASE RSC /l 0x409 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x409 /d "NDEBUG" /d "_AFXDLL"
RSC_PROJ=/l 0x409 /fo"$(INTDIR)/dipstick.res" /d "NDEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
BSC32_FLAGS=/nologo /o"$(OUTDIR)/dipstick.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /machine:I386
# ADD LINK32 uuid.lib /nologo /subsystem:windows /machine:I386
LINK32_FLAGS=uuid.lib /nologo /subsystem:windows /incremental:no\
 /pdb:"$(OUTDIR)/dipstick.pdb" /machine:I386 /out:"$(OUTDIR)/dipstick.exe" 
LINK32_OBJS= \
	"$(INTDIR)\AutoBestDlg.obj" \
	"$(INTDIR)\CrackURL.obj" \
	"$(INTDIR)\Dipstick.obj" \
	"$(INTDIR)\dipstick.res" \
	"$(INTDIR)\DipstickDlg.obj" \
	"$(INTDIR)\DragPad.obj" \
	"$(INTDIR)\HostNameDlg.obj" \
	"$(INTDIR)\HostProperties.obj" \
	"$(INTDIR)\kICMP.obj" \
	"$(INTDIR)\OptionsDlg.obj" \
	"$(INTDIR)\RegEx.obj" \
	"$(INTDIR)\SelectURLsDlg.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\URLSource.obj"

"$(OUTDIR)\dipstick.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

# Begin Custom Build
OutDir=.\Release
TargetName=dipstick
InputPath=.\Release\dipstick.exe
SOURCE=$(InputPath)

"$(OutDir)\$(TargetName).ex_" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   compress $(OutDir)\$(TargetName).exe $(OutDir)\$(TargetName).ex_

# End Custom Build

!ELSEIF  "$(CFG)" == "Dipstick - Win32 Debug"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Target_Dir ""
OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\Debug
TargetName=dipstick
# End Custom Macros

ALL : "$(OUTDIR)\dipstick.exe" "$(OUTDIR)\dipstick.ex_"\
 "$(OUTDIR)\dipstick.hlp" "$(OUTDIR)\dipstick.cnt" "$(OUTDIR)\dipstick.hl_"\
 "$(OUTDIR)\dipstick.cn_"

CLEAN : 
	-@erase "$(INTDIR)\AutoBestDlg.obj"
	-@erase "$(INTDIR)\CrackURL.obj"
	-@erase "$(INTDIR)\dipstick.cn_"
	-@erase "$(INTDIR)\dipstick.cnt"
	-@erase "$(INTDIR)\dipstick.hl_"
	-@erase "$(INTDIR)\dipstick.hlp"
	-@erase "$(INTDIR)\Dipstick.obj"
	-@erase "$(INTDIR)\dipstick.pch"
	-@erase "$(INTDIR)\dipstick.res"
	-@erase "$(INTDIR)\DipstickDlg.obj"
	-@erase "$(INTDIR)\DragPad.obj"
	-@erase "$(INTDIR)\HostNameDlg.obj"
	-@erase "$(INTDIR)\HostProperties.obj"
	-@erase "$(INTDIR)\kICMP.obj"
	-@erase "$(INTDIR)\OptionsDlg.obj"
	-@erase "$(INTDIR)\RegEx.obj"
	-@erase "$(INTDIR)\SelectURLsDlg.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\URLSource.obj"
	-@erase "$(INTDIR)\vc40.idb"
	-@erase "$(INTDIR)\vc40.pdb"
	-@erase "$(OUTDIR)\dipstick.ex_"
	-@erase "$(OUTDIR)\dipstick.exe"
	-@erase "$(OUTDIR)\dipstick.ilk"
	-@erase "$(OUTDIR)\dipstick.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /c
CPP_PROJ=/nologo /MDd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS"\
 /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)/dipstick.pch" /Yu"stdafx.h"\
 /Fo"$(INTDIR)/" /Fd"$(INTDIR)/" /c 
CPP_OBJS=.\Debug/
CPP_SBRS=.\.
# ADD BASE MTL /nologo /D "_DEBUG" /win32
# ADD MTL /nologo /D "_DEBUG" /win32
MTL_PROJ=/nologo /D "_DEBUG" /win32 
# ADD BASE RSC /l 0x409 /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x409 /d "_DEBUG" /d "_AFXDLL"
RSC_PROJ=/l 0x409 /fo"$(INTDIR)/dipstick.res" /d "_DEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
BSC32_FLAGS=/nologo /o"$(OUTDIR)/dipstick.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /debug /machine:I386
# ADD LINK32 uuid.lib /nologo /subsystem:windows /debug /machine:I386
LINK32_FLAGS=uuid.lib /nologo /subsystem:windows /incremental:yes\
 /pdb:"$(OUTDIR)/dipstick.pdb" /debug /machine:I386\
 /out:"$(OUTDIR)/dipstick.exe" 
LINK32_OBJS= \
	"$(INTDIR)\AutoBestDlg.obj" \
	"$(INTDIR)\CrackURL.obj" \
	"$(INTDIR)\Dipstick.obj" \
	"$(INTDIR)\dipstick.res" \
	"$(INTDIR)\DipstickDlg.obj" \
	"$(INTDIR)\DragPad.obj" \
	"$(INTDIR)\HostNameDlg.obj" \
	"$(INTDIR)\HostProperties.obj" \
	"$(INTDIR)\kICMP.obj" \
	"$(INTDIR)\OptionsDlg.obj" \
	"$(INTDIR)\RegEx.obj" \
	"$(INTDIR)\SelectURLsDlg.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\URLSource.obj"

"$(OUTDIR)\dipstick.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

# Begin Custom Build
OutDir=.\Debug
TargetName=dipstick
InputPath=.\Debug\dipstick.exe
SOURCE=$(InputPath)

"$(OutDir)\$(TargetName).ex_" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   compress $(OutDir)\$(TargetName).exe $(OutDir)\$(TargetName).ex_

# End Custom Build

!ELSEIF  "$(CFG)" == "Dipstick - Win32 Release Static"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Dipstick_"
# PROP BASE Intermediate_Dir "Dipstick_"
# PROP BASE Target_Dir ""
# PROP Use_MFC 5
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Releast"
# PROP Intermediate_Dir "Releast"
# PROP Target_Dir ""
OUTDIR=.\Releast
INTDIR=.\Releast
# Begin Custom Macros
OutDir=.\Releast
TargetName=dipstick
# End Custom Macros

ALL : "$(OUTDIR)\dipstick.exe" "$(OUTDIR)\dipstick.ex_"\
 "$(OUTDIR)\dipstick.hlp" "$(OUTDIR)\dipstick.cnt" "$(OUTDIR)\dipstick.hl_"\
 "$(OUTDIR)\dipstick.cn_"

CLEAN : 
	-@erase "$(INTDIR)\AutoBestDlg.obj"
	-@erase "$(INTDIR)\CrackURL.obj"
	-@erase "$(INTDIR)\dipstick.cn_"
	-@erase "$(INTDIR)\dipstick.cnt"
	-@erase "$(INTDIR)\dipstick.hl_"
	-@erase "$(INTDIR)\dipstick.hlp"
	-@erase "$(INTDIR)\Dipstick.obj"
	-@erase "$(INTDIR)\dipstick.pch"
	-@erase "$(INTDIR)\dipstick.res"
	-@erase "$(INTDIR)\DipstickDlg.obj"
	-@erase "$(INTDIR)\DragPad.obj"
	-@erase "$(INTDIR)\HostNameDlg.obj"
	-@erase "$(INTDIR)\HostProperties.obj"
	-@erase "$(INTDIR)\kICMP.obj"
	-@erase "$(INTDIR)\OptionsDlg.obj"
	-@erase "$(INTDIR)\RegEx.obj"
	-@erase "$(INTDIR)\SelectURLsDlg.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\URLSource.obj"
	-@erase "$(OUTDIR)\dipstick.ex_"
	-@erase "$(OUTDIR)\dipstick.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

# ADD BASE CPP /nologo /MD /W3 /O1 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /c
# ADD CPP /nologo /MT /W3 /GX /O1 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /Yu"stdafx.h" /c
CPP_PROJ=/nologo /MT /W3 /GX /O1 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D\
 "_MBCS" /Fp"$(INTDIR)/dipstick.pch" /Yu"stdafx.h" /Fo"$(INTDIR)/" /c 
CPP_OBJS=.\Releast/
CPP_SBRS=.\.
# ADD BASE MTL /nologo /D "NDEBUG" /win32
# ADD MTL /nologo /D "NDEBUG" /win32
MTL_PROJ=/nologo /D "NDEBUG" /win32 
# ADD BASE RSC /l 0x409 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x409 /d "NDEBUG"
RSC_PROJ=/l 0x409 /fo"$(INTDIR)/dipstick.res" /d "NDEBUG" 
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
BSC32_FLAGS=/nologo /o"$(OUTDIR)/dipstick.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
# ADD BASE LINK32 lib\icmp.lib /nologo /subsystem:windows /machine:I386 /out:"Release/DipStick.exe"
# ADD LINK32 uuid.lib /nologo /subsystem:windows /machine:I386
LINK32_FLAGS=uuid.lib /nologo /subsystem:windows /incremental:no\
 /pdb:"$(OUTDIR)/dipstick.pdb" /machine:I386 /out:"$(OUTDIR)/dipstick.exe" 
LINK32_OBJS= \
	"$(INTDIR)\AutoBestDlg.obj" \
	"$(INTDIR)\CrackURL.obj" \
	"$(INTDIR)\Dipstick.obj" \
	"$(INTDIR)\dipstick.res" \
	"$(INTDIR)\DipstickDlg.obj" \
	"$(INTDIR)\DragPad.obj" \
	"$(INTDIR)\HostNameDlg.obj" \
	"$(INTDIR)\HostProperties.obj" \
	"$(INTDIR)\kICMP.obj" \
	"$(INTDIR)\OptionsDlg.obj" \
	"$(INTDIR)\RegEx.obj" \
	"$(INTDIR)\SelectURLsDlg.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\URLSource.obj"

"$(OUTDIR)\dipstick.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

# Begin Custom Build
OutDir=.\Releast
TargetName=dipstick
InputPath=.\Releast\dipstick.exe
SOURCE=$(InputPath)

"$(OutDir)\$(TargetName).ex_" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   compress $(OutDir)\$(TargetName).exe $(OutDir)\$(TargetName).ex_

# End Custom Build

!ELSEIF  "$(CFG)" == "Install - Win32 Debug"

# PROP BASE Use_MFC 2
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Install\Debug"
# PROP BASE Intermediate_Dir "Install\Debug"
# PROP BASE Target_Dir "Install"
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Install\Debug"
# PROP Intermediate_Dir "Install\Debug"
# PROP Target_Dir "Install"
OUTDIR=.\Install\Debug
INTDIR=.\Install\Debug

ALL : "Dipstick - Win32 Debug" "$(OUTDIR)\Install.exe"

CLEAN : 
	-@erase "$(INTDIR)\install.obj"
	-@erase "$(INTDIR)\Install.res"
	-@erase "$(INTDIR)\vc40.idb"
	-@erase "$(INTDIR)\vc40.pdb"
	-@erase "$(OUTDIR)\Install.exe"
	-@erase "$(OUTDIR)\Install.ilk"
	-@erase "$(OUTDIR)\Install.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /YX /c
# ADD CPP /nologo /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /YX /c
CPP_PROJ=/nologo /MLd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS"\
 /D "_MBCS" /Fp"$(INTDIR)/Install.pch" /YX /Fo"$(INTDIR)/" /Fd"$(INTDIR)/" /c 
CPP_OBJS=.\Install\Debug/
CPP_SBRS=.\.
# ADD BASE MTL /nologo /D "_DEBUG" /win32
# ADD MTL /nologo /D "_DEBUG" /win32
MTL_PROJ=/nologo /D "_DEBUG" /win32 
# ADD BASE RSC /l 0x409 /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x409 /d "_DEBUG"
RSC_PROJ=/l 0x409 /fo"$(INTDIR)/Install.res" /d "_DEBUG" 
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
BSC32_FLAGS=/nologo /o"$(OUTDIR)/Install.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /debug /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib version.lib /nologo /subsystem:windows /debug /machine:I386
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib\
 advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib\
 odbccp32.lib version.lib /nologo /subsystem:windows /incremental:yes\
 /pdb:"$(OUTDIR)/Install.pdb" /debug /machine:I386 /out:"$(OUTDIR)/Install.exe" 
LINK32_OBJS= \
	"$(INTDIR)\install.obj" \
	"$(INTDIR)\Install.res"

"$(OUTDIR)\Install.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "Install - Win32 Pure"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Install\Pure"
# PROP BASE Intermediate_Dir "Install\Pure"
# PROP BASE Target_Dir "Install"
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Install\Pure"
# PROP Intermediate_Dir "Install\Pure"
# PROP Target_Dir "Install"
OUTDIR=.\Install\Pure
INTDIR=.\Install\Pure

ALL : "$(OUTDIR)\Install.exe"

CLEAN : 
	-@erase "$(INTDIR)\install.obj"
	-@erase "$(INTDIR)\Install.res"
	-@erase "$(OUTDIR)\Install.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

# ADD BASE CPP /nologo /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /YX /c
# ADD CPP /nologo /ML /W3 /GX /O1 /Ob2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /YX /c
CPP_PROJ=/nologo /ML /W3 /GX /O1 /Ob2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D\
 "_MBCS" /Fp"$(INTDIR)/Install.pch" /YX /Fo"$(INTDIR)/" /c 
CPP_OBJS=.\Install\Pure/
CPP_SBRS=.\.
# ADD BASE MTL /nologo /D "_DEBUG" /win32
# ADD MTL /nologo /D "NDEBUG" /win32
MTL_PROJ=/nologo /D "NDEBUG" /win32 
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
RSC_PROJ=/l 0x409 /fo"$(INTDIR)/Install.res" /d "NDEBUG" 
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
BSC32_FLAGS=/nologo /o"$(OUTDIR)/Install.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib version.lib /nologo /subsystem:windows /debug /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib version.lib /nologo /subsystem:windows /incremental:no /machine:I386
# SUBTRACT LINK32 /debug
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib\
 advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib\
 odbccp32.lib version.lib /nologo /subsystem:windows /incremental:no\
 /pdb:"$(OUTDIR)/Install.pdb" /machine:I386 /out:"$(OUTDIR)/Install.exe" 
LINK32_OBJS= \
	"$(INTDIR)\install.obj" \
	"$(INTDIR)\Install.res"

"$(OUTDIR)\Install.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "Install - Win32 Static"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Install\Static"
# PROP BASE Intermediate_Dir "Install\Static"
# PROP BASE Target_Dir "Install"
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Install\Static"
# PROP Intermediate_Dir "Install\Static"
# PROP Target_Dir "Install"
OUTDIR=.\Install\Static
INTDIR=.\Install\Static

ALL : "$(OUTDIR)\Install.exe"

CLEAN : 
	-@erase "$(INTDIR)\install.obj"
	-@erase "$(INTDIR)\Install.res"
	-@erase "$(OUTDIR)\Install.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

# ADD BASE CPP /nologo /ML /W3 /GX /O1 /Ob2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /YX /c
# ADD CPP /nologo /ML /W3 /GX /O1 /Ob2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "STATI_K" /YX /c
CPP_PROJ=/nologo /ML /W3 /GX /O1 /Ob2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D\
 "_MBCS" /D "STATI_K" /Fp"$(INTDIR)/Install.pch" /YX /Fo"$(INTDIR)/" /c 
CPP_OBJS=.\Install\Static/
CPP_SBRS=.\.
# ADD BASE MTL /nologo /D "NDEBUG" /win32
# ADD MTL /nologo /D "NDEBUG" /D "STATI_K" /win32
MTL_PROJ=/nologo /D "NDEBUG" /D "STATI_K" /win32 
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG" /d "STATI_K"
RSC_PROJ=/l 0x409 /fo"$(INTDIR)/Install.res" /d "NDEBUG" /d "STATI_K" 
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
BSC32_FLAGS=/nologo /o"$(OUTDIR)/Install.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib version.lib /nologo /subsystem:windows /incremental:no /machine:I386 /out:"Install\Pure/Dipstick.exe"
# SUBTRACT BASE LINK32 /debug
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib version.lib /nologo /subsystem:windows /incremental:no /machine:I386
# SUBTRACT LINK32 /debug
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib\
 advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib\
 odbccp32.lib version.lib /nologo /subsystem:windows /incremental:no\
 /pdb:"$(OUTDIR)/Install.pdb" /machine:I386 /out:"$(OUTDIR)/Install.exe" 
LINK32_OBJS= \
	"$(INTDIR)\install.obj" \
	"$(INTDIR)\Install.res"

"$(OUTDIR)\Install.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "Install - Win32 Canned"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Install\Canned"
# PROP BASE Intermediate_Dir "Install\Canned"
# PROP BASE Target_Dir "Install"
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Install\Canned"
# PROP Intermediate_Dir "Install\Canned"
# PROP Target_Dir "Install"
OUTDIR=.\Install\Canned
INTDIR=.\Install\Canned

ALL : "$(OUTDIR)\Install.exe"

CLEAN : 
	-@erase "$(INTDIR)\install.obj"
	-@erase "$(INTDIR)\Install.res"
	-@erase "$(OUTDIR)\Install.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

# ADD BASE CPP /nologo /ML /W3 /GX /O1 /Ob2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /YX /c
# ADD CPP /nologo /ML /W3 /GX /O1 /Ob2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "K_ANNED" /YX /c
CPP_PROJ=/nologo /ML /W3 /GX /O1 /Ob2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D\
 "_MBCS" /D "K_ANNED" /Fp"$(INTDIR)/Install.pch" /YX /Fo"$(INTDIR)/" /c 
CPP_OBJS=.\Install\Canned/
CPP_SBRS=.\.
# ADD BASE MTL /nologo /D "NDEBUG" /win32
# ADD MTL /nologo /D "NDEBUG" /D "K_ANNED" /win32
MTL_PROJ=/nologo /D "NDEBUG" /D "K_ANNED" /win32 
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG" /d "K_ANNED"
RSC_PROJ=/l 0x409 /fo"$(INTDIR)/Install.res" /d "NDEBUG" /d "K_ANNED" 
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
BSC32_FLAGS=/nologo /o"$(OUTDIR)/Install.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib version.lib /nologo /subsystem:windows /incremental:no /machine:I386 /out:"Install\Pure/Dipstick.exe"
# SUBTRACT BASE LINK32 /debug
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib version.lib /nologo /subsystem:windows /incremental:no /machine:I386
# SUBTRACT LINK32 /debug
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib\
 advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib\
 odbccp32.lib version.lib /nologo /subsystem:windows /incremental:no\
 /pdb:"$(OUTDIR)/Install.pdb" /machine:I386 /out:"$(OUTDIR)/Install.exe" 
LINK32_OBJS= \
	"$(INTDIR)\install.obj" \
	"$(INTDIR)\Install.res"

"$(OUTDIR)\Install.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ENDIF 

.c{$(CPP_OBJS)}.obj:
   $(CPP) $(CPP_PROJ) $<  

.cpp{$(CPP_OBJS)}.obj:
   $(CPP) $(CPP_PROJ) $<  

.cxx{$(CPP_OBJS)}.obj:
   $(CPP) $(CPP_PROJ) $<  

.c{$(CPP_SBRS)}.sbr:
   $(CPP) $(CPP_PROJ) $<  

.cpp{$(CPP_SBRS)}.sbr:
   $(CPP) $(CPP_PROJ) $<  

.cxx{$(CPP_SBRS)}.sbr:
   $(CPP) $(CPP_PROJ) $<  

################################################################################
# Begin Target

# Name "Dipstick - Win32 Release"
# Name "Dipstick - Win32 Debug"
# Name "Dipstick - Win32 Release Static"

!IF  "$(CFG)" == "Dipstick - Win32 Release"

!ELSEIF  "$(CFG)" == "Dipstick - Win32 Debug"

!ELSEIF  "$(CFG)" == "Dipstick - Win32 Release Static"

!ENDIF 

################################################################################
# Begin Source File

SOURCE=.\Dipstick.cpp

!IF  "$(CFG)" == "Dipstick - Win32 Release"

DEP_CPP_DIPST=\
	".\CrackURL.h"\
	".\Dipstick.h"\
	".\DipstickDlg.h"\
	".\shared-code\ip_icmp.h"\
	".\shared-code\kICMP.h"\
	".\shared-code\ms_icmp.h"\
	".\shared-code\RegEx.h"\
	".\stdafx.h"\
	

"$(INTDIR)\Dipstick.obj" : $(SOURCE) $(DEP_CPP_DIPST) "$(INTDIR)"\
 "$(INTDIR)\dipstick.pch"


!ELSEIF  "$(CFG)" == "Dipstick - Win32 Debug"

DEP_CPP_DIPST=\
	".\CrackURL.h"\
	".\Dipstick.h"\
	".\DipstickDlg.h"\
	".\shared-code\ip_icmp.h"\
	".\shared-code\kICMP.h"\
	".\shared-code\ms_icmp.h"\
	".\shared-code\RegEx.h"\
	".\stdafx.h"\
	

"$(INTDIR)\Dipstick.obj" : $(SOURCE) $(DEP_CPP_DIPST) "$(INTDIR)"\
 "$(INTDIR)\dipstick.pch"


!ELSEIF  "$(CFG)" == "Dipstick - Win32 Release Static"

DEP_CPP_DIPST=\
	".\CrackURL.h"\
	".\Dipstick.h"\
	".\DipstickDlg.h"\
	".\shared-code\ip_icmp.h"\
	".\shared-code\kICMP.h"\
	".\shared-code\ms_icmp.h"\
	".\shared-code\RegEx.h"\
	".\stdafx.h"\
	

"$(INTDIR)\Dipstick.obj" : $(SOURCE) $(DEP_CPP_DIPST) "$(INTDIR)"\
 "$(INTDIR)\dipstick.pch"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\DipstickDlg.cpp

!IF  "$(CFG)" == "Dipstick - Win32 Release"

DEP_CPP_DIPSTI=\
	".\AutoBestDlg.h"\
	".\CrackURL.h"\
	".\Dipstick.h"\
	".\DipstickDlg.h"\
	".\DragPad.h"\
	".\HostNameDlg.h"\
	".\HostProperties.h"\
	".\OptionsDlg.h"\
	".\SelectURLsDlg.h"\
	".\shared-code\ip_icmp.h"\
	".\shared-code\kICMP.h"\
	".\shared-code\ms_icmp.h"\
	".\shared-code\RegEx.h"\
	".\stdafx.h"\
	".\URLSource.h"\
	

"$(INTDIR)\DipstickDlg.obj" : $(SOURCE) $(DEP_CPP_DIPSTI) "$(INTDIR)"\
 "$(INTDIR)\dipstick.pch"


!ELSEIF  "$(CFG)" == "Dipstick - Win32 Debug"

DEP_CPP_DIPSTI=\
	".\AutoBestDlg.h"\
	".\CrackURL.h"\
	".\Dipstick.h"\
	".\DipstickDlg.h"\
	".\DragPad.h"\
	".\HostNameDlg.h"\
	".\HostProperties.h"\
	".\OptionsDlg.h"\
	".\SelectURLsDlg.h"\
	".\shared-code\ip_icmp.h"\
	".\shared-code\kICMP.h"\
	".\shared-code\ms_icmp.h"\
	".\shared-code\RegEx.h"\
	".\stdafx.h"\
	".\URLSource.h"\
	

"$(INTDIR)\DipstickDlg.obj" : $(SOURCE) $(DEP_CPP_DIPSTI) "$(INTDIR)"\
 "$(INTDIR)\dipstick.pch"


!ELSEIF  "$(CFG)" == "Dipstick - Win32 Release Static"

DEP_CPP_DIPSTI=\
	".\AutoBestDlg.h"\
	".\CrackURL.h"\
	".\Dipstick.h"\
	".\DipstickDlg.h"\
	".\DragPad.h"\
	".\HostNameDlg.h"\
	".\HostProperties.h"\
	".\OptionsDlg.h"\
	".\SelectURLsDlg.h"\
	".\shared-code\ip_icmp.h"\
	".\shared-code\kICMP.h"\
	".\shared-code\ms_icmp.h"\
	".\shared-code\RegEx.h"\
	".\stdafx.h"\
	".\URLSource.h"\
	

"$(INTDIR)\DipstickDlg.obj" : $(SOURCE) $(DEP_CPP_DIPSTI) "$(INTDIR)"\
 "$(INTDIR)\dipstick.pch"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\StdAfx.cpp

!IF  "$(CFG)" == "Dipstick - Win32 Release"

DEP_CPP_STDAF=\
	".\CrackURL.h"\
	".\shared-code\ip_icmp.h"\
	".\shared-code\kICMP.h"\
	".\shared-code\ms_icmp.h"\
	".\shared-code\RegEx.h"\
	".\stdafx.h"\
	
# ADD CPP /Yc"stdafx.h"

BuildCmds= \
	$(CPP) /nologo /MD /W3 /GX /O1 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D\
 "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)/dipstick.pch" /Yc"stdafx.h" /Fo"$(INTDIR)/"\
 /c $(SOURCE) \
	

"$(INTDIR)\StdAfx.obj" : $(SOURCE) $(DEP_CPP_STDAF) "$(INTDIR)"
   $(BuildCmds)

"$(INTDIR)\dipstick.pch" : $(SOURCE) $(DEP_CPP_STDAF) "$(INTDIR)"
   $(BuildCmds)

!ELSEIF  "$(CFG)" == "Dipstick - Win32 Debug"

DEP_CPP_STDAF=\
	".\CrackURL.h"\
	".\shared-code\ip_icmp.h"\
	".\shared-code\kICMP.h"\
	".\shared-code\ms_icmp.h"\
	".\shared-code\RegEx.h"\
	".\stdafx.h"\
	
# ADD CPP /Yc"stdafx.h"

BuildCmds= \
	$(CPP) /nologo /MDd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS"\
 /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)/dipstick.pch" /Yc"stdafx.h"\
 /Fo"$(INTDIR)/" /Fd"$(INTDIR)/" /c $(SOURCE) \
	

"$(INTDIR)\StdAfx.obj" : $(SOURCE) $(DEP_CPP_STDAF) "$(INTDIR)"
   $(BuildCmds)

"$(INTDIR)\dipstick.pch" : $(SOURCE) $(DEP_CPP_STDAF) "$(INTDIR)"
   $(BuildCmds)

!ELSEIF  "$(CFG)" == "Dipstick - Win32 Release Static"

DEP_CPP_STDAF=\
	".\CrackURL.h"\
	".\shared-code\ip_icmp.h"\
	".\shared-code\kICMP.h"\
	".\shared-code\ms_icmp.h"\
	".\shared-code\RegEx.h"\
	".\stdafx.h"\
	
# ADD BASE CPP /Yc"stdafx.h"
# ADD CPP /Yc"stdafx.h"

BuildCmds= \
	$(CPP) /nologo /MT /W3 /GX /O1 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS"\
 /Fp"$(INTDIR)/dipstick.pch" /Yc"stdafx.h" /Fo"$(INTDIR)/" /c $(SOURCE) \
	

"$(INTDIR)\StdAfx.obj" : $(SOURCE) $(DEP_CPP_STDAF) "$(INTDIR)"
   $(BuildCmds)

"$(INTDIR)\dipstick.pch" : $(SOURCE) $(DEP_CPP_STDAF) "$(INTDIR)"
   $(BuildCmds)

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\dipstick.rc

!IF  "$(CFG)" == "Dipstick - Win32 Release"

DEP_RSC_DIPSTIC=\
	".\res\best.wav"\
	".\res\complete.ico"\
	".\res\Dipstick.ico"\
	".\res\dipstick.rc2"\
	".\res\kdnd.avi"\
	".\res\Kdragurl.avi"\
	".\res\pending.ico"\
	".\res\pinging.ico"\
	".\res\unreach.ico"\
	".\shared-data\klever-background.bmp"\
	

"$(INTDIR)\dipstick.res" : $(SOURCE) $(DEP_RSC_DIPSTIC) "$(INTDIR)"
   $(RSC) $(RSC_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "Dipstick - Win32 Debug"

DEP_RSC_DIPSTIC=\
	".\res\background.bmp"\
	".\res\best.wav"\
	".\res\complete.ico"\
	".\res\Dipstick.ico"\
	".\res\dipstick.rc2"\
	".\res\kdnd.avi"\
	".\res\Kdragurl.avi"\
	".\res\pending.ico"\
	".\res\pinging.ico"\
	".\res\unreach.ico"\
	

"$(INTDIR)\dipstick.res" : $(SOURCE) $(DEP_RSC_DIPSTIC) "$(INTDIR)"
   $(RSC) $(RSC_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "Dipstick - Win32 Release Static"

DEP_RSC_DIPSTIC=\
	".\res\background.bmp"\
	".\res\best.wav"\
	".\res\complete.ico"\
	".\res\Dipstick.ico"\
	".\res\dipstick.rc2"\
	".\res\kdnd.avi"\
	".\res\Kdragurl.avi"\
	".\res\pending.ico"\
	".\res\pinging.ico"\
	".\res\unreach.ico"\
	

"$(INTDIR)\dipstick.res" : $(SOURCE) $(DEP_RSC_DIPSTIC) "$(INTDIR)"
   $(RSC) $(RSC_PROJ) $(SOURCE)


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\DragPad.cpp

!IF  "$(CFG)" == "Dipstick - Win32 Release"

DEP_CPP_DRAGP=\
	".\CrackURL.h"\
	".\Dipstick.h"\
	".\DipstickDlg.h"\
	".\DragPad.h"\
	".\shared-code\ip_icmp.h"\
	".\shared-code\kICMP.h"\
	".\shared-code\ms_icmp.h"\
	".\shared-code\RegEx.h"\
	".\stdafx.h"\
	

"$(INTDIR)\DragPad.obj" : $(SOURCE) $(DEP_CPP_DRAGP) "$(INTDIR)"\
 "$(INTDIR)\dipstick.pch"


!ELSEIF  "$(CFG)" == "Dipstick - Win32 Debug"

DEP_CPP_DRAGP=\
	".\CrackURL.h"\
	".\Dipstick.h"\
	".\DipstickDlg.h"\
	".\DragPad.h"\
	".\shared-code\ip_icmp.h"\
	".\shared-code\kICMP.h"\
	".\shared-code\ms_icmp.h"\
	".\shared-code\RegEx.h"\
	".\stdafx.h"\
	

"$(INTDIR)\DragPad.obj" : $(SOURCE) $(DEP_CPP_DRAGP) "$(INTDIR)"\
 "$(INTDIR)\dipstick.pch"


!ELSEIF  "$(CFG)" == "Dipstick - Win32 Release Static"

DEP_CPP_DRAGP=\
	".\CrackURL.h"\
	".\Dipstick.h"\
	".\DipstickDlg.h"\
	".\DragPad.h"\
	".\shared-code\ip_icmp.h"\
	".\shared-code\kICMP.h"\
	".\shared-code\ms_icmp.h"\
	".\shared-code\RegEx.h"\
	".\stdafx.h"\
	

"$(INTDIR)\DragPad.obj" : $(SOURCE) $(DEP_CPP_DRAGP) "$(INTDIR)"\
 "$(INTDIR)\dipstick.pch"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\OptionsDlg.cpp

!IF  "$(CFG)" == "Dipstick - Win32 Release"

DEP_CPP_OPTIO=\
	".\CrackURL.h"\
	".\Dipstick.h"\
	".\OptionsDlg.h"\
	".\shared-code\ip_icmp.h"\
	".\shared-code\kICMP.h"\
	".\shared-code\ms_icmp.h"\
	".\shared-code\RegEx.h"\
	".\stdafx.h"\
	

"$(INTDIR)\OptionsDlg.obj" : $(SOURCE) $(DEP_CPP_OPTIO) "$(INTDIR)"\
 "$(INTDIR)\dipstick.pch"


!ELSEIF  "$(CFG)" == "Dipstick - Win32 Debug"

DEP_CPP_OPTIO=\
	".\CrackURL.h"\
	".\Dipstick.h"\
	".\OptionsDlg.h"\
	".\shared-code\ip_icmp.h"\
	".\shared-code\kICMP.h"\
	".\shared-code\ms_icmp.h"\
	".\shared-code\RegEx.h"\
	".\stdafx.h"\
	

"$(INTDIR)\OptionsDlg.obj" : $(SOURCE) $(DEP_CPP_OPTIO) "$(INTDIR)"\
 "$(INTDIR)\dipstick.pch"


!ELSEIF  "$(CFG)" == "Dipstick - Win32 Release Static"

DEP_CPP_OPTIO=\
	".\CrackURL.h"\
	".\Dipstick.h"\
	".\OptionsDlg.h"\
	".\shared-code\ip_icmp.h"\
	".\shared-code\kICMP.h"\
	".\shared-code\ms_icmp.h"\
	".\shared-code\RegEx.h"\
	".\stdafx.h"\
	

"$(INTDIR)\OptionsDlg.obj" : $(SOURCE) $(DEP_CPP_OPTIO) "$(INTDIR)"\
 "$(INTDIR)\dipstick.pch"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\HostNameDlg.cpp

!IF  "$(CFG)" == "Dipstick - Win32 Release"

DEP_CPP_HOSTN=\
	".\CrackURL.h"\
	".\Dipstick.h"\
	".\HostNameDlg.h"\
	".\shared-code\ip_icmp.h"\
	".\shared-code\kICMP.h"\
	".\shared-code\ms_icmp.h"\
	".\shared-code\RegEx.h"\
	".\stdafx.h"\
	

"$(INTDIR)\HostNameDlg.obj" : $(SOURCE) $(DEP_CPP_HOSTN) "$(INTDIR)"\
 "$(INTDIR)\dipstick.pch"


!ELSEIF  "$(CFG)" == "Dipstick - Win32 Debug"

DEP_CPP_HOSTN=\
	".\CrackURL.h"\
	".\Dipstick.h"\
	".\HostNameDlg.h"\
	".\shared-code\ip_icmp.h"\
	".\shared-code\kICMP.h"\
	".\shared-code\ms_icmp.h"\
	".\shared-code\RegEx.h"\
	".\stdafx.h"\
	

"$(INTDIR)\HostNameDlg.obj" : $(SOURCE) $(DEP_CPP_HOSTN) "$(INTDIR)"\
 "$(INTDIR)\dipstick.pch"


!ELSEIF  "$(CFG)" == "Dipstick - Win32 Release Static"

DEP_CPP_HOSTN=\
	".\CrackURL.h"\
	".\Dipstick.h"\
	".\HostNameDlg.h"\
	".\shared-code\ip_icmp.h"\
	".\shared-code\kICMP.h"\
	".\shared-code\ms_icmp.h"\
	".\shared-code\RegEx.h"\
	".\stdafx.h"\
	

"$(INTDIR)\HostNameDlg.obj" : $(SOURCE) $(DEP_CPP_HOSTN) "$(INTDIR)"\
 "$(INTDIR)\dipstick.pch"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\HostProperties.cpp

!IF  "$(CFG)" == "Dipstick - Win32 Release"

DEP_CPP_HOSTP=\
	".\CrackURL.h"\
	".\Dipstick.h"\
	".\DipstickDlg.h"\
	".\HostProperties.h"\
	".\shared-code\ip_icmp.h"\
	".\shared-code\kICMP.h"\
	".\shared-code\ms_icmp.h"\
	".\shared-code\RegEx.h"\
	".\stdafx.h"\
	

"$(INTDIR)\HostProperties.obj" : $(SOURCE) $(DEP_CPP_HOSTP) "$(INTDIR)"\
 "$(INTDIR)\dipstick.pch"


!ELSEIF  "$(CFG)" == "Dipstick - Win32 Debug"

DEP_CPP_HOSTP=\
	".\CrackURL.h"\
	".\Dipstick.h"\
	".\DipstickDlg.h"\
	".\HostProperties.h"\
	".\shared-code\ip_icmp.h"\
	".\shared-code\kICMP.h"\
	".\shared-code\ms_icmp.h"\
	".\shared-code\RegEx.h"\
	".\stdafx.h"\
	

"$(INTDIR)\HostProperties.obj" : $(SOURCE) $(DEP_CPP_HOSTP) "$(INTDIR)"\
 "$(INTDIR)\dipstick.pch"


!ELSEIF  "$(CFG)" == "Dipstick - Win32 Release Static"

DEP_CPP_HOSTP=\
	".\CrackURL.h"\
	".\Dipstick.h"\
	".\DipstickDlg.h"\
	".\HostProperties.h"\
	".\shared-code\ip_icmp.h"\
	".\shared-code\kICMP.h"\
	".\shared-code\ms_icmp.h"\
	".\shared-code\RegEx.h"\
	".\stdafx.h"\
	

"$(INTDIR)\HostProperties.obj" : $(SOURCE) $(DEP_CPP_HOSTP) "$(INTDIR)"\
 "$(INTDIR)\dipstick.pch"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\Help\DipStick.hpj

!IF  "$(CFG)" == "Dipstick - Win32 Release"

# Begin Custom Build - Making help file...
OutDir=.\Release
ProjDir=.
TargetName=dipstick
InputPath=.\help\dipstick.hpj

BuildCmds= \
	"$(ProjDir)\makehelp.bat" \
	compress $(OutDir)\$(TargetName).hlp $(OutDir)\$(TargetName).hl_ \
	compress $(OutDir)\$(TargetName).cnt $(OutDir)\$(TargetName).cn_ \
	

"$(OutDir)\$(TargetName).hlp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"$(OutDir)\$(TargetName).cnt" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"$(OutDir)\$(TargetName).hl_" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"$(OutDir)\$(TargetName).cn_" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)
# End Custom Build

!ELSEIF  "$(CFG)" == "Dipstick - Win32 Debug"

# Begin Custom Build - Making help file...
OutDir=.\Debug
ProjDir=.
TargetName=dipstick
InputPath=.\help\dipstick.hpj

BuildCmds= \
	"$(ProjDir)\makehelp.bat" \
	compress $(OutDir)\$(TargetName).hlp $(OutDir)\$(TargetName).hl_ \
	compress $(OutDir)\$(TargetName).cnt $(OutDir)\$(TargetName).cn_ \
	

"$(OutDir)\$(TargetName).hlp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"$(OutDir)\$(TargetName).cnt" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"$(OutDir)\$(TargetName).hl_" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"$(OutDir)\$(TargetName).cn_" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)
# End Custom Build

!ELSEIF  "$(CFG)" == "Dipstick - Win32 Release Static"

# Begin Custom Build - Making help file...
OutDir=.\Releast
ProjDir=.
TargetName=dipstick
InputPath=.\help\dipstick.hpj

BuildCmds= \
	"$(ProjDir)\makehelp.bat" \
	compress $(OutDir)\$(TargetName).hlp $(OutDir)\$(TargetName).hl_ \
	compress $(OutDir)\$(TargetName).cnt $(OutDir)\$(TargetName).cn_ \
	

"$(OutDir)\$(TargetName).hlp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"$(OutDir)\$(TargetName).cnt" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"$(OutDir)\$(TargetName).hl_" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"$(OutDir)\$(TargetName).cn_" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)
# End Custom Build

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\AutoBestDlg.cpp

!IF  "$(CFG)" == "Dipstick - Win32 Release"

DEP_CPP_AUTOB=\
	".\AutoBestDlg.h"\
	".\CrackURL.h"\
	".\Dipstick.h"\
	".\shared-code\ip_icmp.h"\
	".\shared-code\kICMP.h"\
	".\shared-code\ms_icmp.h"\
	".\shared-code\RegEx.h"\
	".\stdafx.h"\
	".\URLSource.h"\
	

"$(INTDIR)\AutoBestDlg.obj" : $(SOURCE) $(DEP_CPP_AUTOB) "$(INTDIR)"\
 "$(INTDIR)\dipstick.pch"


!ELSEIF  "$(CFG)" == "Dipstick - Win32 Debug"

DEP_CPP_AUTOB=\
	".\AutoBestDlg.h"\
	".\CrackURL.h"\
	".\Dipstick.h"\
	".\shared-code\ip_icmp.h"\
	".\shared-code\kICMP.h"\
	".\shared-code\ms_icmp.h"\
	".\shared-code\RegEx.h"\
	".\stdafx.h"\
	".\URLSource.h"\
	

"$(INTDIR)\AutoBestDlg.obj" : $(SOURCE) $(DEP_CPP_AUTOB) "$(INTDIR)"\
 "$(INTDIR)\dipstick.pch"


!ELSEIF  "$(CFG)" == "Dipstick - Win32 Release Static"

DEP_CPP_AUTOB=\
	".\AutoBestDlg.h"\
	".\CrackURL.h"\
	".\Dipstick.h"\
	".\shared-code\ip_icmp.h"\
	".\shared-code\kICMP.h"\
	".\shared-code\ms_icmp.h"\
	".\shared-code\RegEx.h"\
	".\stdafx.h"\
	".\URLSource.h"\
	

"$(INTDIR)\AutoBestDlg.obj" : $(SOURCE) $(DEP_CPP_AUTOB) "$(INTDIR)"\
 "$(INTDIR)\dipstick.pch"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\URLSource.cpp

!IF  "$(CFG)" == "Dipstick - Win32 Release"

DEP_CPP_URLSO=\
	".\CrackURL.h"\
	".\shared-code\ip_icmp.h"\
	".\shared-code\kICMP.h"\
	".\shared-code\ms_icmp.h"\
	".\shared-code\RegEx.h"\
	".\stdafx.h"\
	".\URLSource.h"\
	

"$(INTDIR)\URLSource.obj" : $(SOURCE) $(DEP_CPP_URLSO) "$(INTDIR)"\
 "$(INTDIR)\dipstick.pch"


!ELSEIF  "$(CFG)" == "Dipstick - Win32 Debug"

DEP_CPP_URLSO=\
	".\CrackURL.h"\
	".\shared-code\ip_icmp.h"\
	".\shared-code\kICMP.h"\
	".\shared-code\ms_icmp.h"\
	".\shared-code\RegEx.h"\
	".\stdafx.h"\
	".\URLSource.h"\
	

"$(INTDIR)\URLSource.obj" : $(SOURCE) $(DEP_CPP_URLSO) "$(INTDIR)"\
 "$(INTDIR)\dipstick.pch"


!ELSEIF  "$(CFG)" == "Dipstick - Win32 Release Static"

DEP_CPP_URLSO=\
	".\CrackURL.h"\
	".\shared-code\ip_icmp.h"\
	".\shared-code\kICMP.h"\
	".\shared-code\ms_icmp.h"\
	".\shared-code\RegEx.h"\
	".\stdafx.h"\
	".\URLSource.h"\
	

"$(INTDIR)\URLSource.obj" : $(SOURCE) $(DEP_CPP_URLSO) "$(INTDIR)"\
 "$(INTDIR)\dipstick.pch"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\Help\Dipstick.cnt

!IF  "$(CFG)" == "Dipstick - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Dipstick - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Dipstick - Win32 Release Static"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\CrackURL.cpp

!IF  "$(CFG)" == "Dipstick - Win32 Release"

DEP_CPP_CRACK=\
	".\CrackURL.h"\
	".\shared-code\ip_icmp.h"\
	".\shared-code\kICMP.h"\
	".\shared-code\ms_icmp.h"\
	".\shared-code\RegEx.h"\
	".\stdafx.h"\
	

"$(INTDIR)\CrackURL.obj" : $(SOURCE) $(DEP_CPP_CRACK) "$(INTDIR)"\
 "$(INTDIR)\dipstick.pch"


!ELSEIF  "$(CFG)" == "Dipstick - Win32 Debug"

DEP_CPP_CRACK=\
	".\CrackURL.h"\
	".\shared-code\ip_icmp.h"\
	".\shared-code\kICMP.h"\
	".\shared-code\ms_icmp.h"\
	".\shared-code\RegEx.h"\
	".\stdafx.h"\
	

"$(INTDIR)\CrackURL.obj" : $(SOURCE) $(DEP_CPP_CRACK) "$(INTDIR)"\
 "$(INTDIR)\dipstick.pch"


!ELSEIF  "$(CFG)" == "Dipstick - Win32 Release Static"

DEP_CPP_CRACK=\
	".\CrackURL.h"\
	".\shared-code\ip_icmp.h"\
	".\shared-code\kICMP.h"\
	".\shared-code\ms_icmp.h"\
	".\shared-code\RegEx.h"\
	".\stdafx.h"\
	

"$(INTDIR)\CrackURL.obj" : $(SOURCE) $(DEP_CPP_CRACK) "$(INTDIR)"\
 "$(INTDIR)\dipstick.pch"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\SelectURLsDlg.cpp

!IF  "$(CFG)" == "Dipstick - Win32 Release"

DEP_CPP_SELEC=\
	".\CrackURL.h"\
	".\Dipstick.h"\
	".\SelectURLsDlg.h"\
	".\shared-code\ip_icmp.h"\
	".\shared-code\kICMP.h"\
	".\shared-code\ms_icmp.h"\
	".\shared-code\RegEx.h"\
	".\stdafx.h"\
	

"$(INTDIR)\SelectURLsDlg.obj" : $(SOURCE) $(DEP_CPP_SELEC) "$(INTDIR)"\
 "$(INTDIR)\dipstick.pch"


!ELSEIF  "$(CFG)" == "Dipstick - Win32 Debug"

DEP_CPP_SELEC=\
	".\CrackURL.h"\
	".\Dipstick.h"\
	".\SelectURLsDlg.h"\
	".\shared-code\ip_icmp.h"\
	".\shared-code\kICMP.h"\
	".\shared-code\ms_icmp.h"\
	".\shared-code\RegEx.h"\
	".\stdafx.h"\
	

"$(INTDIR)\SelectURLsDlg.obj" : $(SOURCE) $(DEP_CPP_SELEC) "$(INTDIR)"\
 "$(INTDIR)\dipstick.pch"


!ELSEIF  "$(CFG)" == "Dipstick - Win32 Release Static"

DEP_CPP_SELEC=\
	".\CrackURL.h"\
	".\Dipstick.h"\
	".\SelectURLsDlg.h"\
	".\shared-code\ip_icmp.h"\
	".\shared-code\kICMP.h"\
	".\shared-code\ms_icmp.h"\
	".\shared-code\RegEx.h"\
	".\stdafx.h"\
	

"$(INTDIR)\SelectURLsDlg.obj" : $(SOURCE) $(DEP_CPP_SELEC) "$(INTDIR)"\
 "$(INTDIR)\dipstick.pch"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=".\shared-code\RegEx.cpp"

!IF  "$(CFG)" == "Dipstick - Win32 Release"

DEP_CPP_REGEX=\
	".\CrackURL.h"\
	".\shared-code\ip_icmp.h"\
	".\shared-code\kICMP.h"\
	".\shared-code\ms_icmp.h"\
	".\shared-code\RegEx.h"\
	".\stdafx.h"\
	
# ADD CPP /Yu"../stdafx.h"

"$(INTDIR)\RegEx.obj" : $(SOURCE) $(DEP_CPP_REGEX) "$(INTDIR)"\
 "$(INTDIR)\dipstick.pch"
   $(CPP) /nologo /MD /W3 /GX /O1 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D\
 "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)/dipstick.pch" /Yu"../stdafx.h"\
 /Fo"$(INTDIR)/" /c $(SOURCE)


!ELSEIF  "$(CFG)" == "Dipstick - Win32 Debug"

DEP_CPP_REGEX=\
	".\CrackURL.h"\
	".\shared-code\ip_icmp.h"\
	".\shared-code\kICMP.h"\
	".\shared-code\ms_icmp.h"\
	".\shared-code\RegEx.h"\
	".\stdafx.h"\
	
# ADD CPP /Yu"../stdafx.h"

"$(INTDIR)\RegEx.obj" : $(SOURCE) $(DEP_CPP_REGEX) "$(INTDIR)"\
 "$(INTDIR)\dipstick.pch"
   $(CPP) /nologo /MDd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS"\
 /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)/dipstick.pch" /Yu"../stdafx.h"\
 /Fo"$(INTDIR)/" /Fd"$(INTDIR)/" /c $(SOURCE)


!ELSEIF  "$(CFG)" == "Dipstick - Win32 Release Static"

DEP_CPP_REGEX=\
	".\CrackURL.h"\
	".\shared-code\ip_icmp.h"\
	".\shared-code\kICMP.h"\
	".\shared-code\ms_icmp.h"\
	".\shared-code\RegEx.h"\
	".\stdafx.h"\
	
# ADD CPP /Yu"../stdafx.h"

"$(INTDIR)\RegEx.obj" : $(SOURCE) $(DEP_CPP_REGEX) "$(INTDIR)"\
 "$(INTDIR)\dipstick.pch"
   $(CPP) /nologo /MT /W3 /GX /O1 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D\
 "_MBCS" /Fp"$(INTDIR)/dipstick.pch" /Yu"../stdafx.h" /Fo"$(INTDIR)/" /c\
 $(SOURCE)


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=".\shared-code\kICMP.cpp"

!IF  "$(CFG)" == "Dipstick - Win32 Release"

DEP_CPP_KICMP=\
	".\CrackURL.h"\
	".\shared-code\ip_icmp.h"\
	".\shared-code\kICMP.h"\
	".\shared-code\ms_icmp.h"\
	".\shared-code\RegEx.h"\
	".\stdafx.h"\
	
# ADD CPP /Yu"../stdafx.h"

"$(INTDIR)\kICMP.obj" : $(SOURCE) $(DEP_CPP_KICMP) "$(INTDIR)"\
 "$(INTDIR)\dipstick.pch"
   $(CPP) /nologo /MD /W3 /GX /O1 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D\
 "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)/dipstick.pch" /Yu"../stdafx.h"\
 /Fo"$(INTDIR)/" /c $(SOURCE)


!ELSEIF  "$(CFG)" == "Dipstick - Win32 Debug"

DEP_CPP_KICMP=\
	".\CrackURL.h"\
	".\shared-code\ip_icmp.h"\
	".\shared-code\kICMP.h"\
	".\shared-code\ms_icmp.h"\
	".\shared-code\RegEx.h"\
	".\stdafx.h"\
	
# ADD CPP /Yu"../stdafx.h"

"$(INTDIR)\kICMP.obj" : $(SOURCE) $(DEP_CPP_KICMP) "$(INTDIR)"\
 "$(INTDIR)\dipstick.pch"
   $(CPP) /nologo /MDd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS"\
 /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)/dipstick.pch" /Yu"../stdafx.h"\
 /Fo"$(INTDIR)/" /Fd"$(INTDIR)/" /c $(SOURCE)


!ELSEIF  "$(CFG)" == "Dipstick - Win32 Release Static"

DEP_CPP_KICMP=\
	".\CrackURL.h"\
	".\shared-code\ip_icmp.h"\
	".\shared-code\kICMP.h"\
	".\shared-code\ms_icmp.h"\
	".\shared-code\RegEx.h"\
	".\stdafx.h"\
	
# ADD CPP /Yu"../stdafx.h"

"$(INTDIR)\kICMP.obj" : $(SOURCE) $(DEP_CPP_KICMP) "$(INTDIR)"\
 "$(INTDIR)\dipstick.pch"
   $(CPP) /nologo /MT /W3 /GX /O1 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D\
 "_MBCS" /Fp"$(INTDIR)/dipstick.pch" /Yu"../stdafx.h" /Fo"$(INTDIR)/" /c\
 $(SOURCE)


!ENDIF 

# End Source File
# End Target
################################################################################
# Begin Target

# Name "Install - Win32 Debug"
# Name "Install - Win32 Pure"
# Name "Install - Win32 Static"
# Name "Install - Win32 Canned"

!IF  "$(CFG)" == "Install - Win32 Debug"

!ELSEIF  "$(CFG)" == "Install - Win32 Pure"

!ELSEIF  "$(CFG)" == "Install - Win32 Static"

!ELSEIF  "$(CFG)" == "Install - Win32 Canned"

!ENDIF 

################################################################################
# Begin Source File

SOURCE=.\Install\Install.rc
DEP_RSC_INSTA=\
	".\Install\Custom.rch"\
	".\shared-data\install-icon.ico"\
	

!IF  "$(CFG)" == "Install - Win32 Debug"


"$(INTDIR)\Install.res" : $(SOURCE) $(DEP_RSC_INSTA) "$(INTDIR)"
   $(RSC) /l 0x409 /fo"$(INTDIR)/Install.res" /i "Install" /d "_DEBUG"\
 $(SOURCE)


!ELSEIF  "$(CFG)" == "Install - Win32 Pure"


"$(INTDIR)\Install.res" : $(SOURCE) $(DEP_RSC_INSTA) "$(INTDIR)"
   $(RSC) /l 0x409 /fo"$(INTDIR)/Install.res" /i "Install" /d "NDEBUG"\
 $(SOURCE)


!ELSEIF  "$(CFG)" == "Install - Win32 Static"


"$(INTDIR)\Install.res" : $(SOURCE) $(DEP_RSC_INSTA) "$(INTDIR)"
   $(RSC) /l 0x409 /fo"$(INTDIR)/Install.res" /i "Install" /d "NDEBUG" /d\
 "STATI_K" $(SOURCE)


!ELSEIF  "$(CFG)" == "Install - Win32 Canned"


"$(INTDIR)\Install.res" : $(SOURCE) $(DEP_RSC_INSTA) "$(INTDIR)"
   $(RSC) /l 0x409 /fo"$(INTDIR)/Install.res" /i "Install" /d "NDEBUG" /d\
 "K_ANNED" $(SOURCE)


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\Install\install.cpp
DEP_CPP_INSTAL=\
	".\shared-code\install.h"\
	

!IF  "$(CFG)" == "Install - Win32 Debug"


"$(INTDIR)\install.obj" : $(SOURCE) $(DEP_CPP_INSTAL) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "Install - Win32 Pure"


"$(INTDIR)\install.obj" : $(SOURCE) $(DEP_CPP_INSTAL) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "Install - Win32 Static"


"$(INTDIR)\install.obj" : $(SOURCE) $(DEP_CPP_INSTAL) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "Install - Win32 Canned"


"$(INTDIR)\install.obj" : $(SOURCE) $(DEP_CPP_INSTAL) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

# End Source File
################################################################################
# Begin Project Dependency

# Project_Dep_Name "Dipstick"

!IF  "$(CFG)" == "Install - Win32 Debug"

"Dipstick - Win32 Debug" : 
   $(MAKE) /$(MAKEFLAGS) /F ".\dipstick.mak" CFG="Dipstick - Win32 Debug" 

!ELSEIF  "$(CFG)" == "Install - Win32 Pure"

!ELSEIF  "$(CFG)" == "Install - Win32 Static"

!ELSEIF  "$(CFG)" == "Install - Win32 Canned"

!ENDIF 

# End Project Dependency
# End Target
# End Project
################################################################################
