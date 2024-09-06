#include "hw_uart.h"

static UART_HandleTypeDef* debugUART = &huart2;

void uartInit(void)
{

}

/*
  # 115200 bps 기준
  115200 / 8 = 14400 bytes -> 1초

  14400 / 1024 = 14.0624 kbytes

  1ms : 115.2 bits -> 14.4 bytes
  if (size > 14)
  {
    // 전송 데이터에 문제 발생 가능성
  }
*/
/*
void uartTx(uint8_t* data, uint32_t size)
{
  uint32_t bps = debugUART->Init.BaudRate; // 115200 bps
  uint32_t timeout_bit = bps / 1000; // 115200 / 1000ms = 115.2 bps per 1ms
  uint32_t timeout_byte = timeout_bit / 8; // 14 byte

  if (size > timeout_byte)
  {
    // 14 바이트 이상이면 1ms -> 전송 데이터에 문제 발생
    
  }

  return HAL_UART_Transmit(debugUART, (const uint8_t*)data, size, size/14);
}
*/

HAL_StatusTypeDef uartTx(uint8_t* data, uint32_t size)
{
  uint32_t timeout = size / 14;
  if (timeout < 1)
  {
    timeout = 1;
  }
  return HAL_UART_Transmit(debugUART, (const uint8_t*)data, size, timeout);
}