/*
    Copyright (C) 2018 ER2C
    Politektik Elektronika Negeri Surabaya
    Agung Pambudi <agung.pambudi5595@gmail.com>
*/

///////////////////////////////////////////////////////////////////////////////
//  Includes
///////////////////////////////////////////////////////////////////////////////
#include "flowrtos.h"

////////////////////////////////////////////////////////////////////////////////
// Code
////////////////////////////////////////////////////////////////////////////////
uint32_t dt1 = 400000, dt2 = 500000, dt3 = 700000, t1 = 0, t2 = 0, t3 = 0;

void task1(){
    PRINTF("Task 1 | p = d = 400 ms | c = 100 ms | %u us = start\n\r", count_time_us);
    delay_us(100000);
    t1++;
    dt1 = dt1 * t1;
    PRINTF("Task 1 | p = d = 400 ms | c = 100 ms | %u us = finish | d = %u\n\r", count_time_us, dt1);
}

void task2(){
    PRINTF("Task 2 | p = d = 500 ms | c = 200 ms | %u us = start\n\r", count_time_us);
    delay_us(200000);
    t2++;
    dt2 = dt2 * t2;
    PRINTF("Task 2 | p = d = 500 ms | c = 200 ms | %u us = finish| d = %u\n\r", count_time_us, dt2);
}

void task3(){
    PRINTF("Task 3 | p = d = 700 ms | c = 200 ms | %u us = start\n\r", count_time_us);
    delay_us(200000);
    t3++;
    dt3 = dt3 * t3;
    PRINTF("Task 3 | p = d = 700 ms | c = 200 ms | %u us = finish| d = %u\n\r", count_time_us, dt3);
}

int main(void){
    management_io();
    management_timer_init();
    management_memory_init();    
    management_task_init();
    create_task(task1,400000,400000,0);
    create_task(task2,500000,500000,0);
    create_task(task3,700000,700000,0);
    dxl_uart_init();
    PRINTF("BISMILLAH\n\r");
    scheduler();
    while(true);
}

/*
uart 2 115200 debug
uart 5 57600 dxl
*/
/*******************************************************************************
 * EOF
 ******************************************************************************/
