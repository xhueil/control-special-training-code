/*
 *****************************************************************************************
 *	�� Ŀ �� ��:�๦�ܵ���ʱ��
 *  ʵ �� ƽ ̨��������� QX-MCS51������
 *	�� �� �� �ߣ�miki
 *  �� Ŀ ˵ ����ʹ��DS1302ʱ��оƬ���м�ʱ����LCD1602��ʾʱ����Ϣ��DHT11���������¶ȵ�
 *  github �� ַ��
 *	�� �� �� �ڣ�2017-11-18
 *****************************************************************************************
 */

/************************************* ����ͷ�ļ� ***************************************/
#include "config.h"
#include "digital_tube.h"
#include "delay.h"
#include "timer.h"
#include "lcd1602.h"
#include "ds1302.h"
#include "keyboard.h"

/************************************* ȫ�ֱ������� **************************************/

/********************************** ��չȫ�ֱ������� ************************************/
extern u8 GlobalInterruptAdd;

/************************************ �ֲ��������� **************************************/
static void displayTime(void);


/*
 *****************************************************************************************
 * �������ƣ�main
 * �������ܣ��������������������
 * �����������
 * �����������
 * ����˵������
 ******************************************************************************************
 */
void main()
{
	lcd1602_init();
	ds1302_init();	
	/* ��ʱ��0��ʼ���ӳ��� */
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





