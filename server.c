#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void handle_signal(int sig, siginfo_t *info, void *context)
{
    static char c = 0;
    static int bit_count = 0;

    if (sig == SIGUSR1)
    {
        // printf("HERE\n");
        c |= (1 << bit_count);
    }
        
    bit_count++;
    
    
    if (bit_count == 8) {
        // printf("THERE\n");
        write(1, &c, 1);
        fflush(stdout);
        bit_count = 0;
        c = 0;
    }
    // Optionally, send acknowledgment to client
    // kill(info->si_pid, SIGUSR1);
}

int main(void)
{
    struct sigaction sa;
    sa.sa_flags = SA_SIGINFO;
    sa.sa_sigaction = handle_signal;
    sigemptyset(&sa.sa_mask);
    sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGUSR2, &sa, NULL);

    printf("Server PID: %d\n", getpid());

    // Keep the server running to handle incoming signals
    while (1) {
        pause();
    }

    return 0;
}
