//
// Created by kikog on 11/24/2024.
//

#include <windows.h>
#include <tlhelp32.h>
#include <stdio.h>

void ProcessID() {

    // Creates a Snapshot of the processes and will print if failed.
    HANDLE hSnaphot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    if (hSnaphot == INVALID_HANDLE_VALUE) {
        printf("Failed to create process.");
    }

    // Gets information about the first process and setting the size of the structure so we can enum through processes.
    PROCESSENTRY32 firstProcess;
    firstProcess.dwSize = sizeof(PROCESSENTRY32);

    // Getting the first process and printing its ID and name.
    if (Process32First(hSnaphot, &firstProcess)) {
        do {
            printf(" | Process Name: %s", firstProcess.szExeFile);
            printf(" | Parent Process ID: %Id", firstProcess.th32ParentProcessID);
            printf(" | Process ID: %Id\n", firstProcess.th32ProcessID);
        }
        // Going into a loop that always checks the next process in the snapshot.
        while (Process32Next(hSnaphot, &firstProcess));

    }
    else {
        printf("Failed to get process.\n");
    }
    CloseHandle(hSnaphot);
}

int main() {
    ProcessID();
    return 0;
}
