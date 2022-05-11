#ifndef __BSP_XPT2046_LCD_H
#define	__BSP_XPT2046_LCD_H


#include "stm32f1xx_hal.h"


#define             macXPT2046_EXTI_ActiveLevel                     0

#define             macXPT2046_EXTI_Read()											HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_4)


#define             macXPT2046_CS_ENABLE()         HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13, GPIO_PIN_SET)
#define             macXPT2046_CS_DISABLE()        HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13, GPIO_PIN_RESET)

#define             macXPT2046_CLK_HIGH()         HAL_GPIO_WritePin(GPIOE, GPIO_PIN_0, GPIO_PIN_SET)
#define             macXPT2046_CLK_LOW()          HAL_GPIO_WritePin(GPIOE, GPIO_PIN_0, GPIO_PIN_RESET)

#define             macXPT2046_MOSI_1()          HAL_GPIO_WritePin(GPIOE, GPIO_PIN_2, GPIO_PIN_SET)
#define             macXPT2046_MOSI_0()          HAL_GPIO_WritePin(GPIOE, GPIO_PIN_2, GPIO_PIN_RESET)

#define             macXPT2046_MISO()            HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_3)


#define             macXPT2046_Coordinate_GramScan                  1               
#define             macXPT2046_THRESHOLD_CalDiff                    2              

#define	            macXPT2046_CHANNEL_X 	                          0x90 	         
#define	            macXPT2046_CHANNEL_Y 	                          0xd0	        



typedef	struct         
{	
   uint16_t x;		
   uint16_t y;
	
} strType_XPT2046_Coordinate;   


typedef struct        
{
	long double An,  		 
              Bn,     
              Cn,   
              Dn,    
              En,    
              Fn,     
              Divider;
	
} strType_XPT2046_Calibration;


typedef struct         
{
	long double dX_X,  			 
              dX_Y,     
              dX,   
              dY_X,    
              dY_Y,    
              dY;

} strType_XPT2046_TouchPara;



extern volatile uint8_t               ucXPT2046_TouchFlag;
extern volatile uint8_t               time_up;

extern strType_XPT2046_TouchPara      strXPT2046_TouchPara;



void                     XPT2046_Init                    ( void );

uint8_t                  XPT2046_Touch_Calibrate         ( void );
uint8_t                  XPT2046_Get_TouchedPoint        ( strType_XPT2046_Coordinate * displayPtr, strType_XPT2046_TouchPara * para );
 
void Check_touchkey (void);  

strType_XPT2046_Coordinate Get_TouchedPoint();

int check_touchedInside(int x1 , int y1 , int x2 , int y2);

//-----------------------------
  

#endif /* __BSP_TOUCH_H */

