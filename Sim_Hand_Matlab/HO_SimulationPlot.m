% close all
global T_step q0
global m_h m_unih m_th m_sh m_unia m_foot 
global m_pl m1_a m2_a m1_tr m2_tr 
global L_pl L_inth L_th L_sh L_ankle L1_tr L2_tr L_shd L1_a L2_a r_target
global angle_fix_shd angle_fix_elbow
global L_arm L1_forearm L2_forearm L_palm T

figure

V=q;

q1_ra=V(1,:);
q2_ra=V(2,:);
q3_ra=V(3,:);
q4_ra=V(4,:);
q5_ra=V(5,:);
q6_ra=V(6,:);
q7_ra=V(7,:);


%% Right hand transition matrices
P_arm_ra = trans(3,-L_arm);
P1_forearm_ra= trans(3,-L1_forearm); 
P2_forearm_ra= trans(3,-L2_forearm); 
P_palm_ra = trans(3,-L_palm); 

k=10;
%% actually plotting! yay!!     :|
c=4;
sb=1;
for i=1:5:n
%% Pelvis rotation and transmission
hold off
tic
%% Right hand rotation matrices
R1_fix_shd=rot(1,-angle_fix_shd,4);
R1_ra = rot(2,q1_ra(i),4);
R2_ra = rot(1,q2_ra(i),4);
R3_ra = rot(3,q3_ra(i),4);
R4_ra = rot(2,q4_ra(i),4);
R5_ra = rot(3,q5_ra(i),4);
R6_ra = rot(1,q6_ra(i),4);
R7_ra = rot(2,q7_ra(i),4);

%% needed points positions
r_sh_ra=[0;0;0];
r_elbow_ra=R1_fix_shd*R1_ra*R2_ra*R3_ra*P_arm_ra*R4_ra*[0;0;0;1];
r_wrist_ra=R1_fix_shd*R1_ra*R2_ra*R3_ra*P_arm_ra*R4_ra*P1_forearm_ra*R5_ra*P2_forearm_ra*R6_ra*R7_ra*[0;0;0;1];
r_palm_ra=R1_fix_shd*R1_ra*R2_ra*R3_ra*P_arm_ra*R4_ra*P1_forearm_ra*R5_ra*P2_forearm_ra*R6_ra*R7_ra*[0;0;0;1];


r_palm_a=R1_fix_shd*R1_ra*R2_ra*R3_ra*P_arm_ra*R4_ra*P1_forearm_ra*R5_ra*P2_forearm_ra*R6_ra*R7_ra*trans([],[0.04;0;-0.00])*[0;0;0;1];
r_palm_b=R1_fix_shd*R1_ra*R2_ra*R3_ra*P_arm_ra*R4_ra*P1_forearm_ra*R5_ra*P2_forearm_ra*R6_ra*R7_ra*trans([],[0.04;0;-0.1])*[0;0;0;1];
r_palm_c=R1_fix_shd*R1_ra*R2_ra*R3_ra*P_arm_ra*R4_ra*P1_forearm_ra*R5_ra*P2_forearm_ra*R6_ra*R7_ra*trans([],[-0.04;0;-0.1])*[0;0;0;1];
r_palm_d=R1_fix_shd*R1_ra*R2_ra*R3_ra*P_arm_ra*R4_ra*P1_forearm_ra*R5_ra*P2_forearm_ra*R6_ra*R7_ra*trans([],[-0.04;0;-0.0])*[0;0;0;1];

% r_finger1_1=R1_fix_shd*R1_ra*R2_fix_shd*R2_ra*R3_ra*P_arm_ra*R4_ra*R5_ra*P_forearm_ra*R6_ra*R7_ra*trans([],[0.02;0;-0.12])*trans([],[0;0;-0.05])*[0;0;0;1];
% r_finger1_2=R1_fix_shd*R1_ra*R2_fix_shd*R2_ra*R3_ra*P_arm_ra*R4_ra*R5_ra*P_forearm_ra*R6_ra*R7_ra*trans([],[0.02;0;-0.12])*trans([],[0;0;-0.05])*trans([],[0;0;-0.05])*[0;0;0;1];
% 
% r_finger2_1=R1_fix_shd*R1_ra*R2_fix_shd*R2_ra*R3_ra*P_arm_ra*R4_ra*R5_ra*P_forearm_ra*R6_ra*R7_ra*trans([],[0.02;0;-0.12])*trans([],[-0.01;0;-0.06])*[0;0;0;1];
% r_finger2_2=R1_fix_shd*R1_ra*R2_fix_shd*R2_ra*R3_ra*P_arm_ra*R4_ra*R5_ra*P_forearm_ra*R6_ra*R7_ra*trans([],[0.02;0;-0.12])*trans([],[-0.01;0;-0.06])*trans([],[0;0;-0.06])*[0;0;0;1];
% 
% r_finger3_1=R1_fix_shd*R1_ra*R2_fix_shd*R2_ra*R3_ra*P_arm_ra*R4_ra*R5_ra*P_forearm_ra*R6_ra*R7_ra*trans([],[0.02;0;-0.12])*trans([],[-0.02;0;-0.04])*[0;0;0;1];
% r_finger3_2=R1_fix_shd*R1_ra*R2_fix_shd*R2_ra*R3_ra*P_arm_ra*R4_ra*R5_ra*P_forearm_ra*R6_ra*R7_ra*trans([],[0.02;0;-0.12])*trans([],[-0.02;0;-0.04])*trans([],[0;0;-0.04])*[0;0;0;1];

%% plotting 


plot3([r_sh_ra(1) r_elbow_ra(1)],[r_sh_ra(2) r_elbow_ra(2)],[r_sh_ra(3) r_elbow_ra(3)],'Color',[1-0.16*c,1-0.16*c,1-0.16*c],'LineWidth',2);
hold on
grid on
xlabel('x');ylabel('y');zlabel('z');
plot3([r_palm_a(1) r_palm_b(1) r_palm_c(1) r_palm_d(1) r_palm_a(1)],[r_palm_a(2) r_palm_b(2) r_palm_c(2) r_palm_d(2) r_palm_a(2)],[r_palm_a(3) r_palm_b(3) r_palm_c(3) r_palm_d(3) r_palm_a(3)],'r','LineWidth',1.5);
plot3([0 0 0 0 0],[0.05 0.05 0.35 0.35 0.05],[0 -0.6 -0.6 0 0],'Color',[1-0.16*c,1-0.16*c,1-0.16*c],'LineWidth',1.5);
plot3([r_elbow_ra(1) r_wrist_ra(1)],[r_elbow_ra(2) r_wrist_ra(2)],[r_elbow_ra(3) r_wrist_ra(3)],'Color',[1-0.16*c,1-0.16*c,1-0.16*c],'LineWidth',2);
% plot3([r_wrist_ra(1) r_palm_ra(1)],[r_wrist_ra(2) r_palm_ra(2)],[r_wrist_ra(3) r_palm_ra(3)],'Color',[1-0.16*c,1-0.16*c,1-0.16*c],'LineWidth',2);

% plot3([r_palm_b(1) r_finger1_1(1)],[r_palm_b(2) r_finger1_1(2)],[r_palm_b(3) r_finger1_1(3)],'Color',[0 0 1],'LineWidth',1);
% plot3([r_finger1_1(1) r_finger1_2(1)],[r_finger1_1(2) r_finger1_2(2)],[r_finger1_1(3) r_finger1_2(3)],'Color',[0 0 1],'LineWidth',1);
% 
% plot3([r_palm_b(1)-0.01 r_finger2_1(1)],[r_palm_b(2) r_finger2_1(2)],[r_palm_b(3) r_finger2_1(3)],'Color',[0 0 1],'LineWidth',1);
% plot3([r_finger2_1(1) r_finger2_2(1)],[r_finger2_1(2) r_finger2_2(2)],[r_finger2_1(3) r_finger2_2(3)],'Color',[0 0 1],'LineWidth',1);
% 
% plot3([r_palm_b(1)-0.02 r_finger3_1(1)],[r_palm_b(2) r_finger3_1(2)],[r_palm_b(3) r_finger3_1(3)],'Color',[0 0 1],'LineWidth',1);
% plot3([r_finger3_1(1) r_finger3_2(1)],[r_finger3_1(2) r_finger3_2(2)],[r_finger3_1(3) r_finger3_2(3)],'Color',[0 0 1],'LineWidth',1);


% % r=0.03; % some radius
% % color=[0 1 0]; % red color
% % t=linspace(0,2*pi);
% % circle=fill(r_target(1)+r*cos(t),r_target(2)+r*sin(t),[0,1,0]);


plot3([r_sh_ra(1)],[r_sh_ra(2)],[r_sh_ra(3)],'b.','MarkerSize',20)
plot3([r_elbow_ra(1)],[r_elbow_ra(2)],[r_elbow_ra(3)],'b.','MarkerSize',20)
plot3([r_wrist_ra(1)],[r_wrist_ra(2)],[r_wrist_ra(3)],'b.','MarkerSize',20)
plot3([r_palm_ra(1)],[r_palm_ra(2)],[r_palm_ra(3)],'b.','MarkerSize',20)

%  if i<(n/2)
%         r_target=[0.4;0.2;0.1];
%     else
%         r_target=[0.5;-0.1;-0.3];
%     end
%     

%  plot3([r_target(1)],[r_target(2)],[r_target(3)],'c.','MarkerSize',20)
[x,y,z] = cylinder(0.03);
z(2, :) = 0.2;
h=surf(x+r_target(1),y+r_target(2)+0.03,z+r_target(3)-0.1,'EdgeColor','k','facecolor',[1 0 1]);


% view(161,14);
% view(28,20);
% view(0,0);
view(20,20);

axis(0.8*[-0.3 0.8 -.3 .5 -1 0.5],'square')
axis square
   %  axis off
     %grid off
  %   figure(gcf)
     drawnow
      
%    hold on
%pause(0.1);
sb=sb+1;
%c=c+3;
hold off
pause(T-toc)
end
