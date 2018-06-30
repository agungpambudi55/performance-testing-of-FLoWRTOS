/*
    Copyright (C) 2018 ER2C
    Politektik Elektronika Negeri Surabaya
    Agung Pambudi <agung.pambudi5595@gmail.com>
*/

/*
debug       | uart 2 | baudrate 115200 
dxl ax-18a  | uart 5 | TX baudrate 57600 | dxl baudrate 57142
imu gy-521  | uart 5 | RX baudrate 57600 
*/

///////////////////////////////////////////////////////////////////////////////
//  Includes
///////////////////////////////////////////////////////////////////////////////
#include "flowrtos.h"

////////////////////////////////////////////////////////////////////////////////
// Code
////////////////////////////////////////////////////////////////////////////////
// fungsi konversi float2string
void print_f2s(float data, int mantissa){
    float f;
    char str[30];
    int a, b, c, k, l = 0, m, i=0;
    f = data;

    // check for negetive float
    if(f<0.0){
        str[i++] = '-';
        f *= -1;
    }
    if(data > -1 && data < 1)
    { str[i++] = '0'; };

    a=f;    // extracting whole number
    f-=a;   // extracting decimal part
    k = mantissa;
    
    // number of digits in whole number
    while(k>-1){
        l = pow(10,k);
        m = a/l;
        if(m>0) { break; } 
        k--;
    }

    // number of digits in whole number are k+1
    for(l=k+1;l>0;l--){
        b = pow(10,l-1);
        c = a/b;
        str[i++]=c+48;
        a%=b;
    }
    str[i++] = '.';
    
    /* extracting decimal digits till mantissa */
    for(l=0;l<mantissa;l++){
        f*=10.0;
        b = f;
        str[i++]=b+48;
        f-=b;
    }
    str[i]='\0';
    PRINTF("%s",str);
}

int main(void){
    // bool flag = false;
    management_io();
    management_timer_init();
    while (true){
        // update_data_imu();
        // PRINTF("pitch = "); print_f2s(imu->pitch,2);
        // PRINTF("\troll = "); print_f2s(imu->roll,2);
        // PRINTF("\tyaw = "); print_f2s(imu->yaw,2);
        // PRINTF("\n\r");

        // if(flag == true){ SetDxl(1, 1023); flag = false; }
        // else { SetDxl(1, 0); flag = true; }

        // delay_us(500000);
        SetDxl(1, 0);
        delay_us(1000000);
        SetDxl(1, 200);
        delay_us(1000000);
        SetDxl(1, 400);
        delay_us(1000000);
        SetDxl(1, 600);
        delay_us(1000000);
        SetDxl(1, 800);
        delay_us(1000000);
        SetDxl(1, 1023);
        delay_us(1000000);
        SetDxl(1, 800);
        delay_us(1000000);
        SetDxl(1, 600);
        delay_us(1000000);
        SetDxl(1, 400);
        delay_us(1000000);
        SetDxl(1, 200);
        delay_us(1000000);
    };
}

/*******************************************************************************
 * EOF
 ******************************************************************************/
