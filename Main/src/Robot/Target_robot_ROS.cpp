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
#include"MinimumJerkInterpolation.h"

using namespace  std;
using namespace  Eigen;

bool simulation=false;


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

int main(int argc, char **argv)
{
        MatrixXd P_x_r(1,3);      
    MatrixXd V_x_r(1,3);      
    MatrixXd A_x_r(1,3); 
    MatrixXd P_y_r(1,3);   
    MatrixXd V_y_r(1,3);      
    MatrixXd A_y_r(1,3);      
    MatrixXd P_z_r(1,3);      
    MatrixXd V_z_r(1,3);      
    MatrixXd A_z_r(1,3);

    MatrixXd X_coef_r;        
    MatrixXd Y_coef_r;        
    MatrixXd Z_coef_r; 
    VectorXd P_r(3); VectorXd V_r(3);
    
    VectorXd q_ra(7);
    q_ra<<0,0,0,-10*M_PI/180,0,0,0;

  
/*
    VectorXd q;
    q.resize(7,1);
*/
    vector<double> q(7);

    int qc_offset[40]={0};
    int qref[12]={0};


  VectorXd q_motor_l;
    q_motor_l.resize(8,1);

    VectorXd q_end;
    q_end.resize(7,1);

    VectorXd r_right_palm(3);
    MatrixXd R_target_r;
    R_target_r.resize(3,3);
    R_target_r.fill(0);

    double time_r;
    MatrixXd t_r(1,3);
    int count = 0; 
    time_r=count*.005;

    t_r<<0,2,4;
    VectorXd r_target_r(3); 
    VectorXd r_middle_r(3); 
    VectorXd r_start_r(3); 
    ros::init(argc, argv, "handnode");
    ros::NodeHandle nh;

    ros::Publisher  trajectory_data_pub  = nh.advertise<std_msgs::Int32MultiArray>("jointdata/qc",100);
    std_msgs::Int32MultiArray trajectory_data;
    //ros::ServiceServer HandMoveService = nh.advertiseService("HandMove", handMove);

    ros::Rate loop_rate(200);

    while (ros::ok()) {
    MinimumJerkInterpolation coef_generator;




    right_hand RH( q_ra, r_target_r,  R_target_r);
 
    
    r_start_r=RH.r_right_palm;
    /*
    r_middle_r<< 0.343,0.003,0.084;
    r_target_r<< 0.223,0.173,-0.207; */
    r_middle_r<< 0.238,-0.112,-0.386;
    r_target_r<< 0.358,0.196,-0.00241;
    while (time_r<4)
    {
    
    P_x_r<< r_start_r(0),r_middle_r(0),r_target_r(0);
    P_y_r<< r_start_r(1),r_middle_r(1),r_target_r(1);
    P_z_r<< r_start_r(2),r_middle_r(2),r_target_r(2);
    /*
    P_x_r<< r_middle_r(0),r_middle_r(0),r_target_r(0);
    P_y_r<< r_middle_r(1),r_middle_r(1),r_target_r(1);
    P_z_r<< r_middle_r(2),r_middle_r(2),r_target_r(2);*/



    V_x_r<<0,INFINITY,0;
    V_y_r<<0,INFINITY,0;
    V_z_r<<0,INFINITY,0;
    A_x_r<<0,INFINITY,0;
    A_y_r<<0,INFINITY,0;
    A_z_r<<0,INFINITY,0;

    X_coef_r=coef_generator.Coefficient(t_r,P_x_r,V_x_r,A_x_r);
    Y_coef_r=coef_generator.Coefficient(t_r,P_y_r,V_y_r,A_y_r);
    Z_coef_r=coef_generator.Coefficient(t_r,P_z_r,V_z_r,A_z_r);

   if(time_r<t_r(1)&& time_r>=t_r(0)){
    P_r<<   coef_generator.GetAccVelPos(X_coef_r.row(0),time_r,t_r(0),5)(0,0),
            coef_generator.GetAccVelPos(Y_coef_r.row(0),time_r,t_r(0),5)(0,0),
            coef_generator.GetAccVelPos(Z_coef_r.row(0),time_r,t_r(0),5)(0,0);
    V_r<<   coef_generator.GetAccVelPos(X_coef_r.row(0),time_r,t_r(0),5)(0,1),
            coef_generator.GetAccVelPos(Y_coef_r.row(0),time_r,t_r(0),5)(0,1),
            coef_generator.GetAccVelPos(Z_coef_r.row(0),time_r,t_r(0),5)(0,1);

    RH.update_right_hand(q_ra,V_r,r_middle_r,R_target_r);
    r_right_palm=RH.r_right_palm;
    RH.doQP(q_ra);
    q_ra=RH.q_next;

    count++;
    time_r=(count)*.005;
   }
    else if(time_r<t_r(2)&& time_r>=t_r(1)){
    P_r<<   coef_generator.GetAccVelPos(X_coef_r.row(1),time_r,t_r(1),5)(0,0),
            coef_generator.GetAccVelPos(Y_coef_r.row(1),time_r,t_r(1),5)(0,0),
            coef_generator.GetAccVelPos(Z_coef_r.row(1),time_r,t_r(1),5)(0,0);
    V_r<<   coef_generator.GetAccVelPos(X_coef_r.row(1),time_r,t_r(1),5)(0,1),
            coef_generator.GetAccVelPos(Y_coef_r.row(1),time_r,t_r(1),5)(0,1),
            coef_generator.GetAccVelPos(Z_coef_r.row(1),time_r,t_r(1),5)(0,1);

    RH.update_right_hand(q_ra,V_r,r_target_r,R_target_r);
    r_right_palm=RH.r_right_palm;
    RH.doQP(q_ra);
    q_ra=RH.q_next;
    
    count++;
    time_r=(count)*.005;

   }; 

 if (simulation)
                {
                    vector<double> q_init(31);
                    for (int i = 0; i < 31; ++i) {
                        q_init[i]=0;
                    }
                q_init[15]=q_ra(0);   q_init[15+7]=0;
                q_init[16]=q_ra(1);   q_init[16+7]=0;
                q_init[17]=q_ra(2);   q_init[17+7]=0;
                q_init[18]=q_ra(3);   q_init[18+7]=0;
                q_init[19]=q_ra(4);   q_init[19+7]=0;
                q_init[20]=q_ra(5);   q_init[20+7]=0;
                q_init[21]=q_ra(6);   q_init[21+7]=0;


                     SendGazebo(q_init);
                }
    //q_end=q_ra; 
    //qref.block(0,count,7,1)=q_end;
  else{
    
    q[0]=-int(10*(q_ra(0))*180/M_PI*120/60);
    q[1]=int(10*(q_ra(1))*180/M_PI*120/60);
    q[2]=-int(7*(q_ra(2))*180/M_PI*100/60);
    q[3]=int(7*(q_ra(3))*180/M_PI*100/60);

    q[4]=int((q_ra(4))*(2048)/M_PI);
    q[5]=int((q_ra(5))*(4000-2050)/(23*M_PI/180));
    q[6]=int((q_ra(6))*(4000-2050)/(23*M_PI/180));
    q[7]=0;


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
        trajectory_data.data.push_back(q[i]+qc_offset[i+12]);
    }
    for(int  i = 0;i < 8;i++)
    {
        trajectory_data.data.push_back(q_motor_l[i]+qc_offset[i+20]);
    }
  
  
    
    trajectory_data_pub.publish(trajectory_data);

    ROS_INFO("done!");

    ros::spinOnce();
  };
        loop_rate.sleep();
        };
        
         };

   return 0 ;

  };   
