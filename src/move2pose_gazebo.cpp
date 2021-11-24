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
#include<std_msgs/Float64.h>
#include<gazebo_msgs/LinkStates.h>





using namespace  std;
using namespace  Eigen;


    


void  SendGazebo(vector<double> q){
    ros::NodeHandle nh;
    
    ros::Publisher pub1  ;ros::Publisher pub2  ;ros::Publisher pub3  ;ros::Publisher pub4  ;
    ros::Publisher pub5  ;ros::Publisher pub6  ;ros::Publisher pub7  ;ros::Publisher pub8  ;
    ros::Publisher pub9  ;ros::Publisher pub10 ;ros::Publisher pub11 ;ros::Publisher pub12 ;
    ros::Publisher pub13 ;ros::Publisher pub14 ;ros::Publisher pub15 ;ros::Publisher pub16 ;
    ros::Publisher pub17 ;ros::Publisher pub18 ;ros::Publisher pub19 ;ros::Publisher pub20 ;
    ros::Publisher pub21 ;ros::Publisher pub22 ;ros::Publisher pub23 ;ros::Publisher pub24 ;
    ros::Publisher pub25 ;ros::Publisher pub26 ;ros::Publisher pub27 ;ros::Publisher pub28 ;
    ros::Publisher pub29 ;ros::Publisher pub30 ;ros::Publisher pub31 ;


    pub1  = nh.advertise<std_msgs::Float64>("rrbot/joint1_position_controller/command",100);
    pub2  = nh.advertise<std_msgs::Float64>("rrbot/joint2_position_controller/command",100);
    pub3  = nh.advertise<std_msgs::Float64>("rrbot/joint3_position_controller/command",100);
    pub4  = nh.advertise<std_msgs::Float64>("rrbot/joint4_position_controller/command",100);
    pub5  = nh.advertise<std_msgs::Float64>("rrbot/joint5_position_controller/command",100);
    pub6  = nh.advertise<std_msgs::Float64>("rrbot/joint6_position_controller/command",100);
    pub7  = nh.advertise<std_msgs::Float64>("rrbot/joint7_position_controller/command",100);
    pub8  = nh.advertise<std_msgs::Float64>("rrbot/joint8_position_controller/command",100);
    pub9  = nh.advertise<std_msgs::Float64>("rrbot/joint9_position_controller/command",100);
    pub10 = nh.advertise<std_msgs::Float64>("rrbot/joint10_position_controller/command",100);
    pub11 = nh.advertise<std_msgs::Float64>("rrbot/joint11_position_controller/command",100);
    pub12 = nh.advertise<std_msgs::Float64>("rrbot/joint12_position_controller/command",100);
    pub13 = nh.advertise<std_msgs::Float64>("rrbot/joint13_position_controller/command",100);
    pub14 = nh.advertise<std_msgs::Float64>("rrbot/joint14_position_controller/command",100);
    pub15 = nh.advertise<std_msgs::Float64>("rrbot/joint15_position_controller/command",100);
    pub16 = nh.advertise<std_msgs::Float64>("rrbot/joint16_position_controller/command",100);
    pub17 = nh.advertise<std_msgs::Float64>("rrbot/joint17_position_controller/command",100);
    pub18 = nh.advertise<std_msgs::Float64>("rrbot/joint18_position_controller/command",100);
    pub19 = nh.advertise<std_msgs::Float64>("rrbot/joint19_position_controller/command",100);
    pub20 = nh.advertise<std_msgs::Float64>("rrbot/joint20_position_controller/command",100);
    pub21 = nh.advertise<std_msgs::Float64>("rrbot/joint21_position_controller/command",100);
    pub22 = nh.advertise<std_msgs::Float64>("rrbot/joint22_position_controller/command",100);
    pub23 = nh.advertise<std_msgs::Float64>("rrbot/joint23_position_controller/command",100);
    pub24 = nh.advertise<std_msgs::Float64>("rrbot/joint24_position_controller/command",100);
    pub25 = nh.advertise<std_msgs::Float64>("rrbot/joint25_position_controller/command",100);
    pub26 = nh.advertise<std_msgs::Float64>("rrbot/joint26_position_controller/command",100);
    pub27 = nh.advertise<std_msgs::Float64>("rrbot/joint27_position_controller/command",100);
    pub28 = nh.advertise<std_msgs::Float64>("rrbot/joint28_position_controller/command",100);
    pub29 = nh.advertise<std_msgs::Float64>("rrbot/joint29_position_controller/command",100);
    pub30 = nh.advertise<std_msgs::Float64>("rrbot/joint30_position_controller/command",100);
    pub31 = nh.advertise<std_msgs::Float64>("rrbot/joint31_position_controller/command",100);


    std_msgs::Float64 data;
    data.data=q[1];
    pub1.publish(data);
    data.data=q[2];
    pub2.publish(data);
    data.data=q[3];
    pub3.publish(data);
    data.data=q[4];
    pub4.publish(data);
    data.data=q[5];
    pub5.publish(data);
    data.data=q[6];
    pub6.publish(data);
    data.data=q[7];
    pub7.publish(data);
    data.data=q[8];
    pub8.publish(data);
    data.data=q[9];
    pub9.publish(data);
    data.data=q[10];
    pub10.publish(data);
    data.data=q[11];
    pub11.publish(data);
    data.data=q[12];
    pub12.publish(data);
    data.data=q[13];
    pub13.publish(data);
    data.data=q[14];
    pub14.publish(data);
    data.data=q[15];
    pub15.publish(data);
    data.data=q[16];
    pub16.publish(data);
    data.data=q[17];
    pub17.publish(data);
    data.data=q[18];
    pub18.publish(data);
    data.data=q[19];
    pub19.publish(data);
    data.data=q[20];
    pub20.publish(data);
    data.data=q[21];
    pub21.publish(data);
    data.data=q[22];
    pub22.publish(data);
    data.data=q[23];
    pub23.publish(data);
    data.data=q[24];
    pub24.publish(data);
    data.data=q[25];
    pub25.publish(data);
    data.data=q[26];
    pub26.publish(data);
    data.data=q[27];
    pub27.publish(data);
    data.data=q[28];
    pub28.publish(data);
    data.data=q[29];
    pub29.publish(data);
    data.data=q[30];
    pub30.publish(data);
    data.data=q[31];
    pub31.publish(data);
    ROS_INFO("done!");

}
double move2pose(double max,double t_local,double T_start ,double T_end){
    double T_move=T_end-T_start;
    double c3=(10*max)/pow(T_move,3);
    double c4=-(15*max)/pow(T_move,4);
    double c5=(6*max)/pow(T_move,5);
    double theta=0;
    if(t_local<T_start){theta=0;}
    else if (t_local<T_end){theta=c3*pow(t_local-T_start,3)+c4*pow(t_local-T_start,4)+c5*pow(t_local-T_start,5);}
    else{theta=max;}
    return theta;
};


int main(int argc, char **argv)
{
    ros::init(argc, argv, "handnode");
    ros::NodeHandle nh;

    VectorXd q_current;
    q_current.resize(7,1);
    q_current<<0,0,0,0*M_PI/180,0,0,0;

    VectorXd q_goal;
    q_goal.resize(7,1);
    VectorXd q_motor_r;
    q_motor_r.resize(8,1);
    VectorXd q_motor_l;
    q_motor_l.resize(8,1);

    VectorXd qref;
    qref.resize(12,1);
    qref.fill(0);
    q_goal<<-1.43938,
    -0.720068,
    1.0472,
    -1.52088,
    -1.5708,
    -0.3,
    0.3;

    VectorXd q_goal1;
    q_goal1.resize(7,1);
    q_goal1<<-0.527026,
    0.128595,
    1.02958,
    -1.54196,
    -1.44373,
    0.349066,
    -0.349066;

    vector<double> qr_end(34);
  


    double time_r=0;
    double n=0;
    int count = 0; 
    int qc_offset[40]={0};

    
    ros::Rate loop_rate(200);
    while (ros::ok())
    {
   

    while(time_r<8){

    if (time_r<4){
        for (int i = 0; i < 7; ++i) {
        qr_end[i]=q_current(i)+move2pose(q_goal(i)-q_current(i),time_r,0,4);
        };
       
        n++;
        count++;
        time_r=(count)*.005;
    }
    else{

    for (int i = 0; i < 7; ++i) {
        qr_end[i]=q_goal(i)+move2pose(q_goal1(i)-q_goal(i),time_r,4,8);
        };
        n++;
        count++;
        time_r=(count)*.005;
    }
    vector<double> q_init(31);
    for (int i = 0; i < 31; ++i) {
        q_init[i]=0;
    }
    q_init[15]=qr_end[0];   q_init[15+7]=0;
    q_init[16]=-qr_end[1];   q_init[16+7]=0;
    q_init[17]=qr_end[2];   q_init[17+7]=0;
    q_init[18]=qr_end[3];   q_init[18+7]=0;
    q_init[19]=qr_end[4];   q_init[19+7]=0;
    q_init[20]=qr_end[5];   q_init[20+7]=0;
    q_init[21]=qr_end[6];   q_init[21+7]=0;

    SendGazebo(q_init);
    //ros::spinOnce();
   
    loop_rate.sleep();

  };   
    };
return 0 ;
};