#ifndef __HW_UART_H__
#define __HW_UART_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "usart.h"

HAL_StatusTypeDef uartTx(uint8_t* data, uint32_t size);

#ifdef __cplusplus
}
#endif

#endif