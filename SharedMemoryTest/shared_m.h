#define SHM_INFO_COUNT 30

// https://doitnow-man.tistory.com/68 참고.

typedef struct _shm_info
{

    char str_ip[50];
    unsigned int int_ip;
    unsigned int int_id;

} SHM_INFOS; //SHM_INFOS 라는 구조체 별칭으로 쉽게 struct 생성가능.