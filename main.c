#include <stdio.h>
#include <stdlib.h>


int write_eicar(char filename[]) {
    const char eicarPrefix[] = "X5O!P\%@AP[4\\PZX54(P^)7CC)7}";
    const char eicarString[] = "$EICAR-STANDARD-ANTIVIRUS-TEST-FILE!$";
    const char eicarSuffix[] = "H+H*";
    printf("Hello, World! Dropping 'evil' executable now.");
    FILE *file_to_write_to;
    file_to_write_to = fopen(filename, "w");
    if (file_to_write_to == NULL) {
        fprintf(stderr, "Error writing to %s\n", filename);
        return(1);
    }
    fputs(eicarPrefix, file_to_write_to);
    fputs(eicarString, file_to_write_to);
    fputs(eicarSuffix, file_to_write_to);
    fclose(file_to_write_to);
    return 0;
}


int main() {
    char filepath[] = "eicar.com";
    if (write_eicar(filepath) != 0) {
        return 1;
    }
    system(filepath);
    return 0;
}