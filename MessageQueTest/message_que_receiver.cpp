#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/stat.h>

// 동일한 구조체 정의.
struct message_buff1
{
    long msgtype;
    char mytext[256];
    char myname[16];
    int seq;
};

int main(int argc, char **argv)
{

    key_t key_id;
    struct message_buff1 msg1;
    int msgtype = 1;

    printf("argc : %d\n", argc);

    // msg 가져오기.
    key_id = msgget(1031, IPC_CREAT | 0666);

    while (1)
    {
        //메시지를 가져오고 지운다,
        int is_received = msgrcv((key_t)key_id, (void *)&msg1, sizeof(struct message_buff1), msgtype, 0);

        if (is_received == -1)
        {
            printf("Message not detected.\n");
        }
        else
        {
            //메시지 출력.
            printf("Received Message from %s : %s\n", msg1.myname, msg1.mytext);
        }

        sleep(1);
    }

    return 0;
}