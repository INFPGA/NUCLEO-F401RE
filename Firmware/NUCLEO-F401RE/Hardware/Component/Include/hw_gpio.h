#ifndef __HW_GPIO_H__
#define __HW_GPIO_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "gpio.h"

#define LOW         0
#define HIGH        1

typedef enum
{
  LED,
  GPIO_PIN_MAX
} PinList_t;

typedef struct
{
  GPIO_TypeDef* port;
  uint32_t pin;
  uint8_t state;
} PinInfo_t;

void pinInit(void);
uint8_t pinRead(uint8_t ch);
bool pinWrite(PinList_t ch, uint8_t state);
bool pinToggleDelay(PinList_t ch, uint32_t repeatCount, uint32_t ms);

#ifdef __cplusplus
}
#endif

#endif