motor_m_g = 40; % mass of 1 motor (grams)
motor_dm_cm = 17; % distance from center of mass of the motor to the COM of
                  %the quadrotor (cm)
motor_h_cm = 3; %height of the  motor above arm (cm)
motor_r_cm = 3; %radius of a motor (cm) 
ESC_m_g = 30; %mass of 1 ESC (grams)
ESC_a_cm = 3; %width of ESC (cm)
ESC_b_cm = 7; %length of ESC (cm)
ESC_ds_cm =10;%distance from ESC COM to quad COM (cm)
HUB_m_g = 100; % hub mass (total mass-esc mass-motor mass-arm mass) (grams)
HUB_r_cm = 5; %hub radius (cm)
HUB_H_cm = 4; %hub height (cm)
arms_m_g = 30; %arm mass (grams)
arms_r_cm = 1.5; %arm width (cm)
arms_L_cm =12; %arm lenght (cm)
arms_da_cm = 5;
    
    motor_m = motor_m_g/1000;
    motor_dm = motor_dm_cm/100;
    motor_h = motor_h_cm/100;
    motor_r = motor_r_cm/100;
    ESC_m = ESC_m_g/1000;
    ESC_a = ESC_a_cm/100;
    ESC_b = ESC_b_cm/100;
    ESC_ds = ESC_ds_cm/100;
    HUB_m = HUB_m_g/1000;
    HUB_r = HUB_r_cm/100;
    HUB_H = HUB_H_cm/100;
    arms_m = arms_m_g/1000;
    arms_r = arms_r_cm/100;
    arms_L = arms_L_cm/100;
    arms_da = arms_da_cm/100;

    d = motor_dm; % The d variable is same distance as motor_dm
    
    g = 9.81; % m/s^2

mass = 0.480; % Already converted to kg

T = 0.0760; % Seconds
minThr = 5; % Just an integer
cr = 70;
b = 850;

ct = 7.6184e-8;
cq = 2.6839e-9;

Jx = 5.6e-3;
Jy = 5.6e-3;
Jz = 8.1e-3;
Jb = [Jx 0 0; 0 Jy 0; 0 0 Jz];
Jbinv = [1/Jx 0 0; 0 1/Jy 0; 0 0 1/Jz];
% dctcq matrix for "Plus" Configuration
dctcq = [0 d*ct 0 -d*ct; -d*ct 0 d*ct 0; -cq cq -cq cq];
plusConfig = 1;

% Jm (Motor Rotation Inertia for Rotating Component only)
% Mass of rotating component is 52.7% of the total mass of the motor + prop
mRC = (motor_m)*(0.527);
Jm = ((mRC)*(motor_r)^2)/2; % Jm = mr^2/2

% Saves all the variables from above into a structure called "quadModel"
quadModel = struct('g',(g),'d',(d),'mass',(mass),'ct',(ct),'cq',(cq),...
    'Jx',(Jx),'Jy',(Jy),'Jz',(Jz),'Jm',(Jm),'Jb',(Jb),'Jbinv',(Jbinv),'dctcq',(dctcq),...
    'motor_m',(motor_m),'motor_dm',(motor_dm),'motor_h',(motor_h),'motor_r',(motor_r),...
    'ESC_m',(ESC_m),'ESC_a',(ESC_a),'ESC_b',(ESC_b),'ESC_ds',(ESC_ds),...
    'HUB_m',(HUB_m),'HUB_r',(HUB_r),'HUB_H',(HUB_H),...
    'arms_m',(arms_m),'arms_r',(arms_r),'arms_L',(arms_L), 'arms_da',(arms_da),'T',(T),'minThr',(minThr),...
    'cr',(cr),'b',(b), 'plusConfig',(plusConfig));

save('quadModel.mat','quadModel')
