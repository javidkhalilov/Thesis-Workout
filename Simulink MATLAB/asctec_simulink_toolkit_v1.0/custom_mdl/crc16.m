
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
%* Type        :   function                                                                                       *
%*                                                                                                              *
%* Circulation :   Public
%*                                                                                                              *
%* Purpose     :   calculate crc16 checksum                                                            *
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
%*  data                        data to calculate checksum                       uint8      defined by cnt  
%*
%*  cnt                         byte counter of data                             double       1x1               *
%*                                                                                                              *
%*          ----------------------------------------------------------------------------------------------------*
%*                                                                                                              *
%*  O U T P U T S :             Description                                     Type        Dim     Unit        *
%*                                                                                                              *
%*  crc16                       crc16 checksum of input data                   uint16       1x1
%*                                                                                                              *
%****************************************************************************************************************
%*  Invoked functions                                                                                           *
%*                                                                                                              *
%*  crc_update.m                                                                                                            *
%*                                                                                                              *
%****************************************************************************************************************
%*  Michael Achtelik        *   23.02.09   *                                                                     *
%****************************************************************************************************************
%*  Lastname, Firstname     * JJJJ-MON-DD *     <Action performed>                                              *
%**************************************************************************

function [crc16] = crc16(data, cnt)
crc = uint16(255); %initialize crc

for i=1:cnt 

    crc = crc_update(crc,data(i)); %update crc bytewise
    
end

crc16 = crc; 

% Note: this algorithm is similar to the following c-implementation:

% unsigned short crc16(void* data, unsigned short cnt)
%  {
%    unsigned short crc=0xff;
%    unsigned char * ptr=(unsigned char *) data;
%    int i;
% 
%    for (i=0;i<cnt;i++)
%      {
%        crc=crc_update(crc,*ptr);
%        ptr++;
%      }
%    return crc;
%    
%  }
