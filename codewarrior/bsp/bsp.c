/*
*********************************************************************************************************
*                                               uC/OS-II
*                                         The Real-Time Kernel
*
*                                (c) Copyright 2004, Micrium, Weston, FL
*                                          All Rights Reserved
*
*
*                                      BOARD SUPPORT PACKAGE (BSP)
*                                         Frescale MC9S12
*
* File : BSP.C
* By   : Eric Shufro
*********************************************************************************************************
*/

#include "include.h"


/*
*********************************************************************************************************
*                                        CONSTANTS
*********************************************************************************************************
*/



/*
*********************************************************************************************************
*                                        MACROS
*********************************************************************************************************
*/
         

/*
*********************************************************************************************************
*                                        PROTOTYPES
*********************************************************************************************************
*/



/*
*********************************************************************************************************
*                                        DATATYPES
*
*
*********************************************************************************************************
*/

static void PIT_Init(void);
static void OSTickISR_Init(void);
static void Led_Init(void);
/*
*********************************************************************************************************
*                                        GLOBALS
*********************************************************************************************************
*/




/*
*********************************************************************************************************
*                                        BSP_Init()
*********************************************************************************************************
*/
void
BSP_Init(void)
{
  PIT_Init();
  OSTickISR_Init();
  Led_Init();
}

/*
*********************************************************************************************************
*                                        PIT_Init()
*********************************************************************************************************
*/
static void 
PIT_Init(void)
{
  PITCFLMT_PITE=0;  //先关掉定时器模块
  PITCE_PCE0=1;     //定时通道0使能
  PITMUX=0x00;      //通道定时器使用微计数器0
  PITINTE_PINTE0=1; //第一路定时器的定时中断被使能
  
  PITMTLD0=0x07;/*0x4c;    */  
  PITLD0=0xa120;/*0x4b40;  */  /*晶振10M，这里定时100ms中断*/
  
  PITCFLMT_PITE=1;  //开定时器模块 
  
}

/*
*********************************************************************************************************
*                                        OSTickISR_Init()
*********************************************************************************************************
*/
static void
OSTickISR_Init(void)
{


}

/*
*********************************************************************************************************
*                                        Led_Init()
*********************************************************************************************************
*/                  
static void 
Led_Init(void)
{
  DDRP=0x10;
  PTP=0xff;       /*close led*/

}
