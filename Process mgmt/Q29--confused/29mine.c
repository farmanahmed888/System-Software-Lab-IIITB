/*
============================================================================
Name : 29.c
Author : Farman Ahmed
Description : Write a program to get scheduling policy and modify the scheduling policy (SCHED_FIFO, SCHED_RR).
Date: 10th September, 2023.
============================================================================
*/
#include <bits/types/struct_sched_param.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sched.h>
int main(){
    pid_t pid;
    pid=getpid();
    int current_policy=sched_getscheduler(pid);
    printf("current running policy is:--");
    switch (current_policy) {
        case SCHED_FIFO:
            printf("SCHED_FIFO\n");
            break;
        case SCHED_RR:
            printf("SCHED_RR\n");
            break;
        case SCHED_OTHER:
            printf("SCHED_OTHER\n");
            break;
        default:
            printf("Unknown\n");
            break;
    }
    printf("Now modifying scheduling policy. \n");
    struct sched_param param;
    param.sched_priority = -10;
    int changed_policy=sched_setscheduler(pid,SCHED_FIFO,&param);
    if(changed_policy==-1) printf("changing scheduling policy failed.\n");
    else{
        printf("After modification Scheduled Policy is :--\n");
        int get_policy=sched_getscheduler(pid);
        switch (get_policy) {
            case SCHED_FIFO:
                printf("SCHED_FIFO\n");
                break;
            case SCHED_RR:
                printf("SCHED_RR\n");
                break;
            case SCHED_OTHER:
                printf("SCHED_OTHER\n");
                break;
            default:
                printf("Unknown\n");
                break;
        }
    } 
}