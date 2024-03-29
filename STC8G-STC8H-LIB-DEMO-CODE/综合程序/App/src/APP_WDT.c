/*---------------------------------------------------------------------*/
/* --- STC MCU Limited ------------------------------------------------*/
/* --- STC 1T Series MCU Demo Programme -------------------------------*/
/* --- Mobile: (86)13922805190 ----------------------------------------*/
/* --- Fax: 86-0513-55012956,55012947,55012969 ------------------------*/
/* --- Tel: 86-0513-55012928,55012929,55012966 ------------------------*/
/* --- Web: www.STCAI.com ---------------------------------------------*/
/* --- BBS: www.STCAIMCU.com  -----------------------------------------*/
/* --- QQ:  800003751 -------------------------------------------------*/
/* 如果要在程序中使用此代码,请在程序中注明使用了STC的资料及程序            */
/*---------------------------------------------------------------------*/

#include	"APP.h"
#include	"STC8G_H_WDT.h"

/*************   功能说明   ***************

本例程基于STC8H8K64U为主控芯片的实验箱8进行编写测试，STC8G、STC8H系列芯片可通用参考.

5秒后不喂狗, 等待看门狗复位.

下载时, 选择时钟 24MHz (用户可在"config.h"修改频率).

******************************************/

//========================================================================
//                               本地常量声明	
//========================================================================


//========================================================================
//                               本地变量声明
//========================================================================


//========================================================================
//                               本地函数声明
//========================================================================


//========================================================================
//                            外部函数和变量声明
//========================================================================


//========================================================================
// 函数: WDT_init
// 描述: 用户初始化程序.
// 参数: None.
// 返回: None.
// 版本: V1.0, 2020-09-28
//========================================================================
void WDT_init(void)
{
	WDT_InitTypeDef	WDT_InitStructure;					//结构定义

	WDT_InitStructure.WDT_Enable     = ENABLE;					//中断使能   ENABLE或DISABLE
	WDT_InitStructure.WDT_IDLE_Mode  = WDT_IDLE_STOP;		//IDLE模式是否停止计数		WDT_IDLE_STOP,WDT_IDLE_RUN
	WDT_InitStructure.WDT_PS         = WDT_SCALE_256;		//看门狗定时器时钟分频系数		WDT_SCALE_2,WDT_SCALE_4,WDT_SCALE_8,WDT_SCALE_16,WDT_SCALE_32,WDT_SCALE_64,WDT_SCALE_128,WDT_SCALE_256
	WDT_Inilize(&WDT_InitStructure);					//初始化
	
	msecond = 0;
	second = 0;
}

//========================================================================
// 函数: Sample_WDT
// 描述: 用户应用程序.
// 参数: None.
// 返回: None.
// 版本: V1.0, 2020-09-28
//========================================================================
void Sample_WDT(void)
{
	if(second <= 5)   //5秒后不喂狗, 将复位,
		WDT_Clear();    // 喂狗

	if(++msecond >= 10)
	{
		msecond = 0;
		second++;
	}
}

