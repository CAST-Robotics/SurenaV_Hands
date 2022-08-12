#include "S5_right_hand.h"
#include "../Eigen/Dense"
#include "../Eigen/Geometry"
#include "../Eigen/QuadProg.h"
#include "../Eigen/testQPsolvers.hpp"
#include "../Eigen/eiquadprog.hpp"
#include "../Eigen/Core"
#include "../Eigen/Cholesky"
#include "../Eigen/LU"
#include <iostream>
#include <vector>
#include "fstream"
#include <string>
#include "ros/ros.h"
#include<std_msgs/Float32MultiArray.h>
#include<std_msgs/Int32MultiArray.h>




using namespace  std;
using namespace  Eigen;



int main(int argc, char **argv)
{
     
    VectorXd r_target_1;
    r_target_1.resize(3,1);
    VectorXd r_target_2;
    r_target_2.resize(3,1);
    VectorXd r_target_3;
    r_target_3.resize(3,1);

    MatrixXd R_middle_r;
    R_middle_r.resize(3,3);

    VectorXd r_target;
    r_target.resize(3,1);

    VectorXd V_ra;
    V_ra.resize(3,1);

    VectorXd q_ra;
    q_ra.resize(7,1);
    q_ra<<0,0,0,0,0,0,0;

    vector<double> qr_end(34); ///////////

    MatrixXd R_target_r;
    R_target_r.resize(3,3);

    VectorXd t_r;
    t_r.resize(3,1); 

    int qref[12]={0};
    int qc_offset[40]={0};

    VectorXd q_motor_r;
    q_motor_r.resize(8,1);
    VectorXd q_motor_l;
    q_motor_l.resize(8,1);

    int i=0;
    double time_r;
    int count = 0; 
    double T=4;
    time_r=count*.005;
    t_r<<0,2,4;



    R_target_r.fill(0);

   // r_target_1<<0.343,-0.003,0.084;  //salam
    //r_target_2<<0.343,0.003,0.084;
    r_target_2<<0.343,-0.3,-0.3;
   // r_target_3<<0.299,-0.020,-0.346;   // surena hastam

    right_hand RH( q_ra, r_target,  R_target_r);
    double dist_=RH.dist;
    double d0=dist_;

    ros::init(argc, argv, "handnode");
    ros::NodeHandle nh;

    ros::Publisher  trajectory_data_pub  = nh.advertise<std_msgs::Int32MultiArray>("jointdata/qc",100);
    std_msgs::Int32MultiArray trajectory_data;
    //ros::ServiceServer HandMoveService = nh.advertiseService("HandMove", handMove);

    ros::Rate loop_rate(200);
    while (ros::ok())
    {
   
    while (time_r<10){
        if (time_r<10){
        r_target=r_target_2;
        R_middle_r.fill(0);
        RH.update_right_hand(q_ra,r_target , R_middle_r,i,d0);
        RH.doQP(q_ra);
        q_ra=RH.q_next;
        for (int i=0; i<q_ra.size(); i++){
            qr_end[i]=q_ra(i);
            cout<<qr_end[i]<<endl;
        }
        }
       
        //cout<<"okey"<<endl;
        i++;
        count++;
        time_r=(count)*.005;
    
    




    
    q_motor_r[0]=-int(10*(qr_end[0])*180/M_PI*120/60);
    q_motor_r[1]=int(10*(qr_end[1])*180/M_PI*120/60);
    q_motor_r[2]=-int(7*(qr_end[2])*180/M_PI*100/60);
    q_motor_r[3]=int(7*(qr_end[3])*180/M_PI*100/60);

    q_motor_r[4]=int((qr_end[4])*(2048)/M_PI);
    q_motor_r[5]=int((qr_end[5])*(4000-2050)/(23*M_PI/180));
    q_motor_r[6]=int((qr_end[6])*(4000-2050)/(23*M_PI/180));
    q_motor_r[7]=0;


    q_motor_l[0]=0;
    q_motor_l[1]=0;
    q_motor_l[2]=0;
    q_motor_l[3]=0;
    q_motor_l[4]=0;
    q_motor_l[5]=0;
    q_motor_l[6]=0;
    q_motor_l[7]=0;
     for (int i = 0; i < 27; ++i) {
        qc_offset[i]=0;
        };

    trajectory_data.data.clear();

    for(int  i = 0;i < 12;i++)
    {
        trajectory_data.data.push_back(qref[i]+qc_offset[i]);
    }
    //right hand epose
    for(int  i = 0;i < 8;i++)
    {
        trajectory_data.data.push_back(q_motor_r[i]+qc_offset[i+12]);
    }
    for(int  i = 0;i < 8;i++)
    {
        trajectory_data.data.push_back(q_motor_l[i]+qc_offset[i+20]);
    }


    trajectory_data_pub.publish(trajectory_data);

    //ros::spinOnce();
    ROS_INFO("done!");

    loop_rate.sleep();};
    };
    return 0 ;

  };   


