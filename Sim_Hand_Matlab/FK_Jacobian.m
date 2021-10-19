clear all;clc;
clc;clear all;close all;
%run HO_Physical_features

syms q1_ra q2_ra q3_ra q4_ra q5_ra q6_ra q7_ra real
syms dq1_ra dq2_ra dq3_ra dq4_ra dq5_ra dq6_ra dq7_ra angle_fix_shd angle_fix_elbow real
syms L_arm L_palm L1_forearm L2_forearm real
% syms L_arm L_forearm L_palm  real
% q1_ra= -30*pi/180;
% q2_ra= -10*pi/180;
% q3_ra= 20*pi/180 ;
% q4_ra= 0*pi/180;
% q5_ra=20*pi/180;
% q6_ra= 0; 
% q7_ra= 0;
% L_arm= 257.47/1000  ; %234
% L1_forearm=71.75/1000 ;
% L2_forearm= 159.38/1000 ; %362.5
% L_palm=0/1000 ;%100
% angle_fix_shd=20*pi/180;
% angle_fix_elbow=20*pi/180;

q=[q1_ra;q2_ra;q3_ra;q4_ra;q5_ra;q6_ra;q7_ra];
dq=[dq1_ra;dq2_ra;dq3_ra;dq4_ra;dq5_ra;dq6_ra;dq7_ra];

%% Right hand rotation matrices
R1_fix_shd=rot(1,-angle_fix_shd,4);
R1_ra = rot(2,q1_ra,4);
% R2_fix_shd=rot(1,angle_fix_shd,4);
R2_ra = rot(1,q2_ra,4);
R3_ra = rot(3,q3_ra,4);
% R1_fix_elbow=rot(2,-angle_fix_elbow,4);
R4_ra = rot(2,q4_ra,4);
%R2_fix_elbow=rot(2,angle_fix_elbow,4);
R5_ra = rot(3,q5_ra,4);
R6_ra = rot(2,q6_ra,4);
R7_ra = rot(1,q7_ra,4);

%% Right hand transition matrices
P_arm_ra = trans(3,-L_arm);
P1_forearm_ra= trans(3,-L1_forearm); 
P2_forearm_ra= trans(3,-L2_forearm); 
P_palm_ra = trans(3,-L_palm); 

%%
r_right_palm=R1_fix_shd*R1_ra*R2_ra*R3_ra*P_arm_ra*R4_ra*P1_forearm_ra*R5_ra*P2_forearm_ra*R6_ra*R7_ra*P_palm_ra*[0;0;0;1];
dr_right_palm=jacobian(r_right_palm(1:3),q)*dq;
J_palm_ra=jacobian(dr_right_palm,dq)

diary ('r_right_palm.txt');
 J_palm_ra
 diary off

