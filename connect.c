#include <unistd.h>
#include <stdio.h>

int connect(char * ssid) {
    char *programName = "networksetup";
    char *arg1 = "-setairportnetwork";
    char *arg2 = "en0";

    int i = 1;
    do {
        i = execlp(programName, programName, arg1, arg2, ssid, NULL);
    }
    while (i == -1);
    printf("connected to %s", ssid);
    return 0;
}

void disconnect(void) {
    char *programName = "networksetup";
    char *arg1 = "-setairportpower";
    char *arg2 = "en0";
    char *on = "on";
    char *off = "off";

    int i = execlp(programName, programName, arg1, arg2, off, NULL);
    int n = execlp(programName, programName, arg1, arg2, on, NULL);
}
