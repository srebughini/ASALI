#define AppVersion "3.0.0"

[Setup]
AppName=Asali
AppVersion={#AppVersion}
AppPublisher=Stefano Rebughini
AppPublisherURL=https://srebughini.github.io/ASALI/
AppSupportURL=https://github.com/srebughini/ASALI/issues
AppUpdatesURL=https://github.com/srebughini/ASALI
DefaultDirName={pf}\Asali
DefaultGroupName=Asali {#AppVersion}
DisableProgramGroupPage=yes
OutputBaseFilename=Asali-Setup-{#AppVersion}
Compression=lzma
SolidCompression=yes
PrivilegesRequired=admin
SetupIconFile=dist\Asali\_internal\src\resources\images\Icon.ico
ArchitecturesInstallIn64BitMode=x64
OutputDir=installer
UninstallDisplayIcon={app}\Asali.exe
LicenseFile=..\LICENSE

[Languages]
Name: "english"; MessagesFile: "compiler:Default.isl"

[Files]
Source: "dist\Asali\Asali.exe"; DestDir: "{app}"; Flags: ignoreversion
Source: "dist\Asali\_internal\*"; DestDir: "{app}\_internal"; Flags: recursesubdirs createallsubdirs ignoreversion
Source: "..\LICENSE"; DestDir: "{app}"; Flags: ignoreversion

[Icons]
Name: "{group}\Asali"; Filename: "{app}\Asali.exe"
Name: "{commondesktop}\Asali"; Filename: "{app}\Asali.exe"; Tasks: desktopicon

[Tasks]
Name: "desktopicon"; Description: "Create a &desktop icon"; GroupDescription: "Additional icons:"; Flags: checkedonce

[Run]
Filename: "{app}\Asali.exe"; Description: "Launch Asali"; Flags: nowait postinstall skipifsilent
