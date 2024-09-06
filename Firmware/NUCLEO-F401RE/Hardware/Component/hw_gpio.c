#include "hw_gpio.h"




static PinInfo_t gpio[GPIO_PIN_MAX] = 
{ 
  { LD2_GPIO_Port,  LD2_Pin,  HIGH },
};

void pinInit(void)
{
  bool ret;

  for (uint8_t i=0; i<GPIO_PIN_MAX; i++)
  {
    ret = pinWrite(i, gpio[i].state);
    if (!ret)
    {
      break;
    }
  }

  return ret;
}

uint8_t pinRead(uint8_t ch)
{
  uint8_t state;

  gpio[ch].state = HAL_GPIO_ReadPin(gpio[ch].port, gpio[ch].pin);

  state = gpio[ch].state;

  if (state > HIGH)
  {
    return 0xFF;
  }
  return state;
}

bool pinWrite(PinList_t ch, uint8_t state)
{
  if (ch >= GPIO_PIN_MAX || state > HIGH)
  {
    return false;
  }

  HAL_GPIO_WritePin(gpio[ch].port, gpio[ch].pin, state);

  return true;
}

bool pinToggle(PinList_t ch)
{
  if (ch >= GPIO_PIN_MAX)
  {
    return false;
  }

  HAL_GPIO_TogglePin(gpio[ch].port, gpio[ch].pin);

  return true;
}

bool pinToggleDelay(PinList_t ch, uint32_t repeatCount, uint32_t ms)
{
  if (ch >= GPIO_PIN_MAX)
  {
    return false;
  }

  uint32_t currentTime = HAL_GetTick();

  for (uint32_t i=0; i<repeatCount; i++)
  {
    if (HAL_GetTick() - currentTime >= ms)
    {
      currentTime = HAL_GetTick();
      pinToggle(ch);
    }
  }
}