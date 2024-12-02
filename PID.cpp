#include <windows.h>
#include <tlhelp32.h>
#include <iostream>
using namespace std;

void ProcessID() {

	// Creates a Snapshot of the processes and will print if failed.
	HANDLE hSnaphot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	if (hSnaphot == INVALID_HANDLE_VALUE) {
		wcout << "Failed to create process.";
		}

	// Get's information about the first process and setting the size of the structure so we can enum through processes.
	PROCESSENTRY32 firstProcess;
	firstProcess.dwSize = sizeof(PROCESSENTRY32);

	if (Process32First(hSnaphot, &firstProcess)) {
		do {
			wcout << L" | " << firstProcess.szExeFile;
			wcout << L" | Parent Process ID: " << firstProcess.th32ParentProcessID;
			wcout << L" | Process ID: " << firstProcess.th32ProcessID << endl;
		} 
		while (Process32Next(hSnaphot, &firstProcess));
		
	}
	else {
		wcout << "Failed to get process." << endl;
	}
	CloseHandle(hSnaphot);
}

int main() {
	ProcessID();
	return 0;
	}
