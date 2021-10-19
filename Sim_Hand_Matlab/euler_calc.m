function [phi,theta,sai]=euler_calc(R)
theta = acos(R(3,3));
if abs(sin(theta))>1e-6
    phi=acos(R(3,2)/(-sin(theta)));
    sai=acos(R(2,3)/sin(theta));
else
    sai=acos(R(1,1));
    phi=0;
end
end
    
