clc;clear all;close all;
run S5_HO_Physical_features;
global r_target T

T=0.005;
t_d=20;
n=t_d/T;


r_target=[0.277;-0.0302;-0.226];
q0=1*[0;0;0;-10*pi/180;0;0;0];

r_0=S5_HO_FK_right_palm(q0);


V_des=5;
d_des=0.001;
qdot_max=10;

power=1* (10^(-4));
Left_palm_position_power=10^(6);


tic

% u=zeros(7,n);


q=zeros(7,1);
qdot=zeros(7,1);
q(:,1)=q0(:,1);

Jha=S5_HO_Jacobians(q(:,1));
J_right_palm=Jha(1:3,1:7);
r_right_palm=S5_HO_FK_right_palm(q(:,1));



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

 d=sqrt((r_target(1)- r_right_palm(1))^2+(r_target(2)- r_right_palm(2))^2+(r_target(3)- r_right_palm(3))^2);
 d0=d;
 i=1;
f = 1;

 while  d>d_des   
    Q=power*eye(7,7); P=zeros(1,7);
    
%     upbound(1:7,1)=min(((1/T)*((pi/180)*[80;10;60;-1;90;20;20]- q(:,i))),qdot_max);
%     lowbound(1:7,1)=max(((1/T)*((pi/180)*[-110;-90;-60;-90;-90;-20;-20] - q(:,i))),-qdot_max);
    upbound(1:7,1)=min(((1/T)*((pi/180)*[80;10;60;-5;90;20;20]- q(:,i))),qdot_max);
    lowbound(1:7,1)=max(((1/T)*((pi/180)*[-110;-90;-60;-90;-90;-20;-20] - q(:,i))),-qdot_max);
%     
%     
%     upbound(1:7,1)=[inf;inf;inf;inf;inf;inf;inf];
%     lowbound(1:7,1)=-[inf;inf;inf;inf;inf;inf;inf];
    
    Q= Q+ Left_palm_position_power*(2* transpose(J_right_palm(1,:)) * J_right_palm(1,:) + 2* transpose(J_right_palm(2,:)) * J_right_palm(2,:) + 2* transpose(J_right_palm(3,:)) * J_right_palm(3,:));
    P=P + Left_palm_position_power*(-2*(Vx_right_palm)* J_right_palm(1,:) - 2*(Vy_right_palm)*J_right_palm(2,:)  - 2*(Vz_right_palm)*J_right_palm(3,:));
    
    d=sqrt((r_target(1)- r_right_palm(1))^2+(r_target(2)- r_right_palm(2))^2+(r_target(3)- r_right_palm(3))^2);
    
    
    u=quadprog(Q,transpose(P),[],[],[],[],lowbound,upbound);
    
    qdot(:,i+1)=u;
    q(:,i+1)=q(:,i) + T* qdot(:,i);
    
    
    Jha=S5_HO_Jacobians(q(:,i+1));
    J_right_palm=Jha(1:3,1:7);
    
    r_right_palm=S5_HO_FK_right_palm(q(:,i+1));
    
    
    
 % % velocity update occurs in every step toward destination, magnitude is calculated by remained time   
%     Vx_left_palm=(r_target(1)-r_left_palm(1))/((n+1-i)*T);
%     Vy_left_palm=(r_target(2)-r_left_palm(2))/((n+1-i)*T);
%     Vz_left_palm=(r_target(3)-r_left_palm(3))/((n+1-i)*T);

% velocity update occurs in every step toward destination, magnitude is V_des 
Vx_right_palm=V_des*min(i/100,1)*(atan(d/d0*10)/pi*2)^2*(r_target(1)-r_right_palm(1))/norm(r_target-r_right_palm);
Vy_right_palm=V_des*min(i/100,1)*(atan(d/d0*10)/pi*2)^2*(r_target(2)-r_right_palm(2))/norm(r_target-r_right_palm);
Vz_right_palm=V_des*min(i/100,1)*(atan(d/d0*10)/pi*2)^2*(r_target(3)-r_right_palm(3))/norm(r_target-r_right_palm);

%  % velocity is defined by fifth order polynomial, coefficients have been calculted 
%  t=i*T;
% Vx_left_palm=[5*t^4 4*t^3 3*t^2 2*t 1 0]*coef_x;
% Vy_left_palm=[5*t^4 4*t^3 3*t^2 2*t 1 0]*coef_y;
% Vz_left_palm=[5*t^4 4*t^3 3*t^2 2*t 1 0]*coef_z;
    V_x(f) = Vx_right_palm;
V_y(f) = Vy_right_palm;
V_z(f) = Vz_right_palm;
f = f+1;
      i=i+1; 
end
toc
%%
n=size(q,2);
run HO_SimulationPlot

figure();
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
% 
figure(3)
plot (1:1:length(V_z),V_x)
hold on
plot (1:1:length(V_z),V_y)
hold on
plot (1:1:length(V_z),V_z)


