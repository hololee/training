//https://doitnow-man.tistory.com/110
/*
단방향 통신.
구조체 단위 통신,

*/

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/stat.h>

struct message_buff1
{
    long msgtype;
    char mytext[256];
    char myname[16];
    int seq;
};

int main()
{

    int count = 0;

    key_t key_id;
    struct message_buff1 msg1;

    key_id = msgget((key_t)1031, IPC_CREAT | 0666); //IPC_CREAT : 메시지큐가 없으면 새로 생성.
    printf("Key id is %d\n", key_id);

    //seq
    msg1.seq = count;

    while (1)
    {
        // 지속해서 메시지 보내기.

        //전송 횟수 체크.
        count++;

        // 첫번째 매게변수의 주소 위치에 메모리 크기 세팅.
        memset(&msg1, 0, sizeof(struct message_buff1));

        //type 0보다 크기만 하면 ok.
        msg1.msgtype = 1;

        // 메세지 추가.
        snprintf(msg1.myname, sizeof(msg1.myname), "hololee");
        snprintf(msg1.mytext, sizeof(msg1.mytext), "Message number is :  %d", count);

        //메시지 전송.
        msgsnd(key_id, (void *)&msg1, sizeof(struct message_buff1), IPC_NOWAIT); // msgflg 참조 . https://www.it-note.kr/98

        printf("send %dth Message.\n", count);
        sleep(1);
    }
    return 0;
}
