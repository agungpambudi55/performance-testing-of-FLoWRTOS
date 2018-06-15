/*
    Copyright (C) 2018 ER2C
    Politektik Elektronika Negeri Surabaya
    Agung Pambudi <agung.pambudi5595@gmail.com>
*/

///////////////////////////////////////////////////////////////////////////////
//  Includes
///////////////////////////////////////////////////////////////////////////////
#include "flowrtos.h"
#include "KinematicControl.h"

////////////////////////////////////////////////////////////////////////////////
// Code
////////////////////////////////////////////////////////////////////////////////
uint32_t time_start_task, time_finish_task;

void task1(){	// -+ 44 us
	time_start_task = count_time_us;
	get_euler_angles();
	time_finish_task = count_time_us;
	PRINTF("\n\rIMU = %u us\n\r", (time_finish_task - time_start_task));
}

void main(void){
    management_io();
    management_memory_init();
    management_timer_init();
    management_task_init();
    create_task("Task_1", task1, 1000);
    learning(1000000);
    scheduler();
    while(true);
}
/*******************************************************************************
 * EOF
 ******************************************************************************/
