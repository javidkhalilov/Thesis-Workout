%****************************************************************************************************************
%*                                                                                                              *
%*                                         Quadrocopter Onboard Matlab                                          *
%*                                                                                                              *
%****************************************************************************************************************
%*                                                                                                              *
%*                       L E H R S T U H L   F U E R   F L U G S Y S T E M D Y N A M I K                        *
%*                     I N S T I T U T E   O F   F L I G H T   S Y S T E M   D Y N A M I C S                    *
%*                                                                                                              *
%*                                     Technische Universitaet Muenchen (TUM)                                   *
%*                                Boltzmannstrasse 15 - D-85748 Garching - Germany                              *
%*                    Phone: +49 89 289-16081, eMail: office@fsd.mw.tum.de, Web: www.fsd.mw.tum.de              *
%*                                                                                                              *
%*   (c) 2009 by Institute of Flight System Dynamics of Technische Universitaet Muenchen, All Rights Reserved   *
%*                                                                                                              *
%****************************************************************************************************************
%*                                                                                                              *
%*                                        InitOnboardMatlab.m                                                   *
%*                                                                                                              *
%****************************************************************************************************************
%*                                                                                                              *
%* Type        :   Script                                                                                       *
%*                                                                                                              *
%* Circulation :   Public
%*                                                                                                              *
%* Purpose     :   Initialize variables for Simulink model "onboard_matlab.mdl"                                 *
%*                                                                                                              *
%* Version     :   1.1                                                                                          *
%*                                                                                                              *
%****************************************************************************************************************
%*                                                                                                              *
%* Remarks  :   Initialize variables and bus objects for Simulink model "onboard_matlab.mdl"                    *
%*                                                                                                              *
%****************************************************************************************************************
%*                                                                                                              *
%* Syntax   :   -                                                                                               *
%*                                                                                                              *
%*  I N P U T S :               Description                                     Type        Dim     Unit        *
%*                                                                                                              *
%*  -                                                                                                           *
%*                                                                                                              *
%*          ----------------------------------------------------------------------------------------------------*
%*                                                                                                              *
%*  O U T P U T S :             Description                                     Type        Dim     Unit        *
%*                                                                                                              *
%*  -                                                                                                           *
%*                                                                                                              *
%****************************************************************************************************************
%*  Invoked functions               Location inside directory structure of                                      *
%*                                                                                                              *
%*  InitOnboardMatlab_bus.m                                                                                     *
%*                                                                                                              *
%****************************************************************************************************************
%*  Achtelik, Michael       * 2009-02-23 *   initial design                                                     *
%****************************************************************************************************************
%*  Raffler, Thomas         * 2011-04-27 *   cleanup and modifications for new parameter and uart blocks        *
%****************************************************************************************************************

% onboard sampletime
Sampletime.Onboard = 0.001;

% parameter definition and calculations
Mass = 0.5;
ACC_Gravity = 9.805;


% map calculated parameters to tunable parameters 1 ... 40
uart_up_p_01 = Mass;
uart_up_p_02 = ACC_Gravity;
uart_up_p_03 = 10;
uart_up_p_04 = 5;
uart_up_p_05 = 10;
uart_up_p_06 = 12;
uart_up_p_07 = 6;
uart_up_p_08 = 12;
uart_up_p_09 = 0;
uart_up_p_10 = 0.9;  % Sinus dalgasi icin genlik (1, 0 ilef full thrust arasi)
uart_up_p_11 = 0.5; % Sinus dalgasi sifir noktasi (0.5 %50 thrust oluyor)
uart_up_p_12 = 0.1; % Sine sweep sinyali icin ilk frekans (Hz)
uart_up_p_13 = 10; % Sine sweep sinyali icin son frekans (Hz)
uart_up_p_14 = 50; % Sine sweep suresi (sn)
uart_up_p_15 = 0;
uart_up_p_16 = 0;
uart_up_p_17 = 0;
uart_up_p_18 = 0;
uart_up_p_19 = 0;
uart_up_p_20 = 0;
uart_up_p_21 = 0;
uart_up_p_22 = 0;
uart_up_p_23 = 0;
uart_up_p_24 = 0;
uart_up_p_25 = 0;
uart_up_p_26 = 0;
uart_up_p_27 = 0;
uart_up_p_28 = 0;
uart_up_p_29 = 0;
uart_up_p_30 = 0;
uart_up_p_31 = 0;
uart_up_p_32 = 0;
uart_up_p_33 = 0;
uart_up_p_34 = 0;
uart_up_p_35 = 0;
uart_up_p_36 = 0;
uart_up_p_37 = 0;
uart_up_p_38 = 0;
uart_up_p_39 = 0;
uart_up_p_40 = 0;