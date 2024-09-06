#ifndef HW_GPIO_H_
#define HW_GPIO_H_

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

bool pinInit(void);
uint8_t pinRead(uint8_t ch);
bool pinWrite(PinList_t ch, uint8_t state);
bool pinToggle(PinList_t ch);

#ifdef __cplusplus
}
#endif

#endif