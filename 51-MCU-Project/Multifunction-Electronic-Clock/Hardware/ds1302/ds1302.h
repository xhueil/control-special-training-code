#ifndef DS1302_H__
#define DS1302_H__

/************************************* 包含头文件 ***************************************/
#include "config.h"


/**************************************** 宏定义 *****************************************/

/*************************************** 函数声明 ****************************************/
void ds1302_init(void);
void write_1302(u8 add,u8 dat);
u8 read_1302(u8 add);
u8 BCD_Decimal(u8 bcd);
void write_sfm(u8 add,u8 dat);//写时分秒
void write_nyr(u8 add,u8 dat);
void write_week(u8 week);//写星期函数


extern u8 miao,shi,fen,ri,yue,nian,week;



#endif






