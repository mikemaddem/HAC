//
// Created by mikem on 4/13/2020.
//

#include <iostream>
#include <windows.h>
#include <stdio.h>
#include <tchar.h>
#include <psapi.h>
#include <windows.h> //include windows.h header file (needed for windows API)
#include <tlhelp32.h> //include tlhelp32.h
#include <tchar.h>	//tchar.h header file
#include <iostream> //include iostream header file for input/output operations
#include <string> //include string header (needed for some string operations)


int main() {
    std::cout << "Hello, World!" << std::endl;
    DWORD aProcess[1024], cbNeeded, cProcesses;
    HANDLE hProcess = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    std::cout << hProcess;
    return 0;
}