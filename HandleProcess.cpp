#include <windows.h>
#include <tchar.h>
#include <psapi.h>
#include <iostream>
#include <winbase.h>

using namespace std;

void PrintProcessNameAndID( DWORD processID ){
	TCHAR  szProcessName[MAX_PATH];
	HANDLE hProcess = OpenProcess( PROCESS_QUERY_INFORMATION | PROCESS_VM_READ, FALSE, processID );
	if (NULL != hProcess ){
		HMODULE hMod;
		DWORD cbNeeded;
		if ( EnumProcessModules( hProcess, &hMod, sizeof(hMod), &cbNeeded)){
			GetModuleBaseName( hProcess, hMod, szProcessName, MAX_PATH );
			cout<<" "<<szProcessName<<"  (PID: "<<processID<<")"<<endl;
		}
	}
	CloseHandle( hProcess );
}

void KillProcessByCommand(DWORD processID){
	HANDLE hProcess = OpenProcess( PROCESS_TERMINATE, FALSE, processID );
	if(!TerminateProcess(hProcess,0))cout<<" [+] Fail To Kill Process."<<endl;
    CloseHandle( hProcess );
}

void PrintImageFileName(DWORD processID){
	TCHAR szImageName[MAX_PATH];
	HANDLE hProcess=OpenProcess(PROCESS_QUERY_INFORMATION | PROCESS_VM_READ, FALSE, processID);
	if(NULL!=hProcess){
		GetProcessImageFileName(hProcess,szImageName,sizeof(szImageName)/sizeof(*szImageName));
		cout<<" "<<szImageName<<endl;
	}
	else cout<<" Fail to Open Process"<<endl;
	CloseHandle(hProcess);
}
