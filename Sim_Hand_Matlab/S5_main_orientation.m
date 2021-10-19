clc;clear all;close all;
run S5_HO_Physical_features;
global r_target T

T=0.005;
t_d=20;
n=t_d/T;
c=0;

% r_target=[0.277;-0.0302;-0.226];
r_target=[0.299;0.020;-0.346];

% r_target=[0.343;-0.003;0.084];
q0=1*[0;0;0;-10*pi/180;0;0;0];
R_target=rot(2,0*pi/180,3)*rot(1,0*pi/180,3);
% R_target=rot(2,5*pi/180,3)*rot(3,10*pi/180,3)*rot(2,10*pi/180,3);
% R_target=rot(2,-30*pi/180,3)*rot(3,0*pi/180,3)*rot(2,0*pi/180,3);

r_0=S5_HO_FK_right_palm(q0);
[phi_target,theta_target,sai_target]=S5_euler_calc(R_target); %%%%%%%%%%%%%%%


V_des=5;
d_des=0.01;
qdot_max=10;
d_orient=.1;


power=1* (10^(-4));
Right_palm_position_power=10^(6);
Right_palm_orientation_power=10^(2);


tic

% u=zeros(7,n);


q=zeros(7,1);
qdot=zeros(7,1);
q(:,1)=q0(:,1);

Jha=S5_HO_Jacobians(q(:,1));
J_right_palm=Jha(1:3,1:7);
J_w_right_palm=Jha(4:6,1:7);
r_right_palm=S5_HO_FK_right_palm(q(:,1));


R1_fix_shd=rot(1,-angle_fix_shd,4);
R1_ra = rot(2,q0(1),4);
R2_ra = rot(1,q0(2),4);
R3_ra = rot(3,q0(3),4);
R4_ra = rot(2,q0(4),4);
R5_ra = rot(3,q0(5),4);
R6_ra = rot(2,q0(6),4);
R7_ra = rot(1,q0(7),4);
R_right_palm=R1_fix_shd*R1_ra*R2_ra*R3_ra*R4_ra*R5_ra*R6_ra*R7_ra;
[phi,theta,sai]=S5_euler_calc(R_right_palm);

% % velocity update occurs in every step toward destination, magnitude is calculated by remained time 
% Vx_left_palm=(r_target(1)-r_left_palm(1))/(n*T);
% Vy_left_palm=(r_target(2)-r_left_palm(2))/(n*T);
% Vz_left_palm=(r_target(3)-r_left_palm(3))/(n*T);

% % velocity update occurs in every step toward destination, magnitude is V_des 
% Vx_left_palm=V_des*(r_target(1)-r_left_palm(1))/norm(r_target-r_left_palm);
% Vy_left_palm=V_des*(r_target(2)-r_left_palm(2))/norm(r_target-r_left_palm);
% Vz_left_palm=V_des*(r_target(3)-r_left_palm(3))/norm(r_target-r_left_palm);

 % velocity is defined by fifth order polynomial, coefficients have been calculted 
Vx_right_palm=0;
Vy_right_palm=0;
Vz_right_palm=0;
w_right_palm=[0;0;0]
 d=sqrt((r_target(1)- r_right_palm(1))^2+(r_target(2)- r_right_palm(2))^2+(r_target(3)- r_right_palm(3))^2);
 dor=sqrt((theta-theta_target)^2+(sai-sai_target)^2+(phi-phi_target)^2);
 d0=d;
 i=1;
% && (abs(theta-theta_target)>.02)  && (abs(sai-sai_target)>.02)  && (abs(phi-phi_target)>.02)   
f = 1;
% || (abs(theta-theta_target)>.02)   || (abs(sai-sai_target)>.02)  || (abs(phi-phi_target)>.02)
 while d>d_des 
    Q=power*eye(7,7); P=zeros(1,7);
    c=c+1;
%     upbound(1:7,1)=min(((1/T)*((pi/180)*[70;10;60;-5;90;20;20]- q(:,i))),qdot_max);
%     lowbound(1:7,1)=max(((1/T)*((pi/180)*[-90;-90;-60;-120;-90;-20;-20] - q(:,i))),-qdot_max);
    upbound(1:7,1)=min(((1/T)*((pi/180)*[80;10;60;-5;90;20;20]- q(:,i))),qdot_max);
    lowbound(1:7,1)=max(((1/T)*((pi/180)*[-110;-90;-60;-90;-90;-20;-20] - q(:,i))),-qdot_max);
%     
%     
%     upbound(1:7,1)=[inf;inf;inf;inf;inf;inf;inf];
%     lowbound(1:7,1)=-[inf;inf;inf;inf;inf;inf;inf];
    
    Q= Q+ Right_palm_position_power*(2* transpose(J_right_palm(1,:)) * J_right_palm(1,:) + 2* transpose(J_right_palm(2,:)) * J_right_palm(2,:) + 2* transpose(J_right_palm(3,:)) * J_right_palm(3,:));
    P=P + Right_palm_position_power*(-2*(Vx_right_palm)* J_right_palm(1,:) - 2*(Vy_right_palm)*J_right_palm(2,:)  - 2*(Vz_right_palm)*J_right_palm(3,:));
    
    if d<d_orient
    Q= Q+ (tanh(3*(d_orient-d)/d_orient))^2*Right_palm_orientation_power*(2* transpose(J_w_right_palm(1,:)) * J_w_right_palm(1,:) + 2* transpose(J_w_right_palm(2,:)) * J_w_right_palm(2,:) + 2* transpose(J_w_right_palm(3,:)) * J_w_right_palm(3,:));
    P=P +(tanh(3*(d_orient-d)/d_orient))^2* Right_palm_orientation_power*(-2*(w_right_palm(1))* J_w_right_palm(1,:) - 2*(w_right_palm(2))*J_w_right_palm(2,:)  - 2*(w_right_palm(3))*J_w_right_palm(3,:));
    end
    
 
    d=sqrt((r_target(1)- r_right_palm(1))^2+(r_target(2)- r_right_palm(2))^2+(r_target(3)- r_right_palm(3))^2);
    dor=sqrt((theta-theta_target)^2+(sai-sai_target)^2+(phi-phi_target)^2);

    
    u=quadprog(Q,transpose(P),[],[],[],[],lowbound,upbound);
    
    qdot(:,i+1)=u;
    q(:,i+1)=q(:,i) + T* qdot(:,i);
    
    
    Jha=S5_HO_Jacobians(q(:,i+1));
    J_right_palm=Jha(1:3,1:7);
    J_w_right_palm=Jha(4:6,1:7);

    
    r_right_palm=S5_HO_FK_right_palm(q(:,i+1));
    
    
    
 % % velocity update occurs in every step toward destination, magnitude is calculated by remained time   
%     Vx_right_palm=(r_target(1)-r_right_palm(1))/((n+1-i)*T);
%     Vy_right_palm=(r_target(2)-r_right_palm(2))/((n+1-i)*T);
%     Vz_right_palm=(r_target(3)-r_right_palm(3))/((n+1-i)*T);

% velocity update occurs in every step toward destination, magnitude is V_des 

Vx_right_palm=V_des*min(i/100,1)*(tanh(d/d0*10)/pi*2)^2*(r_target(1)-r_right_palm(1))/norm(r_target-r_right_palm);
Vy_right_palm=V_des*min(i/100,1)*(tanh(d/d0*10)/pi*2)^2*(r_target(2)-r_right_palm(2))/norm(r_target-r_right_palm);
Vz_right_palm=V_des*min(i/100,1)*(tanh(d/d0*10)/pi*2)^2*(r_target(3)-r_right_palm(3))/norm(r_target-r_right_palm);
% Vx_right_palm=V_des*min(i/100,1)*((1/(1+2.71^(-d/d0*10)))/pi*2)^2*(r_target(1)-r_right_palm(1))/norm(r_target-r_right_palm);
% Vy_right_palm=V_des*min(i/100,1)*((1/(1+2.71^(-d/d0*10)))/pi*2)^2*(r_target(2)-r_right_palm(2))/norm(r_target-r_right_palm);
% Vz_right_palm=V_des*min(i/100,1)*((1/(1+2.71^(-d/d0*10)))/pi*2)^2*(r_target(3)-r_right_palm(3))/norm(r_target-r_right_palm);

%  % velocity is defined by fifth order polynomial, coefficients have been calculted 

%  t=i*T;
% coef_x=order6(0,t_d,r_0(1),r_target(1),0,0,0,0);
% coef_y=order6(0,t_d,r_0(2),r_target(2),0,0,0,0);
% coef_z=order6(0,t_d,r_0(3),r_target(3),0,0,0,0);
% 
% Vx_right_palm=[5*t^4 4*t^3 3*t^2 2*t 1 0]*coef_x;
% Vy_right_palm=[5*t^4 4*t^3 3*t^2 2*t 1 0]*coef_y;
% Vz_right_palm=[5*t^4 4*t^3 3*t^2 2*t 1 0]*coef_z;

V_x(f) = Vx_right_palm;
V_y(f) = Vy_right_palm;
V_z(f) = Vz_right_palm;
f = f+1;
    
R1_fix_shd=rot(1,-angle_fix_shd,4);
R1_ra = rot(2,q(1,i),4);
R2_ra = rot(1,q(2,i),4);
R3_ra = rot(3,q(3,i),4);
R4_ra = rot(2,q(4,i),4);
R5_ra = rot(3,q(5,i),4);
R6_ra = rot(2,q(6,i),4);
R7_ra = rot(1,q(7,i),4);
R_right_palm=R1_fix_shd*R1_ra*R2_ra*R3_ra*R4_ra*R5_ra*R6_ra*R7_ra;
[phi,theta,sai]=S5_euler_calc(R_right_palm);

sai_dot=(tanh(3*(d_orient-d)/d_orient))^2*(sai_target-sai);
phi_dot=(tanh(3*(d_orient-d)/d_orient))^2*(phi_target-phi);
theta_dot=(tanh(3*(d_orient-d)/d_orient))^2*(theta_target-theta);

w_right_palm=[sin(phi)*theta_dot+cos(phi)*cos(theta)*sai_dot;sin(theta)*sai_dot+phi_dot;cos(phi)*theta_dot-cos(theta)*sin(phi)*sai_dot];
% w_right_palm=[sin(sai)*sin(theta)*phi_dot+cos(sai)*theta_dot;cos(sai)*sin(theta)*phi_dot-sin(sai)*theta_dot;cos(theta)*phi_dot+sai_dot];

i=i+1; 
 end
toc
% %%
n=size(q,2);
run HO_SimulationPlot

figure(2);
subplot(4,1,1)
plot(q');
title('q');
subplot(4,1,2)
plot(qdot');
title('dq/dt');
subplot(4,1,3)
plot(diff(qdot'));
title('d2q/dt2');
subplot(4,1,4)
plot(diff(diff(qdot')));
title('d3q/dt3');
% plot(orien_norm)

figure(3)
plot (1:1:length(V_z),V_x)
hold on
plot (1:1:length(V_z),V_y)
hold on
plot (1:1:length(V_z),V_z)


