#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void send_char(int pid, char c)
{
    for (int i = 0; i < 8; i++) {
        if (c & (1 << i))
            kill(pid, SIGUSR1);
        else
            kill(pid, SIGUSR2);
        usleep(100);  // Sleep to ensure the signal is received
    }
}

int main(int argc, char **argv)
{
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <PID> <message>\n", argv[0]);
        return 1;
    }

    int pid = atoi(argv[1]);
    char *message = argv[2];

    for (int i = 0; message[i] != '\0'; i++) {
        send_char(pid, message[i]);
    }

    // Optionally, send a null character to indicate end of message
    send_char(pid, '\0');

    return 0;
}
