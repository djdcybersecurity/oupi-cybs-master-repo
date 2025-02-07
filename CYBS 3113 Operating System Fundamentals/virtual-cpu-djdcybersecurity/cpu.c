#define _GNU_SOURCE
#include <sched.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <assert.h>
#include <unistd.h>

// Spin function that delays for a specified number of seconds
void Spin(int seconds) {
    sleep(seconds);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "usage: cpu <string>\n");
        exit(1);
    }
    
    char *str = argv[1];
    while (1) {
        Spin(1);
        // Print the process details including PID and CPU core
        printf("%s, [PID %d] Running on CPU %d\n", str, getpid(), sched_getcpu());
        fflush(stdout); // Ensure output is displayed immediately
    }
    return 0;
}
