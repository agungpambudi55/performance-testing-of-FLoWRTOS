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
    PRINTF("\n\r");
    PRINTF("Task 1 ( periode deadline 1s ) - start %uus\n\r", count_time_us);
    PRINTF("Delay 500ms\n\r");
    delay_us(500000);
    PRINTF("Task 1 ( periode deadline 1s ) - end %uus\n\r", count_time_us);
}

void task2(){
    PRINTF("\n\r");
    PRINTF("Task 2 ( periode deadline 2s ) - start %uus\n\r", count_time_us);
    PRINTF("Delay 1s\n\r");
    delay_us(1000000);
    PRINTF("Task 2 ( periode deadline 2s ) - end %uus\n\r", count_time_us);
}

int main(void){
    hardware_init();
    management_timer_init();
    management_memory_init();    
    management_task_init();
    create_task(task1,1000000,2000000,0);
    create_task(task2,2000000,2000000,0);
    while (true){
        scheduler_context_switch();
    };
}

/*
uart 2 115200 debug
*/

/*******************************************************************************
 * EOF
 ******************************************************************************/