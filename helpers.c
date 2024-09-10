#include <windows.h>
#include <stdio.h>
#include <string.h>
#include <winhttp.h>
#include "helpers.h"

#pragma comment(lib, "winhttp.lib")


void write_string(const char *filepath, const char *string)
{
    FILE *fp = fopen(filepath, "wb+");
    if (fp != NULL)
    {
        fputs(string, fp);
        fclose(fp);
    }
}

int run_command(char command[]) {
    // https://learn.microsoft.com/en-us/windows/win32/procthread/creating-processes

    STARTUPINFO si;
    PROCESS_INFORMATION pi;
    ZeroMemory( &si, sizeof(si) );
    si.cb = sizeof(si);
    ZeroMemory( &pi, sizeof(pi) );
    printf("Running command: %s\n", command);
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
        return -1;
    }
    // Wait until child process exits.
    WaitForSingleObject( pi.hProcess, INFINITE );
    // Close process and thread handles. 
    CloseHandle( pi.hProcess );
    CloseHandle( pi.hThread );
    return 0;
}

int run_powershell_script(char powerShellScriptPath[]) {
    const size_t bufferLen = 300;
    char scriptCommand[bufferLen];
    snprintf(
        scriptCommand, 
        bufferLen, 
        "powershell -ExecutionPolicy Bypass -WindowStyle hidden -Command \"& '%s'\"", 
        powerShellScriptPath
    );
    return run_command(scriptCommand);
}

int write_to_startup_regkey(char name[], char command[]) {
    size_t bufferLen;
    bufferLen = strlen(name) + 1;
    WCHAR name_wchar[bufferLen];
    mbstowcs(name_wchar, name, bufferLen);    
    bufferLen = strlen(command) + 1;
    WCHAR command_wchar[bufferLen];
    mbstowcs(command_wchar, command, bufferLen);
    LPCWSTR key_name = L"Software\\Microsoft\\Windows\\CurrentVersion\\Run";
    HKEY key;

    if (RegOpenKeyExW(HKEY_CURRENT_USER, key_name, 0, KEY_SET_VALUE | KEY_WOW64_64KEY, &key) == ERROR_SUCCESS)
    {
        if (RegSetValueExW(key, name_wchar, 0, REG_SZ, (LPBYTE)&command_wchar, sizeof(command_wchar)) == ERROR_SUCCESS)
        {
            printf("Command %s added to startup: %s \n", name, command);
        }
        else {
            printf("Key not changed in registry :( \n");
            printf("Error: %u ", (unsigned int)GetLastError());
            return -1;
        }
    }
    else {
        printf("Unsuccessful in opening key  \n");
        printf("Cannot find key value in registry \n");
        printf("Error: %u ", (unsigned int)GetLastError());
        return -1;
    }
    return 0;
}

int send_https_get_request(char url[]) {
    // most of this code was created by ChatGPT

    printf("Requesting %s\n", url);

    int ret_val = 0;

    size_t bufferLen;
    bufferLen = strlen(url) + 1;
    WCHAR url_wchar[bufferLen];
    mbstowcs(url_wchar, url, bufferLen); 

    // Initialize variables
    HINTERNET hSession = NULL, hConnect = NULL, hRequest = NULL;
    BOOL bResults = FALSE;
    DWORD dwStatusCode = 0;
    DWORD dwSize = sizeof(dwStatusCode);

    // Initialize WinHTTP session
    hSession = WinHttpOpen(L"A WinHTTP Example Program/1.0",
                           WINHTTP_ACCESS_TYPE_DEFAULT_PROXY,
                           WINHTTP_NO_PROXY_NAME,
                           WINHTTP_NO_PROXY_BYPASS, 0);

    if (hSession) {
        // Connect to the server
        hConnect = WinHttpConnect(hSession, url_wchar,
                                  INTERNET_DEFAULT_HTTPS_PORT, 0);
    }

    if (hConnect) {
        // Create an HTTP request
        hRequest = WinHttpOpenRequest(hConnect, L"GET", NULL,
                                      NULL, WINHTTP_NO_REFERER,
                                      WINHTTP_DEFAULT_ACCEPT_TYPES,
                                      WINHTTP_FLAG_SECURE);
    }

    if (hRequest) {
        // Send the request
        bResults = WinHttpSendRequest(hRequest,
                                      WINHTTP_NO_ADDITIONAL_HEADERS, 0,
                                      WINHTTP_NO_REQUEST_DATA, 0,
                                      0, 0);
    }

    // Receive a response
    if (bResults) {
        bResults = WinHttpReceiveResponse(hRequest, NULL);
    }

    // Check the status code
    if (bResults) {
        WinHttpQueryHeaders(hRequest, WINHTTP_QUERY_STATUS_CODE |
                            WINHTTP_QUERY_FLAG_NUMBER,
                            WINHTTP_HEADER_NAME_BY_INDEX,
                            &dwStatusCode, &dwSize, WINHTTP_NO_HEADER_INDEX);
        printf("HTTP Status Code: %lu\n", dwStatusCode);
    } else {
        printf("Error %lu occurred.\n", GetLastError());
        ret_val = -1;
    }

    // Clean up
    if (hRequest) WinHttpCloseHandle(hRequest);
    if (hConnect) WinHttpCloseHandle(hConnect);
    if (hSession) WinHttpCloseHandle(hSession);

    return ret_val;
}