#ifndef __LCD_IMG_H__
#define __LCD_IMG_H__

//ͼ������, BMM������(xdata)
unsigned char xdata gImage_gxw[1024] = { /* 0X10,0X01,0X00,0X80,0X00,0X40, */
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X3F,0X03,0XF0,0X3F,0X03,0XF0,0X00,0X00,0X00,0X0C,0X00,0X00,0X00,0XC0,0X00,
0X00,0X21,0X02,0X10,0X21,0X02,0X10,0X00,0X00,0X00,0X0C,0X00,0X18,0XFF,0XE0,0X00,
0X00,0X21,0X02,0X10,0X21,0X02,0X10,0X00,0X00,0X00,0X08,0X1C,0X1C,0X1B,0X00,0X00,
0X00,0X21,0X02,0X10,0X21,0X02,0X10,0X00,0X00,0X1F,0XFF,0XFE,0X0C,0X0E,0X00,0X00,
0X00,0X21,0X02,0X10,0X21,0X02,0X10,0X00,0X00,0X00,0X0C,0X00,0X00,0X8C,0X60,0X00,
0X00,0X21,0X02,0X10,0X21,0X02,0X10,0X00,0X00,0X04,0X0C,0X10,0X00,0XFF,0XF0,0X00,
0X00,0X21,0X02,0X10,0X21,0X02,0X10,0X00,0X00,0X07,0XFF,0XF8,0X0C,0XCC,0X60,0X00,
0X00,0X21,0X02,0X10,0X21,0X02,0X10,0X00,0X00,0X06,0X63,0X18,0X7E,0XCC,0X60,0X00,
0X7F,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XF8,0X00,0X06,0X33,0X98,0X0C,0XFF,0XE0,0X00,
0X7F,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XF8,0X00,0X06,0X32,0X18,0X0C,0XCC,0X60,0X00,
0X60,0X00,0X00,0X00,0X00,0X00,0X00,0X18,0X00,0X06,0X05,0XD8,0X0C,0XCC,0X60,0X00,
0X60,0X00,0X00,0X00,0X00,0X00,0X00,0X18,0X00,0X06,0XFF,0X78,0X0C,0XFF,0XE0,0X00,
0X60,0X00,0X00,0X00,0X00,0X00,0X00,0X18,0X00,0X06,0X08,0XD8,0X0C,0XCC,0X60,0X00,
0X60,0X00,0X00,0X00,0X00,0X00,0X00,0X18,0X00,0X07,0XFF,0XF8,0X0C,0XCC,0X60,0X00,
0X60,0X00,0X00,0X00,0X00,0X00,0X00,0X18,0X00,0X06,0X0C,0X18,0X0C,0XCF,0XE0,0X00,
0X60,0X00,0X00,0X00,0X00,0X00,0X00,0X18,0X00,0X06,0X0C,0X18,0X3E,0X80,0X40,0X00,
0X60,0X00,0X00,0X00,0X00,0X00,0X00,0X18,0X00,0X06,0X0C,0X18,0X73,0XC0,0X00,0X00,
0X60,0X00,0X00,0X00,0X00,0X00,0X00,0X18,0X00,0X06,0X0D,0XF0,0X20,0X7F,0XF8,0X00,
0X60,0X00,0X00,0X00,0X00,0X00,0X00,0X18,0X00,0X06,0X00,0X30,0X00,0X00,0X00,0X00,
0X60,0X00,0X00,0X00,0X00,0X00,0X00,0X18,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X60,0X00,0X00,0X00,0X00,0X00,0X00,0X18,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X60,0X00,0X00,0X00,0X00,0X00,0X00,0X18,0X00,0X06,0X00,0X18,0X01,0X84,0X00,0X00,
0X60,0X00,0X00,0X00,0X00,0X00,0X00,0X18,0X00,0X07,0XFF,0XFC,0X01,0XC6,0X00,0X00,
0X60,0X00,0X00,0X00,0X00,0X00,0X00,0X18,0X00,0X06,0X00,0X58,0X01,0X86,0X30,0X00,
0X60,0X00,0X00,0X00,0X00,0X00,0X00,0X18,0X00,0X07,0XFF,0XD8,0X7F,0XFF,0XF8,0X00,
0X60,0X00,0XFD,0X1F,0XF0,0X7A,0X00,0X18,0X00,0X06,0X0C,0X18,0X01,0X86,0X00,0X00,
0X60,0X01,0X87,0X13,0X30,0XC6,0X00,0X18,0X00,0X06,0X0C,0X18,0X01,0X86,0X00,0X00,
0X60,0X03,0X03,0X33,0X11,0X83,0X00,0X18,0X00,0X06,0X0C,0X18,0X00,0X40,0X00,0X00,
0X60,0X03,0X03,0X03,0X01,0X83,0X00,0X18,0X00,0X06,0X0C,0XD8,0X00,0X30,0X00,0X00,
0X60,0X03,0X80,0X03,0X03,0X80,0X00,0X18,0X00,0X06,0XFF,0XF8,0X03,0X38,0X00,0X00,
0X60,0X01,0XC0,0X03,0X03,0X00,0X00,0X18,0X00,0X06,0X0F,0X18,0X0B,0X98,0X80,0X00,
0X60,0X00,0X78,0X03,0X03,0X00,0X00,0X18,0X00,0X06,0X0D,0X98,0X0B,0X18,0XC0,0X00,
0X60,0X00,0X1E,0X03,0X03,0X00,0X00,0X18,0X00,0X06,0X0C,0XD8,0X1B,0X00,0X70,0X00,
0X60,0X00,0X07,0X03,0X03,0X00,0X00,0X18,0X00,0X06,0X0C,0X18,0X1B,0X01,0X30,0X00,
0X60,0X00,0X03,0X03,0X03,0X80,0X00,0X18,0X00,0X06,0X0C,0XD8,0X3B,0X01,0X30,0X00,
0X60,0X03,0X03,0X03,0X03,0X83,0X00,0X18,0X00,0X07,0XF7,0XB8,0X33,0X01,0X80,0X00,
0X60,0X03,0X03,0X03,0X01,0X82,0X00,0X18,0X00,0X06,0X00,0X18,0X03,0X01,0X80,0X00,
0X60,0X01,0XC6,0X03,0X01,0XC6,0X00,0X18,0X00,0X07,0XFF,0XF8,0X01,0XFF,0X80,0X00,
0X60,0X01,0X7C,0X07,0XC0,0X7C,0X00,0X18,0X00,0X06,0X00,0X18,0X00,0X00,0X00,0X00,
0X60,0X00,0X00,0X00,0X00,0X00,0X00,0X18,0X00,0X04,0X00,0X00,0X00,0X00,0X00,0X00,
0X60,0X00,0X00,0X00,0X00,0X00,0X00,0X18,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X60,0X00,0X00,0X00,0X00,0X00,0X00,0X18,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X60,0X00,0X00,0X00,0X00,0X00,0X00,0X18,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X60,0X00,0X00,0X00,0X00,0X00,0X00,0X18,0X21,0X86,0X00,0X07,0X00,0X00,0X00,0X10,
0X60,0X00,0X00,0X00,0X00,0X00,0X00,0X18,0X31,0X86,0X00,0X07,0X00,0X03,0XFF,0XF8,
0X60,0X00,0X00,0X00,0X00,0X00,0X00,0X18,0X65,0X66,0X00,0X02,0X00,0X00,0X00,0X68,
0X60,0X00,0X00,0X00,0X00,0X00,0X00,0X18,0XC7,0X7C,0X00,0X02,0X08,0X00,0X00,0XC0,
0X60,0X00,0X00,0X00,0X00,0X00,0X00,0X18,0X95,0X6C,0X41,0XFF,0XFC,0X00,0X03,0X80,
0X60,0X00,0X00,0X00,0X00,0X00,0X00,0X19,0X3D,0X6F,0XE1,0X82,0X0C,0X00,0X0E,0X00,
0X60,0X00,0X00,0X00,0X00,0X00,0X00,0X18,0X3E,0XE9,0XA1,0X82,0X0C,0X00,0X0E,0X00,
0X60,0X00,0X00,0X00,0X00,0X00,0X00,0X18,0X60,0X59,0X81,0X82,0X0C,0X00,0X0C,0X0C,
0X60,0X00,0X00,0X00,0X00,0X00,0X00,0X18,0X6F,0XFD,0X81,0XFF,0XFC,0X1F,0XFF,0XFE,
0X60,0X00,0X00,0X00,0X00,0X00,0X00,0X18,0XE0,0X15,0X81,0X82,0X0C,0X00,0X0C,0X02,
0X7F,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XF8,0XA6,0X45,0X81,0X82,0X0C,0X00,0X0C,0X00,
0X7F,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XF9,0X27,0XC7,0X01,0X82,0X0C,0X00,0X0C,0X00,
0X00,0X21,0X02,0X10,0X21,0X02,0X10,0X00,0X26,0X47,0X01,0XFF,0XFC,0X00,0X0C,0X00,
0X00,0X21,0X02,0X10,0X21,0X02,0X10,0X00,0X26,0X5F,0X01,0X82,0X0B,0X00,0X0C,0X00,
0X00,0X21,0X02,0X10,0X21,0X02,0X10,0X00,0X26,0X77,0X01,0X02,0X03,0X00,0X0C,0X00,
0X00,0X21,0X02,0X10,0X21,0X02,0X10,0X00,0X26,0XEF,0X80,0X02,0X03,0X00,0X0C,0X00,
0X00,0X21,0X02,0X10,0X21,0X02,0X10,0X00,0X24,0X59,0XC0,0X02,0X03,0X00,0X0C,0X00,
0X00,0X21,0X02,0X10,0X21,0X02,0X10,0X00,0X38,0X30,0XE0,0X03,0XFF,0X80,0X7C,0X00,
0X00,0X21,0X02,0X10,0X21,0X02,0X10,0X00,0X38,0XE0,0X00,0X00,0X00,0X00,0X18,0X00,
0X00,0X3F,0X03,0XF0,0X3F,0X03,0XF0,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
};

#endif