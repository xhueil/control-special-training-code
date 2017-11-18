/*
 *****************************************************************************************
 *	项 目 名 称:多功能电子时钟
 *  实 验 平 台：清翔电子 QX-MCS51开发板
 *	创 建 作 者：miki
 *  项 目 说 明：利用定时器中断实现准确走时，使用数码管来显示时间，蜂鸣器实现闹钟功能
 *               按键实现校时和切换成秒表功能，以及实现设置闹钟功能等
 *  github 地 址：
 *	创 建 日 期：2017-11-18
 *****************************************************************************************
 */

/************************************* 包含头文件 ***************************************/
#include "config.h"
#include "digital_tube.h"
#include "delay.h"
#include "timer.h"

/************************************* 全局变量定义 **************************************/
u8 GlobalShi1,GlobalShi0;
u8 GlobalFen1,GlobalFen0;
u8 GlobalMiao1,GlobalMiao0;
u16 GlobalTemp;

/********************************** 扩展全局变量定义 ************************************/
extern u8 GlobalInterruptAdd;

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
	/* 定时器0初始化子程序 */
	timer0InterruptInit(); 
	while(1)
	{
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
}

