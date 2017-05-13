%****************************************************************************************************************
%*                                                                                                              *
%*                                           Quadrocopter Onboard Matlab                                        *
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
%*   (c) 2011 by Institute of Flight System Dynamics of Technische Universitaet Muenchen, All Rights Reserved   *
%*                                                                                                              *
%****************************************************************************************************************
%*                                                                                                              *
%*                                           parameter_store_onboard.m                                          *
%*                                                                                                              *
%****************************************************************************************************************
%*                                                                                                              *
%* Type        :   Script                                                                                       *
%* Circulation :   Public                                                                                       *
%* Purpose     :   store (already loaded) parameters on the quadrocpter                                         *
%* Version     :   1.1                                                                                          *
%*                                                                                                              *
%****************************************************************************************************************
%*                                                                                                              *
%* Remarks     :   Before you run this function use this command to create the comport object in matlab:        *
%*                 com = serial('COM"your comport"', 'BaudRate', 57600)                                         *
%*                                                                                                              *
%*                 Note: Don't store parameters in flight. The command takes about 2 seconds!                   *
%*                 You can store parameters on the LPC about 2000 times. Don't store unless you really have to! *
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
%*  Invoked functions                                                                                           *
%*                                                                                                              *
%*  -                                                                                                           *
%*                                                                                                              *
%****************************************************************************************************************
%*  Michael Achtelik        * 2009-02-23 *   initial design                                                     *
%****************************************************************************************************************
%*  Raffler, Thomas         * 2011-04-27 *   renamed file and serial object, updated comments                   *
%****************************************************************************************************************

fopen(com); %open comport

start=int8([62 42 62 115]); %define store command by startstring and descriptor
fwrite(com,start,'uint8'); %send command

fclose(com); %close comport