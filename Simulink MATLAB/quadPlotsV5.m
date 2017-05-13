function [] = quadPlots(yout,tout)
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%


close all; clc;
[~,column] = size(yout);
if column==26
    PC = true;
else PC = false;
end
fS=14;
A = yout;
T = tout;
t = T;
P = A(:,1); % rad/s for now, converted before plotting
Q = A(:,2);
R = A(:,3);
Phi   = A(:,4)*180/pi; % In radians for now, converted before plotting
Theta = A(:,5)*180/pi;
Psi   = A(:,6)*180/pi;

U = A(:,7);%*3.2808399; 
V = A(:,8);%*3.2808399;
W = A(:,9);%*3.2808399;
X = A(:,10);%*3.2808399; 
Y = A(:,11);%*3.2808399;
Z = A(:,12);%*3.2808399;

w1 = A(:,13);
w2 = A(:,14);
w3 = A(:,15);
w4 = A(:,16);
mc1 = A(:,17);
mc2 = A(:,18);
mc3 = A(:,19);
mc4 = A(:,20);
if (PC==true)
Phi_cmd = A(:,21)*180/pi;
Theta_cmd = A(:,22)*180/pi;
Psi_cmd = A(:,23)*180/pi;
Z_cmd   = A(:,24);%*3.2808399;
X_cmd = A(:,25);%*3.2808399;
Y_cmd = A(:,26);%*3.2808399;
end
% Plots ___________________________________________________________________
figure ('Units', 'pixels', ...
    'Position', [100 100 500 375]);
subplot(3,1,1)
plot(T,P,'b')
xlabel('Time (s)','FontSize',fS)
y1=ylabel('Angular Velocity (deg/sec)','FontSize',fS);
set(y1, 'Units', 'Normalized', 'Position', [-0.05, 0.5, 0]);
xlim([min(t) max(t)])
title('p','FontSize',fS)
grid on

subplot(3,1,2)
plot(T,Q,'r')
xlabel('Time (s)','FontSize',fS)
y2=ylabel('Angular Velocity (deg/sec)','FontSize',fS);
set(y2, 'Units', 'Normalized', 'Position', [-0.05, 0.5, 0]);
xlim([min(t) max(t)])
title('q','FontSize',fS)
grid on

subplot(3,1,3)
plot(T,R,'g')
xlabel('Time (s)','FontSize',fS)
y3=ylabel('Angular Velocity (deg/sec)','FontSize',fS);
set(y3, 'Units', 'Normalized', 'Position', [-0.05, 0.5, 0]);
xlim([min(t) max(t)])
title('r','FontSize',fS)
grid on

figure ('Units', 'pixels', ...
    'Position', [100 100 500 375]);
subplot(3,1,1)
plot(T,Phi,'b')
% hold on
% plot(T,Phi_cmd,'k--','LineWidth',1)
% hold off
xlabel('Time (s)','FontSize',fS)
y4=ylabel('Angle (deg)','FontSize',fS);
set(y4, 'Units', 'Normalized', 'Position', [-0.05, 0.5, 0]);
xlim([min(t) max(t)])
title('Phi','FontSize',fS)
grid on
 
subplot(3,1,2)
plot(T,Theta,'r')
% hold on
% plot(T,Theta_cmd,'k--','LineWidth',1)
% hold off
xlabel('Time (s)','FontSize',fS)
y5=ylabel('Angle(deg)','FontSize',fS);
set(y5, 'Units', 'Normalized', 'Position', [-0.05, 0.5, 0]);
xlim([min(t) max(t)])
title('Theta','FontSize',fS)
grid on

subplot(3,1,3)
plot(T,Psi,'g')
% hold on
% plot(T,Psi_cmd,'k--','LineWidth',1)
% hold off
xlabel('Time (s)','FontSize',fS)
y6=ylabel('Angle (deg)','FontSize',fS);
set(y6, 'Units', 'Normalized', 'Position', [-0.05, 0.5, 0]);
xlim([min(t) max(t)])
title('Psi','FontSize',fS)
grid on

figure ('Units', 'pixels', ...
    'Position', [100 100 500 375]);
subplot(3,1,1)
plot(T,U,'b')
xlabel('Time (s)','FontSize',fS)
y7=ylabel('Velocity (m/s)','FontSize',fS);
set(y7, 'Units', 'Normalized', 'Position', [-0.05, 0.5, 0]);
xlim([min(t) max(t)])
title('U','FontSize',fS)
grid on

subplot(3,1,2)
plot(T,V,'r')
xlabel('Time (s)','FontSize',fS)
y8=ylabel('Velocity (m/s)','FontSize',fS);
set(y8, 'Units', 'Normalized', 'Position', [-0.05, 0.5, 0]);
xlim([min(t) max(t)])
title('V','FontSize',fS)
grid on

subplot(3,1,3)
plot(T,W,'g')
xlabel('Time (s)','FontSize',fS)
y9=ylabel('Velocity (m/s)','FontSize',fS);
set(y9, 'Units', 'Normalized', 'Position', [-0.05, 0.5, 0]);
xlim([min(t) max(t)])
title('W','FontSize',fS)
grid on

figure('Units', 'pixels', ...
    'Position', [100 100 500 375]);
subplot(3,1,1)
plot(T,X,'b')
if (PC==true)
hold on
plot(T,X_cmd,'k--','LineWidth',1)
hold off
end
xlabel('Time (s)','FontSize',fS)
y10=ylabel('Position (m)','FontSize',fS);
set(y10, 'Units', 'Normalized', 'Position', [-0.05, 0.5, 0]);
xlim([min(t) max(t)])
title('X','FontSize',fS)
grid on

subplot(3,1,2)
plot(T,Y,'r')
if (PC==true)
hold on
plot(T,Y_cmd,'k--','LineWidth',1)
hold off
end
xlabel('Time (s)','FontSize',fS)
y11=ylabel('Position (m)','FontSize',fS);
set(y11, 'Units', 'Normalized', 'Position', [-0.05, 0.5, 0]);
xlim([min(t) max(t)])
title('Y','FontSize',fS)
grid on

subplot(3,1,3)
plot(T,Z,'g')
% hold on
% plot(T,Z_cmd,'k--','LineWidth',1)
% hold off
xlabel('Time (s)','FontSize',fS)
y12=ylabel('Position (m)','FontSize',fS);
set(y12, 'Units', 'Normalized', 'Position', [-0.05, 0.5, 0]);
xlim([min(t) max(t)])
title('Z','FontSize',fS)
grid on

figure ('Units', 'pixels', ...
    'Position', [100 100 500 375]);
plot(X,Y,'r');
xlabel('X Position (m)','FontSize',fS);
y13=ylabel('Y Position (m)','FontSize',fS);
set(y13, 'Units', 'Normalized', 'Position', [-0.05, 0.5, 0]);
title('X and Y Positions of Quadrotor in 10x10 Room','FontSize',fS)
xlim([-5 5])
ylim([-5 5])
grid on

figure ('Units', 'pixels', ...
    'Position', [100 100 500 375]);

scatter3(X,Y,Z,25);
%view(10,15)
title('X,Y and Z Positions of Quadrotor in 10x10 Room','FontSize',fS);
xlabel('X Position (m)','FontSize',fS);
y14=ylabel('Y Position (m)','FontSize',fS);
z14=zlabel('Z Position (m)','FontSize',fS);
%set(y14, 'Units', 'Normalized', 'Position', [-0.05, 0.5, 0]);
%set(z14, 'Units', 'Normalized', 'Position', [-0.05, 0.5, 0]);
xlim([-5 5])
ylim([-5 5])
zlim([0 2])
grid on






% Create a new figure for motor speeds
figure ('Units', 'pixels', ...
    'Position', [100 100 500 375]);
subplot(4,1,1)
[AX,H1,H2] = plotyy(T,mc1,T,w1);
x1=xlabel('Time (s)','FontSize',fS);
%set(x1, 'Units', 'Normalized', 'Position', [0, 0.01, 0]);
ylabel(AX(1),'Throttle Cmd (%)','FontSize',fS)
ylabel(AX(2),'Motor RPM','FontSize',fS)
xlim(AX(1),[min(T) max(T)])
xlim(AX(2),[min(T) max(T)])
title('Motor 1','FontSize',fS)
grid on

subplot(4,1,2)
[AX,H1,H2] = plotyy(T,mc2,T,w2);
x2=xlabel('Time (s)','FontSize',fS);
%set(x2, 'Units', 'Normalized', 'Position', [0,-0.01, 0]);
ylabel(AX(1),'Throttle Cmd (%)','FontSize',fS)
ylabel(AX(2),'Motor RPM','FontSize',fS)
xlim(AX(1),[min(T) max(T)])
xlim(AX(2),[min(T) max(T)])
title('Motor 2','FontSize',fS)
grid on

subplot(4,1,3)
[AX,H1,H2] = plotyy(T,mc3,T,w3);
x3=xlabel('Time (s)','FontSize',fS);
%set(x3, 'Units', 'Normalized', 'Position', [0, 0.01, 0]);
ylabel(AX(1),'Throttle Cmd (%)','FontSize',fS)
ylabel(AX(2),'Motor RPM','FontSize',fS)
xlim(AX(1),[min(T) max(T)])
xlim(AX(2),[min(T) max(T)])
title('Motor 3','FontSize',fS)
grid on

subplot(4,1,4)
[AX,H1,H2] = plotyy(T,mc4,T,w4);
xlabel('Time (s)','FontSize',fS)
ylabel(AX(1),'Throttle Cmd (%)','FontSize',fS)
ylabel(AX(2),'Motor RPM','FontSize',fS)
xlim(AX(1),[min(T) max(T)])
xlim(AX(2),[min(T) max(T)])
title('Motor 4','FontSize',fS)
grid on
end
