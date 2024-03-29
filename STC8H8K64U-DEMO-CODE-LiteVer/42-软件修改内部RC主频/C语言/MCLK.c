/*---------------------------------------------------------------------*/
/* --- STC MCU Limited ------------------------------------------------*/
/* --- STC 1T Series MCU Demo Programme -------------------------------*/
/* --- Mobile: (86)13922805190 ----------------------------------------*/
/* --- Fax: 86-0513-55012956,55012947,55012969 ------------------------*/
/* --- Tel: 86-0513-55012928,55012929,55012966 ------------------------*/
/* --- Web: www.STCAI.com ---------------------------------------------*/
/* --- Web: www.STCMCUDATA.com  ---------------------------------------*/
/* --- BBS: www.STCAIMCU.com  -----------------------------------------*/
/* --- QQ:  800003751 -------------------------------------------------*/
/* 如果要在程序中使用此代码,请在程序中注明使用了STC的资料及程序        */
/*---------------------------------------------------------------------*/

/*************  功能说明    **************

本例程基于STC8H8K64U为主控芯片的实验箱9进行编写测试，STC8G、STC8H系列芯片可通用参考.

程序使用P6口做跑马灯，演示系统时钟源切换效果。

跑马灯每跑一轮切换一次时钟源，分别是默认IRC主频，主频48分频，内部32K IRC。

下载时, 选择时钟 24MHZ (用户可自行修改频率).

******************************************/

#include "stc8h.h"       //包含此头文件后，不需要再包含"reg51.h"头文件

#define     MAIN_Fosc       24000000L   //定义主时钟

typedef     unsigned char   u8;
typedef     unsigned int    u16;
typedef     unsigned long   u32;


u8 ledIndex;
u8 code ledNum[]={0x01,0x02,0x04,0x08,0x10,0x20,0x40,0x80};
u8 mode = 1;

void  delay_ms(u8 ms);
void  MCLK_Sel(void);

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
    P6M1 = 0xff;   P6M0 = 0xff;   //设置为漏极开路(实验箱加了上拉电阻到3.3V)
    P7M1 = 0x00;   P7M0 = 0x00;   //设置为准双向口

    P40 = 0;		//LED Power On
    ledIndex = 0;
    while(1)
    {
        P6 = ~ledNum[ledIndex];	//输出低驱动
        ledIndex++;
        if(ledIndex > 7)
        {
            ledIndex = 0;
            MCLK_Sel();
        }
        delay_ms(10);
    }
}

//========================================================================
// 函数: void  MCLK_Sel(void)
// 描述: 系统时钟设置函数。
// 参数: none.
// 返回: none.
// 版本: VER1.0
// 日期: 2020-7-29
// 备注: 
//========================================================================
void  MCLK_Sel(void)
{
    if(mode == 0)
    {
        mode++;
        HIRCCR = 0x80; //启动内部 IRC
        while (!(HIRCCR & 1)); //等待时钟稳定
        CLKDIV = 0;
        CLKSEL = 0x00; //选择内部 IRC ( 默认 )
    }
    else if(mode == 1)
    {
        mode++;
        HIRCCR = 0x80; //启动内部 IRC
        while (!(HIRCCR & 1)); //等待时钟稳定
        CLKDIV = 48;   //MCLK/48
        CLKSEL = 0x00; //选择内部 IRC ( 默认 )
    }
//    else if(mode == 2)
//    {
//        mode++;
//        XOSCCR = 0xc0; //启动外部晶振
//        while (!(XOSCCR & 1)); //等待时钟稳定
//        CLKDIV = 0x00; //时钟不分频
//        CLKSEL = 0x01; //选择外部晶振
//    }
    else
    {
        mode = 0;
        IRC32KCR = 0x80; //启动内部 32K IRC
        while (!(IRC32KCR & 1)); //等待时钟稳定
        CLKDIV = 0x00; //时钟不分频
        CLKSEL = 0x03; //选择内部 32K
    }
}

//========================================================================
// 函数: void  delay_ms(u8 ms)
// 描述: 延时函数。
// 参数: ms,要延时的ms数, 这里只支持1~255ms. 自动适应主时钟.
// 返回: none.
// 版本: VER1.0
// 日期: 2013-4-1
// 备注: 
//========================================================================
void  delay_ms(u8 ms)
{
    u16 i;
    do{
        i = MAIN_Fosc / 10000;
        while(--i)    ;   //10T per loop
    }while(--ms);
}

