#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

long counter = 0;

void custom(int signal) {
    long offby = abs(1000000000 - counter);
    printf("\nYou stopped at: %lu\n", counter);
    printf("You were off by %lu\n", offby);
    exit(0);
}

int main() {
    (void) signal(SIGINT, custom);
    printf("Try to hit 1 Billion!\n");
    while (1) {
        counter += 1;
    }
    return 0;
}