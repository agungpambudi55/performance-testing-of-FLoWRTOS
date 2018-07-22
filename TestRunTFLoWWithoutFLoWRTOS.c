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
void main(void){
    management_io();
    management_timer_init();
    while(true){
    	get_euler_angles();
    	kinematic_control(0, 0, 0, true);
		set_position();
    	delay_us(50000);
    }

    while (false){
	   	PRINTF("0 0 0\n\r");
		kinematic_control(0,0,0);
		delay_us(1000000);

		PRINTF("25 0 0\n\r");
		kinematic_control(25,0,0);
		delay_us(1000000);

		PRINTF("0 0 0\n\r");
		kinematic_control(0,0,0);
		delay_us(1000000);

		PRINTF("-25 0 0\n\r");
		kinematic_control(-25,0,0);
		delay_us(1000000);

		PRINTF("0 0 0\n\r");
		kinematic_control(0,0,0);
		delay_us(1000000);

		PRINTF("0 25 0\n\r");
		kinematic_control(0,25,0);
		delay_us(1000000);

		PRINTF("0 0 0\n\r");
		kinematic_control(0,0,0);
		delay_us(1000000);

		PRINTF("0 -25 0\n\r");
		kinematic_control(0,-25,0);
		delay_us(1000000);

		PRINTF("0 0 0\n\r");
		kinematic_control(0,0,0);
		delay_us(1000000);

		PRINTF("0 0 25\n\r");
		kinematic_control(0,0,25);
		delay_us(1000000);

		PRINTF("0 0 0\n\r");
		kinematic_control(0,0,0);
		delay_us(1000000);

		PRINTF("0 0 -25\n\r");
		kinematic_control(0,0,-25);
		delay_us(1000000);

		PRINTF("0 0 0\n\r");
		kinematic_control(0,0,0);
		delay_us(1000000);

		PRINTF("15 15 0\n\r");
		kinematic_control(15,15,0);
		delay_us(1000000);

		PRINTF("0 0 0\n\r");
		kinematic_control(0,0,0);
		delay_us(1000000);

		PRINTF("15 -15 0\n\r");
		kinematic_control(15,-15,0);
		delay_us(1000000);

		PRINTF("0 0 0\n\r");
		kinematic_control(0,0,0);
		delay_us(1000000);

		PRINTF("-15 -15 0\n\r");
		kinematic_control(-15,-15,0);
		delay_us(1000000);

		PRINTF("0 0 0\n\r");
		kinematic_control(0,0,0);
		delay_us(1000000);

		PRINTF("-15 15 0\n\r");
		kinematic_control(-15,15,0);
		delay_us(1000000);
	}
}

/*******************************************************************************
 * EOF
 ******************************************************************************/
