function [ H ] = trans(axis, d)
if isempty(axis)
    H=[1 0 0 d(1);
        0 1 0 d(2);
        0 0 1 d(3);
        0 0 0 1];
else
    if axis==1
        H=[1 0 0 d;
            0 1 0 0;
            0 0 1 0;
            0 0 0 1];
    elseif axis==2
        H=[1 0 0 0;
            0 1 0 d;
            0 0 1 0;
            0 0 0 1];
    elseif axis==3
        H=[1 0 0 0;
            0 1 0 0;
            0 0 1 d;
            0 0 0 1];
    end
end
% if and(dim~=3,dim~=4)
%     wrong dimension
%     stop
% end
% Hd=H(1:dim,1:dim);
end

