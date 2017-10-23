#ifndef WIZARD_H
#define WIZARD_H

Project_Win32_GUI = 0
Project_Win32_DLL = 1
Project_Win32_Library = 2
Project_Win32_Console = 3
Project_WinCE_GUI = 4
Project_WinCE_DLL = 5
Project_WinCE_Library = 6

Action_SetActive = 1
Action_KillActive = 2
Action_UpdateUI = 3

#IFDEF UNICODE
	#define WizAddStep  WizAddStepW
	#define WizAddProjectFile  WizAddProjectFileW
	#define WizGetProjectName  WizGetProjectNameW
	#define WizGetProjectSymbol  WizGetProjectSymbolW
	#define WizSetProjectSymbol  WizSetProjectSymbolW
	#define WizWriteFileFromResource WizWriteFileFromResourceW
	#define WizWriteTextFileFromResource WizWriteTextFileFromResourceW
#else
	#define WizAddStep  WizAddStepA
	#define WizAddProjectFile  WizAddProjectFileA
	#define WizGetProjectName  WizGetProjectNameA
	#define WizGetProjectSymbol  WizGetProjectSymbolA
	#define WizSetProjectSymbol  WizSetProjectSymbolA
	#define WizWriteFileFromResource WizWriteFileFromResourceA
	#define WizWriteTextFileFromResource WizWriteTextFileFromResourceA
#endif

#endif
