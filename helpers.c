#include <windows.h>
#include <stdio.h>
#include "helpers.h"


int RunCommand(char command[]) {
    // https://learn.microsoft.com/en-us/windows/win32/procthread/creating-processes

    STARTUPINFO si;
    PROCESS_INFORMATION pi;

    ZeroMemory( &si, sizeof(si) );
    si.cb = sizeof(si);
    ZeroMemory( &pi, sizeof(pi) );

    printf("Running command: %s", command);

    // Start the child process. 
    if(!CreateProcess(NULL,   // No module name (use command line)
        command,        // Command line
        NULL,           // Process handle not inheritable
        NULL,           // Thread handle not inheritable
        FALSE,          // Set handle inheritance to FALSE
        0,              // No creation flags
        NULL,           // Use parent's environment block
        NULL,           // Use parent's starting directory 
        &si,            // Pointer to STARTUPINFO structure
        &pi)            // Pointer to PROCESS_INFORMATION structure
    ) {
        printf("CreateProcess failed (%d).\n", GetLastError());
        return 1;
    }

    // Wait until child process exits.
    WaitForSingleObject( pi.hProcess, INFINITE );

    // Close process and thread handles. 
    CloseHandle( pi.hProcess );
    CloseHandle( pi.hThread );
    return 0;
}

int RunPowerShellScript(char powerShellScriptPath[]) {
    const size_t bufferLen = 300;
    char scriptCommand[bufferLen];
    snprintf(scriptCommand, bufferLen, "powershell -ExecutionPolicy Bypass -Command \"& '%s'\"", powerShellScriptPath);
    return RunCommand(scriptCommand);
}
