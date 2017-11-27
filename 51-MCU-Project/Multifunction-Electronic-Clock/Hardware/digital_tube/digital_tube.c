/*
 *****************************************************************************************
 *	�� �� �� ��:digital_tube.
 *  �� �� ƽ ̨��Keil uVision4
 *	�� �� �� �ߣ�miki
 *  �� �� �� �ܣ�����ܵĳ�ʼ��������ʾ����
 *  github �� ַ��
 *	�� �� �� �ڣ�2017-11-18
 *****************************************************************************************
 */

/************************************* ����ͷ�ļ� ***************************************/
#include "digital_tube.h"
#include "delay.h"

/*************************************** IO�ڶ��� ****************************************/
sbit DULA_IO = P2^6;
sbit WELA_IO = P2^7;

/************************************* ȫ�ֱ������� **************************************/
u8 code GlobalDispalyTable[]={
							  0x3f,0x06,0x5b,0x4f,
							  0x66,0x6d,0x7d,0x07,
							  0x7f,0x6f,0x77,0x7c,
							  0x39,0x5e,0x79,0x71};

/*
 *****************************************************************************************
 * �������ƣ�digitalTubeDisplayTime
 * �������ܣ��������ʾʱ����Ϣ
 * ���������shi1,shi0,fen1,fen0,miao1,miao0
 * �����������
 * ����˵������
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


