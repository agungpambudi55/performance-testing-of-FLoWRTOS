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
	// time_start_task = count_time_us;
	get_euler_angles();
	// time_finish_task = count_time_us;
	// PRINTF("\n\rIMU = %u us\n\r", (time_finish_task - time_start_task));
}

void task2(){	// -+ 42 us
	// time_start_task = count_time_us;
	kinematic_control(0, 0, 0, true);
	// time_finish_task = count_time_us;
	// PRINTF("\n\rIK_C = %u us\n\r", (time_finish_task - time_start_task));
}

void task3(){	// -+ 5146 us
	// time_start_task = count_time_us;
	set_position();
	// time_finish_task = count_time_us;
	// PRINTF("\n\rDXL = %u us\n\r", (time_finish_task - time_start_task));
}

void main(void){
    management_io();
    management_memory_init();
    management_timer_init();
    management_task_init();
    create_task("Task_1", task1, 1000);
    create_task("Task_2", task2, 2000);
    create_task("Task_3", task3, 7000);
    learning(1000000);
    scheduler();
    while(true);
}

/*******************************************************************************
 * EOF
 ******************************************************************************/
