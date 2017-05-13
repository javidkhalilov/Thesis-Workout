P=0;
Q=0;
R=0;
Phi=0;
The=0;
Psi=-90;
U=0;
V=0;
W=0;
X=0;
Y=0;
Z=1;

w1=3900;
w2=3900;
w3=3900;
w4=3900;

IC = struct('P',(P),'Q',(Q),'R',(R),'Phi',(Phi),'The',(The),'Psi',(Psi),...
    'U',(U),'V',(V),'W',(W),'X',(X),'Y',(Y),'Z',(Z),'w1',(w1),'w2',(w2),'w3',(w3),'w4',(w4));

save('HoverV6.mat','IC')