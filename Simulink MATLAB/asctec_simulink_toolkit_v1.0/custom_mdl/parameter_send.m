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
%*                                              parameter_send.m                                                *
%*                                                                                                              *
%****************************************************************************************************************
%*                                                                                                              *
%* Type        :   Script                                                                                       *
%* Circulation :   Public                                                                                       *
%* Purpose     :   send parameters to the quadrocpter                                                           *
%* Version     :   1.1                                                                                          *
%*                                                                                                              *
%****************************************************************************************************************
%*                                                                                                              *
%* Remarks     :   Before you run this function use this command to create the comport object in matlab:        *
%*                 com = serial('COM"your comport"', 'BaudRate', 250000)                                        *
%*                                                                                                              *
%*                 Note: parameters will get lost after the next reboot unless you store them permanently with  *
%*                 the script 'parameter_store_onboard.m'                                                       *
%*                                                                                                              *
%****************************************************************************************************************
%*                                                                                                              *
%* Syntax   :   -                                                                                               *
%*                                                                                                              *
%*  I N P U T S :               Description                                     Type        Dim     Unit        *
%*                                                                                                              *
%*  -                                                                                                           *
%*          ----------------------------------------------------------------------------------------------------*
%*                                                                                                              *
%*  O U T P U T S :             Description                                     Type        Dim     Unit        *
%*                                                                                                              *
%*  -                                                                                                           *
%*                                                                                                              *
%****************************************************************************************************************
%*  Invoked functions                                                                                           *
%*                                                                                                              *
%*  crc16.m                                                                                                     *
%*                                                                                                              *
%****************************************************************************************************************
%*  Achtelik, Michael       * 2009-02-23 *   initial design                                                     *
%****************************************************************************************************************
%*  Raffler, Thomas         * 2011-04-27 *   modifications for new parameter blocks, renamed serial             *
%****************************************************************************************************************
%*  Achtelik, Michae        * 2012-06-15 *   modifications for new SDK Version and sample controller            *
%****************************************************************************************************************

%InitOnboardMatlab;

%% prepare data
%create the parameter vector
send=[...
uart_up_p_01 uart_up_p_02 uart_up_p_03 uart_up_p_04 uart_up_p_05 uart_up_p_06 uart_up_p_07 uart_up_p_08 uart_up_p_09 uart_up_p_10 ...
uart_up_p_11 uart_up_p_12 uart_up_p_13 uart_up_p_14 uart_up_p_15 uart_up_p_16 uart_up_p_17 uart_up_p_18 uart_up_p_19 uart_up_p_20 ...
uart_up_p_21 uart_up_p_22 uart_up_p_23 uart_up_p_24 uart_up_p_25 uart_up_p_26 uart_up_p_27 uart_up_p_28 uart_up_p_29 uart_up_p_30 ...
uart_up_p_31 uart_up_p_32 uart_up_p_33 uart_up_p_34 uart_up_p_35 uart_up_p_36 uart_up_p_37 uart_up_p_38 uart_up_p_39 uart_up_p_40...
]; 

%scale and limit parameters for transmission. Scaling must be identic to settings in the onboard matlab code/blocks!
for j=1:40
    send(j)=(send(j))*2^16;
    if send(j) > 2^31-1 %saturate on overflow
       send(j) = 2^31-1;
    end
    if send(j) < -2^31 %saturate on underflow
       send(j) = -2^31;
    end
end
    
send=int32(send); %cast to integer for transmission

for j=1:40 %cast for checksum calculation
   tmp=typecast(send(j),'uint8'); 
   send_crc((j-1)*4+1:(j-1)*4+4)=tmp;
end
crc=uint32(crc16(send_crc,160)); %calculate checksum
start=int8('>*>p'); %define Startstring

%% send over serial
fopen(com); %open Comport

fwrite(com,int8('>*>h'),'uint8'); % stop debug transmission
pause(0.2);
%send data 1 times
for k=1:1
    %send startstring
    fwrite(com,start,'uint8');
    %send data
    fwrite(com,send(1:10),'int32'); 
    fwrite(com,send(11:20),'int32'); 
    pause(0.1);
    fwrite(com,send(21:30),'int32'); 
    fwrite(com,send(31:40),'int32');
    %send checksum
    fwrite(com,crc,'uint32');  
    %pause(0.2);
end

fclose(com); %close comport