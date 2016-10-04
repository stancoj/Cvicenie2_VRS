/**
*****************************************************************************
**
**  File        : main.c
**
**  Abstract    : main function.
**
**  Functions   : main
**
**  Environment : Atollic TrueSTUDIO/STM32
**                STMicroelectronics STM32Lxx Standard Peripherals Library
**
**  Distribution: The file is distributed "as is", without any warranty
**                of any kind.
**
**  (c)Copyright Atollic AB.
**  You may use this file as-is or modify it according to the needs of your
**  project. This file may only be built (assembled or compiled and linked)
**  using the Atollic TrueSTUDIO(R) product. The use of this file together
**  with other tools than Atollic TrueSTUDIO(R) is not permitted.
**
*****************************************************************************
*/

/* Includes */
#include <stddef.h>
#include "stm32l1xx.h"


/* Private typedef */
/* Private define  */
/* Private macro */
/* Private variables */
/* Private function prototypes */
/* Private functions */


/**
**===========================================================================
**
**  Abstract: main program
**
**===========================================================================
*/
int main(void)
{
  int i = 0;

  RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOA,ENABLE);
  RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOC,ENABLE);

  	GPIO_InitTypeDef GPIO_Init_LED, GPIO_Init_BUTTON;

  	GPIO_Init_LED.GPIO_Mode = GPIO_Mode_OUT;
  	GPIO_Init_LED.GPIO_OType = GPIO_OType_PP;
  	GPIO_Init_LED.GPIO_Pin = GPIO_Pin_5;
  	GPIO_Init_LED.GPIO_Speed = GPIO_Speed_40MHz;

  	GPIO_Init_BUTTON.GPIO_Mode = GPIO_Mode_IN;
  	GPIO_Init_BUTTON.GPIO_OType = GPIO_OType_PP;
  	GPIO_Init_BUTTON.GPIO_Pin = GPIO_Pin_13;
  	GPIO_Init_BUTTON.GPIO_PuPd = GPIO_PuPd_NOPULL;

	GPIO_Init(GPIOA,&GPIO_Init_LED);
	GPIO_Init(GPIOC,&GPIO_Init_BUTTON);

  while (1)
  {
	i++;
  }
  return 0;
}

#ifdef  USE_FULL_ASSERT

/**
  * @brief  Reports the name of the source file and the source line number
  *   where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t* file, uint32_t line)
{
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

  /* Infinite loop */
  while (1)
  {
  }
}
#endif

/*
 * Minimal __assert_func used by the assert() macro
 * */
void __assert_func(const char *file, int line, const char *func, const char *failedexpr)
{
  while(1)
  {}
}

/*
 * Minimal __assert() uses __assert__func()
 * */
void __assert(const char *file, int line, const char *failedexpr)
{
   __assert_func (file, line, NULL, failedexpr);
}
