#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

void* thread_routine(void* t) {
    int i;
    for (i = 0 ; i < 20; ++i) {
        if (i == 3) {
            pthread_exit("call pthreead exit");
            //return "ttttt";
        }
        printf("B");
        fflush(stdout);
        usleep(20);
    }
    return NULL;
}

int main(int argc, char const *argv[])
{
    pthread_t tid;
    int ret;
    if ((ret = pthread_create(&tid, NULL, thread_routine, NULL)) != 0) {
        fprintf(stderr, "pthread_create: %s\n", strerror(ret));
        exit(EXIT_FAILURE);
    }
    int i;
    for (i = 0; i < 20; ++i) {
        printf("A");
        fflush(stdout);
        usleep(20);
    }
    void* value;
    if ((ret = pthread_join(tid, &value)) != 0) {
        printf("error\n");
        fprintf(stderr, "pthread_join:%s\n", strerror(ret));
        exit(EXIT_FAILURE);
    }
    printf("return value: %s\n", (char*)value);
    return 0;
}
