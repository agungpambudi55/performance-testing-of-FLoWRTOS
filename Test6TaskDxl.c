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
void task1(){
    PRINTF("Task 1 | p = d = 900 ms | c = 200 ms | %u us = start\n\r", count_time_us);
    delay_us(200000);
    PRINTF("Task 1 | p = d = 900 ms | c = 200 ms | %u us = finish\n\r", count_time_us);
}

void task2(){
    PRINTF("Task 2 | p = d = 600 ms | c = 200 ms | %u us = start\n\r", count_time_us);
    delay_us(200000);
    PRINTF("Task 2 | p = d = 600 ms | c = 200 ms | %u us = finish\n\r", count_time_us);
}

void task3(){
    PRINTF("Task 3 | p = d = 800 ms | c = 100 ms | %u us = start\n\r", count_time_us);
    delay_us(100000);
    PRINTF("Task 3 | p = d = 800 ms | c = 100 ms | %u us = finish\n\r", count_time_us);
}

void task4(){
    PRINTF("Task 4 | p = d = 400 ms | c = 100 ms | %u us = start\n\r", count_time_us);
    delay_us(100000);
    PRINTF("Task 4 | p = d = 400 ms | c = 100 ms | %u us = finish\n\r", count_time_us);
}

void task5(){
    PRINTF("Task 5 | p = d = 500 ms | c = 100 ms | %u us = start\n\r", count_time_us);
    delay_us(100000);
    PRINTF("Task 5 | p = d = 500 ms | c = 100 ms | %u us = finish\n\r", count_time_us);
}

void task6(){
    PRINTF("Task 6 | p = d = 700 ms | c = 200 ms | %u us = start\n\r", count_time_us);
    delay_us(200000);
    PRINTF("Task 6 | p = d = 700 ms | c = 200 ms | %u us = finish\n\r", count_time_us);
}

int main(void){
    management_io();
    management_timer_init();
    management_memory_init();    
    management_task_init();
    create_task(task5,500000,500000,0);
    create_task(task2,600000,600000,0);
    create_task(task6,700000,700000,0);
    create_task(task4,400000,400000,0);
    create_task(task1,900000,900000,0);
    create_task(task3,800000,800000,0);
    dxl_uart_init();
    PRINTF("BISMILLAH PASTI BISA!\n\r");
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
