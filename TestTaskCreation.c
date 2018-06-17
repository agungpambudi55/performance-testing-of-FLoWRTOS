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
void task1(void){}
void task2(void){}
void task3(void){}
void task4(void){}
void task5(void){}
void task6(void){}
void task7(void){}
void task8(void){}
void task9(void){}
void task10(void){}

int main(void){
    hardware_init();
    management_memory_init();    
    management_timer_init();
    management_task_init();
    create_task(task1,1000000,1000000,0);
    create_task(task2,2000000,2000000,0);
    create_task(task3,3000000,3000000,0);
    create_task(task4,4000000,4000000,0);
    create_task(task5,5000000,5000000,0);
    create_task(task6,6000000,6000000,0);
    create_task(task7,7000000,7000000,0);
    create_task(task8,8000000,8000000,0);
    create_task(task9,9000000,9000000,0);
    create_task(task10,10000000,10000000,0);
    while (true);
}

/*******************************************************************************
 * EOF
 ******************************************************************************/
