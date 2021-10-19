function [ Rd ] = rot( axis, q, dim)
if axis==1
    R=[1 0 0 0;0 cos(q) -sin(q) 0;0 sin(q) cos(q) 0;0 0 0 1];
elseif axis==2
    R=[cos(q) 0 sin(q) 0;0 1 0 0;-sin(q) 0 cos(q) 0;0 0 0 1];
elseif axis==3
    R=[cos(q) -sin(q) 0 0;sin(q) cos(q) 0 0;0 0 1 0;0 0 0 1];
else
    wrong axis
    stop
end
if and(dim~=3,dim~=4)
    wrong dimension
    stop
end
Rd=R(1:dim,1:dim);
end

