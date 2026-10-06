#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    printf("hello world (pid:%d)\n", getpid());
    int rc = fork();
    if (rc < 0) { // fail
       fprintf(stderr, "fork failed\n");
       exit(1);
    } else if (rc == 0) { // child
       printf("hello, I am child (pid:%d)\n", getpid());
    } else { // parent
       printf("hello, I am parent of %d (pid:%d)\n", rc, getpid());
    }
    while(1); // para di mamatay
    return 0;
}