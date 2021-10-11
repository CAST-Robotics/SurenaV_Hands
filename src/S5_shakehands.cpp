#include "S5_right_hand.h"
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
cout<<"ok0";
VectorXd r_target_r;
r_target_r.resize(3,1);
VectorXd r_middle_r;
r_middle_r.resize(3,1);
MatrixXd R_middle_r;
R_middle_r.resize(3,3);

VectorXd r_target;
r_target.resize(3,1);

VectorXd r_right_palm;
r_right_palm.resize(3,1);

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

VectorXd t_r;
t_r.resize(3,1); 

MatrixXd qref;
qref.resize(7,3200);

int i=0;
double time_r;
int count = 0; 
double T=4;
time_r=count*.005;
t_r<<0,2,4;

//right_hand RH;
right_hand RH_obj;


r_target_r<<0.277,
            -0.0302,
            -0.226;
R_target_r=RH_obj.rot(2,-90*M_PI/180,3)*RH_obj.rot(1,30*M_PI/180,3)*RH_obj.rot(3,90*M_PI/180,3)*RH_obj.rot(2,-45*M_PI/180,3);

cout<<"ok1";
right_hand RH( q_ra, r_target,  R_target_r);
double dist_=RH.dist;
double d0=dist_;
r_right_palm=RH.r_right_palm;
while(time_r<16){
    if (time_r<2){
    R_middle_r.fill(0);
    r_target=r_target_r;
    RH.update_right_hand(q_ra,r_target , R_middle_r,i,d0);

    //cout<<"running:)"<<endl;
    RH.doQP(q_ra);
    q_ra=RH.q_next;
    qr_end=q_ra;
    qref.block(0,i,7,1)=qr_end;}
    else{
       if(time_r==2.005){
            qr_end(1)=0;
            qr_end(2)=0;
            qref.block(0,i,7,1)=qr_end;

        };
    qr_end(3)=qr_end(3)+0.5*M_PI/180*sin((time_r)/2*(2*M_PI));
    qref.block(0,i,7,1)=qr_end;

    };

    //cout<<qref.block(0,i,7,1)<<","<<endl;
    
    i++;
    count++;
    time_r=(count)*.005;
   

};
ofstream fw("/home/surena/Projects/pybullet/qscenario.txt", std::ofstream::out);
//check if file was successfully opened for writing
if (fw.is_open())
{
  //store array contents to text file
  for (int i = 0; i < 3200; i++) {
      for (int j = 0; j <7; j++){
     fw << qref(j,i) << "\n";
 }
  }
  fw.close();
}
    //cout<<qref;
    return 0;

};


