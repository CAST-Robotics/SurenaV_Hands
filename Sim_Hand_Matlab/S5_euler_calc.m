% function [phi,theta,sai]=S5_euler_calc(R)
% if R(2,1)==1 | R(2,1)==-1
%     phi=atan2(R(1,3),R(3,3));
% else
%     phi=atan2(-R(3,1),R(1,1));
% end
% theta=asin(R(2,1));
% if R(2,1)==1 | R(2,1)==-1
% sai=0;
% else
% sai=atan2(-R(2,3),R(2,2));
% end
% end
    
 function [phi,theta,sai]=S5_euler_calc(R)
 
 if R(2,1)<1 && R(2,1)>-1
     theta=asin(R(2,1));
     phi=atan2(-R(3,1),R(1,1));
     sai=atan2(-R(2,3),R(2,2));
 elseif R(2,1)==-1 
     theta=-pi/2;
     phi=-atan2(R(3,2),R(3,3));
     sai=0;
 else
     theta=+pi/2;
     phi=atan2(R(3,2),R(3,3));
     sai=0;


     
 
 end