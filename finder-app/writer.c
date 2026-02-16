#include "stdio.h"
#include <syslog.h>

int main(int argc, char *argv[]) {
    // Get two arguments writefile and writestr from the command line
    if (argc != 3) {
        printf("Usage: %s <writefile> <writestr>\n", argv[0]);
        syslog(LOG_USER | LOG_ERR, "Invalid arguments");
        return 1;
    }
    char *writefile = argv[1];
    char *writestr = argv[2];

    // Open the file for writing
    FILE *fp = fopen(writefile, "w");
    if (fp == NULL) {
        perror("Error opening file");
        syslog(LOG_USER | LOG_ERR, "Error opening file %s", writefile);
        return 1;
    }

    fprintf(fp, "%s\n", writestr);
    syslog(LOG_USER | LOG_DEBUG, "Writing %s to %s", writestr, writefile);
    fclose(fp);
    return 0;
}