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


using namespace  std;
using namespace  Eigen;
int main(){
double a=0.05 ;
double b=2*a ;

cout<<"ok0";
VectorXd r_target_r;
r_target_r.resize(3,1);
VectorXd r_middle_r;
r_middle_r.resize(3,1);
MatrixXd R_middle_r;
R_middle_r.resize(3,3);

VectorXd r_target;
r_target.resize(3,1);

VectorXd V_ra;
V_ra.resize(3,1);

VectorXd q_ra;
q_ra.resize(7,1);
q_ra<<0,0,0,0,0,0,0;

VectorXd qr_end;
qr_end.resize(7,1);
qr_end<<0,0,0,0,0,0,0;

MatrixXd R_target_r;
R_target_r.resize(3,3);


MatrixXd qref;
qref.resize(7,1600);

int i=0;
double time_r;
int count = 0; 
double T=2;
time_r=count*.005;

//right_hand RH;
right_hand RH_obj;
//R_target_r=RH_obj.R_right_palm;

R_target_r.fill(0);
r_target_r<<0.340,0.256,-0.212;
//r_target_r<<0.384,0,-0.282;
cout<<"ok1";
right_hand RH( q_ra, r_target,  R_target_r);
double dist_=RH.dist;
double d0=dist_;

while(time_r<8){

    if(time_r<2){

    RH.update_right_hand(q_ra,r_target_r , R_target_r,i,d0);
    RH.doQP(q_ra);
    q_ra=RH.q_next;
    qr_end=q_ra;
    qref.block(0,i,7,1)=qr_end;
    }
    
  /*  else if (time_r<4) {

    double L=a;
    double v=30*L/pow(T,3)*pow(time_r-2,2)-60*L/pow(T,4)*pow(time_r-2,3)+30*L/pow(T,5)*pow(time_r-2,4);
    double P=10*L/pow(T,3)*pow(time_r-2,3)-15*L/pow(T,4)*pow(time_r-2,4)+6*L/pow(T,5)*pow(time_r-2,5);
    //V_ra<<0,-v*a/L/2,v*b/L;
    V_ra<<0,v,0;
    RH.update_right_hand(q_ra,V_ra,r_target_r,R_target_r);
    RH.doQP(q_ra);
    q_ra=RH.q_next;
    qr_end=q_ra;
    qref.block(0,i,7,1)=qr_end;
    }
   */
    else if (time_r<4){
    double L=sqrt(a*a/4+b*b);
    double v=30*L/pow(T,3)*pow(time_r-2,2)-60*L/pow(T,4)*pow(time_r-2,3)+30*L/pow(T,5)*pow(time_r-2,4);
    double P=10*L/pow(T,3)*pow(time_r-2,3)-15*L/pow(T,4)*pow(time_r-2,4)+6*L/pow(T,5)*pow(time_r-2,5);
    V_ra<<0,-v*a/L/2,v*b/L;
   
    RH.update_right_hand(q_ra,V_ra,r_target_r,R_target_r);
    RH.doQP(q_ra);
    q_ra=RH.q_next;
    qr_end=q_ra;
    qref.block(0,i,7,1)=qr_end;
    }
    else if (time_r<6){
    double L=sqrt(a*a/4+b*b);
    double v=30*L/pow(T,3)*pow(time_r-4,2)-60*L/pow(T,4)*pow(time_r-4,3)+30*L/pow(T,5)*pow(time_r-4,4);
    double P=10*L/pow(T,3)*pow(time_r-4,3)-15*L/pow(T,4)*pow(time_r-4,4)+6*L/pow(T,5)*pow(time_r-4,5);
    V_ra<<0,-v*a/L/2,-v*b/L;
   
    RH.update_right_hand(q_ra,V_ra,r_target_r,R_target_r);
    RH.doQP(q_ra);
    q_ra=RH.q_next;
    qr_end=q_ra;
    qref.block(0,i,7,1)=qr_end;
    }
    else {

    double L=a;
    double v=30*L/pow(T,3)*pow(time_r-6,2)-60*L/pow(T,4)*pow(time_r-6,3)+30*L/pow(T,5)*pow(time_r-6,4);
    double P=10*L/pow(T,3)*pow(time_r-6,3)-15*L/pow(T,4)*pow(time_r-6,4)+6*L/pow(T,5)*pow(time_r-6,5);
    V_ra<<0,v,0;
   
    RH.update_right_hand(q_ra,V_ra,r_target_r,R_target_r);
    RH.doQP(q_ra);
    q_ra=RH.q_next;
    qr_end=q_ra;
    qref.block(0,i,7,1)=qr_end;
    }
    i++;
    count++;
    time_r=(count)*.005;
};
 
   




ofstream fw("/home/surena/Projects/pybullet/Triangle.txt", std::ofstream::out);
//check if file was successfully opened for writing
if (fw.is_open()){
  //store array contents to text file
  for (int i = 0; i < 1600; i++) {
      for (int j = 0; j <7; j++){
     fw << qref(j,i) << "\n";
 }
  }
  fw.close();
}
    //cout<<qref;
    return 0;
};

//g++ S5_trajectory_test.cpp S5_right_hand.cpp