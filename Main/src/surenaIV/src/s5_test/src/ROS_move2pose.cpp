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
    //q_goal<<1,-0.56,-0.52,-0.26,0,0,0;
    q_goal<<0.2,0,0,0,0,0,0;


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

    ros::init(argc, argv, "handnode");
    ros::NodeHandle nh;

    ros::Publisher  trajectory_data_pub  = nh.advertise<std_msgs::Int32MultiArray>("jointdata/qc",100);
    std_msgs::Int32MultiArray trajectory_data;
    //ros::ServiceServer HandMoveService = nh.advertiseService("HandMove", handMove);


    ros::Rate loop_rate(200);
    while (ros::ok())
    {
   

    while(time_r<4){

    if (time_r<4){
        for (int i = 0; i < 7; ++i) {
        qr_end[i]=q_current(i)+move2pose(q_goal(i)-q_current(i),time_r,0,4);
        };
       
        n++;
        count++;
        time_r=(count)*.005;
    }
 /*   
    else{
    if(time_r==4.005){
    qr_end(2)=0;
    qr_end(4)=0;
    };
    qr_end(2)=qr_end(2)+0.5*M_PI/180*sin((time_r)/2*(2*M_PI));
    }
*/
    /*else{

    for (int i = 0; i < 7; ++i) {
        qr_end[i]=q_goal(i)+move2pose(q_goal1(i)-q_goal(i),time_r,4,8);
        };
        n++;
        count++;
        time_r=(count)*.005;
    }
*/
    q_motor_r[0]=int(10*(qr_end[0])*180/M_PI*120/60);
    q_motor_r[1]=int(10*(qr_end[1])*180/M_PI*120/60);
    q_motor_r[2]=int(7*(qr_end[2])*180/M_PI*100/60);
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
    /*ROS_INFO("Offset=%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t\n",
                     q_motor_r[0],q_motor_r[1],q_motor_r[2],q_motor_r[3],q_motor_r[4],
                    q_motor_r[5],q_motor_r[6],q_motor_r[7],q_motor_l[0],q_motor_l[1],
                    q_motor_l[2],q_motor_l[3],q_motor_l[4],q_motor_l[5],q_motor_l[6],q_motor_l[7]);
*/
    loop_rate.sleep();

  };   
    };
return 0 ;
};