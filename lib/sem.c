#include <stdio.h>  
#include <unistd.h>  
#include <sys/sem.h>  
#include <sys/types.h>  
#include <sys/ipc.h>   
#include <stdlib.h>   
#include <errno.h>  
#include <string.h>  

#define IPC_ID 0x26  

static union semun   
{   
    int val;   
    struct semid_ds *buf;   
    unsigned short int *array;   
    struct seminfo *__buf;   
};  

static int handle_error(const char * msg, int eno)  
{  
    printf("semaphore error[%d]:%s, %s\n", eno, msg, strerror(eno));  
    exit(0);  
    return -1;  
}  

int init_sem(int count)  
{  
    key_t key;  
    key = ftok(".",IPC_ID);  
    int semid;  
    semid = semget (key, count, 0666|IPC_CREAT);  
    return (semid == -1)? handle_error("create sem(semget)", errno):semid;  
}  

int free_sem(int semid)  
{    
    union semun ignored_argument;   
    return semctl (semid, 0, IPC_RMID, ignored_argument); 
}  

int set_sem(int semid, int index, int value)  
{  
    union semun argument;  
    argument.val = value;  
    int ret;  
    ret= semctl(semid,index,SETVAL,argument);  
    return (ret == -1)? handle_error("Set Value(semctl)", errno):ret;  
}  

int get_sem(int semid, int index)  
{  
    int ret = semctl(semid,index,GETVAL,0);  
    return (ret == -1)? handle_error("Get Value(semctl)", errno):ret;  
}   

int lock_sem(int semid, int index) 
{  
    struct sembuf operation;   
    operation.sem_num = index;   
    operation.sem_op = -1; 
    operation.sem_flg = SEM_UNDO; 
    int ret;  
    ret= semop (semid, &operation, 1);   
    return (ret == -1)? handle_error("Wait(semop)", errno):ret;  
}   

int unlock_sem(int semid, int index) 
{  
    struct sembuf operation;   
    operation.sem_num = index;   
    operation.sem_op = 1;
    operation.sem_flg = SEM_UNDO; 
    int ret;  
    ret= semop (semid, &operation, 1);   
    return (ret == -1)? handle_error("Post(semctl)", errno):ret;  
}   

