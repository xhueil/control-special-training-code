/*
 *****************************************************************************************
 *	�� �� �� ��:timer.c
 *  �� �� ƽ ̨��Keil uVision4
 *	�� �� �� �ߣ�miki
 *  �� �� �� �ܣ���ʱ����ʼ����������
 *  github �� ַ��
 *	�� �� �� �ڣ�2017-11-18
 *****************************************************************************************
 */

/************************************* ����ͷ�ļ� ***************************************/
#include "timer.h"
#include "ds1302.h"

/************************************* ȫ�ֱ������� **************************************/
u8 GlobalInterruptAdd;

/*
 *****************************************************************************************
 * �������ƣ�timer0InterruptInit
 * �������ܣ���ʱ��0�����жϳ�ʼ��
 * �����������
 * �����������
 * ����˵������
 ******************************************************************************************
 */
void timer0InterruptInit(void)
{	
	TMOD = 0x11;
	TH0 = 0;
	TL0 = 0;
	EA = 1;
	ET0 = 1;
	TR0=1;
}

/*
 *****************************************************************************************
 * �������ƣ�timer0InterruptHandler
 * �������ܣ���ʱ��0�жϷ�����
 * �����������
 * �����������
 * ����˵������
 ******************************************************************************************
 */
void timer0InterruptHandler() interrupt 1
{
	miao = BCD_Decimal(read_1302(0x81));
	fen = BCD_Decimal(read_1302(0x83));
	shi  = BCD_Decimal(read_1302(0x85));
	ri  = BCD_Decimal(read_1302(0x87));
	yue = BCD_Decimal(read_1302(0x89));
	nian=BCD_Decimal(read_1302(0x8d));
	week=BCD_Decimal(read_1302(0x8b));

	write_sfm(10,miao);
	write_sfm(7,fen);
	write_sfm(4,shi);
	
	write_nyr(10,ri);
    write_nyr(7,yue);

}
