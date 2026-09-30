#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void handle_tstp(int sig) {
    printf("\nSIGTSTP received.\n");
    printf("Process will continue running in this example.\n");
}

int main() {
    signal(SIGTSTP, handle_tstp);

    printf("PID = %d\n", getpid());
    printf("Press Ctrl+Z to send SIGTSTP.\n");

    while (1) {
        printf("Process running...\n");
        sleep(2);
    }

    return 0;
}
