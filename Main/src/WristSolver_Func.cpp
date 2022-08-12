#include "../Eigen/Dense"
#include "../Eigen/Geometry"
#include "../Eigen/QuadProg.h"
#include "../Eigen/testQPsolvers.hpp"
#include "../Eigen/eiquadprog.hpp"
#include "../Eigen/Core"
#include "../Eigen/Cholesky"
#include "../Eigen/LU"
#include <iostream>
#include <cmath>

using namespace  std;
using namespace  Eigen;


MatrixXd rot(int axis , double q ,int dim){
    if (dim==3){
        MatrixXd R(3,3);
    if (axis==1){
        R<<1,0,0,
                0,cos(q),-sin(q),
                0,sin(q),cos(q);
    }

    if (axis==2){
        R<<cos(q),0,sin(q),
                0,1,0 ,
                -sin(q),0,cos(q);
    }

    if (axis==3){
                R<<cos(q),-sin(q),0,
                sin(q),cos(q),0,
                0,0,1;
    }
    return R;
    };
}

VectorXd wrist_right_calc(double alpha, double beta){

double phi;              
double gama ;           
double r1;           double pz;
double a1;           double b1;
double theta_32;     double theta_22;
double theta_12;      double theta_12_;
double k;
double a;             double b;
VectorXd result(2);


phi=248.5591*M_PI/180;
gama=111.4409*M_PI/180;
pz=-63.6749;
r1=28.0405;

a1=9.4067;   b1=60.9414;


VectorXd r1_(3);
r1_<<r1*cos(phi), r1*sin(phi),0;

VectorXd h1_P(3);
h1_P<<18.8173,18.6175,0.07835;

VectorXd P(3);
P<<0,0,pz;

MatrixXd R_PtoO;
R_PtoO.resize(3,3);
R_PtoO=rot(3,gama,3)*rot(1,alpha,3)*rot(2,beta,3);
//cout<<R_PtoO<<endl;

MatrixXd h1_O;
h1_O.resize(3,3);
h1_O=P+R_PtoO*h1_P;

MatrixXd R_OtoA1;
R_OtoA1.resize(3,3);
R_OtoA1=rot(3,phi,3);

MatrixXd h1_A1;
h1_A1.resize(3,1);
h1_A1=r1_+R_OtoA1*h1_O;
/*
VectorXd C(3);
C=h1_A1;
*/
theta_32=acos(h1_A1(1)/b1);
//cout<<theta_32<<endl;

k=(pow(h1_A1(0),2)+pow(h1_A1(1),2)+pow(h1_A1(2),2)-pow(a1,2)-pow(b1,2))/(2*a1*b1*sin(theta_32));


theta_22=acos(k);
//cout<<theta_22<<endl;


a=a1+b1*cos(theta_22)*sin(theta_32);
b=b1*sin(theta_22)*sin(theta_32);

//cout<<a<<endl<<b;

theta_12= -asin((a*h1_A1(2)+b*sqrt(pow(a,2)+pow(b,2)-pow(h1_A1(2),2)))/(pow(a,2)+pow(b,2)));
theta_12_= -asin((a*h1_A1(2)-b*sqrt(pow(a,2)+pow(b,2)-pow(h1_A1(2),2)))/(pow(a,2)+pow(b,2)));
//cout<<theta_12*180/M_PI<<endl<<theta_12_*180/M_PI;

result<< theta_12*180/M_PI,theta_12_*180/M_PI;
return result;
}

VectorXd wrist_left_calc(double alpha, double beta){

double phi;              
double gama ;           
double r1;           double pz;
double a1;           double b1;
double theta_31;     double theta_21;
double theta_11;      double theta_11_;
double k;
double a;             double b;
VectorXd result(2);


phi=292.197718*M_PI/180;
gama=67.80228*M_PI/180;
pz=-86.07491;
r1=28.18923;

a1=9.36598;   b1=87.80285;


VectorXd r1_(3);
r1_<<r1*cos(phi), r1*sin(phi),0;

VectorXd h1_P(3);
h1_P<<-17.1750,19.356,0.0783;

VectorXd P(3);
P<<0,0,pz;

MatrixXd R_PtoO;
R_PtoO.resize(3,3);
R_PtoO=rot(3,gama,3)*rot(1,alpha,3)*rot(2,beta,3);
//cout<<R_PtoO<<endl;

MatrixXd h1_O;
h1_O.resize(3,3);
h1_O=P+R_PtoO*h1_P;

MatrixXd R_OtoA1;
R_OtoA1.resize(3,3);
R_OtoA1=rot(3,phi,3);

MatrixXd h1_A1;
h1_A1.resize(3,1);
h1_A1=r1_+R_OtoA1*h1_O;
/*
VectorXd C(3);
C=h1_A1;
*/
theta_31=acos(h1_A1(1)/b1);
//cout<<theta_32<<endl;

k=(pow(h1_A1(0),2)+pow(h1_A1(1),2)+pow(h1_A1(2),2)-pow(a1,2)-pow(b1,2))/(2*a1*b1*sin(theta_31));


theta_21=acos(k);
//cout<<theta_22<<endl;


a=a1+b1*cos(theta_21)*sin(theta_31);
b=b1*sin(theta_21)*sin(theta_31);

//cout<<a<<endl<<b;

theta_11= -asin((a*h1_A1(2)+b*sqrt(pow(a,2)+pow(b,2)-pow(h1_A1(2),2)))/(pow(a,2)+pow(b,2)));
theta_11_= -asin((a*h1_A1(2)-b*sqrt(pow(a,2)+pow(b,2)-pow(h1_A1(2),2)))/(pow(a,2)+pow(b,2)));
//cout<<theta_12*180/M_PI<<endl<<theta_12_*180/M_PI;

result<< theta_11*180/M_PI,theta_11_*180/M_PI;
return result;

}

int main(){

double alpha=-9.16*M_PI/180;  
double beta=-7.91*M_PI/180;

VectorXd result_right(2);
VectorXd result_left(2);

result_right=wrist_right_calc(alpha,beta);
result_left=wrist_left_calc(alpha,beta);


cout<< "result_right is"<< result_right[1] << endl<< "result_left is"<< result_left[1] ;


return 0;

};
