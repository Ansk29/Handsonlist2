/*
============================================================================
Name : 7.c
Author : Anshul Kakirde
Description : . Write a simple program to print the created thread ids.
Date: , 2024.
============================================================================
*/


#include <stdio.h>
#include <pthread.h>

void *thread_function(void *arg) {
    printf("Thread ID: %lu\n", pthread_self());
    return NULL;
}

int main(void) {
    pthread_t threads[3];
    int i;

    for (i = 0; i < 3; i++) {
        if (pthread_create(&threads[i], NULL, thread_function, NULL) != 0) { // address kaha store karvaya thread function kya run hoga 
            perror("pthread_create");
            return 1;
        }
    }

    for (i = 0; i < 3; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}


/*
Thread ID: 140538271495872
Thread ID: 140538263103168
Thread ID: 140538254710464
*/
