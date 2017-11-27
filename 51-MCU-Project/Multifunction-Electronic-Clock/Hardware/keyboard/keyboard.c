/*
 *****************************************************************************************
 *	�� �� �� ��:keyboard.c
 *  �� �� ƽ ̨��Keil uVision4
 *	�� �� �� �ߣ�miki
 *  �� �� �� �ܣ�������������
 *  github �� ַ��
 *	�� �� �� �ڣ�2017-11-27
 *****************************************************************************************
 */

/************************************* ����ͷ�ļ� ***************************************/
#include "keyboard.h"
#include "delay.h"
#include "lcd1602.h"
#include "ds1302.h"

/************************************* ȫ�ֱ������� **************************************/

/*************************************** IO�ڶ��� ****************************************/
sbit key=P3^7;
sbit key1=P3^0;
sbit key2=P3^1;
sbit key3=P3^2;

/********************************** ��չȫ�ֱ������� ************************************/


/************************************ �ֲ��������� **************************************/



void keyscan(void)
{
	u8 key1n,temp;
	key=0;
	if(key1==0)//key1Ϊ���ܼ�
	{
		delay1Ms(5);
		if(key1==0)
		{
			while(!key1);
			key1n++;
			if(key1n==9)
			key1n=1;
			switch(key1n)
			{
				case 1: 
					TR0=0;//�رն�ʱ��
					//TR1=0;
					write_1602com(er+0x0b);//д����λ��
					write_1602com(0x0f);//���ù��Ϊ��˸
					temp=(miao)/10*16+(miao)%10;
					write_1302(0x8e,0x00);
					write_1302(0x80,0x80|temp);//miao
					write_1302(0x8e,0x80);
					break;

				case 2:  
					write_1602com(er+8);//fen
					break;

				case 3: 
					write_1602com(er+5);//shi
					break;

				case 4: 
					write_1602com(yh+0x0f);//week
					break;

				case 5: 
					write_1602com(yh+0x0b);//ri
					break;

				case 6: 
					write_1602com(yh+0x08);//yue
					break;

				case 7: 
					write_1602com(yh+0x05);//nian
					break;

				case 8:
					write_1602com(0x0c);//���ù�겻��˸
					TR0=1;//�򿪶�ʱ��
					temp=(miao)/10*16+(miao)%10;
					write_1302(0x8e,0x00);
					write_1302(0x80,0x00|temp);//miao
					write_1302(0x8e,0x80);
					break;
			}
		}
	}

	if(key1n!=0)//��key1�������¡��ٰ����¼�����Ч
	{
		
		if(key2==0)  //�ϵ���
		{
			delay1Ms(5);
			if(key2==0)
			{
				while(!key2);
				switch(key1n)
				{
					case 1:
						miao++;
						if(miao==60)
						miao=0;
						write_sfm(0x0a,miao);//д���µ�����
						temp=(miao)/10*16+(miao)%10;
						write_1302(0x8e,0x00);
						write_1302(0x80,0x80|temp);
						write_1302(0x8e,0x80);
						write_1602com(er+0x0b);//��Ϊ����Һ����ģʽ��д�����ݺ�ָ���Զ���һ����������д��ԭ����λ��
						//write_1602com(0x0b);
						break;

					case 2:
						fen++;
						if(fen==60)
						fen=0;
						write_sfm(0x07,fen);
						temp=(fen)/10*16+(fen)%10;
						write_1302(0x8e,0x00);
						write_1302(0x82,temp);
						write_1302(0x8e,0x80);
						write_1602com(er+8);
						break;

					case 3:
						shi++;
						if(shi==24)
						shi=0;
						write_sfm(4,shi);
						temp=(shi)/10*16+(shi)%10;
						write_1302(0x8e,0x00);
						write_1302(0x84,temp);
						write_1302(0x8e,0x80);
						write_1602com(er+5);
						break;

					case 4:
						week++;
						if(week==8)
						week=0;
						write_week(week);
						write_1602com(yh+0x0f);
						break;

					case 5:
						ri++;
						if(ri==31)
						ri=0;
						write_nyr(10,ri);
						temp=(ri)/10*16+(ri)%10;
						write_1302(0x8e,0x00);
						write_1302(0x86,temp);
						write_1302(0x8e,0x80);
						write_1602com(yh+11);
						break;

					case 6:
						yue++;
						if(yue==13)
						yue=0;
						write_nyr(7,yue);
						temp=(yue)/10*16+(yue)%10;
						write_1302(0x8e,0x00);
						write_1302(0x88,temp);
						write_1302(0x8e,0x80);
						write_1602com(yh+8);
						break;

					case 7:
						nian++;
						if(nian==100)
						nian=0;
						write_nyr(4,nian);
						write_1602com(yh+5);
						break;
				}
			}
		}
		if(key3==0)
		{
			delay1Ms(5);
			if(key3==0)
			{
				while(!key3);
				switch(key1n)
				{
					case 1:
						miao--;
						if(miao==-1)
							miao=59;
						write_sfm(0x0a,miao);//д���µ�����
						write_1602com(er+0x0b);//��Ϊ����Һ����ģʽ��д�����ݺ�ָ���Զ���һ����������д��ԭ����λ��
						//write_1602com(0x0b);
						break;

					case 2:
						fen--;
						if(fen==-1)
							fen=59;
						write_sfm(7,fen);
						temp=(fen)/10*16+(fen)%10;
						write_1302(0x8e,0x00);
						write_1302(0x82,temp);
						write_1302(0x8e,0x80);
						write_1602com(er+8);
						break;
					
					case 3:
						shi--;
						if(shi==-1)
							shi=23;
						write_sfm(4,shi);
						temp=(shi)/10*16+(shi)%10;
						write_1302(0x8e,0x00);
						write_1302(0x84,temp);
						write_1302(0x8e,0x80);
						write_1602com(er+5);
						break;
					case 4:
						week--;
						if(week==-1)
							week=7;
						write_week(week);
						write_1602com(yh+0x0f);
						break;
					case 5:
						ri--;
						if(ri==-1)
							ri=30;
						write_nyr(10,ri);
						temp=(ri)/10*16+(ri)%10;
						write_1302(0x8e,0x00);
						write_1302(0x86,temp);
						write_1302(0x8e,0x80);
						write_1602com(yh+11);
						break;
					case 6:
						yue--;
						if(yue==-1)
							yue=12;
						write_nyr(7,yue);
						temp=(yue)/10*16+(yue)%10;
						write_1302(0x8e,0x00);
						write_1302(0x88,temp);
						write_1302(0x8e,0x80);
						write_1602com(yh+8);
						break;	
					case 7:
						nian--;
						if(nian==-1)
							nian=99;
						write_nyr(4,nian);
						write_1602com(yh+5);
						break;			
				}
			}
		}
	}
}


