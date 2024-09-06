#include "hw.h"

bool hwInit(void)
{
  bool ret = true;
  ret &= pinInit();
  return ret;
}