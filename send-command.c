#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

const char* send_command(char *command, char *response) {

    struct sockaddr_in local_addr;
    struct sockaddr_in tello_addr;

    local_addr.sin_family = AF_INET;
    local_addr.sin_port = htons(8889); // htons converts the unsigned short integer to network byte order.
    local_addr.sin_addr.s_addr = INADDR_ANY; // assigns a free ip to local address

    tello_addr.sin_family = AF_INET;
    tello_addr.sin_port = htons(8889);
    tello_addr.sin_addr.s_addr = inet_addr("192.168.10.1");

    socklen_t tello_addr_len;
    tello_addr_len = sizeof(tello_addr);

    int sock = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    bind(sock, (struct sockaddr*)&local_addr, sizeof(local_addr));

    sendto(sock, command, sizeof(command), 0, (struct sockaddr*) &tello_addr, sizeof(local_addr));
    int n = recvfrom(sock, (char*)response, sizeof(response), 0, (struct sockaddr*) &tello_addr, &tello_addr_len);
    int c = close(sock);

    response[n] = '\0'; // add terminator to end of response
    response[strcspn(response, "\n")] = 0; // strips extra newlines from end of response

    return response;
}
