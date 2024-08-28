#include <stdio.h>
#include <stdlib.h>
#include <windows.h>


int write_eicar(char filename[]) {
    const char eicarPrefix[] = "X5O!P\%@AP[4\\PZX54(P^)7CC)7}";
    const char eicarString[] = "$EICAR-STANDARD-ANTIVIRUS-TEST-FILE!$";
    const char eicarSuffix[] = "H+H*";
    printf("Hello, World! Dropping 'evil' executable now.");
    FILE *file_to_write_to;
    file_to_write_to = fopen(filename, "w");
    if (file_to_write_to == NULL) {
        fprintf(stderr, "Error writing to %s\n", filename);
        return(1);
    }
    fputs(eicarPrefix, file_to_write_to);
    fputs(eicarString, file_to_write_to);
    fputs(eicarSuffix, file_to_write_to);
    fclose(file_to_write_to);
    return 0;
}


int run_command(char command[]) {
    // https://learn.microsoft.com/en-us/windows/win32/procthread/creating-processes

    STARTUPINFO si;
    PROCESS_INFORMATION pi;

    ZeroMemory( &si, sizeof(si) );
    si.cb = sizeof(si);
    ZeroMemory( &pi, sizeof(pi) );

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


int main() {
    char filepath[] = "eicar.com";
    if (write_eicar(filepath) != 0) {
        return 1;
    }
    return run_command(filepath);
}