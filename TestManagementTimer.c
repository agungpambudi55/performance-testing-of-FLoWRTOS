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
void main(void){
    hardware_init();
    management_timer_init();
    while(true);
}

// void main(void){
//     uint32_t interval, td, t1, t2, t;
//     interval = 100000;
//     td = interval;

//     hardware_init();
//     management_timer_init();

//     while (td <= (interval*100)){
//         t1=count_time_us;    
//         delay_us(td);
//         t2=count_time_us;
//         t = (t2 - t1) - td;

//         PRINTF("%u %u\n\r", td/1000, t);    
//         // PRINTF("\n\rDelay %u us\n\r", td);
//         // PRINTF("Start delay %u us\n\r", t1);    
//         // PRINTF("Stop delay %u us\n\r", t2);    
//         // PRINTF("Time missed %u us\n\r", t);    

//         t = 0;
//         td += interval;
//     }
// }

/*******************************************************************************
 * EOF
 ******************************************************************************/
