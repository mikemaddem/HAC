//
// Created by mikem on 4/13/2020.
//

#include <iostream>

#include <stdio.h>
#include <windows.h> //include windows.h header file (needed for windows API)
#include <tlhelp32.h> //include tlhelp32.h
#include <tchar.h>    //tchar.h header file
#include <iostream> //include iostream header file for input/output operations
#include <string> //include string header (needed for some string operations)
#include <cstdio>

void osDetect() {
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__)
    //define something for Windows (32-bit and 64-bit, this part is common)
    std::cout << "Windows 32bit detected" << std::endl;
#ifdef _WIN64
    //define something for Windows (64-bit only)
    std::cout << "Windows 64bit detected" << std::endl;
#else
    //define something for Windows (32-bit only)
#endif
#elif __APPLE__
    #include <TargetConditionals.h>
#if TARGET_IPHONE_SIMULATOR
    // iOS Simulator
#elif TARGET_OS_IPHONE
   // iOS device
#elif TARGET_OS_MAC
   // Other kinds of Mac OS
#else
#   error "Unknown Apple platform"
#endif
#elif __linux__
// linux
#elif __unix__ // all unices not caught above
// Unix
#elif defined(_POSIX_VERSION)
// POSIX
#else
#   error "Unknown compiler"
#endif

}

int main() {
    std::cout << "Welcome to HAC" << std::endl;
    std::cout << "HAC is a WIP CS:GO Anticheat client" << std::endl;
    osDetect();
    DWORD aProcess[1024], cbNeeded, cProcesses;
    HANDLE hProcess1 = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    std::cout << sizeof(hProcess1) << std::endl;


    PROCESSENTRY32 entry;
    entry.dwSize = sizeof(PROCESSENTRY32);

    HANDLE snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, NULL);

    if (Process32First(snapshot, &entry) == TRUE) {
        while (Process32Next(snapshot, &entry) == TRUE) {
            if (stricmp(entry.szExeFile, "calculator.exe") == 0) {
                HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, entry.th32ProcessID);

                std::cout << "Grabbed calculator process" << std::endl;

                CloseHandle(hProcess);
            }
        }
    }

    CloseHandle(snapshot);
    std::getchar();
    return 0;
}

