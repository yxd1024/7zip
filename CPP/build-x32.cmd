@echo on

set ROOT=%cd%\7zip
set VC_LTL_PATH=%CD%\..\VC-LTL
set DisableAdvancedSupport=true
set LTL_Mode=Light
set VC_LTL_Helper_Load=
set OUTDIR=%ROOT%\..\..\bin32
mkdir %OUTDIR%

set OPTS=MY_STATIC_LINK=1
set LFLAGS=/SUBSYSTEM:WINDOWS,"5.01"

cd %ROOT%\Bundles\Format7zExtract
nmake %OPTS%
copy O\7zxa.dll %OUTDIR%\7zxa.dll

cd %ROOT%\Bundles\Format7z
nmake %OPTS%
copy O\7za.dll %OUTDIR%\7za.dll

cd %ROOT%\Bundles\Format7zF
nmake %OPTS%
copy O\7z.dll %OUTDIR%\7z.dll

cd %ROOT%\UI\FileManager
nmake %OPTS%
copy O\7zFM.exe %OUTDIR%\7zFM.exe

cd %ROOT%\UI\GUI
nmake %OPTS%
copy O\7zG.exe %OUTDIR%\7zG.exe

cd %ROOT%\UI\Explorer
nmake %OPTS%
copy O\7-zip.dll %OUTDIR%\7-zip.dll

cd %ROOT%\Bundles\SFXWin
nmake %OPTS%
copy O\7z.sfx %OUTDIR%\7z.sfx

cd %ROOT%\..\..\C\Util\7zipInstall
nmake %OPTS%
copy O\7zipInstall.exe %OUTDIR%\..\Install-x32.exe

cd %ROOT%\..\..\C\Util\7zipUninstall
nmake %OPTS%
copy O\7zipUninstall.exe %OUTDIR%\Uninstall.exe

set LFLAGS=/SUBSYSTEM:CONSOLE,"5.01"
cd %ROOT%\UI\Console
nmake %OPTS%
copy O\7z.exe %OUTDIR%\7z.exe

cd %ROOT%\Bundles\SFXCon
nmake %OPTS%
copy O\7zCon.sfx %OUTDIR%\7zCon.sfx

cd %ROOT%\Bundles\Alone
nmake %OPTS%
copy O\7za.exe %OUTDIR%\7za.exe

xcopy /S /G /H /R /Y /Q /I %ROOT%\..\..\Lang %OUTDIR%\Lang
xcopy /S /G /H /R /Y /Q /I %ROOT%\..\..\Formats32 %OUTDIR%\Formats
::xcopy /S /G /H /R /Y /Q /I %ROOT%\..\..\Codecs32 %OUTDIR%\Codecs

%OUTDIR%\7z.exe a -m0=lzma -mx9 %OUTDIR%\..\7z-x32.7z %OUTDIR%\*
copy /b %OUTDIR%\..\Install-x32.exe /b + %OUTDIR%\..\7z-x32.7z /b %OUTDIR%\..\7z-x32.exe
del %OUTDIR%\..\7z-x32.7z
del %OUTDIR%\..\Install-x32.exe

:ende
cd %ROOT%\..
