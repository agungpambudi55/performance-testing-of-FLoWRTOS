/*
    Copyright (C) 2018 ER2C
    Politektik Elektronika Negeri Surabaya
    Agung Pambudi <agung.pambudi5595@gmail.com>
*/

#ifndef KINEMATICCONTROL_H
#define KINEMATICCONTROL_H

#ifdef __cplusplus
extern "C" {
#endif

#include "flowrtos.h"

// dynamixel yaw
#define ID_a1 1
#define goal_position_min_a1    0    
#define goal_position_max_a1    1023 
#define goal_position_center_a1 511
#define angle_max_a1  300 
#define angle_min_a1  0   

// dynamixel roll
#define ID_a2 3
#define goal_position_min_a2    0    
#define goal_position_max_a2    1023 
#define goal_position_center_a2 500
#define angle_max_a2  300 
#define angle_min_a2  0   

// dynamixel pitch
#define ID_a3 2
#define goal_position_min_a3    0    
#define goal_position_max_a3    1023 
#define goal_position_center_a3 511
#define angle_max_a3  300 
#define angle_min_a3  0   

// PHI  180 / 3.14
#define PHI 57.324840764

// panjang joint 3 sampai end of effector (mm)
float L2 = 95.0;

// joint space / angle
float a1, a2, a3;

// posisi default
float X, Y, orientasi;

float alfa;
float res_WS, res;
float tempX, tempY;
float err_roll, err_pitch, err_yaw;
float Ki_roll, Ki_pitch, Ki_yaw;
int dxl_roll, dxl_pitch, dxl_yaw;

void kinematic_control(float X_ref, float Y_ref, float orientasi_ref, bool enable_control);

void set_position(void);

#ifdef __cplusplus
}
#endif
#endif
