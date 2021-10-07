#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>
#include <unistd.h>

#include "shared_m.h"

//참조 https://reakwon.tistory.com/96.

int main()
{

    int count;
    int shm_id;
    SHM_INFOS *shm_info = NULL;

    void *shared_memory = (void *)0;

    //공유 메모리 공간 얻기.
    shm_id = shmget((key_t)3333, sizeof(SHM_INFOS) * SHM_INFO_COUNT, 0666 | IPC_CREAT);

    // 공유 메모리 공간에 현재 프로세스 묶기.
    shared_memory = shmat(shm_id, (void *)0, 0666 | IPC_CREAT);

    shm_info = (SHM_INFOS *)shared_memory;

    while (1)
    {

        count++;

        for (int i = 0; i < SHM_INFO_COUNT; i++)
        {
            printf("Number : %d - %d\n", count, i);
            printf("shared_info str ip : %s\n", shm_info[i].str_ip);
            printf("shared_info int ip  : %d\n", shm_info[i].int_ip);
            printf("shared_info int id : %d\n", shm_info[i].int_id);
            printf("-----------------------------------\n");
        }

        sleep(1);
    }

    return 0;
}