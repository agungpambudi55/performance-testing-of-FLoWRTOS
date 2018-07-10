/*
    Copyright (C) 2018 ER2C
    Politektik Elektronika Negeri Surabaya
    Agung Pambudi <agung.pambudi5595@gmail.com>
*/

#include "KinematicControl.h"

void kinematic_control(float X_ref, float Y_ref, float orientasi_ref, bool enable_control){
	X = X_ref;
	Y = Y_ref;
	orientasi = orientasi_ref;

	a1 = orientasi;                 // joint angle 1 (yaw)

	// resultan untuk membatasi bidang kerja / workspace
	res_WS = sqrt((Y * Y) + (X * X));
	if(res_WS >= L2) res_WS = L2;

	alfa = (atan2(-Y,X) * PHI) + a1;
	tempY =  (res_WS * sin(alfa / PHI));
	tempX =  (res_WS * cos(alfa / PHI));

	a3 = asin(tempX / L2) * PHI;    // joint angle 3 (pitch)
	res = sin((90 - abs(a3)) / PHI) * L2;
	a2 = asin(tempY / res) * PHI;   // joint angle 2 (roll)

	if(enable_control == false){
		// nilai untuk set konversi dxl tanpa kontrol
		dxl_yaw = (int)(goal_position_center_a1 + (int)((a1 * goal_position_max_a1) / angle_max_a1));
		dxl_roll = (int)(goal_position_center_a2 + (int)((a2 * goal_position_max_a2) / angle_max_a2));
		dxl_pitch = (int)(goal_position_center_a3 - (int)((a3 * goal_position_max_a3) / angle_max_a3));
	}else if(enable_control == true){
		// kontrol I
		err_roll = (imu->roll - a2) / 20;
		err_pitch = (imu->pitch - a3) / 20;

		Ki_roll += (float)(((err_roll) * goal_position_max_a2) / angle_max_a2);
		Ki_pitch += (float)(((err_pitch) * goal_position_max_a3) / angle_max_a3);  

		// nilai untuk set konversi dxl dengan kontrol
		dxl_yaw = (int)(goal_position_center_a1 + (int)((a1 * goal_position_max_a1) / angle_max_a1));
		dxl_roll = (int)(goal_position_center_a2 + (int)((a2 * goal_position_max_a2) / angle_max_a2)) + Ki_roll;
		dxl_pitch = (int)(goal_position_center_a3 - (int)((a3 * goal_position_max_a3) / angle_max_a3)) + Ki_pitch;
	}
}

void set_position(void){
	SetDxl(ID_a1, dxl_yaw, 1023);
	SetDxl(ID_a2, dxl_roll, 1023);
	SetDxl(ID_a3, dxl_pitch, 1023);
}