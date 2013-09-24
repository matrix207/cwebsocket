#ifndef SEM_H
#define SEM_H

int init_sem(int count);
int free_sem(int semid);
int set_sem(int semid, int index, int value);
int lock_sem(int semid, int index);
int unlock_sem(int semid, int index);

#endif /* SEM_H */
