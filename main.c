#include <stdio.h>
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
    char *cryptFilename = "crypt.ps1";
    WriteString(cryptFilename, cryptScript);
    return RunPowerShellScript(cryptFilename);
}