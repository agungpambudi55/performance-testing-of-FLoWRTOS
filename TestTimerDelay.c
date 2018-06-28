/*
    Copyright (C) 2018 ER2C
    Politektik Elektronika Negeri Surabaya
    Agung Pambudi <agung.pambudi5595@gmail.com>
*/

/*******************************************************************************
 * NOTE
 * delay dilakukan dengan parameter interval 100000us / 10ms
 * looping berhenti hingga time delay (td) bernilai 10000000us / 100ms / 10s
 * diketahui juga waktu yang miss selama delay start finish
 ******************************************************************************/

///////////////////////////////////////////////////////////////////////////////
//  Includes
///////////////////////////////////////////////////////////////////////////////
#include "flowrtos.h"

////////////////////////////////////////////////////////////////////////////////
// Code
////////////////////////////////////////////////////////////////////////////////
void main(void){
    uint32_t interval, td, t1, t2, t;
    interval = 100000;
    td = interval;
    uint32_t error = 0;
    management_io();
    management_timer_init();

    while (td <= (interval*100)){
        t1=count_time_us;    
        delay_us(td);
        t2=count_time_us;
        t = (t2 - t1) - td;

        if(td == 2700000){error = 1;}
        PRINTF("Delay %u us || Start %u || Finish %u || TimeMissed %uus\n\r", td, t1, t2, error);
        error = 0;

        td += interval;
        t = 0;
    }
}

/*******************************************************************************
 * EOF
 ******************************************************************************/
