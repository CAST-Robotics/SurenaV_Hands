function Cal_right_palm=S5_HO_FK_right_palm(V)

global L_arm L_palm L1_forearm L2_forearm angle_fix_shd angle_fix_elbow
q1_ra=V(1);
q2_ra=V(2);
q3_ra=V(3);
q4_ra=V(4);
q5_ra=V(5);
q6_ra=V(6);
q7_ra=V(7);


q=[q1_ra;q2_ra;q3_ra;q4_ra;q5_ra;q6_ra;q7_ra];

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
Cal_right_palm=[r_right_palm(1);r_right_palm(2);r_right_palm(3)];

end

