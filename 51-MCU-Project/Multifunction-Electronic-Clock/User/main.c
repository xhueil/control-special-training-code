/*
 *****************************************************************************************
 *	项 目 名 称:多功能电子时钟
 *  实 验 平 台：清翔电子 QX-MCS51开发板
 *	创 建 作 者：miki
 *  项 目 说 明：使用DS1302时钟芯片进行计时，用LCD1602显示时间信息，DHT11测试室内温度等
 *  github 地 址：
 *	创 建 日 期：2017-11-18
 *****************************************************************************************
 */

/************************************* 包含头文件 ***************************************/
#include "config.h"
#include "digital_tube.h"
#include "delay.h"
#include "timer.h"
#include "lcd1602.h"
#include "ds1302.h"
#include "keyboard.h"

/************************************* 全局变量定义 **************************************/

/********************************** 扩展全局变量定义 ************************************/
extern u8 GlobalInterruptAdd;

/************************************ 局部函数声明 **************************************/
static void displayTime(void);


/*
 *****************************************************************************************
 * 函数名称：main
 * 函数功能：主函数，整个程序入口
 * 输入参数：无
 * 输出参数：无
 * 其他说明：无
 ******************************************************************************************
 */
void main()
{
	lcd1602_init();
	ds1302_init();	
	/* 定时器0初始化子程序 */
	timer0InterruptInit(); 
	while(1)
	{
		keyscan();
	}
}



static void displayTime(void)
{
	u8 GlobalShi1,GlobalShi0;
	u8 GlobalFen1,GlobalFen0;
	u8 GlobalMiao1,GlobalMiao0;
	u16 GlobalTemp;

	if(GlobalInterruptAdd == 20)
	  {
		GlobalInterruptAdd = 0;
		GlobalTemp ++;
		if(GlobalTemp == 86400)
	   {
			GlobalTemp=0;
	   }
		GlobalShi1=GlobalTemp/3600/10;
		GlobalShi0=GlobalTemp/3600-(GlobalShi1*10);
		GlobalFen1=GlobalTemp%3600/60/10;
		GlobalFen0=GlobalTemp%3600/60-(GlobalFen1*10);
		GlobalMiao1=GlobalTemp%3600%60/10;
		GlobalMiao0=GlobalTemp%3600%60-(GlobalMiao1*10);
	  }
	digitalTubeDisplayTime(GlobalShi1,GlobalShi0,GlobalFen1,
							GlobalMiao1,GlobalMiao1,GlobalMiao0);
}





