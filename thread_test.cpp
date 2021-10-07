#include <pthread.h>

//thread 사용하기 위해선 컴파일시 "-lpthread" 옵션을 줘야 함.
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void *thread_routine(void *arg)
{
    pthread_t tid;

    tid = pthread_self();

    int i = 0;

    while (i < 10)
    {
        printf("%s, %d", (char *)arg, i);
        i++;
        sleep(1);
    }

    // void * 는 리턴이 없는 것 이 아닌  리턴을 정해줘야 함.
    void *result;
    return result;
}

int main()
{
    pthread_t thread;

    char thread_name[] = "thread_name";
    pthread_create(&thread, NULL, thread_routine, &thread_name);

    int i = 0;
    while (i < 5)
    {
        printf("main:%d\n", i);
        i++;
        sleep(1);
    }

    // 바로 종료하지 않고 앞서 실행한 thread 종료 까지 기다림.(main thread에 join 시킨다는 의미인듯...)
    pthread_join(thread, NULL);

    return 0;
}