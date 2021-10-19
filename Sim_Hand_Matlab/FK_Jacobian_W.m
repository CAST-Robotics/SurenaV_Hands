clc;clear all;close all;
%run HO_Physical_features
syms q1_ra q2_ra q3_ra q4_ra q5_ra q6_ra q7_ra real
syms dq1_ra dq2_ra dq3_ra dq4_ra dq5_ra dq6_ra dq7_ra real
syms L_arm L1_forearm L2_forearm L_palm angle_fix_shd angle_fix_elbow real
q=[q1_ra;q2_ra;q3_ra;q4_ra;q5_ra;q6_ra;q7_ra];
dq=[dq1_ra;dq2_ra;dq3_ra;dq4_ra;dq5_ra;dq6_ra;dq7_ra];


%% Right hand rotation matrices
R1_fix_shd=rot(1,-angle_fix_shd,4);
R1_ra = rot(2,q1_ra,4);
R2_ra = rot(1,q2_ra,4);
R3_ra = rot(3,q3_ra,4);
R4_ra = rot(2,q4_ra,4);
R5_ra = rot(3,q5_ra,4);
R6_ra = rot(1,q6_ra,4);
R7_ra = rot(2,q7_ra,4);

%% Right hand transition matrices
P_arm_ra = trans(3,-L_arm);
P1_forearm_ra= trans(3,-L1_forearm); 
P2_forearm_ra= trans(3,-L2_forearm); 
P_palm_ra = trans(3,-L_palm); 


%%% link rotations
 R1_fix_shd;
 R1_arm=R1_fix_shd*R1_ra;
 R2_arm=R1_arm*R2_ra;
 R3_arm=R2_arm*R3_ra;
 R_forearm=R3_arm*R4_ra;
 R1_palm=R_forearm*R5_ra;
 R2_palm=R1_palm*R6_ra;
 R3_palm=R2_palm*R7_ra;
 
 
%%%%%link Ws
% W_arm=R1_fix_shd(1:3,1:3)*[0;dq1_ra;0]+R1_arm(1:3,1:3)*[dq2_ra;0;0]+R2_arm(1:3,1:3)*[0;0;dq3_ra];
% W_forearm=W_arm+R3_arm(1:3,1:3)*[0;dq4_ra;0];
% W_palm=W_forearm+R_forearm(1:3,1:3)*[0;0;dq5_ra]+R1_palm(1:3,1:3)*[0;dq6_ra;0]+R2_palm(1:3,1:3)*[dq7_ra;0;0];

W_arm=R1_arm(1:3,1:3)*[0;dq1_ra;0]+R2_arm(1:3,1:3)*[dq2_ra;0;0]+R3_arm(1:3,1:3)*[0;0;dq3_ra];
W_forearm=W_arm+R_forearm(1:3,1:3)*[0;dq4_ra;0];
W_palm=W_forearm+R1_palm(1:3,1:3)*[0;0;dq5_ra]+R2_palm(1:3,1:3)*[0;dq6_ra;0]+R3_palm(1:3,1:3)*[dq7_ra;0;0];



%% Calculating angular Jacobians
J_w_HO_r=jacobian(W_palm,dq)

diary ('J_w_HO_r.txt');
J_w_HO_r
 diary off