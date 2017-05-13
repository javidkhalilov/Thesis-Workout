#ifndef FTDITOOLSREC_H
#define FTDITOOLSREC_H

#include <stdio.h>
#include <tchar.h>
#include <windows.h>
#include "ftd2xx.h"

#define PURGE_BUFFER 60

#define TXCHANNELS 12
#define RXCHANNELS 20

#ifndef false
    #define false 0 
#endif
#ifndef true       
    #define true 1
#endif
        
typedef signed __int8     int8_t;
typedef signed __int16    int16_t;
typedef signed __int32    int32_t;
typedef unsigned __int8   uint8_t;
typedef unsigned __int16  uint16_t;
typedef unsigned __int32  uint32_t;
typedef signed __int64       int64_t;
typedef unsigned __int64     uint64_t;


FT_HANDLE ftHandle;
short openFtdi;


short open_ftdi(int, char*, int, int);
void close_ftdi();
short send_ftdi(short*);
short read_ftdi (short*, double*);

unsigned short crc_update (unsigned short, unsigned char);
unsigned short crc16(void*, unsigned short);



#endif