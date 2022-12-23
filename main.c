#include <stdio.h>
#include <stdlib.h>
#include "send-command.h"
#include "connect.h"

int main(void){
    int connected = 1;
    connected = connect("tello");
    for(;;) {
        // Initial memory allocation
        char *cmd;
        char *res;
        cmd = (char *) malloc(sizeof(char)*50);
        res = (char *) malloc(sizeof(char)*50);

        // get input
        printf("Enter command: ");
        gets(cmd);

        // send command and print response
        printf("responded: %s\n", send_command(cmd, res));

        free(cmd);
        free(res);
    }
    disconnect();
    return 0;
}
