#include "S5_left_hand.h"
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
qref.resize(7,243);

VectorXd q_le;
q_le.resize(7,1);
q_le<<0,0,0,0,0,0,0;
//-10*M_PI/180

VectorXd r_target_l;
r_target_l.resize(3,1);
r_target_l<<0.277,
            -0.0302,
            -0.226;
//r_target_l<<0.4,
            0,
            0.24;


MatrixXd R_target_l;
R_target_l.resize(3,3);
//R_target_r = RH_obj.rot(1,-80*M_PI/180,3)*RH_obj.rot(3,30*M_PI/180,3) ;
R_target_l.fill(0);
//*RH_obj.rot(1,50*M_PI/180,3);
//R_target_r=RH_obj.rot(2,-70*M_PI/180,3)*RH_obj.rot(3,70*M_PI/180,3)*RH_obj.rot(2,-20*M_PI/180,3);
//R_target_r.fill(0);
cout<<"ok1";
left_hand LH( q_le, r_target_l,  R_target_l);
cout<<"ok2";

double dist_=LH.dist;
double d_des_=LH.d_des;
double dist_or_=LH.dist_or;
VectorXd q_end;
q_end.resize(7,1);
int i=0;
double d0=dist_;
double d1=dist_;
double d2=dist_or_;
//left_hand LH;

cout<<"ok3";


while(d1>d_des_ && d2>0.01){
    LH.update_left_hand(q_le,r_target_l , R_target_l,i,d0);
    d1 = LH.dist;
    d2 = LH.dist_or;
    LH.doQP(q_le);
    q_le=LH.q_next;
    q_end=q_le; 
    //qref.resize(7,i);
    qref.block(0,i,7,1)=q_end;
    //cout<<qref.block(0,i,7,1)<<","<<endl;
    i+=1;


};

//open file for writing
ofstream fw("/home/surena/Projects/SURENAV (Working)/src/lefthand.txt", std::ofstream::out);
//check if file was successfully opened for writing
if (fw.is_open())
{
  //store array contents to text file
  for (int i = 0; i < 243; i++) {
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