@echo off
REM -- First make map file from Microsoft Visual C++ generated resource.h
echo // MAKEHELP.BAT generated Help Map file.  Used by DIPSTICK.HPJ. >"help\dipstick.hm"
echo. >>"help\dipstick.hm"
REM echo // Commands (ID_* and IDM_*) >>"help\dipstick.hm"
REM makehm ID_,HID_,0x10000 IDM_,HIDM_,0x10000 resource.h >>"help\dipstick.hm"
REM echo. >>"help\dipstick.hm"
REM echo // Prompts (IDP_*) >>"help\dipstick.hm"
REM makehm IDP_,HIDP_,0x30000 resource.h >>"help\dipstick.hm"
REM echo. >>"help\dipstick.hm"
REM echo // Resources (IDR_*) >>"help\dipstick.hm"
REM makehm IDR_,HIDR_,0x20000 resource.h >>"help\dipstick.hm"
REM echo. >>"help\dipstick.hm"
echo // Dialogs (IDD_*) >>"help\dipstick.hm"
makehm IDD_,HIDD_,0x20000 resource.h >>"help\dipstick.hm"
echo. >>"help\dipstick.hm"
REM echo // Frame Controls (IDW_*) >>"help\dipstick.hm"
REM makehm IDW_,HIDW_,0x50000 resource.h >>"help\dipstick.hm"
makehm IDH_,IDH_,0 resource.h >>"help\dipstick.hm"
REM -- Make help for Project DIPSTICK

echo Building RTF file
xsltproc -o help/dipstick.rtf shared-code/kinhelp.xsl help/dipstick.xml
echo Building Win32 Help files
start /wait hcrtf -x "help\dipstick.hpj"
echo.
if exist Debug\nul copy "help\dipstick.hlp" Debug
if exist Debug\nul copy "help\dipstick.cnt" Debug
if exist Release\nul copy "help\dipstick.hlp" Release
if exist Release\nul copy "help\dipstick.cnt" Release
if exist Releast\nul copy "help\dipstick.hlp" Releast
if exist Releast\nul copy "help\dipstick.cnt" Releast
echo.
