@echo on

set ROOT=%cd%\7zip
set VC_LTL_PATH=%CD%\..\VC-LTL
set DisableAdvancedSupport=true
set LTL_Mode=Light
set VC_LTL_Helper_Load=
set OUTDIR=%ROOT%\bin64
mkdir %OUTDIR%

set OPTS=CPU=AMD64 MY_STATIC_LINK=1
set LFLAGS=/SUBSYSTEM:WINDOWS,"5.02"

cd %ROOT%\Bundles\Format7zExtract
nmake %OPTS%
copy AMD64\7zxa.dll %OUTDIR%\7zxa.dll

cd %ROOT%\Bundles\Format7z
nmake %OPTS%
copy AMD64\7za.dll %OUTDIR%\7za.dll

cd %ROOT%\Bundles\Format7zF
nmake %OPTS%
copy AMD64\7z.dll %OUTDIR%\7z.dll

cd %ROOT%\Bundles\Format7zFO
nmake %OPTS%
copy AMD64\7z.dll %OUTDIR%\7zOrig.dll

cd %ROOT%\Bundles\Format7zUSB
nmake %OPTS%
copy AMD64\7zu.dll %OUTDIR%\7zu-x64.dll

cd %ROOT%\UI\FileManager
nmake %OPTS%
copy AMD64\7zFM.exe %OUTDIR%\7zFM.exe

cd %ROOT%\UI\GUI
nmake %OPTS%
copy AMD64\7zG.exe %OUTDIR%\7zG.exe

cd %ROOT%\UI\Explorer
nmake %OPTS%
copy AMD64\7-zip.dll %OUTDIR%\7-zip.dll

cd %ROOT%\Bundles\SFXWin
nmake %OPTS%
copy AMD64\7z.sfx %OUTDIR%\7z.sfx

cd %ROOT%\..\..\C\Util\7zipInstall
nmake %OPTS%
copy AMD64\7zipInstall.exe %OUTDIR%\Install-x64.exe

cd %ROOT%\..\..\C\Util\7zipUninstall
nmake %OPTS%
copy AMD64\7zipUninstall.exe %OUTDIR%\Uninstall.exe

set LFLAGS=/SUBSYSTEM:CONSOLE,"5.02"
cd %ROOT%\UI\Console
nmake %OPTS%
copy AMD64\7z.exe %OUTDIR%\7z.exe

cd %ROOT%\Bundles\SFXCon
nmake %OPTS%
copy AMD64\7zCon.sfx %OUTDIR%\7zCon.sfx

cd %ROOT%\Bundles\Alone
nmake %OPTS%
copy AMD64\7za.exe %OUTDIR%\7za.exe

xcopy /S /G /H /R /Y /Q /I %ROOT%\..\..\Lang %OUTDIR%\Lang
::xcopy /S /G /H /R /Y /Q /I %ROOT%\..\..\Formats64 %OUTDIR%\Formats64
::xcopy /S /G /H /R /Y /Q /I %ROOT%\..\..\Codecs64 %OUTDIR%\Codecs64

:ende
cd %ROOT%\..
