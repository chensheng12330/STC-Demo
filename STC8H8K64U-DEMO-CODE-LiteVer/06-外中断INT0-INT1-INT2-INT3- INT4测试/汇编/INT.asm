;/*---------------------------------------------------------------------*/
;/* --- STC MCU Limited ------------------------------------------------*/
;/* --- STC 1T Series MCU Demo Programme -------------------------------*/
;/* --- Mobile: (86)13922805190 ----------------------------------------*/
;/* --- Fax: 86-0513-55012956,55012947,55012969 ------------------------*/
;/* --- Tel: 86-0513-55012928,55012929,55012966 ------------------------*/
;/* --- Web: www.STCAI.com ---------------------------------------------*/
;/* --- Web: www.STCMCUDATA.com ----------------------------------------*/
;/* --- BBS: www.STCAIMCU.com ------------------------------------------*/
;/* --- QQ:  800003751 -------------------------------------------------*/
;/* 如果要在程序中使用此代码,请在程序中注明使用了STC的资料及程序        */
;/*---------------------------------------------------------------------*/


;*************  功能说明    **************

;本例程基于STC8H8K64U为主控芯片的实验箱9进行编写测试，STC8G、STC8H系列芯片可通用参考.

;用STC的MCU的IO方式驱动8位数码管。

;显示效果为: 左边为INT0(SW17)中断计数, 右边为INT1(SW18)中断计数, 计数范围为0~255.

;显示5秒后, 睡眠. 按板上的SW17 SW18唤醒, 继续计秒显示. 5秒后再睡眠.

;由于按键是机械按键, 按下有抖动, 而本例程没有去抖动处理, 所以按一次有多个计数也是正常的.

;INT2, INT3, INT4 实验板上没有引出测试按键，供需要时参考使用.

;下载时, 选择时钟 24MHZ (用户可自行修改频率).

;******************************************

$include (../../comm/STC8H.INC)

;****************************** 用户定义宏 ***********************************/

Fosc_KHZ    EQU 24000   ;24000KHZ

STACK_POIRTER   EQU     0D0H    ; 堆栈开始地址

DIS_DOT         EQU     020H
DIS_BLACK       EQU     010H
DIS_            EQU     011H

;*******************************************************************
;*******************************************************************

EX2     EQU     010H
EX3     EQU     020H
EX4     EQU     040H

;*************  IO口定义    **************/


;*************  本地变量声明    **************/
LED8            DATA    30H     ; 显示缓冲 30H ~ 37H
display_index   DATA    38H     ; 显示位索引

INT0_cnt        DATA    39H     ; 测试用的计数变量
INT1_cnt        DATA    3AH     ;
INT2_cnt        DATA    3BH     ;
INT3_cnt        DATA    3CH     ;
INT4_cnt        DATA    3DH     ;

;*******************************************************************
;*******************************************************************
        ORG     0000H               ;reset
        LJMP    F_Main


        ORG     0003H               ;0  INT0 interrupt
        LJMP    F_INT0_Interrupt      

        ORG     0013H               ;2  INT1 interrupt
        LJMP    F_INT1_Interrupt      

        ORG     0053H               ;10 INT2 interrupt
        LJMP    F_INT2_Interrupt      

        ORG     005BH               ;11 INT3 interrupt
        LJMP    F_INT3_Interrupt      

        ORG     0083H               ;16 INT4 interrupt
        LJMP    F_INT4_Interrupt      


;*******************************************************************
;*******************************************************************


;******************** 主程序 **************************/
        ORG     0100H       ;reset
F_Main:
    ORL     P_SW2, #080H    ;扩展寄存器(XFR)访问使能

    MOV     P0M1, #30H     ;设置P0.4、P0.5为漏极开路(实验箱加了上拉电阻到3.3V)
    MOV     P0M0, #30H
    MOV     P1M1, #30H     ;设置P1.4、P1.5为漏极开路(实验箱加了上拉电阻到3.3V)
    MOV     P1M0, #30H
    MOV     P2M1, #3cH     ;设置P2.2~P2.5为漏极开路(实验箱加了上拉电阻到3.3V)
    MOV     P2M0, #3cH
    MOV     P3M1, #50H     ;设置P3.4、P3.6为漏极开路(实验箱加了上拉电阻到3.3V)
    MOV     P3M0, #50H
    MOV     P4M1, #3cH     ;设置P4.2~P4.5为漏极开路(实验箱加了上拉电阻到3.3V)
    MOV     P4M0, #3cH
    MOV     P5M1, #0cH     ;设置P5.2、P5.3为漏极开路(实验箱加了上拉电阻到3.3V)
    MOV     P5M0, #0cH
    MOV     P6M1, #0ffH    ;设置为漏极开路(实验箱加了上拉电阻到3.3V)
    MOV     P6M0, #0ffH
    MOV     P7M1, #00H     ;设置为准双向口
    MOV     P7M0, #00H
    
    MOV     SP, #STACK_POIRTER
    MOV     PSW, #0
    USING   0       ;选择第0组R0~R7

;================= 用户初始化程序 ====================================

    MOV     display_index, #0
    MOV     R0, #LED8
    MOV     R2, #8
L_ClearLoop:
    MOV     @R0, #DIS_BLACK     ;上电消隐
    INC     R0
    DJNZ    R2, L_ClearLoop
    
    CLR     IE1     ;外中断1标志位
    CLR     IE0     ;外中断0标志位
    SETB    EX1     ;INT1 Enable
    SETB    EX0     ;INT0 Enable

    SETB    IT0     ;INT0 下降沿中断        
;   CLR     IT0     ;INT0 上升,下降沿中断   
    SETB    IT1     ;INT1 下降沿中断        
;   CLR     IT1     ;INT1 上升,下降沿中断

    ;INT2, INT3, INT4 实验板上没有引出测试按键，供需要时参考使用
    MOV     INTCLKO, #EX2  ;使能 INT2 下降沿中断
    ORL     INTCLKO, #EX3  ;使能 INT3 下降沿中断
    ORL     INTCLKO, #EX4  ;使能 INT4 下降沿中断

    SETB    EA      ;允许总中断
    
    MOV     INT0_cnt, #0
    MOV     INT1_cnt, #0

;=================== 主循环 ==================================
L_MainLoop:
    MOV     A, #1           ;延时1ms
    LCALL   F_delay_ms  
    LCALL   F_DisplayScan
    LJMP    L_MainLoop

;**********************************************/


;========================================================================
; 函数: F_delay_ms
; 描述: 延时子程序。
; 参数: ACC: 延时ms数.
; 返回: none.
; 版本: VER1.0
; 日期: 2013-4-1
; 备注: 除了ACCC和PSW外, 所用到的通用寄存器都入栈
;========================================================================
F_delay_ms:
    PUSH    02H     ;入栈R2
    PUSH    03H     ;入栈R3
    PUSH    04H     ;入栈R4

    MOV     R2,A

L_delay_ms_1:
    MOV     R3, #HIGH (Fosc_KHZ / 10)
    MOV     R4, #LOW (Fosc_KHZ / 10)
    
L_delay_ms_2:
    MOV     A, R4           ;1T     Total 10T/loop
    DEC     R4              ;1T
    JNZ     L_delay_ms_3    ;3T
    DEC     R3
L_delay_ms_3:
    DEC     A               ;1T
    ORL     A, R3           ;1T
    JNZ     L_delay_ms_2    ;3T
    
    DJNZ    R2, L_delay_ms_1

    POP     04H     ;出栈R2
    POP     03H     ;出栈R3
    POP     02H     ;出栈R4
    RET

; *********************** 显示相关程序 ****************************************
T_Display:                      ;标准字库
;    0    1    2    3    4    5    6    7    8    9    A    B    C    D    E    F
DB  03FH,006H,05BH,04FH,066H,06DH,07DH,007H,07FH,06FH,077H,07CH,039H,05EH,079H,071H
;  black  -    H    J    K    L    N    o    P    U    t    G    Q    r    M    y
DB  000H,040H,076H,01EH,070H,038H,037H,05CH,073H,03EH,078H,03dH,067H,050H,037H,06EH
;    0.   1.   2.   3.   4.   5.   6.   7.   8.   9.   -1
DB  0BFH,086H,0DBH,0CFH,0E6H,0EDH,0FDH,087H,0FFH,0EFH,046H

T_COM:
DB  001H,002H,004H,008H,010H,020H,040H,080H     ;   位码

;========================================================================
; 函数: F_DisplayScan
; 描述: 显示扫描子程序。
; 参数: none.
; 返回: none.
; 版本: VER1.0
; 日期: 2013-4-1
; 备注: 除了ACCC和PSW外, 所用到的通用寄存器都入栈
;========================================================================
F_DisplayScan:
    PUSH    DPH     ;DPH入栈
    PUSH    DPL     ;DPL入栈
    PUSH    00H     ;R0 入栈
    
    MOV     DPTR, #T_COM
    MOV     A, display_index
    MOVC    A, @A+DPTR
    CPL     A
	MOV     P7,A
    
    MOV     DPTR, #T_Display
    MOV     A, display_index
    ADD     A, #LED8
    MOV     R0, A
    MOV     A, @R0
    MOVC    A, @A+DPTR
    CPL     A
	MOV     P6,A

    INC     display_index
    MOV     A, display_index
    ANL     A, #0F8H            ; if(display_index >= 8)
    JZ      L_QuitDisplayScan
    MOV     display_index, #0;  ;8位结束回0
    
    MOV     A, INT0_cnt
    MOV     B, #100
    DIV     AB
    MOV     LED8+7, A
    MOV     A, #10
    XCH     A, B
    DIV     AB
    MOV     LED8+6, A
    MOV     LED8+5, B
    MOV     LED8+4, #DIS_BLACK;

    MOV     LED8+3, #DIS_BLACK;
    MOV     A, INT1_cnt
    MOV     B, #100
    DIV     AB
    MOV     LED8+2, A
    MOV     A, #10
    XCH     A, B
    DIV     AB
    MOV     LED8+1, A
    MOV     LED8+0, B
L_QuitDisplayScan:
    POP     00H     ;R0 出栈
    POP     DPL     ;DPL出栈
    POP     DPH     ;DPH出栈
    RET


;========================================================================
; 函数: F_INT0_Interrupt
; 描述: INT0中断函数.
; 参数: none.
; 返回: none.
; 版本: VER1.0
; 日期: 2013-4-1
; 备注: 所用到的通用寄存器都入栈保护, 退出时恢复原来数据不改变.
;========================================================================
F_INT0_Interrupt:
    INC     INT0_cnt    ; 中断+1
    RETI
    
;========================================================================
; 函数: F_INT1_Interrupt
; 描述: INT1中断函数.
; 参数: none.
; 返回: none.
; 版本: VER1.0
; 日期: 2013-4-1
; 备注: 所用到的通用寄存器都入栈保护, 退出时恢复原来数据不改变.
;========================================================================
F_INT1_Interrupt:
    INC     INT1_cnt    ; 中断+1
    RETI

;========================================================================
; 函数: F_INT2_Interrupt
; 描述: INT2中断函数.
; 参数: none.
; 返回: none.
; 版本: VER1.0
; 日期: 2020-11-4
; 备注: 所用到的通用寄存器都入栈保护, 退出时恢复原来数据不改变.
;========================================================================
F_INT2_Interrupt:
    INC     INT2_cnt    ; 中断+1
    RETI

;========================================================================
; 函数: F_INT3_Interrupt
; 描述: INT3中断函数.
; 参数: none.
; 返回: none.
; 版本: VER1.0
; 日期: 2020-11-4
; 备注: 所用到的通用寄存器都入栈保护, 退出时恢复原来数据不改变.
;========================================================================
F_INT3_Interrupt:
    INC     INT3_cnt    ; 中断+1
    RETI

;========================================================================
; 函数: F_INT4_Interrupt
; 描述: INT4中断函数.
; 参数: none.
; 返回: none.
; 版本: VER1.0
; 日期: 2020-11-4
; 备注: 所用到的通用寄存器都入栈保护, 退出时恢复原来数据不改变.
;========================================================================
F_INT4_Interrupt:
    INC     INT4_cnt    ; 中断+1
    RETI


    END
