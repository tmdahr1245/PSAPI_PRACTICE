#include <windows.h>
#include <psapi.h>
#include <iostream>
#include <winbase.h>
#include <algorithm>

using namespace std;
void PrintProcessNameAndID( DWORD processID );
void KillProcessByCommand(DWORD processID);
void PrintImageFileName(DWORD processID);
int main( void ){
	DWORD aProcesses[1024], cbNeeded, cProcesses=100;
	int i, input;
	if ( !EnumProcesses( aProcesses, sizeof(aProcesses), &cbNeeded ) ){
		return 1;
	}
	cProcesses = cbNeeded / sizeof(DWORD);
	
	sort(aProcesses,aProcesses+cProcesses);
	for ( i = 0; i < cProcesses; i++ ){
		if( aProcesses[i] != 0 )PrintProcessNameAndID( aProcesses[i] );
	}
	cout<<endl<<endl<<" Input PID for printing path :";
	cin>>input;
	PrintImageFileName(input);
	
	
	cout<<endl<<" Input PID for killing process : ";
	cin>>input;
		
	KillProcessByCommand(input);
	
	return 0;
}