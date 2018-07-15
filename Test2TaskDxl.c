/*
    Copyright (C) 2018 ER2C
    Politektik Elektronika Negeri Surabaya
    Agung Pambudi <agung.pambudi5595@gmail.com>
*/

///////////////////////////////////////////////////////////////////////////////
//  Includes
///////////////////////////////////////////////////////////////////////////////
#include "flowrtos.h"
#include "dxl.h"

////////////////////////////////////////////////////////////////////////////////
// Code
////////////////////////////////////////////////////////////////////////////////
void task1(){
    PRINTF("\n\r");
    PRINTF("Task 1 ( periode deadline 1s ) - start %uus\n\r", count_time_us);

    PRINTF("Run dxl ID 10\n\r");
    SetDxl(10,0);
    delay_us(500000);
    SetDxl(10,1023);

    PRINTF("Task 1 ( periode deadline 1s ) - end %uus\n\r", count_time_us);
}

void task2(){
    PRINTF("\n\r");
    PRINTF("Task 2 ( periode deadline 2s ) - start %uus\n\r", count_time_us);

    PRINTF("Run dxl ID 1\n\r");
    SetDxl(1,0);
    delay_us(500000);
    SetDxl(1,1023);

    PRINTF("Task 2 ( periode deadline 2s ) - end %uus\n\r", count_time_us);
}

int main(void){
    hardware_init();
    dxl_uart_init();
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
uart 5 57600 dxl
*/
/*******************************************************************************
 * EOF
 ******************************************************************************/
