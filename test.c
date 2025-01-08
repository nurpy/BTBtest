#define _GNU_SOURCE
#include <stdio.h>
#include <sched.h>
#include <unistd.h>

int main() {
    cpu_set_t set;
    CPU_ZERO(&set);
    CPU_SET(0, &set);  // Pin to CPU core 0

    // Set the CPU affinity for the current process
    if (sched_setaffinity(0, sizeof(cpu_set_t), &set) == -1) {
        perror("sched_setaffinity");
        return 1;
    }

    // Run Program 1
    printf("Running Program 1\n");
    system("~/CStuff/attacker");

    // Run Program 2 while still running on core 0
    printf("Running Program 2\n");
    system("~/CStuff/victim");

    return 0;
}

