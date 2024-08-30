#include <stdio.h>
#include <stdlib.h>

int main() {
    char *desktopPath = getenv("UserProfile");
    printf("Desktop path: %s\\Desktop", desktopPath);
}