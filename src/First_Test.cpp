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
using  namespace std;


int main(){
    cout<<"ok0";
VectorXd V;
V.resize(3,1);
V << 0 , 0 ,0;
MatrixXd qref;
qref.resize(7,1000);

VectorXd q_ra;
q_ra.resize(7,1);
q_ra<<0,0,0,-10*M_PI/180,0,0,0;

VectorXd r_target_r;
r_target_r.resize(3,1);
//r_target_r<<0.403,0.0004,0.015;
/*
r_target_r<<0.277,
            -0.0302,
            -0.226;*/
r_target_r<<0.304,0.156,-0.212;

right_hand RH_obj;

MatrixXd R_target_r;
R_target_r.resize(3,3);
R_target_r = RH_obj.rot(1,-80*M_PI/180,3)*RH_obj.rot(3,30*M_PI/180,3) ;
//*RH_obj.rot(1,50*M_PI/180,3);
//R_target_r=RH_obj.rot(2,-70*M_PI/180,3)*RH_obj.rot(3,70*M_PI/180,3)*RH_obj.rot(2,-20*M_PI/180,3);
//R_target_r.fill(0);
cout<<"ok1";
right_hand RH( q_ra, r_target_r,  R_target_r);
cout<<"ok2";

double dist_=RH.dist;
double d_des_=RH.d_des;
double dist_or_=RH.dist_or;
VectorXd q_end;
q_end.resize(7,1);
int i=0;
double d0=dist_;
double d1=dist_;
double d2=dist_or_;


cout<<"ok3";


while(d1>d_des_ && d2>0.01 ){
    RH.update_right_hand(q_ra,r_target_r , R_target_r,i,d0);
    d1 = RH.dist;
    d2 = RH.dist_or;
    RH.doQP(q_ra);
    q_ra=RH.q_next;
    q_end=q_ra; 
    //qref.resize(7,i);
    qref.block(0,i,7,1)=q_end;
    //cout<<qref.block(0,i,7,1)<<","<<endl;
    i+=1;


};
//open file for writing
ofstream fw("/home/surena/Projects/SURENAV (Working)/src/pytest.txt", std::ofstream::out);
//check if file was successfully opened for writing
if (fw.is_open())
{
  //store array contents to text file
  for (int i = 0; i < 1000; i++) {
      for (int j = 0; j <7; j++){
     fw << qref(j,i) << "\n";
 }
  }
  fw.close();
}
else cout << "Problem with opening file";

cout<<d1<<endl<<d2<<endl;
//cout<<q_end<<endl<<qref.block(0,430,7,1);
//cout<<q_end;
//cout<<qref;
return 0;

};