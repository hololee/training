#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#include "shared_m.h"

int main()
{
    int count;
    int shmid;
    int i;
    SHM_INFOS *shm_info = NULL;
    void *shared_memory = (void *)0;

    // 공유 메모리 공간 생성.
    shmid = shmget((key_t)3333, sizeof(SHM_INFOS) * SHM_INFO_COUNT, 0666 | IPC_CREAT);

    // 공유메모리 process 연결.
    shared_memory = shmat(shmid, (void *)0, 0);

    //공유 메모리 쓰기.
    shm_info = (SHM_INFOS *)shared_memory;
    while (1)
    {

        count++;

        for (int i = 0; i < SHM_INFO_COUNT; i++)
        {
            snprintf(shm_info[i].str_ip, sizeof(shm_info[i].str_ip), "%d", 10 + i);
            shm_info[i].int_ip = 1000 + i;
            shm_info[i].int_id = 100 + i;

            printf("shm_info %dth writed..%d\n", count, i);
        }

        sleep(3);
    }

    return 0;
}