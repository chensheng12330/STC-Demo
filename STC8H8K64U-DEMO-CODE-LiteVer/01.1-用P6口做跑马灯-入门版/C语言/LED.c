/*---------------------------------------------------------------------*/
/* --- STC MCU Limited ------------------------------------------------*/
/* --- STC 1T Series MCU Demo Programme -------------------------------*/
/* --- Mobile: (86)13922805190 ----------------------------------------*/
/* --- Fax: 86-0513-55012956,55012947,55012969 ------------------------*/
/* --- Tel: 86-0513-55012928,55012929,55012966 ------------------------*/
/* --- Web: www.STCAI.com ---------------------------------------------*/
/* --- BBS: www.STCAIMCU.com  -----------------------------------------*/
/* --- QQ:  800003751 -------------------------------------------------*/
/* 如果要在程序中使用此代码,请在程序中注明使用了STC的资料及程序        */
/*---------------------------------------------------------------------*/

#include "stc8h.h"       //包含此头文件后，不需要再包含"reg51.h"头文件

#define     MAIN_Fosc       24000000L   //定义主时钟

/*************  功能说明    **************

本例程基于STC8H8K64U为主控芯片的实验箱进行编写测试，STC8G、STC8H系列芯片可通用参考.

程序使用P6口来演示跑马灯，输出低驱动。

当用户使用硬件 USB 对 STC8H8K64U 系列进行 ISP 下载时不能调节内部 IRC 的频率，
但用户可用选择内部预置的 16 个频率
（分别是 5.5296M、 6M、 11.0592M、 12M、 18.432M、 20M、 22.1184M、 
24M、27M、 30M、 33.1776M、 35M、 36.864M、 40M、 44.2368M 和 48M）。
下载时用户只能从频率下拉列表中进行选择其中之一，而不能手动输入其他频率。
（使用串口下载则可用输入 4M～48M 之间的任意频率）。

下载时, 选择时钟 24MHZ (用户可自行修改频率).

******************************************/

typedef     unsigned char   u8;
typedef     unsigned int    u16;
typedef     unsigned long   u32;

void  delay_ms(u8 ms);

/******************** 主函数 **************************/
void main(void)
{
    P_SW2 |= 0x80;  //扩展寄存器(XFR)访问使能

    P0M1 = 0x30;   P0M0 = 0x30;   //设置P0.4、P0.5为漏极开路(实验箱加了上拉电阻到3.3V)
    P1M1 = 0x30;   P1M0 = 0x30;   //设置P1.4、P1.5为漏极开路(实验箱加了上拉电阻到3.3V)
    P2M1 = 0x3c;   P2M0 = 0x3c;   //设置P2.2~P2.5为漏极开路(实验箱加了上拉电阻到3.3V)
    P3M1 = 0x50;   P3M0 = 0x50;   //设置P3.4、P3.6为漏极开路(实验箱加了上拉电阻到3.3V)
    P4M1 = 0x3c;   P4M0 = 0x3c;   //设置P4.2~P4.5为漏极开路(实验箱加了上拉电阻到3.3V)
    P5M1 = 0x0c;   P5M0 = 0x0c;   //设置P5.2、P5.3为漏极开路(实验箱加了上拉电阻到3.3V)
    P6M1 = 0x00;   P6M0 = 0xff;   //设置为推挽输出
    P7M1 = 0x00;   P7M0 = 0x00;   //设置为准双向口

    P40 = 0;		//LED Power On
    while(1)
    {
        P60 = 0;		//LED On
        delay_ms(250);
        P60 = 1;		//LED Off

        P61 = 0;		//LED On
        delay_ms(250);
        P61 = 1;		//LED Off

        P62 = 0;		//LED On
        delay_ms(250);
        P62 = 1;		//LED Off

        P63 = 0;		//LED On
        delay_ms(250);
        P63 = 1;		//LED Off

        P64 = 0;		//LED On
        delay_ms(250);
        P64 = 1;		//LED Off

        P65 = 0;		//LED On
        delay_ms(250);
        P65 = 1;		//LED Off

        P66 = 0;		//LED On
        delay_ms(250);
        P66 = 1;		//LED Off

        P67 = 0;		//LED On
        delay_ms(250);
        P67 = 1;		//LED Off
    }
}

//========================================================================
// 函数: void delay_ms(u8 ms)
// 描述: 延时函数。
// 参数: ms,要延时的ms数, 这里只支持1~255ms. 自动适应主时钟.
// 返回: none.
// 版本: VER1.0
// 日期: 2021-3-9
// 备注: 
//========================================================================
void delay_ms(u8 ms)
{
     u16 i;
     do{
          i = MAIN_Fosc / 10000;
          while(--i);   //10T per loop
     }while(--ms);
}

