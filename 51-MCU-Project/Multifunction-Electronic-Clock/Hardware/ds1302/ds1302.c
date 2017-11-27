/*
 *****************************************************************************************
 *	文 件 名 称:ds1302.c
 *  创 建 平 台：Keil uVision4
 *	创 建 作 者：miki
 *  文 件 功 能：ds1302时钟芯片初始化及其配置
 *  github 地 址：
 *	创 建 日 期：2017-11-27
 *****************************************************************************************
 */

/************************************* 包含头文件 ***************************************/
#include "ds1302.h"
#include "lcd1602.h"

/************************************* 全局变量定义 **************************************/
u8 miao,shi,fen,ri,yue,nian,week;


/*************************************** IO口定义 ****************************************/
sbit SCLK=P1^0; 
sbit IO=P1^1;    
sbit RST=P1^2;  
sbit ACC0=ACC^0;
sbit ACC7=ACC^7;

/********************************** 扩展全局变量定义 ************************************/


/************************************ 局部函数定义 **************************************/


/********************ds1302****************************/
void write_byte(u8 dat)
{
	u8 a;
	ACC=dat;
	RST=1;
	for(a=8;a>0;a--)
	{
		IO=ACC0;
		SCLK=0;
		SCLK=1;
		ACC=ACC>>1;
	}
}

u8 read_byte()
{
	u8 a;
	RST=1;
	for(a=8;a>0;a--)
	{
		ACC7=IO;
		SCLK=1;
		SCLK=0;
		ACC=ACC>>1;

	}
	return (ACC);
}

void write_1302(u8 add,u8 dat)
{

	RST=0;
	SCLK=0;
	RST=1;
	write_byte(add);
	write_byte(dat);
	SCLK=1;
	RST=0;
}

u8 read_1302(u8 add)
{
	u8 temp;
	RST=0;
	SCLK=0;
	RST=1;
	write_byte(add);
	temp=read_byte();
	SCLK=1;
	RST=0;
	return(temp);
}

u8 BCD_Decimal(u8 bcd)
{
	 u8 Decimal;
	 Decimal=bcd>>4;
	 return(Decimal=Decimal*10+(bcd&=0x0F));
}

void ds1302_init(void)
{
	RST=0;
	SCLK=0;
	write_1302(0x80,miao|0x00);//允许写
}


	

void write_sfm(u8 add,u8 dat)//写时分秒
{
	u8 gw,sw;
	gw=dat%10;
	sw=dat/10;
	write_1602com(er+add);
	write_1602dat(0x30+sw);
	write_1602dat(0x30+gw);
}

void write_nyr(u8 add,u8 dat)
{
	u8 gw,sw;
	gw=dat%10;
	sw=dat/10;
	write_1602com(yh+add);
	write_1602dat(0x30+sw);
	write_1602dat(0x30+gw);
	

}
void write_week(u8 week)//写星期函数
{
	write_1602com(yh+0x0d);
	switch(week)
	{
		case 1:write_1602dat('M');//delay(5);
			   write_1602dat('O');//delay(5);
			   write_1602dat('N');
			   break;
	   
		case 2:write_1602dat('T');//delay(5);
			   write_1602dat('U');//delay(5);
			   write_1602dat('E');
			   break;
		
		case 3:write_1602dat('W');//delay(5);
			   write_1602dat('E');//delay(5);
			   write_1602dat('D');
			   break;
		
		case 4:write_1602dat('T');//delay(5);
			   write_1602dat('H');//delay(5);
			   write_1602dat('U');
			   break;
		
		case 5:write_1602dat('F');//delay(5);
			   write_1602dat('R');//delay(5);
			   write_1602dat('I');
			   break;
		
		case 6:write_1602dat('S');//delay(5);
			   write_1602dat('T');//delay(5);
			   write_1602dat('A');
			   break;
		
		case 7:write_1602dat('S');//delay(5);
			   write_1602dat('U');//delay(5);
			   write_1602dat('N');
			   break;
	}
}


