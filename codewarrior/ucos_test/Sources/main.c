#include <hidef.h>      /* common defines and macros */
#include "derivative.h"      /* derivative-specific definitions */

#include "include.h"


static  OS_TCB  AppTaskStartTCB;
static  CPU_STK  AppTaskStartStk[100];



static  void    AppTaskStart(void *p_arg);

void main(void) 
{
  /* put your own code here */
  
 /* BSP_Init(); 
  IRQCR=0x00;
  EnableInterrupts;
 */
 
#if 1  
  OS_ERR err;
  CPU_SR  cpu_sr;
  CPU_CRITICAL_ENTER(); 
  
  IRQCR=0x00;   /*由于我板子原因，需要设置外部中断禁止*/

	OSInit(&err);


  OSTaskCreate((OS_TCB * )&AppTaskStartTCB,
                  (CPU_CHAR *)"app",
                  (OS_TASK_PTR)AppTaskStart,
                  (void *)0,
                  (OS_PRIO)4,
                  (CPU_STK *)&AppTaskStartStk[0],
                  (CPU_STK_SIZE)10,
                  (CPU_STK_SIZE)100,
                  (OS_MSG_QTY)0,
                  (OS_TICK)0,
                  (void *)0,
                  (OS_OPT)(OS_OPT_TASK_STK_CHK|OS_OPT_TASK_STK_CLR),
                  (OS_ERR *)&err);
                  
                  
//  CPU_CRITICAL_EXIT();

  OSStart(&err);  
  
#endif


  /* please make sure that you never leave main */
}

static  void  AppTaskStart (void *p_arg)
{
    OS_ERR err;
    p_arg=p_arg;
    
    BSP_Init();     /*初始化PIT模块和LED*/
    CPU_Init(); 
                                      
    while (DEF_TRUE) 
    {                                            
  /*     if(PTP==0xff)
         {
            PTP=0;
         }
         else
         {
            PTP=0xff;
         }              
   */
          /*closed extern interrupt*/
        OSTimeDlyHMSM((CPU_INT16U)0,       /*延时100ms*/
                      (CPU_INT16U)0,
                      (CPU_INT16U)0,
                      (CPU_INT32U)100,
                      (OS_OPT)OS_OPT_TIME_HMSM_STRICT,
                      (OS_ERR *)&err
                   );
    }
}
