/*
 * @Description: 
 * @Author: Chinwong_Leung
 * @Github: https://github.com/ZhanhongLiang
 * @Date: 2019-10-23 22:02:27
 * @LastEditors: Chinwong_Leung
 * @LastEditTime: 2019-10-28 20:07:58
 */

#ifndef ANGLESOLVER_H
#define ANGLESOLVER_H
#define MINECODE

#include "../header/Header.h"
#include "./Settings.hpp"

/**
 * @brief: 
 * @param {type} 
 * @return: 
 * @author: Chinwong_Leung
 */
#ifdef MINECODE
class AngleSolver
{
public:
    //初始化程序
    AngleSolver(string file_path/*, float c_x, float c_y, float c_z, float barrel_y*/);
    
    //大符角度解算
    void GetRuneAngle(RotatedRect rect/*, float ballet_speed, float rune_angle, /*float pre_angle,*//* float gimbal_pitch, float &angle_x, float &angle_y, float &dist*/);
    //float GetRunePitch(float dist, float tvecy_y, float ballet_speed);
    void GetP3Point(uint mode, Point2f offset_point);
    void GetP2Point(RotatedRect &rect,vector<cv::Point2f> &target2D,Point2f offset_point);

public:
    Mat cameraMatrix, distCoeffs;
    Mat object_point_mat;
    vector<Point3f> objectPoints;
    vector<Point2f> projectedPoints;
    vector<Point2f> imagePoints;
    Mat rvec;
    Mat tvec;
    float height_world = 60.0;
    float overlap_dist = 100000.0;
    float barrel_ptz_offset_x = -0;
    float barrel_ptz_offset_y = -0; // mm   + ptz is up barrel

    float ptz_camera_x = 0;       // +left
    float ptz_camera_y = 52.5;       // + camera is  ptz
    float ptz_camera_z = -135;//-225;     // - camera is front ptz
    float scale = 0.99f;              // is calc distance scale not use pnp ,test

    //Kalman1 kalman;
    int f_ = 1500;
    float rune_h;
    float rune_distance;
};
#endif

//官方代码修改
#ifndef MINECODE

#endif


#endif //ANGLESOLVER_H
