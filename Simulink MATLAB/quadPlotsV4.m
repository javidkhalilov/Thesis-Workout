function [] = quadPlots(yout,tout)
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%


close all; clc;
[~,column] = size(yout);
if column==26
    PC = true;
else PC = false;
end
A = yout;
T = tout;
t = T;
P = A(:,1); % rad/s for now, converted before plotting
Q = A(:,2);
R = A(:,3);
Phi   = A(:,4)*180/pi; % In radians for now, converted before plotting
Theta = A(:,5)*180/pi;
Psi   = A(:,6)*180/pi;
Phi_cmd = A(:,21)*180/pi;
Theta_cmd = A(:,22)*180/pi;
Psi_cmd = A(:,23)*180/pi;
U = A(:,7);%*3.2808399; 
V = A(:,8);%*3.2808399;
W = A(:,9);%*3.2808399;
X = A(:,10);%*3.2808399; 
Y = A(:,11);%*3.2808399;
Z = A(:,12);%*3.2808399;
Z_cmd   = A(:,24);%*3.2808399;
w1 = A(:,13);
w2 = A(:,14);
w3 = A(:,15);
w4 = A(:,16);
mc1 = A(:,17);
mc2 = A(:,18);
mc3 = A(:,19);
mc4 = A(:,20);
if (PC==true)
X_cmd = A(:,25);%*3.2808399;
Y_cmd = A(:,26);%*3.2808399;
end
% Plots ___________________________________________________________________
figure ('Units', 'pixels', ...
    'Position', [100 100 500 375]);
subplot(3,1,1)
plot(T,P,'b')
xlabel('Time (s)')
y1=ylabel('Angular Velocity (deg/sec)');
set(y1, 'Units', 'Normalized', 'Position', [-0.05, 0.5, 0]);
xlim([min(t) max(t)])
title('p')
grid on

subplot(3,1,2)
plot(T,Q,'r')
xlabel('Time (s)')
y2=ylabel('Angular Velocity (deg/sec)');
set(y2, 'Units', 'Normalized', 'Position', [-0.05, 0.5, 0]);
xlim([min(t) max(t)])
title('q')
grid on

subplot(3,1,3)
plot(T,R,'g')
xlabel('Time (s)')
y3=ylabel('Angular Velocity (deg/sec)');
set(y3, 'Units', 'Normalized', 'Position', [-0.05, 0.5, 0]);
xlim([min(t) max(t)])
title('r')
grid on

figure ('Units', 'pixels', ...
    'Position', [100 100 500 375]);
subplot(3,1,1)
plot(T,Phi,'b')
hold on
plot(T,Phi_cmd,'k--','LineWidth',1)
hold off
xlabel('Time (s)')
y4=ylabel('Angle (deg)');
set(y4, 'Units', 'Normalized', 'Position', [-0.05, 0.5, 0]);
xlim([min(t) max(t)])
title('Phi')
grid on
 
subplot(3,1,2)
plot(T,Theta,'r')
hold on
plot(T,Theta_cmd,'k--','LineWidth',1)
hold off
xlabel('Time (s)')
y5=ylabel('Angle(deg)');
set(y5, 'Units', 'Normalized', 'Position', [-0.05, 0.5, 0]);
xlim([min(t) max(t)])
title('Theta')
grid on

subplot(3,1,3)
plot(T,Psi,'g')
hold on
plot(T,Psi_cmd,'k--','LineWidth',1)
hold off
xlabel('Time (s)')
y6=ylabel('Angle (deg)');
set(y6, 'Units', 'Normalized', 'Position', [-0.05, 0.5, 0]);
xlim([min(t) max(t)])
title('Psi')
grid on

figure ('Units', 'pixels', ...
    'Position', [100 100 500 375]);
subplot(3,1,1)
plot(T,U,'b')
xlabel('Time (s)')
y7=ylabel('Velocity (m/s)');
set(y7, 'Units', 'Normalized', 'Position', [-0.05, 0.5, 0]);
xlim([min(t) max(t)])
title('U')
grid on

subplot(3,1,2)
plot(T,V,'r')
xlabel('Time (s)')
y8=ylabel('Velocity (m/s)');
set(y8, 'Units', 'Normalized', 'Position', [-0.05, 0.5, 0]);
xlim([min(t) max(t)])
title('V')
grid on

subplot(3,1,3)
plot(T,W,'g')
xlabel('Time (s)')
y9=ylabel('Velocity (m/s)');
set(y9, 'Units', 'Normalized', 'Position', [-0.05, 0.5, 0]);
xlim([min(t) max(t)])
title('W')
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
xlabel('Time (s)')
y10=ylabel('Position (m)');
set(y10, 'Units', 'Normalized', 'Position', [-0.05, 0.5, 0]);
xlim([min(t) max(t)])
title('X')
grid on

subplot(3,1,2)
plot(T,Y,'r')
if (PC==true)
hold on
plot(T,Y_cmd,'k--','LineWidth',1)
hold off
end
xlabel('Time (s)')
y11=ylabel('Position (m)');
set(y11, 'Units', 'Normalized', 'Position', [-0.05, 0.5, 0]);
xlim([min(t) max(t)])
title('Y')
grid on

subplot(3,1,3)
plot(T,Z,'g')
hold on
plot(T,Z_cmd,'k--','LineWidth',1)
hold off
xlabel('Time (s)')
y12=ylabel('Position (m)');
set(y12, 'Units', 'Normalized', 'Position', [-0.05, 0.5, 0]);
xlim([min(t) max(t)])
title('Z')
grid on

% Create a new figure for motor speeds
figure ('Units', 'pixels', ...
    'Position', [100 100 500 375]);
subplot(4,1,1)
[AX,H1,H2] = plotyy(T,mc1,T,w1);
x1=xlabel('Time (s)');
%set(x1, 'Units', 'Normalized', 'Position', [0, 0.01, 0]);
ylabel(AX(1),'Motor Throttle Command (%)')
ylabel(AX(2),'Motor Speed (RPM)')
xlim(AX(1),[min(T) max(T)])
xlim(AX(2),[min(T) max(T)])
title('Motor 1')
grid on

subplot(4,1,2)
[AX,H1,H2] = plotyy(T,mc2,T,w2);
x2=xlabel('Time (s)');
%set(x2, 'Units', 'Normalized', 'Position', [0,-0.01, 0]);
ylabel(AX(1),'Motor Throttle Command (%)')
ylabel(AX(2),'Motor Speed (RPM)')
xlim(AX(1),[min(T) max(T)])
xlim(AX(2),[min(T) max(T)])
title('Motor 2')
grid on

subplot(4,1,3)
[AX,H1,H2] = plotyy(T,mc3,T,w3);
x3=xlabel('Time (s)');
%set(x3, 'Units', 'Normalized', 'Position', [0, 0.01, 0]);
ylabel(AX(1),'Motor Throttle Command (%)')
ylabel(AX(2),'Motor Speed (RPM)')
xlim(AX(1),[min(T) max(T)])
xlim(AX(2),[min(T) max(T)])
title('Motor 3')
grid on

subplot(4,1,4)
[AX,H1,H2] = plotyy(T,mc4,T,w4);
xlabel('Time (s)')
ylabel(AX(1),'Motor Throttle Command (%)')
ylabel(AX(2),'Motor Speed (RPM)')
xlim(AX(1),[min(T) max(T)])
xlim(AX(2),[min(T) max(T)])
title('Motor 4')
grid on
end
