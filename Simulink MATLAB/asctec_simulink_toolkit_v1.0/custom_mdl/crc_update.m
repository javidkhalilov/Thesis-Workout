%****************************************************************************************************************
%*                                                                                                              *
%*                                              Quadrocopter Onboard Matlab                                     *
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
%*                                             crc16.m                                                    *
%*                                                                                                              *
%****************************************************************************************************************
%*                                                                                                              *
%* Type        :   function                                                                                     *
%*                                                                                                              *
%* Circulation :   Public
%*                                                                                                              *
%* Purpose     :   update crc checksum                                                                          *
%*                                                                                                              *
%* Version     :   1.0                                                                                          *
%*                                                                                                              *
%****************************************************************************************************************
%*                                                                                                              *
%* Remarks  :                                                                                                   *
%*                                                                                                              *
%****************************************************************************************************************
%*                                                                                                              *
%* Syntax   :   -                                                                                               *
%*                                                                                                              *
%*  I N P U T S :               Description                                     Type        Dim                 *
%*                                                                                                              *
%*  data                        data to update checksum                        uint8        1x1  
%*
%*  crc                         checksum to update                             uint16        1x1                 *
%*                                                                                                              *
%*          ----------------------------------------------------------------------------------------------------*
%*                                                                                                              *
%*  O U T P U T S :             Description                                     Type        Dim     Unit        *
%*                                                                                                              *
%*    out                     updated crc16 checksum                            uint16       1x1
%*                                                                                                              *
%****************************************************************************************************************
%*  Invoked functions                                                                                           *
%*                                                                                                              *
%*                                                                                                              *
%*                                                                                                              *
%****************************************************************************************************************
%*  Michael Achtelik        *   23.02.09   *                                                                    *
%****************************************************************************************************************
%*  Lastname, Firstname     * JJJJ-MON-DD *     <Action performed>                                              *
%**************************************************************************

function [out] = crc_update(crc, data)
 
 tmp = bitand(crc,uint16(255));
 data = bitxor(uint8(data), uint8(tmp));
 data = bitxor(data,bitshift(data, 4));

 tmp = bitand(bitshift(crc,-8),uint16(255));
 tmp = bitor(uint16(bitshift(uint16(data),8)), uint16(tmp));
 tmp = bitxor(uint16(tmp), uint16(bitshift(data,-4)));
 out = bitxor(uint16(tmp), uint16(bitshift(uint16(data),3)));
 
end


% Note: this algorithm is similar to the following c-implementation:

% unsigned short crc_update (unsigned short crc, unsigned char data)
%      {
%          data ^= (crc & 0xff);
%          data ^= data << 4;
% 
%          return ((((unsigned short )data << 8) | ((crc>>8)&0xff)) ^ (unsigned char )(data >> 4)
%                  ^ ((unsigned short )data << 3));
%      }
 

 
 