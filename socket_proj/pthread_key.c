#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <memory.h>
#include <stdlib.h>

pthread_key_t pthread_key;

void destroy_key(void* arg) {
    printf("destroy key\n");
    free(arg);
    
}

typedef struct TSD {
    pthread_t tid;
    char* str;
} tsd_t;

void* thread_routine(void* arg) {
    tsd_t* pdata = (tsd_t*)malloc(sizeof(tsd_t));
    pdata->tid = pthread_self();
    pdata->str = (char*) arg;
    printf("tsd data is: 0x%x, %s\n", (int)pdata->tid, pdata->str);

    pthread_setspecific(pthread_key, pdata);
    sleep(2);

    tsd_t* pget = pthread_getspecific(pthread_key);
    printf("get tsd data is: 0x%x, %s\n", (int)pget->tid, pget->str);


    return NULL;
}
int main(int argc, char const *argv[])
{
    /* code */
    pthread_key_create(&pthread_key, destroy_key);
    pthread_t thread1;
    pthread_t thread2;
    pthread_create(&thread1, NULL, thread_routine, "thread1");

    pthread_create(&thread2, NULL, thread_routine, "thread2");

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    pthread_key_delete(pthread_key);
    printf("end of main\n");
    return 0;
}
