/*
 *****************************************************************************************
 *	文 件 名 称:digital_tube.
 *  创 建 平 台：Keil uVision4
 *	创 建 作 者：miki
 *  文 件 功 能：数码管的初始化及其显示配置
 *  github 地 址：
 *	创 建 日 期：2017-11-18
 *****************************************************************************************
 */

/************************************* 包含头文件 ***************************************/
#include "digital_tube.h"
#include "delay.h"

/************************************* 全局变量定义 **************************************/
u8 code GlobalDispalyTable[]={
							  0x3f,0x06,0x5b,0x4f,
							  0x66,0x6d,0x7d,0x07,
							  0x7f,0x6f,0x77,0x7c,
							  0x39,0x5e,0x79,0x71};

/*
 *****************************************************************************************
 * 函数名称：digitalTubeDisplayTime
 * 函数功能：数码管显示时间信息
 * 输入参数：shi1,shi0,fen1,fen0,miao1,miao0
 * 输出参数：无
 * 其他说明：无
 ******************************************************************************************
 */
void digitalTubeDisplayTime(u8 shi1,shi0,fen1,fen0,miao1,miao0)
{
      	DULA_IO=1;
		P0=GlobalDispalyTable[shi1];
		DULA_IO=0;

		P0=0xff;
		WELA_IO=1;

		P0=0xfe;
		WELA_IO=0;
		delay1Ms(1);

		DULA_IO=1;
		P0=GlobalDispalyTable[shi0];
		DULA_IO=0;

		P0=0xff;
		
		WELA_IO=1;
		P0=0xfd;
		WELA_IO=0;
		delay1Ms(1);

		DULA_IO=1;
		P0=0x40;//"-"
		DULA_IO=0;

		P0=0xff;
		
		WELA_IO=1;
		P0=0xfb;
		WELA_IO=0;
		delay1Ms(1);
		
		DULA_IO=1;
		P0=GlobalDispalyTable[fen1];
		DULA_IO=0;

		P0=0xff;

		WELA_IO=1;
		P0=0xf7;
		WELA_IO=0;
		delay1Ms(1);

		
		DULA_IO=1;
		P0=GlobalDispalyTable[fen0];
		DULA_IO=0;
		P0=0xff;
		WELA_IO=1;
		P0=0xef;
		WELA_IO=0;
		delay1Ms(1);

		DULA_IO=1;
		P0=0x40;//"-"
		DULA_IO=0;

		P0=0xff;
		
		WELA_IO=1;
		P0=0xdf;
		WELA_IO=0;
		delay1Ms(1);
				
		DULA_IO=1;
		P0=GlobalDispalyTable[miao1];
		DULA_IO=0;

		P0=0xff;

		WELA_IO=1;
		P0=0xbf;
		WELA_IO=0;
		delay1Ms(1);

		
		DULA_IO=1;
		P0=GlobalDispalyTable[miao0];
		DULA_IO=0;

		P0=0xff;

		WELA_IO=1;
		P0=0x7f;
		WELA_IO=0;
		delay1Ms(1);
}


