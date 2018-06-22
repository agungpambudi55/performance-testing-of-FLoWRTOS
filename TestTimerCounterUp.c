/*
    Copyright (C) 2018 ER2C
    Politektik Elektronika Negeri Surabaya
    Agung Pambudi <agung.pambudi5595@gmail.com>
*/

/*******************************************************************************
 * NOTE
 * Hilangkan comment pada souce code file flowrtos_timer dibawah tulisan 
 * "mencetak hasil pembangkitan waktu"
 * if((count_time_us%1000000)==0)
 * { 
 *     PRINTF("%u us || %u ms || %u s || every 1 second\n\r", count_time_us, count_time_ms, count_time_ms/1000); 
 * }
 ******************************************************************************/

///////////////////////////////////////////////////////////////////////////////
//  Includes
///////////////////////////////////////////////////////////////////////////////
#include "flowrtos.h"

////////////////////////////////////////////////////////////////////////////////
// Code
////////////////////////////////////////////////////////////////////////////////

void main(void){
    management_io();
    management_timer_init();
    while(true);
}

/*******************************************************************************
 * EOF
 ******************************************************************************/
