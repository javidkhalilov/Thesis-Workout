#include "ftditools.h"

FT_HANDLE ftHandle;
short openFtdi=0;

short open_ftdi(int BaudRate, char *DeviceName, int SendTimeout, int ReadTimeout)
{
	unsigned long ftStatus;
    
    ftStatus = FT_OpenEx(DeviceName,FT_OPEN_BY_DESCRIPTION,&ftHandle);
    ftStatus = FT_SetBaudRate(ftHandle, (unsigned long)BaudRate);
	ftStatus = FT_SetDataCharacteristics(ftHandle, FT_BITS_8, FT_STOP_BITS_1, FT_PARITY_NONE);
    ftStatus = FT_SetTimeouts(ftHandle, ReadTimeout, SendTimeout);
	ftStatus = FT_SetFlowControl(ftHandle, FT_FLOW_NONE, 0, 0);
    ftStatus = FT_SetUSBParameters (ftHandle, 64, 64);
    ftStatus = FT_SetLatencyTimer (ftHandle, 4);
    
	printf("opening device... \n");
	if (ftStatus == FT_OK)
    {
        printf("successful\n");
		return(1);
    }
          // FT_Open OK, use ftHandle to access device } 
    else 
    {
		printf("failed\n");
       
        return(-1); // FT_Open failed }
    }
}

void close_ftdi()
{
    if (openFtdi == 1)
    {
        FT_Close(ftHandle);
        openFtdi=0;
		printf("closed device\n");
    }
}


short read_ftdi (short* data_out, double* HL_Status)
{
	unsigned long ftStatus;
    int size = 0;
	char data_in[256];
	short sync = 0;
	short i=0, j=0, k=0;
	int readcount = 0;
	int read_tmp = 0;
	char descriptor = 0;
	unsigned short* crc = NULL;
	short* data_ptr = NULL;
	unsigned long RxBytes, BytesReceived;
	static short data_out_store[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    static short status_store[] = {0,0};
    short send_size = 22;
	short data_new_flag = 1;
 
	size = send_size*2+3+1+2+2+3;

    
    ftStatus = FT_Read(ftHandle,data_in,size,&BytesReceived);
    if ((BytesReceived < size)||(ftStatus != FT_OK))
    {
        data_new_flag = 0;
        
    }	
    else
    {
        readcount = BytesReceived;
    }
   
	while ((sync!=3) && (data_new_flag == 1))
	{
		if (sync==0)
		{
		    if (data_in[i]=='>')
                sync=1;
			else
				sync=0;
		}
		else if (sync==1)
		{
			if (data_in[i]=='*')
				sync=2;
			else
				sync=0;
		}
		else if (sync==2)
		{
			if (data_in[i]=='>')
				sync=3;       
			else
				sync=0;
		}
        
        if ((i == (readcount-1)) && (sync == 1))
        {
            ftStatus = FT_Read(ftHandle,&data_in[i+1],2,&BytesReceived);
            readcount = readcount+2;
            if ((BytesReceived < size)||(ftStatus != FT_OK))
            {
               data_new_flag = 0;
            }	
        }
        else if ((i == (readcount-1)) && (sync == 2))
        {
            ftStatus = FT_Read(ftHandle,&data_in[i+1],1,&BytesReceived);
            readcount = readcount+2;
            if ((BytesReceived < size)||(ftStatus != FT_OK))
            {
                data_new_flag = 0;
            }	
        }
        if ((i == (readcount-1)) && (sync != 3))
        {
            data_new_flag = 0;
        }
        
    	i++;
	}
    
	if (((readcount-i)<(size-3))&&(data_new_flag == 1))
	{
		read_tmp = i-3;    
        ftStatus = FT_Read(ftHandle,&data_in[readcount],read_tmp,&BytesReceived);
        if ((BytesReceived < read_tmp)||(ftStatus != FT_OK))
        {
             data_new_flag = 0;
        }	
        else
        {
            readcount += BytesReceived;
        }
    
	}
    
	if (data_new_flag == 1)
	{
		i=i+2;
		descriptor = data_in[i];
		i=i+1;
		data_ptr = (short*) &(data_in[i]);
        i = i+send_size*2;
		crc = (unsigned short*)&(data_in[i]);

		if (crc16(data_ptr, send_size*2) == *crc)
		{
            status_store[0] = *((short*) &data_in[i-4]);
            status_store[1] = *((short*) &data_in[i-2]);
            memcpy(data_out_store, data_ptr, sizeof(data_out_store));
		}
	}
	memcpy(data_out, data_out_store, sizeof(data_out_store));
    HL_Status[0] = ((double) status_store[0])/1000.0;
    HL_Status[1] = ((double) status_store[1])/1000.0;
    
    FT_GetQueueStatus(ftHandle,&RxBytes);
    
    if (RxBytes>PURGE_BUFFER)
    {
        ftStatus = FT_Purge(ftHandle, FT_PURGE_RX);
    }
    return data_new_flag;
}

short send_ftdi(short *control_data)
{
	char send_data[TXCHANNELS*2+6];	
	unsigned short crc = 0;
	short j=0, send_switch=1;
    unsigned int BytesSent=0;
    if (send_switch)
    {
        send_data[0] = '>';
        send_data[1] = '*';
        send_data[2] = '>';
        send_data[3] = 'c';
        memcpy(&send_data[4], control_data, TXCHANNELS*2);
        crc = crc16(&send_data[4], TXCHANNELS*2);
        memcpy(&send_data[TXCHANNELS*2+4], &crc, 2);

        FT_Write(ftHandle, send_data, TXCHANNELS*2+6, &BytesSent);
        return BytesSent;
    }
    else
    {
        return 0;
    }
}

unsigned short crc_update (unsigned short crc, unsigned char data)
{
    data ^= (crc & 0xff);
    data ^= data << 4;

    return ((((unsigned short )data << 8) | ((crc>>8)&0xff)) ^ (unsigned char )(data >> 4)
         ^ ((unsigned short )data << 3));
}

 unsigned short crc16(void* data, unsigned short cnt)
{
    unsigned short crc=0xff;
    unsigned char * ptr=(unsigned char *) data;
    int i;

    for (i=0;i<cnt;i++)
    {
        crc=crc_update(crc,*ptr);
        ptr++;
    }
    return crc;

}

 