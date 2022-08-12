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


int main(){


double phi;              double alpha;
double gama ;            double beta;
double r1;           double pz;
double a1;           double b1;
double theta_32;     double theta_22;
double theta_12;      double theta_12_;
double k;
double a;             double b;

alpha=9.18*M_PI/180;
beta=10.17*M_PI/180;
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
cout<<theta_12*180/M_PI<<endl<<theta_12_*180/M_PI;
//a1*sin(theta_12)+b1*sin(theta_12+theta_22)*sin(theta_32)+C(2);
return 0;

};
