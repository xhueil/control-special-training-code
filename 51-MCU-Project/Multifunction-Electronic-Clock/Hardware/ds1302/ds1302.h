#ifndef DS1302_H__
#define DS1302_H__

/************************************* ����ͷ�ļ� ***************************************/
#include "config.h"


/**************************************** �궨�� *****************************************/

/*************************************** �������� ****************************************/
void ds1302_init(void);
void write_1302(u8 add,u8 dat);
u8 read_1302(u8 add);
u8 BCD_Decimal(u8 bcd);
void write_sfm(u8 add,u8 dat);//дʱ����
void write_nyr(u8 add,u8 dat);
void write_week(u8 week);//д���ں���


extern u8 miao,shi,fen,ri,yue,nian,week;



#endif






