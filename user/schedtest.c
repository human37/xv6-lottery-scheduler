#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"


int
main(void) {

    #ifdef RANDOM
        printf("\nthe RANDOM scheduler is being used:\n\n");

        #ifdef RANDOMTICKETTRUE
            printf("random ticket numbers are being assigned.\n\n");
        #else
        #endif
    #else
    #endif

    int tempvar1, tempvar2;
    char c = '.';
    int pid;

    pid = fork();
    if (pid == 0) {
        c = '@';
        pid = fork();
        if (pid == 0) {
            c = '*';
            pid = fork();
            if (pid == 0) {
                c = '_';
                pid = fork();
                if (pid == 0) {
                    c = '#';
                }
            }
        }
    }

    for (int i = 0; i < 100; i++) {
        tempvar1 = i;
        tempvar2 = i;
        for (int j = 0; j < 10000000; j++) {
            tempvar1 += 1;
            tempvar2 += 1;
            if (j % 10000 == 0) {
                tempvar1 /= tempvar2;
                tempvar2 %= 25;
            }
        }
        printf("%c ", c);
    }

    if (tempvar2 > tempvar1) {
        exit(0);
    }
    wait(0);
    exit(0);
    return 0;
}
